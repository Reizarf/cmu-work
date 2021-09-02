/** M6502: portable 6502 emulator ****************************/
/**                                                         **/
/**                       Machine.c                         **/
/**                                                         **/
/** This file contains machine-specific code used by the    **/
/** 6502 CPU emulation.                                     **/
/**                                                         **/
/** Copyright (C) Wayne Wall 2020                           **/
/**                                                         **/
/*************************************************************/

#include "M6502.h"
#include "Machine.h"
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// Internal function prototypes

void Newline();

void ConsoleInitOutput();
void ConsoleResetOutput();
void ConsoleOutChar(byte value);

void ConsoleInitInput();
void ConsoleResetInput();
byte ConsoleGetChar();

void BootLoader();
void LoadBinary(FILE *file);
byte ReadTwoHexDigits(FILE *file);

// Global variables.

#define EMULATOR_STOP 0       /* Emulator should stop running */
#define EMULATOR_RUN  1       /* Emulator should keep running */
#define EMULATOR_USER_ABORT 2 /* User has aborted emulator */
#define EMULATOR_BOOTLOADER 3 /* Emulator is running the bootloader */

byte EmulatorStatus = EMULATOR_RUN; // Holds emulator status.

// Define special "user abort" keystroke.

#define USER_ABORT_KEY 0x05   /* Ctrl-E */

// This array represents the first 60 KB of 6502 RAM from
// hex address 0000 through BFFFF.

#define RAM_MIN_ADDR 0x0000
#define RAM_MAX_ADDR 0xEFFF

byte RAM[RAM_MAX_ADDR - RAM_MIN_ADDR + 1];
size_t RAM_SIZE = sizeof(RAM) / sizeof(RAM[0]);

// This array represents ROM beginning at hex address F000
// and extending through FFFF.

#define ROM_MIN_ADDR 0xF000
#define ROM_MAX_ADDR 0xFFFF

byte ROM[ROM_MAX_ADDR - ROM_MIN_ADDR + 1];
size_t ROM_SIZE = sizeof(ROM) / sizeof(ROM[0]);

// Special IO addresses

#define IO_CONSOLE_OUT 0xEC01
#define IO_CONSOLE_IN 0xEC00

// ***** Main program entry function *****

int main()
{
  printf("M6502 Emulator");
  Newline();
  
  // Zero all RAM memory
  
  for ( size_t i = 0; i < RAM_SIZE; ++i )
  {
    RAM[i] = 0;
  }
  
  // Zero all ROM storage
  
  for ( size_t i = 0; i < ROM_SIZE; ++i )
  {
    ROM[i] = 0;
  }
  
  // Set emulator status
  
  EmulatorStatus = EMULATOR_RUN;
  
  while ( EmulatorStatus != EMULATOR_STOP )
  {  
    BootLoader();
    
    M6502 machine_state;
    memset(&machine_state, 0, sizeof(machine_state));
    
    // Initialize 6502 machine state.   

    Reset6502(&machine_state);
    
    // Initialize console I/O
    
    ConsoleInitOutput();
    ConsoleInitInput();  

    word state = Run6502(&machine_state);
    
    // Reset console I/O
    
    ConsoleResetInput();
    ConsoleResetOutput();
    
    // If program was aborted by user...
    
    if ( EmulatorStatus == EMULATOR_USER_ABORT )
    {
      Newline();
      printf("User abort from console...");
      Newline();
    }
    
    Newline();
    printf("main: Run6502(...) returned $%04X", state);
    Newline();
    
    char response[] = "XXX";
    size_t response_size = sizeof(response) / sizeof(response[0]);
    
    printf("Exit emulator (Y=Yes, N=No)? ");
    fgets(response, response_size-1, stdin);
    
    if ( toupper(response[0]) == 'Y' )
    {
      break;
    }
    
    EmulatorStatus = EMULATOR_RUN;
  }
  
  return 0;
}

// Write a byte to the specified address

void Wr6502(register word Addr,register byte Value)
{
  // If writing to RAM space...
    
  if ( ( Addr >= RAM_MIN_ADDR) && ( Addr <= RAM_MAX_ADDR ) )
  {
    // If writing to a special I/O address
    
    if ( Addr == IO_CONSOLE_OUT )
    {
      ConsoleOutChar(Value);
    }
    else
    {
      RAM[Addr - RAM_MIN_ADDR] = Value;
    }
  }
  else
  {
    // If writing to ROM space...
    
    if ( ( Addr >= ROM_MIN_ADDR ) && ( Addr <= ROM_MAX_ADDR ) )
    {
      // If we're running the bootloader, it's okay to write to ROM.
      
      if ( EmulatorStatus == EMULATOR_BOOTLOADER )
      {
        ROM[Addr - ROM_MIN_ADDR] = Value;
      }
      else
      {
        printf("\r\nIgnoring attempt to write ROM address (%04X)\r\n", (int) Addr);
      }
    }
    else
    {
      printf("\r\nIgnoring attempt to write to invalid address (%04X)\r\n", (int) Addr);
    }
  }
}

// Read a byte from the specified address

byte Rd6502(register word Addr)
{
  // If address is in ROM space...
  
  if ( ( Addr >= ROM_MIN_ADDR) && ( Addr <= ROM_MAX_ADDR ) )
  {
    return ROM[Addr - ROM_MIN_ADDR];
  }
  else
  {
    // If address is in general RAM space
    
    if ( ( Addr >= RAM_MIN_ADDR) && ( Addr <= RAM_MAX_ADDR ) )
    {
      // If reading from a special I/O address
      
      if ( Addr == IO_CONSOLE_IN )
      {
        return ConsoleGetChar();
      }
      else
      {
        // *** TEMP *** For testing MDIAG memory diagnostic program.
        
        // If address is within $C000 - $CFFF (inclusive)...

        /*
        if ( ( Addr >= 0xC000 ) && ( Addr <= 0xCFFF ) )
        {
          // Every so often, return bad data.
            
          if ( ( rand() % 1000000 ) == 0 )
          {
            return RAM[Addr - RAM_MIN_ADDR] ^ 0x20;
          }
        }
        */
        
        // *** END OF TEMP ***
        
        return RAM[Addr - RAM_MIN_ADDR];
      }
    }
    else
    {
      printf("\r\nReading from invalid address (%04X).  Returning zero.\r\n", (int) Addr);
    }
  } 
}

// Determines if an interrupt needs to happen.

byte Loop6502(register M6502 *R)
{
  // Based on emulator status...
  
  switch ( EmulatorStatus )
  {
    case EMULATOR_RUN:
      return INT_NONE;  // Continue to run
      break;
      
    case EMULATOR_USER_ABORT:
    default:
      return INT_QUIT;  // Stop the emulator
      break;
  }
}

/** Patch6502() **********************************************/
/** Emulation calls this function when it encounters an     **/
/** unknown opcode. This can be used to patch the code to   **/
/** emulate BIOS calls, such as disk and tape access. The   **/
/** function should return 1 if the exception was handled,  **/
/** or 0 if the opcode was truly illegal.                   **/
/********************************************************** **/

byte Patch6502(register byte Op,register M6502 *R)
{
  Newline();
  printf("Unknown 6502 opcode (%x)", Op);
  Newline();
  
  return 0;   // Assume opcode is NOT a BIOS call.
}

// Advance to a new line on the console.
// "\r\n" on Windows machines.
// "\n" on Linux/Macintosh machines.

void Newline()
{
  printf("\n");
}

// Init console for output.  Called once before output begins.

void ConsoleInitOutput()
{
  // *** Nothing to do! ***
}

// Reset console after output is finished.

void ConsoleResetOutput()
{
  // Make sure all output buffers have been flushed.
  
  fflush(stdout);
}

// Output one character to the console

void ConsoleOutChar(byte value)
{
  putchar( ( (int) value ) & 0xFF );
  fflush(stdout);
}

// Initialize console input before first use.

struct termios initial_term;  // Holds initial terminal config

void ConsoleInitInput()
{
  // Fetch initial terminal configuration (for later restoration)
  
  tcgetattr( fileno(stdin), &initial_term);
  
  struct termios current_term;
  
  // Fetch current terminal config (for modification)
  
  tcgetattr( fileno(stdin), &current_term );

  cfmakeraw(&current_term);     // Set terminal to "raw" input mode.
  current_term.c_cc[VMIN] = 0;  // Non-blocking input.
 
  tcsetattr( fileno(stdin), TCSANOW, &current_term );
}

// Reset console input after all use.

void ConsoleResetInput()
{
  // Restore initial terminal state.
  
  tcsetattr( fileno(stdin), TCSANOW, &initial_term );
}

// Silently (no echo) input one character from the console

byte ConsoleGetChar()
{
  byte key_char = 0;
  
  // Non-blocking input.  Returns immediately if no character typed.
  
  read( fileno(stdin), &key_char, 1);
  
  // Since there's no special character processing, check to see if
  // user typed the USER_ABORT_KEY.
  
  if ( key_char == USER_ABORT_KEY )
  {
    // Indicate execution should be aborted at next opportunity.
    
    EmulatorStatus = EMULATOR_USER_ABORT;
  }
  
  return key_char & 0x7F;   // Return 7-bit ASCII character code
}

// Prompt user to load a binary file (or not)

void BootLoader()
{
  printf("Emulator Boot Loader");
  Newline();
  
  // Preserve emulator status and indicate we're running the bootloader.
  
  byte EmulatorStatusSaved = EmulatorStatus;
  EmulatorStatus = EMULATOR_BOOTLOADER;
  
  char file_name[FILENAME_MAX] = "";
  size_t file_name_size;
  
  do
  {
    Newline();
    printf("Enter binary file to load (or Enter to reset CPU): ");
    
    fgets(file_name, FILENAME_MAX - 1, stdin);
    file_name_size = strlen(file_name) - 1;     // Remove EOL from file namestring
    file_name[file_name_size] = '\0';
    
    // If a file name was entered, open the file and load binary from it.
    
    if ( file_name_size > 0 )
    {
      FILE *bin_file = fopen(file_name, "r");
      
      if ( bin_file != NULL )
      {
        LoadBinary(bin_file);
        fclose(bin_file);
      }
      else
      {
        printf("Can't open file %s", file_name);
        Newline();
      }
    }
    
  } while ( file_name_size != 0 );
  
  // Restore emulator status
  
  EmulatorStatus = EmulatorStatusSaved;
}

void LoadBinary(FILE *file)
{
  printf("Loading binary...");
  Newline();
  
  int file_char;
  word mem_addr = 0;  // Current memory address to store binary into.
  
  while ( ( file_char = fgetc(file) ) != EOF )
  {
    if ( file_char == '*' )
    {
      // New memory address follows in next 4 hex digts.
      // Low order byte is first.
      
      word value_high = ReadTwoHexDigits(file);
      word value_low = ReadTwoHexDigits(file);
      mem_addr = (value_high << 8) | value_low;
    }
    else
    {
      ungetc(file_char, file);  // Put character back in file stream
      
      // 8 bits of data follow as 2 hex digits
      
      byte value = ReadTwoHexDigits(file);
      Wr6502(mem_addr, value);
      mem_addr++;
    }
  }
  
  Newline();    
  
  printf("Binary successfully loaded");
  Newline();
}

byte ReadTwoHexDigits(FILE *file)
{
  byte value = 0;
  
  for ( size_t times = 1; times <= 2; times++ )
  {
    int file_char;
    
    if ( ( file_char = fgetc(file) ) != EOF )
    {
      if ( isxdigit(file_char) )
      {
        value = value << 4;
        
        if ( (file_char >= '0') && (file_char <= '9') )
        {
          value |= (file_char - '0');
        }
        else
        {
          value |= ( (toupper(file_char) - 'A') + 10);
        }
      }
      else
      {
        printf("Non-hex character encountered!");
        Newline();
        return 0;
      }
    }
    else
    {
      printf("Unexpected EOF!");
      Newline();
      return 0;      
    }
  }
  
  return value;
}

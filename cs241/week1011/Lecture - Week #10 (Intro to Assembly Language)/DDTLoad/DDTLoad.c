// Programmer: Wayne Wall
// Description: Loads Scot's 6502 assembler "binary" files into a TLB computer
//              by sending the file contents to an Arduino (connected to a USB
//              serial port) passes then on to DDT running on the TLB.
//
//              Before running DDTLoad, type the DDT "L" command on the TLB
//              to start the DDT loader code.  While the load is happening,
//              nothing will be displayed on the TLB.

#include <stdio.h>
#include <ctype.h>
//#include <termios.h>
#include <unistd.h>

typedef unsigned short word;

void BootLoader();
void LoadBinary(FILE *serial_port, FILE *bin_file);
void SendToTLB(FILE *serial_port, unsigned char value);
void SerialInit(FILE *serial_port);
void SerialReset(FILE *serial_port);

// Main entry point.
// Usage: DDTLoad serialport filename
//
// Where: serialport is the serial port (i.e., \dev\ttyUSB0).
//        filename name of assembler binary file.

int main(int argc,char *argv[])
{
  // Must have exactly three command line parameters

  if ( argc != 3 )
  {
    printf("Usage: DDTLoad serialport filename\n");
    printf("Where: serialport: is the serial port (i.e., /dev/ttyUSB0)\n");
    printf("       filename: name of assembler binary file\n\n");
    return 1;
  }

  // Open the USB serial port for binary output

  FILE *serial_port = fopen(argv[1], "wb");

  if ( serial_port == NULL )
  {
    printf("Error opening serial port '%s'\n", argv[1]);
    return 1;
  }

  // Open the binary file for input

  FILE *bin_file = fopen(argv[2], "r");

  if ( bin_file == NULL )
  {
    printf("Error opening binary file '%s'\n", argv[2]);
    fclose(serial_port);
    return 1;
  }


  // Load the binary file into the TLB via the USB serial port

  LoadBinary(serial_port, bin_file);

  fclose(bin_file);
  fclose(serial_port);
}

// Load an assembler binary file by sending the appropriate characters
// to the TLB computer via the Arudino USB serial port.

void LoadBinary(FILE *serial_port, FILE *bin_file)
{
  int file_char;

  sleep(1);

  while ( ( file_char = fgetc(bin_file) ) != EOF )
  {
    SendToTLB(serial_port, (unsigned char) file_char);
  }

  // Send a carriage return to signify the load has completed.

  SendToTLB(serial_port, '\r');

  fflush(serial_port);
  sleep(5);   // Wait to make sure buffers have time to empty.
}

// Send an 8-bit value to the TLB (via DDT input)

void SendToTLB(FILE *serial_port, unsigned char value)
{
  fprintf(serial_port, "%c", value);
  fflush(serial_port);  // Force output to serial port.
}


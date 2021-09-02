
/*	650X cross assembler for the IBM.  The assembler is based on the 	*/
/*	PAL65 resident assembler written for the Apple IIe.					*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_MAX 32
#define LINE_MAX 256
#define SYMBOL_MAX 17
#define OPCODE_MAX 10
#define ON 1
#define OFF 0

/*	Global file and IO pointers */
FILE	*srcdev;	/* Source file pointer */
FILE	*orgdev;	/* must maintain the original file pointer */
FILE	*lstdev;	/* Pointer to listing device.  Usu. lpt1: */
FILE	*bindev;	/* Pointer to object code file.  */
FILE	*errdev;	/* Pointer to error log file.  */

struct	opcode {
	char		name[OPCODE_MAX];
	unsigned short int class;
	unsigned short int code1;
	unsigned short int code2;
	struct opcode	*next;
	} *op_codes;

/****************************************************************/
/* class definitions 						*/
/*								*/
/*	class 0	Immediate mode operation			*/
/*	class 1	Absolute addressing mode including zero page	*/
/*	class 2	Absolute addressing mode no zero page mode	*/
/*	class 3	Zero page mode only addressing mode		*/
/*	class 4	Relative addressing mode			*/
/*	class 5	Implied addressing mode				*/
/****************************************************************/

struct	symbol {
	char		name[SYMBOL_MAX];
	unsigned long int  address;
	unsigned short int type;
	struct symbol	*next;
	struct symbol	*prev;
	struct symbol	*cref;
	} *sym_root;

/****************************************************************/
/*								*/
/* Symbol type definition					*/
/*								*/
/*	type 0	Undefined symbol, these should go away during	*/
/*		the first pass.					*/
/*	type 1	Label.  The value is the address at definition.	*/
/*	type 2	Variable.  The value is assigned at definition	*/
/*	type 3							*/
/*								*/
/****************************************************************/

unsigned long int	prog_count;	/* Program counter */
unsigned long int	line_count;	/* Program line counter */
unsigned long int	load_addr=0;	/* load address */	
char		in_line[LINE_MAX];	/* input line buffer    */
unsigned int    char_ptr=0;		/* pointer char in 'inline' */
unsigned int	paren;			/* parentesis counter */
unsigned int    err_flag=0;		/* maintains error count */
unsigned int    warn_flag=0;		/* maintains warning count */
unsigned short int pass=0;		/* pass number */
int	lst_pos;

void	file_init(void);
void	file_close(void);
void	pass1(void);
int		get_label(char *);
void	def_label(char * , int);
int     get_op(char *);
int     term(void);
int     fact(void);
int		get_operand(void);
int     get_sym(char * , int);
void    eat_space(void);
void    eat_to_space(void);
void	eat_to_delim(void);
int		isdelim(char);
unsigned short int lo_byte(int);
unsigned short int hi_byte(int);
void    print_ops(void);
void	print_sym(FILE *);
void	addr_out(unsigned int);
void	byte_out(unsigned int);
void	word_out(unsigned int);
void	pc_out(void);
void	line_out(void);
void	p_error(void);
void	head_out(void);
void	syntax(void);
int     type(char);
void	direct(void);
void	end(int);
//void	load_out(long int)
struct symbol *     find_symbol(char *);
struct symbol *     enter_symbol(char * , int);
struct opcode *     find_op(char *);

int	VERBOSE=OFF,	/* turn off verbose switch */
	LIST=ON,	/* Turn on LIST mode switch */
	CREF=OFF,	/* Turn off cross referance */
	HEADER=OFF,	/* Do not generate a header file */
	BIN=ON,		/* Generate apple binary code */			// (WW) Changed ";" to ","
	MOT=OFF;	/* Generate motorola S format code */
	

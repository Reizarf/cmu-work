/*	650X cross assembler for the IBM.  The assembler is based on the 	*/
/*	PAL65 resident assembler written for the Apple IIe.					*/

// (WW) Replace #define (which doesn't work with gcc) with explicit "#pragma GCC ..."
//#define _CRT_NONSTDC_NO_WARNINGS
#pragma GCC diagnostic ignored "-Wimplicit-int"
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#pragma GCC diagnostic ignored "-Wint-conversion"

#include "asm65.h"

/* Global variables for Motorola S format output */
int	bytes;		/* keeps track of the number of bytes output */
char	check_sum;	/* running check sum */
unsigned long int	mot_addr;
char	out_str[129];
char	source[FILE_MAX];
char	binary[FILE_MAX];
char	error[FILE_MAX];
char	list[FILE_MAX];
char	mot_out[FILE_MAX];

int	s_format(void);
//print_line(void);

// (WW) This program makes numerous calls to "strcmpi(...)", which seems
//	to be semi-deprecated and not available in gcc Linux libraries.
//	So, I copy/paste an implementation off the Internet.

int strcmpi(char* s1, char* s2){
    int i;
     
    if(strlen(s1)!=strlen(s2))
        return -1;
         
    for(i=0;i<strlen(s1);i++){
        if(toupper(s1[i])!=toupper(s2[i]))
            return s1[i]-s2[i];
    }
    return 0;
}

// (WW) Local implementation of "strlwr(...)" to convert a string to lower case.

void strlwr(char *str)
{
  while ( *str != '\0' )
  {
    *str = tolower(*str);
    str++;
  }
}

// (WW) Holds the relative path the program was launched from.
//	Includes trailing "/".

char rel_startup_path[FILE_MAX];

main(int argc,char *argv[])
{
int	i;
int	switch_flag;

// (WW) argv[0] holds path to program executable.
//	Keep the relative path where executable resides, so we know
//	where to look for other files (such as the opcode file).

char *lastSlash = strrchr(argv[0], '/');
size_t num_chars = lastSlash - argv[0] + 1;

strncpy(rel_startup_path, argv[0], num_chars);
rel_startup_path[num_chars] = '\0';


bytes=0;		/* initialize variables */
check_sum=0;
sym_root=NULL;
op_codes=init_op();
/*print_ops();*/

// (WW) The original logic here was incorrect.  Fixed it.

if ( argc > 1 )
{
    for (i = 1; i < argc; i++)
    {
	switch_flag=0;
	if (!strcmpi(argv[i],"/NOLIST")) {
	    LIST=OFF;
	    switch_flag=1;
	    }
	if (!strcmpi(argv[i],"/LIST")) {
	    LIST=ON;
	    switch_flag=1;
	    }
	if (!strcmpi(argv[i],"/VERBOSE")) {
	    VERBOSE=ON;
	    switch_flag=1;
	    }
	if (!strcmpi(argv[i],"/CREF")) {
	    CREF=ON;
	    switch_flag=1;
	    }
	if (!strcmpi(argv[i],"/NOCREF")) {
	    CREF=OFF;
	    switch_flag=1;
	    }
	if (!strcmpi(argv[i],"/HEADER")) {
	    HEADER=ON;
	    switch_flag=1;
	    }
	if (!strcmpi(argv[i],"/NOHEADER")) {
	    HEADER=OFF;
	    switch_flag=1;
	    }
	if (!strcmpi(argv[i],"/MOT")) {
	    MOT=ON;
	    switch_flag=1;
	    }
	if (!strcmpi(argv[i],"/BIN")) {
	    MOT=OFF;
	    switch_flag=1;
	    }
	if (!switch_flag) {
	    printf("Unrecognized switch %s\n",argv[i]);
	    }
    }
}

file_init();

pass=0;			/* optimization first pass */
pass1();
if (srcdev!=orgdev) {
    fclose(srcdev);
    srcdev=orgdev;
    }
rewind(srcdev);
pass=1;			/* secondary optimization passes */
if (!err_flag) {
    pass=2;		/* code generation pass */
    printf ("Generating Code\n");
    pass1();
    }
if (MOT && !err_flag) {
    printf ("Engaging s-format post processor\n");
    printf ("Opening output file %s\n",mot_out);
    printf ("Opening input file %s\n",binary);
    fclose(srcdev);
    if ((srcdev=fopen(binary,"r"))==NULL) {
        printf ("Could not open source file.\n");
        end(1);
        }
    fclose(bindev);
    if ((bindev=fopen(mot_out,"w"))==NULL) {
        printf ("Could not open output file.\n");
	end(1);
        }
    s_format();
    }
end(0);
}

void pass1()
{
char	label[SYMBOL_MAX];
char	opcode[OPCODE_MAX];
int     i,j,k;
struct symbol *sym_ptr;

line_count=0;
prog_count=0;
while (fgets(in_line,LINE_MAX,srcdev) != NULL) {
    char_ptr=0;
    line_count++;
    printf("Line %lu\r",line_count);
    switch (type(in_line[char_ptr])) {
        case 0:     /*  type 0 is a white space char*/
        eat_space();
        if (VERBOSE) fprintf (errdev,"First char in line %lu is a space.\n",line_count);
	if (VERBOSE) fprintf (errdev,"Program counter = $%04X\n",prog_count);
        syntax();	/* Interpret rest of line */
        break;

        case 1:    /* type 1 is alphabetic */
        if (VERBOSE) fprintf (errdev,"First char in line %lu is a LABEL\n",line_count);
	if (VERBOSE) fprintf (errdev,"Program counter = $%04X\n",prog_count);
	def_label(label,1);	/* Label here is definition */
        eat_space();   /* Eat any white spaces */
        syntax();      /* interpret the rest of the line */
        break;

        case 3:
	case 4:    
        if (VERBOSE) fprintf (errdev,"Line %lu is a comment\n",line_count);
	if (VERBOSE) fprintf (errdev,"Program counter = $%04X\n",prog_count);
        break;

        case 5:
        case 6:
        if (VERBOSE) fprintf (errdev,"Line %lu is compiler directive\n",line_count);
	if (VERBOSE) fprintf (errdev,"Program counter = $%04X\n",prog_count);
	direct();
        break;

	default:
	printf ("First char in line %lu is illegal\n",line_count);
	fprintf (errdev,"First char in line %lu is illegal\n",line_count);
	err_flag++;
        break;
        }
    if (pass==2) line_out();
    }
printf("\n");
}

void syntax()

{

switch (type(in_line[char_ptr])) {
    case 1:    /* Alphabetic, must be opcode */
    do_op();
    break;
    case 3:     /* ; is still a comment */
    case 4:	/* ! is a comment */
    break;
    case 5:     /* dot is a directive here */
    case 6:     /* # is also a directive */
    direct();
    break;
    default:   /* All others are illegal */
    break;          
    }
}

void direct()
{
char	dir[SYMBOL_MAX];
char	arg[SYMBOL_MAX];
char	var[SYMBOL_MAX];
char	file_name[FILE_MAX];
struct symbol *var_ptr;
long int value;
unsigned short int byte;
unsigned int  word;
int	i,j;

get_sym(dir,SYMBOL_MAX);
if (!strcmpi(dir,".LOC")) {	/* Set program counter */
    if (VERBOSE) fprintf(errdev,"Got a .LOC\n");
    if ((prog_count=get_operand())) {
	if (VERBOSE) fprintf (errdev,"Program counter is $%04X\n",prog_count);
	if (in_line[char_ptr]==',') {
	    char_ptr++;
	    if ((load_addr=get_operand()) >= 0) {
		if (VERBOSE) fprintf (errdev,"Load address is $%04X\n",load_addr);
		}
	    else {
		printf ("Invalid load address in line %lu\n",line_count);
		fprintf (errdev,"Invalid load address in line %lu\n",line_count);
		err_flag++;
    		}
	    }
	else {
	    load_addr=prog_count;
	    if (VERBOSE) fprintf (errdev,"Load address is $%04X\n",load_addr);
	    }
	if (pass==2) load_out(load_addr);
	}
    else {
	printf ("Invalid compile address in line %lu\n",line_count);
	fprintf (errdev,"Invalid compile address in line %lu\n",line_count);
	err_flag++;
	}
    }

if (!strcmpi(dir,".DEF") && (!pass)) {	/* Define a constant */  // (WW) Changed & to &&
    if (VERBOSE) fprintf (errdev,"Got a .DEF in %lu\n",line_count);
    if (VERBOSE) fprintf (errdev,"pass = %d\n", pass);   // (WW) Temp diagnostic
    eat_space();
    get_sym(var,SYMBOL_MAX);
    switch (pass) {
        case 0:
	// (WW) It's okay if the symbol is in the symbol table, but
	//	has yet to be defined. If already defined, then issue error.
	//	Changed logic here.
	
	var_ptr = find_symbol(var);
	
	if (var_ptr != NULL)
	{
	    if ( var_ptr->type == 0 )
	    {
		// Variable is in symbol table, but undefined.
		// Get operand and make that the variable's value.
		
		eat_space();
		if (in_line[char_ptr]=='=')
		{
		    char_ptr++;
		    var_ptr->address=get_operand();
		    var_ptr->type = 2;
		    if (VERBOSE) fprintf(errdev,"%s = $%04X\n",var,var_ptr->address);
		}		
	    }
	    else
	    {	    
		printf ("ERROR: Multiply defined symbol %s\n",var);
		fprintf (errdev,"ERROR: Multiply defined symbol %s\n",var);
		p_error();
		err_flag++;
	    }
	}
        else
	{
	    var_ptr=enter_symbol(var,2);
	    eat_space();
	    if (in_line[char_ptr]=='=') {
	        char_ptr++;
	        var_ptr->address=get_operand();
	        if (VERBOSE) fprintf(errdev,"%s = $%04X\n",var,var_ptr->address);
	        }
	    else {
	        var_ptr->address=NULL;
	        }
	}
	break;

	case 1:
	case 2:
	break;

        }
    }
    
if (!strcmpi(dir,".BYTE")) {	/* Initialize one byte location */
    if (VERBOSE) fprintf(errdev,"Got a .BYTE in line %lu\n",line_count);
    eat_space();
    value=get_operand();
    byte=value & 0XFF;		/* only use low order byte */
    if (pass==2) {
	pc_out();
	byte_out(byte);
	}
    prog_count++;
    }

if (!strcmpi(dir,".WORD")) {	/* Initialize two byte location */
    if (VERBOSE) fprintf(errdev,"Got a .WORD in line %lu\n",line_count);
    eat_space();
    value=get_operand();
    word=value & 0XFFFF;		/* Only use top two bytes */
    if (pass==2) {
	pc_out();
	word_out(word);
	}
    prog_count+=2;
    }

if (!strcmpi(dir,".ASCII")) {	/* Initialize an ascii string */
    if (VERBOSE) fprintf(errdev,"Got a .ASCII in line %lu\n",line_count);
    eat_space();
    
    // (WW) First non-whitespace character after the ".ASCII" directive
    //      is the text delimiter.
    
    if ( in_line[char_ptr] != '\0' )
    {
	char text_delim = in_line[char_ptr];
	
	if ( pass == 2 ) pc_out();
	char_ptr++;
	
	char text_char = in_line[char_ptr];
	
	while ( (text_char != text_delim) && (text_char != '\0') )
	{
	    if ( pass == 2 ) byte_out(text_char);
	    char_ptr++;
	    prog_count++;
	    text_char = in_line[char_ptr];
	}
    }
    else
    {
	printf ("ERROR: Illegal ascii string in line %lu\n",line_count);
	fprintf (errdev,"ERROR: Illegal ascii string in line %lu\n",line_count);
	p_error();
	err_flag++;
    }
}

if (!strcmpi(dir,".PAGE")) {	/* Break the page on listing output */
    if(LIST) fprintf(lstdev,"\f");
    }

if (!strcmpi(dir,".LIST")) {	/* Turn on listing to output */
    LIST=ON;
    }

if (!strcmpi(dir,".NOLIST")) {	/* Turn off listing to output */
    LIST=OFF;
    }

if (!strcmpi(dir,".VERBOSE")) {		/* Turn on trouble shooting */
    VERBOSE=ON;
    }

if (!strcmpi(dir,".NOVERBOSE")) {	/* Turn off trouble shooting */
    VERBOSE=OFF;
    }

if (!strcmpi(dir,".BIN")) {	/* Generate binary - default*/
    BIN=ON;
    }

if (!strcmpi(dir,".NOBIN")) {	/* Do not generate binary */
    BIN=OFF;
    }

if (!strcmpi(dir,".LINK")) {	/* Link in another file */
//    BIN=ON;			/* turn on binary generation */	// (WW) Don't think this should be here
    if (VERBOSE) fprintf(errdev,"Got a .LINK in %ld\n",line_count);
    eat_space();
    i=get_sym(file_name,FILE_MAX);
    j=0;
    for (i=0;((i<FILE_MAX) && (file_name[i]!='\0'));i++) {  // (WW) Changed NULL to '\0'
	if (file_name[i]=='.') j++;
	}
    if (j==0) {
	file_name[i++]='.';
	file_name[i++]='P';
	file_name[i++]='6';
	file_name[i++]='5';
	file_name[i]='\0';		/* terminate string */ // (WW) Changed NULL to '\0'
	}
    printf ("Linking file %s at line %ld\n",file_name,line_count);
    if(VERBOSE)fprintf (errdev,"Linking file %s at line %ld\n",file_name,line_count);
    if (srcdev!=orgdev) fclose(srcdev);
    if ((srcdev=fopen(file_name,"r"))==NULL) {
	// (WW) Try lower case filename as well.
	strlwr(file_name);
	if ( (srcdev = fopen(file_name, "r")) == NULL ) {
	    printf ("LINK ERROR: can not open link file %s\n",file_name);
	    fprintf (errdev,"LINK ERROR: can not open link file %s\n",file_name);
	    err_flag++;
	    end(1);
	    }
	}
    }

if (!strcmpi(dir,".END")) {	/* End of input */
    if (VERBOSE) fprintf(errdev,"Got a .END in line %lu\n",line_count);
    if (pass==2) {
	if(LIST)fprintf(lstdev,"END at line %ld\n",line_count);
	if (!MOT) end (0);	// (WW) Don't call "end()" if generating MOT
	}
    }
}

do_op()
{
char    opcode[OPCODE_MAX];     /* place for opcode */
unsigned long int address;	/* address of operand */
int rel_add;			/* relative address */
struct opcode *op;      	/* pointer to opcode table */

get_op(opcode);
if (VERBOSE) fprintf (errdev,"Have opcode %s  ",opcode);
if((op=find_op(opcode))!=NULL) {
    if (pass==2)pc_out();
/*    prog_count++;*/
    switch (op->class) {
        case 0:	/* Immediate mode instructions */
	eat_space();
	if (pass==2) {
	    byte_out(op->code1);
	    }
	address=get_operand();
	if ((address>255) && (pass != 0)) {  // (WW) Don't check during pass 0.
	    printf ("WARNING: Immediate mode operand over range line %lu\n",line_count);
	    fprintf (errdev,"WARNING: Immediate mode operand over range line %lu\n",line_count);
	    p_error();
	    }
	if (pass==2) byte_out(address & 0XFF);
	prog_count+=2;
	break;

        case 1:	/* Absolute mode, incl. zero page */
	eat_space();
        address=get_operand();
	prog_count+=2;
	if (address>255) {	/* Two byte address */
	    prog_count++;
	    if (pass==2) {
		byte_out(op->code2);
	        word_out(address);
		}
	    }
	else {
	    if (pass==2) {
		byte_out(op->code1);
		byte_out(address);
		}
	    }
        break;

        case 2:	/* Absolute without a zero page mode */
        eat_space();       /* eat any spaces */
	address=get_operand();
	prog_count+=3;
	if (pass==2) {
	    byte_out(op->code1);
	    word_out(address);
	    }
        break;

        case 3:	/* Zero page only instructions */
	eat_space();
	address=get_operand();
	prog_count+=2;
	if (pass==2) {
	    byte_out(op->code1);
	    byte_out(address);
	    }
	break;

        case 4:	/* Relative addressing */
	eat_space();
	address=get_operand();
        prog_count+=2;
	if (pass==2) {
	    byte_out(op->code1);
	    rel_add=address-prog_count;
	    byte_out(rel_add);
	    if ((rel_add>127) || (rel_add<-128)) {
		printf("WARNING: Relative address too big line %lu\n",line_count);
		fprintf(errdev,"WARNING: Relative address too big line %lu\n",line_count);
		p_error();
		}
	    }
        break;

	case 5:	/* Implied addressing mode */
	if (pass==2) byte_out(op->code1);
	prog_count++;
	break;

	default:	/* Just in case */
	printf ("ERROR: Illegal opcode class.  Compiler error\n");
	fprintf (errdev,"ERROR: Illegal opcode class.  Compiler error\n");
	p_error();
	end(1);
	break;
        }
    }
else {
    printf ("ERROR: Unrecognized op-code %s\n",opcode);
    fprintf (errdev,"ERROR: Unrecognized op-code %s\n",opcode);
    p_error();
    err_flag++;
    }
}

get_operand()
{
int     val;

// (WW) If we're pointing to the beginning of a comment, then return
//	a default operand of zero.

if ( char_ptr <= LINE_MAX )
{
    if ( type(in_line[char_ptr]) == 3 )
    {
	return 0;  // Beginning of a comment.
    }
}

val=term();
eat_space();
while ((char_ptr <= LINE_MAX)) {
    switch (in_line[char_ptr]) {
	case '+':
	char_ptr++;     /* space over operator */
	eat_space();
	val+=term();
	break;

	case '-':
	char_ptr++;     /* space over operator */
	eat_space();
	val-=term();
	break;

	case ')':
	paren--;
	char_ptr++;
	eat_space();
	return val;
	break;

	case ';':
	case ',':
	case 0:
	if (paren) printf ("WARNING: Unmatched parenthesis\n");
	if (paren) fprintf (errdev,"WARNING: Unmatched parenthesis\n");
	return val;
	break;

	default:
	printf ("Illegal syntax in line %lu at %d\n",line_count,char_ptr);
	fprintf (errdev,"Illegal syntax in line %lu at %d\n",line_count,char_ptr);
	return val;
	break;
	}
    }
}

term()
{
int     val;

val=fact();
eat_space();
while (char_ptr<=LINE_MAX) {
    switch (in_line[char_ptr]) {
	case '*':
	char_ptr++;     /* space over operator */
	eat_space();
	val*=fact();
	break;

	case '/':
	char_ptr++;     /* space over operator */
	eat_space();
	val/=fact();
	break;

	case 0:
	default:
	return val;
	break;
	}
    }
}

fact()
{
char    oper[SYMBOL_MAX];
struct symbol *sym;

eat_space();
switch (in_line[char_ptr]) {
    case '\'':		/* enter an ascii character */
    char_ptr+=2;
    return in_line[char_ptr-1];
    break;

    case '.':		/* Use PC for value */
    char_ptr++;
    eat_space();
    return prog_count;
    break;

    case '>':            /* high order byte */
    char_ptr++;
    eat_space;
    return (fact()>>8) & 0X00FF;
    break;

    case '<':            /* low order byte */
    char_ptr++;
    eat_space;
    return fact()&0X00FF;
    break;

    case '%':            /* octal constant*/	// (WW) Changed from '&' to '%'
    char_ptr++;
    eat_space;
    get_sym(oper,128);
    return strtol(oper,NULL,8);
    break;

    case '$':            /* hex constant */
    char_ptr++;
    eat_space;
    get_sym(oper,128);
    return strtol(oper,NULL,16);
    break;

    case '-':
    char_ptr++;
    eat_space();
    get_sym(oper,128);
    return -( strtol(oper,NULL,10));
    break;

    case '(':
    paren++;
    char_ptr++;     /* space over operator */
    eat_space();
    return get_operand();
    break;

    case 0:
    return 0;
    break;

    default:
    if (VERBOSE) fprintf(errdev,"At fact with default operand = %c\n",in_line[char_ptr]);
    if (isdigit(in_line[char_ptr])) {
	get_sym(oper,SYMBOL_MAX);
	return strtol(oper,NULL,10);
	}
    if (isalpha(in_line[char_ptr])) {
	get_sym(oper,SYMBOL_MAX);
	if ((sym=find_symbol(oper))!=NULL) {
	    if (VERBOSE) fprintf (errdev,"Found symbol %s.\n",oper);
	    if (pass==2) {
		if (sym->type==0) {
		    printf("ERROR: Undefined label in %lu\n",line_count);
		    fprintf(errdev,"ERROR: Undefined label in %lu\n",line_count);
		    p_error();
		    err_flag++;
		    }
		}
	    return sym->address;
	    }
	else {
	    if (VERBOSE) fprintf (errdev,"Did not find symbol %s\n",oper);
	    if (pass==0) {
		sym=enter_symbol(oper,0);
		}
	    if (pass==2) {
		if (sym->type==0) {
		    printf("ERROR: Undefined label in %lu\n",line_count);
		    fprintf(errdev,"ERROR: Undefined label in %lu\n",line_count);
		    p_error();
		    err_flag++;
		    }
		}
	    return sym->address;
	    }
	}
    printf ("WARNING: Unrecongnized operand in line %lu\n",line_count);
    fprintf (errdev,"WARNING: Unrecongnized operand in line %lu\n",line_count);
    p_error();
    break;
    }
}

void def_label(char *label , int type)
{
struct symbol *label_ptr;

get_label(label);	/* Get label from input stream */
if (VERBOSE) fprintf (errdev,"Label is %s\n",label);
switch (pass) {
    case 0:
    if ((label_ptr=find_symbol(label))==NULL) {
        if (VERBOSE) fprintf (errdev,"Did not find symbol\n");
	label_ptr=enter_symbol(label,type);
	}
    else {
	if (label_ptr->type) {
	    printf ("ERROR: Symbol %s is multiply defined\n",label);
	    fprintf (errdev,"ERROR: Symbol %s is multiply defined\n",label);
	    p_error();
	    err_flag++;
	    }
	else {
	    if (VERBOSE) {
		fprintf(errdev,"Changing %s from ",label_ptr->name);
		fprintf(errdev,"%04X to ",label_ptr->address);
	 	}
	    label_ptr->address=prog_count;
	    if (VERBOSE) {
		fprintf(errdev,"%04X in %lu\n",label_ptr->address,line_count);
		}
	    label_ptr->type=1;
	    }
	}
    break;

    case 1:
    break;

    case 2:
    if ((label_ptr=find_symbol(label))==NULL) {
	printf("ERROR: Undefined label in %lu\n",line_count);
        fprintf (errdev,"ERROR: Undefined label in %lu\n",line_count);
	label_ptr=enter_symbol(label,type);
	}
    else {
	if (prog_count != label_ptr->address) {
	    printf("Phase error in %lu\n",line_count);
	    fprintf(errdev,"Phase error in %lu\n",line_count);
	    p_error();
	    err_flag++;
	    }
	}
    break;
    }
}


get_label(char *label)
{
int     i;

i=get_sym(label,SYMBOL_MAX);
if (label[i]==':') label[i]='\0';  // (WW) Changed NULL to '\0'
}    

type(char c)
{
if (isspace(c)) return 0;	/* test for white space */
if (isalpha(c)) return 1;	/* test for alphabetic char */
if (isdigit(c)) return 2;	/* test for number */
if (c==';')     return 3;	/* semis are comments */
if (c=='!')     return 4;	/* exclamations are comments */
if (c=='.')	return 5;	/* dot is PC or directive    */
if (c=='#')     return 6;	/* # is directive always     */
if (c=='$')	return 7;	/* $ denotes a hex constant */
if (c=='&')	return 8;	/* & denotes an octal constant */
if (c=='<')	return 9;	/* < denotes least significant byte */
if (c=='>')	return 10;	/* > denotes most sig byte */
return 100;                  /* undetected types are illegal */
}

struct symbol * find_symbol(char *sym)
{
struct symbol *next_sym,    /* Temporary pointer to next symbol */
              *prev_sym,    /* Temporary pointer to previous symbol */
              *cref_sym;    /* Always NULL for now */

                            /* Initialize pointers */
next_sym=sym_root;          /* Point to root at beginning od search */
prev_sym=NULL;              /* No previous pointer at root */
cref_sym=NULL;              /* No CREF pointer for now     */

if (next_sym==NULL) return NULL;
while(strcmp(next_sym->name,sym)!=0) {
    next_sym=next_sym->next;
    if (next_sym==NULL) return NULL;
    }
if (VERBOSE) fprintf (errdev,"Found LABEL %s\n",sym);
if (VERBOSE) fprintf (errdev,"Name is %s\n",next_sym->name);
if (VERBOSE) fprintf (errdev,"Address is $%04X\n",next_sym->address);
if (VERBOSE) fprintf (errdev,"Type is %d\n",next_sym->type);
return next_sym;
}

struct symbol * enter_symbol(char *sym , int type)
{
struct symbol *next_sym,    /* Temporary pointer to next symbol */
              *prev_sym,    /* Temporary pointer to previous symbol */
              *cref_sym;    /* Always NULL for now */

                            /* Initialize pointers */
next_sym=sym_root;          /* Point to root at beginning od search */
prev_sym=NULL;              /* No previous pointer at root */
cref_sym=NULL;              /* No CREF pointer for now     */

while(next_sym!=NULL) {
    prev_sym=next_sym;
    next_sym=next_sym->next;
    }
next_sym=malloc(sizeof(struct symbol));
if (next_sym==NULL) {
    printf ("Error opening symbol table\n");
    fprintf (errdev,"Error opening symbol table\n");
    p_error();
    end (1);
    }
else {
    if (sym_root==NULL) sym_root=next_sym;
    else prev_sym->next=next_sym;
    next_sym->prev=prev_sym;
    next_sym->next=NULL;
    next_sym->cref=NULL;
    strcpy(next_sym->name,sym);
    if (type) next_sym->address=prog_count;
    else next_sym->address=0XFFFF;
    next_sym->type=type;
    }
return next_sym;
}

void print_sym(FILE *dev)
{
struct symbol *next_sym;    /* Temporary pointer to next symbol */
int	i,j;
                            /* Initialize pointers */
next_sym=sym_root;          /* Point to root at beginning of search */
i=0;
fprintf (dev,"\f");
while(next_sym!=NULL) {
    i++;
    fprintf (dev,"%d\t%s",i,next_sym->name);
    for (j=0;j<(15-strlen(next_sym->name));j++)fprintf(dev," ");
    fprintf (dev,"$%04X\n",next_sym->address);
    next_sym=next_sym->next;
    }
}

void head_out()
{
struct symbol *next_sym;    /* Temporary pointer to next symbol */
int	i,j;
FILE	*header;		/* output device for header info */
char	file_name[FILE_MAX];

next_sym=sym_root;          /* Point to root at beginning of search */
printf("\n\nEnter the header file name ");
fgets(file_name, FILE_MAX, stdin);		// (WW) Use "fgets" instead of "gets"
file_name[strlen(in_line)-1] = '\0';		// 	Remove EOL input by "fgets".
if ((header=fopen(file_name,"w"))==NULL) {
    printf("Could not open header file %s\n",file_name);
    }
else {
    printf("File %s open\n",file_name);
    fprintf(header,"; Machine generated header file\n");
    fprintf(header,"; File name is %s\n;\n\n",file_name);
    while(next_sym!=NULL) {
	fprintf (header,"\t.DEF\t%s=",next_sym->name);
	fprintf (header,"$%04X\n",next_sym->address);
	next_sym=next_sym->next;
	}
    }
fclose(header);
}

get_op(char *opcode)
{
int     i;

if (get_sym(opcode,OPCODE_MAX)) {
    return 1;
    }
else {
    printf ("ERROR: Illegal op-code\n");
    fprintf (errdev,"ERROR: Illegal op-code\n");
    p_error();
    err_flag++;
    return 0;
    }
}

get_sym(char *symbol,int len)
{
int     i;

for (i=0;i<len;i++) {
    symbol[i]=in_line[char_ptr];
    if (isspace(symbol[i]) || isdelim(symbol[i])) {
        symbol[i]='\0';		// (WW) Replaced NULL with '\0'
        return i-1;
        }
    char_ptr++;
    }
symbol[i]='\0';    /* add string termination */	// (WW) Replaced NULL with '\0'
eat_to_delim();
printf ("WARNING: Symbol too long line %lu. ",line_count);
printf ("Ignoring extra characters\n");
fprintf (errdev,"WARNING: Symbol too long line %lu. ",line_count);
fprintf (errdev,"Ignoring extra characters\n");
p_error();
warn_flag++;
return 0;
}    

struct opcode *find_op(char *op)
{
struct opcode *this_op;     /* Temporary pointer to next symbol */

this_op=op_codes;           /* Point to root at beginning od search */
while(strcmp(this_op->name,op)!=0) {
    this_op=this_op->next;
    if (this_op==NULL) return 0;
    }
if (VERBOSE) fprintf (errdev,"Found OPCODE %s\n",op);
if (VERBOSE) fprintf (errdev,"Name is %s\n",this_op->name);
if (VERBOSE) fprintf (errdev,"class is %d\n",this_op->class);
if (VERBOSE) fprintf (errdev,"Code 1 = %X\n",this_op->code1);
if (VERBOSE) fprintf (errdev,"Code 2 = %X\n",this_op->code2);
return this_op;
}

init_op()
{
struct opcode 	*this_op,   /* Pointer to current entry */
		*last_op,   /* Temporary pointer to the last opcode */
                *first_op;  /* store root of opcode table       */

FILE          *op_dev;      /* file pointer to op codes data    */

char          opcode[OPCODE_MAX];
int           class;
int           code1;
int           code2;

this_op=last_op=first_op=NULL;

// (WW) Changed code to look for opcode table in the same folder the
//	executable was found in.  Allows us to run the program while
//	positioned in a different folder.

char opcode_file[FILE_MAX];

strcpy(opcode_file, rel_startup_path);
strcat(opcode_file, "opcodes.dat");

if ((op_dev=fopen(opcode_file,"r"))==NULL) {
    printf ("Error: Failure to open opcode table.\n");
    fprintf (errdev,"Error: Failure to open opcode table.\n");
    p_error();
    end (1);
    }
else {
    while(fscanf (op_dev,"%6s %1d %02X %02X",opcode,&class,&code1,&code2)!=EOF)
        {
	if ((this_op=malloc(sizeof(struct opcode))) == NULL) 
            {
            printf ("Error: Failure creating op code table.\n");
            fprintf (errdev,"Error: Failure creating op code table.\n");
	    p_error();
            fclose(op_dev);
            this_op=first_op;
            while (this_op != NULL) {
                last_op=this_op;
                this_op=this_op->next;
                free(last_op);
                }
            end (1);
            }
        if (first_op==NULL) {
            first_op=this_op;
            }
        else {
            last_op->next=this_op;
	    }
        this_op->next=NULL;
        strcpy(this_op->name,opcode);
        this_op->class=class;
        this_op->code1=code1;
        this_op->code2=code2;
        last_op=this_op;
        }
    }
return first_op;
}

void print_ops()
{
struct opcode  *next_op;
int            i;

next_op=op_codes;
i=0;
while (next_op!=NULL) {
    if (i % 20 == 0)printf ("op code   class   code 1  code 2\n"); 
    printf ("%6s    ",next_op->name);
    printf ("%02d      ",next_op->class);
    printf ("%02X      ",next_op->code1);
    printf ("%02X\n",next_op->code2);
    next_op=next_op->next;
    if (++i % 20 == 0) getchar();	// (WW) Changed "getch()" to "getchar()"
    }
}

void file_init()
{
char		in_line[LINE_MAX];

printf ("Enter source file name ");
fgets(in_line, LINE_MAX, stdin);	// (WW) Use "fgets" instead of "gets"
in_line[strlen(in_line)-1] = '\0';	// 	Remove EOL input by "fgets".
files(in_line);
}

files(char in_line[LINE_MAX])
{
char		file_name[LINE_MAX];
int		i,j;

for (i=0;(((source[i]=file_name[i]=in_line[i])!='.') && (in_line[i]!=0)); i++);
if (i>8) {
	printf ("i = %d",i);
	printf ("  %s\n",source);
	printf ("WARNING Source file name is too long \n");
	fprintf (errdev,"WARNING Source file name is too long \n");
	end (0);
	}
else {
	if (file_name[i]=='.') file_name[i]='\0';  // (WW) Changed NULL to '\0'
	if (source[i]=='.') {
		for (j=1 ; (j<4) && ((source[i+j]=in_line[i+j])!=0) ; j++);
		source[i+j]=0;
		}
	else {
		source[i++]='.';
		source[i++]='p';	// (WW) Changed 'P' to 'p'
		source[i++]='6';
		source[i++]='5';
		source[i]=0;		/* terminate string */
		}
	}
strcpy(binary,file_name);
strcat(binary,".bin");
strcpy(error,file_name);
strcat(error,".err");
strcpy(list,file_name);
strcat(list,".lst");
printf ("Source file is %s\n",source);
printf ("Binary file is %s\n",binary);
printf ("Error file is %s\n",error);
printf ("Listing file is %s\n",list);
if (MOT) {
    strcpy(mot_out,file_name);
    strcat(mot_out,".mot");
    printf ("S format file is %s\n",mot_out);
    }
if ((orgdev=fopen(source,"r"))==NULL) {
	printf ("Could not open source file.\n");
	end (1);
	}
srcdev=orgdev;
if ((bindev=fopen(binary,"w"))==NULL) {
	printf ("Could not open binary file.\n");
	fclose(srcdev);
	end (1);
	}
if ((errdev=fopen(error,"w"))==NULL) {
	printf ("Could not open error file.\n");
	fclose (srcdev);
	fclose (bindev);
	end (1);
	}
if ((lstdev=fopen(list,"w"))==NULL) {
	printf ("Could not open listing device.\n");
	fclose (srcdev);
	fclose (bindev);
	fclose (errdev);
	end (1);
	}
}

void file_close()
{
fclose(srcdev);
fclose(bindev);
fclose(errdev);
fclose(lstdev);
}

void eat_space()
{
while(isspace(in_line[char_ptr])) char_ptr++;    /* eat spaces */
}

void eat_to_space()
{
while (!isspace(in_line[char_ptr])) char_ptr++;  /* eat to spaces */
}

void eat_to_delim()
{
while (!isdelim(in_line[char_ptr])) char_ptr++;  /* eat to delimiter */
}

isdelim(char c)
{
if (isspace(c)) return 1;
/* if (ispunct(c)) return 1; */
switch (c) {
    case ',':
    case '=':
    case '+':
    case '-':
    return 1;
    break;

    default:
    return 0;
    break;
    }
}

void p_error()
{
int	i;

printf ("%s\n",in_line);
fprintf (errdev,"%s\n",in_line);
for (i=0;i<char_ptr;i++) {
    printf("%c",in_line[i]);
    fprintf(errdev,"%c",in_line[i]);
    }
printf("^\n");
fprintf(errdev,"^\n");
}

load_out(long int addr)
/* output load address */
{
if (BIN) fprintf(bindev,"*%04X",addr);
}


void addr_out(unsigned int addr)
/* output a two byte address */
{
if (BIN) {
    fprintf(bindev,"%04X",(addr & 0XFFFF));
    }
}

void word_out(unsigned int word)
{
if (BIN) {
    fprintf(bindev,"%02X%02X",(word & 0XFF),((word>>8) & 0XFF));
    }  
if (LIST) {
    fprintf(lstdev,"%02X%02X ",(word & 0XFF),((word>>8) & 0XFF));
    lst_pos+=5;
    }
}

void byte_out(unsigned int byte)
{
if (BIN) {
    fprintf(bindev,"%02X",(byte & 0XFF));
    }
if (LIST) {
    fprintf(lstdev,"%02X ",(byte & 0XFF));
    lst_pos+=3;
    }
}

void pc_out()
{
if (LIST) {
    fprintf(lstdev,"%04X ",prog_count);
    lst_pos=5;
    }
}

void line_out()
{
int	i;

if (LIST) {
    for (i=lst_pos;i<14;i++) fprintf(lstdev," ");
    fprintf(lstdev,"	%s",in_line);
    }
}

void end(int flag)
{
if ((pass==2) && (!err_flag)) {
    if (CREF) print_sym(lstdev);
    if (HEADER) head_out();
    }
printf ("%d errors & %d warnings detected\n",err_flag,warn_flag);
file_close();
exit (flag);
}

s_format()
{
int	chr;
char	addr_str[33];
int	i;

bytes=0;
load_addr=0;
while ((chr=fgetc(srcdev)) != EOF) {
    if (chr=='*') {		/* update address pointer */
	if (bytes>0) print_line();
        for (i=0;i<4;i++) {
	    if ((chr=fgetc(srcdev)) != EOF) {
		addr_str[i]=chr;
		addr_str[i+1]='\0';	// (WW) Changed NULL to '\0'
		}
	    else {
		printf ("unexpected end of file found\n");
		exit(1);
	   	}
	    }
	load_addr=strtol(addr_str,NULL,16);
	}
    else {
	out_str[bytes]=chr;
	bytes++;
	if (bytes>63) print_line();
	}
    }
print_line();
fprintf(bindev,"S9030000FC\n");
}

print_line()
{
int 	byts,i;
char	str[4];

out_str[bytes]='\0';	// (WW) Changed NULL to '\0'
byts=bytes/2+3;
check_sum=byts;
check_sum+=((load_addr&0XFF)+((load_addr&0XFF00)>>8));
for (i=0;i<bytes;i+=2) {
    str[0]=out_str[i];
    str[1]=out_str[i+1];
    str[2]='\0';		// (WW) Changed NULL to '\0'
    check_sum+=strtol(str,NULL,16);
    }
check_sum=~check_sum;
fprintf(bindev,"S1%02X%04X",byts,load_addr);
fprintf(bindev,"%s",out_str);
fprintf(bindev,"%02X\n",check_sum);
load_addr+=bytes/2;
bytes=0;
}

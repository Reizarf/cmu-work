#include <stdio.h>
//info regi reip rax rbp rdi
//disas - see asm code
//-S look at asm code generation
//-g (adds debugger info for gdb)
//stepi - step once in asm code
//step - step once in c code


//rax and eax are same register
//ax is lower 16 bits
//al is the lower 8 bits
//ah is the upper 8 bits
//

struct Thing {
    long g;
    long h;

};

void fun(Thing *ta, long *ya) {
    asm("   incq 0(%RDI)");   //really the xa address is in the RDI
    asm("   decq 8(%RSI)");              //incq is for 64 bit
    asm("   incq (%RSI)");          //h is decremented
    //asm("   incq (%RSI");
}

int main(){
    long x,y;
    Thing t;
    t.g=20;
    t.h=30;

    x=10;
    y=20;
    fun(x,y);
    printf("%ld\n",sizeof(long));
    printf("%ld and %d",x,y);

    return 0;
}
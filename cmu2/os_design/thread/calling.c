#include <stdio.h>

struct Thing {
	long g;
	long h;
};

void fun(Thing *ta,long *ya) {
	/* increment xa, decrement ya */
	asm("	incq 0(%rdi)");  /* Really the xa address is in the RDI */
							/* increment g */
	asm(" 	decq 8(%rdi)"); // h is dec						
	asm("   incq (%rsi)");
}

int main() {
	long x,y;
	Thing t;
	t.g=10;
	t.h=20;
	x=10;
	y=30;
	printf("%ld\n",sizeof(long));
	fun(&t,&y);
	printf("%ld,%ld and %ld",t.g,t.h,y); 
	return 0;
}

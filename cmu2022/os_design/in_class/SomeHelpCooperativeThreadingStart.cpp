#include <iostream>
#include <unistd.h>

using namespace std;

typedef void ThreadFun(int threadNum);

struct ThreadState{ // Intel Hardware
	uint64_t  rax,rbx,rcx,rdx,rdi;
};

/*
class ThreadState{ // Intel Hardware
	public:
	virtual void doSomething()=0;  // =NULL;
	uint64_t  rax,rbx,rcx,rdx,rdi;
}; */

ThreadState threads[3];

void saveState(ThreadState *t) {
	asm("save: ");
	asm("mov %rax,0(%rdi)");
	asm("mov %rbx,8(%rdi)");
	asm("mov %rcx,16(%rdi)");
	asm("mov %rdx,24(%rdi)");
	asm("mov %rdi,32(%rdi)");
}

void restoreState(ThreadState *t) {
	asm("restore: ");
	asm("mov 0(%rdi),%rax");
	asm("mov 8(%rdi),%rbx");
	asm("mov 16(%rdi),%rcx");
	asm("mov 24(%rdi),%rdx");
	asm("mov 32(%rdi),%rdi");
}

void startThread(ThreadFun *f) {
	//ThreadState t;
	int randomThread=rand()%3;//implemented random here

	saveState(&(threads[0]));
	//restoreState(&t);
	cout << hex <<threads[0].rdi << endl; 
	saveState(&(threads[1]));
	//restoreState(&t);
	cout << hex <<threads[1].rdi << endl; 
	saveState(&(threads[2]));
	//restoreState(&t);
	cout << hex <<threads[2].rdi << endl; 
}

void yield(int threadNum) {
	// Implement random
}

/* Change nothing below this line.  Get the program to execute the code
 * of main, main1, and main2
 * It does not matter the order that the code for main, main1, and 
 * main2 gets executed, but it should execute a piece of the code
 * and then use sharecpu to gives other threads a chance to execute.
 */

void main1(int threadNum) {
  for (int i=0;i<10;i++) {
      cout << "Main 1 says Hello" << endl;
      usleep(1000);
      yield(threadNum);
  }
}

void main2(int thread) {
  for (int i=0;i<10;i++) {
    cout << "Main 2 says Hello" << endl;
    usleep(1000);
    yield(thread);
  }
}

int main() { 
  startThread(main1);
  cout << "Back to Main" << endl;
  startThread(main2);
/*  while (true) {
        cout << "Main says hello" << endl;
        usleep(100);
        yield(0);
  }*/
  return 0;
}

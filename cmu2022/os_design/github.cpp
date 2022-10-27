#include <iostream>
#include <unistd.h>
// #include <ios_base.h>

using namespace std;

typedef void ThreadFun(int threadNum);
const int maxThreads = 3;
struct ThreadState {
  uint64_t rax,rbx,rcx,rdx,rdi,rsi,rbp,r8;
  //8 bytes off of each other
  //rdx linux, rcx windows(?)
  //try compiling with -S flag
};
ThreadState threads[maxThreads];

void saveState(ThreadState *t){
  asm("save: ");
  asm("mov %rax,0(%rdi)");
  asm("mov %rbx,8(%rdi)");
  asm("mov %rcx,16(%rdi)");
  asm("mov %rdx,24(%rdi)");
  asm("mov %rdi,32(%rdi)");
}
void restoreState(ThreadState *t){
  asm("restore: ");

  // restore:
  asm("mov 0(%rdi),%rax");
  asm("mov 8(%rdi),%rbx");
  asm("mov 16(%rdi),%rcx");
  asm("mov 24(%rdi),%rdx");
  asm("mov 32(%rdi),%rdi");
}


//in class 
int current=0;

void setStackandRun(unsigned long * stack, ThreadFun *fun){
  asm("mov %rsp,%rdi");
  fun(*stack);
}
unsigned long * stacks[3];
//in class^
void startThread(ThreadFun &f) {
  //ThreadState t;
  // startThread(t);
  // saveState(t);
  // restoreState(t);
  const int maxStack = 64000;
  stacks[current+1]=(unsigned long *)malloc(sizeof(unsigned long)* maxStack) + (sizeof(unsigned long) * maxStack);//allocate stack
  current++;
  
  setStackandRun((stacks[current+1]),f);
  f(current);
  saveState(&(threads[0]));
  cout << hex << ((long) &f) << ' ' << f<< endl;
  saveState(&(threads[1]));
}
void yield(int threadNum) {
	// Implement random
  int randomThread=rand()%3;//I used the random numbers
	ThreadState t;
	saveState(&(threads[randomThread]));
	restoreState(&t);
	cout << hex <<"threads[randomThread].rdi: "<<threads[randomThread].rdi << endl; //double check if it's rdi vs r something else
	saveState(&(threads[randomThread]));
	restoreState(&t);
	//cout << hex <<"threads[randomThread].rax: "<<threads[randomThread].rax << endl; 
	saveState(&(threads[randomThread]));
	restoreState(&t);
	cout << hex <<"threads[randomThread].rbx: "<<threads[randomThread].rbx << endl;
    int randThread=rand()%3;
    randThread = threadNum;
	//ThreadState t;
	saveState(&(threads[threadNum]));
	//restoreState(&t);
	cout << hex <<threads[0].rdi << endl; //double check if it's rdi vs r something else
	saveState(&(threads[1]));
	//restoreState(&t);
	cout << hex <<threads[1].rax << endl; 
	saveState(&(threads[2]));
	//restoreState(&t);
	cout << hex <<threads[2].rbx << endl;

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
      cout << "i: " << i <<endl;
  }
}

void main2(int thread) {
  for (int i=0;i<10;i++) {
    cout << "Main 2 says Hello" << endl;
    usleep(1000);
    yield(thread);
    cout << "i: " << i <<endl;
  }
}

int main() { 
  startThread(main1);
  cout << "\n\nBack to Main\n\n" << endl;
  startThread(main2);
  for(int i = 0; i < 5; i++) {//this was a while true loop
        cout << "Main 0 says hello" << endl;
        usleep(100);
        yield(0);
  }
  return 0;
}
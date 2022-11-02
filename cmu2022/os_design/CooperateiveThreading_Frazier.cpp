#include <iostream>
#include <unistd.h>

using namespace std;

class reg { //typedef reg {
  int rax, rbx, rcx, rdx, rsi, rsp, rdi, rbp, r8;
};

reg r[3];
int numThreads=3;
int currentThread=3;

typedef void ThreadFun(int threadNum);

void save(reg *ptr) {
    asm("mov %rax, (%rdi)\n"
        "mov %rbx, 8(%rdi)\n"
        "mov %rcx, 16(%rdi)\n"
        "mov %rdx, 24(%rdi)\n"
        "mov %rsi, 32(%rdi)\n"
        "mov %rbp, 40(%rdi)\n"
        "mov %r8, 48(%rdi)");
}

void load(reg *ptr) {
    asm("mov 48(%rdi), %r8 \n"
        "mov 40(%rdi), %rbp \n"
        "mov 32(%rdi), %rsi \n"
        "mov 24(%rdi), %rdx \n"
        "mov 16(%rdi), %rcx \n"
        "mov 8(%rdi), %rbx \n"
        "mov (%rdi), %rax");
}

void setStackAndRun(char *stack, ThreadFun *f){
  asm("mov %rdi, %rsp");
  f(currentThread);
}

void startThread(ThreadFun *f) {
  numThreads++;
  char *stack = (char *)malloc(sizeof(char) * 64000) + 64000;
  save(&(r[currentThread]));
  currentThread = numThreads - 1;
  load(&(r[currentThread]));
  // set rsp stack
  //asm("mov %rsp, %rdi");
  setStackAndRun(stack, f);
  //f(currentThread);
}

void sharecpu(int threadNum) {
    save(&(r[threadNum]));
    // threadNum update to random between 0 and number -1
    threadNum = rand() % numThreads;
    // set currentThread
    currentThread = threadNum;
    cout <<endl<<"ThreadNum: "<<threadNum<<endl;
    load(&(r[threadNum]));
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
      sharecpu(threadNum);
  }
}

void main2(int thread) {
  for (int i=0;i<10;i++) {
    cout << "Main 2 says Hello" << endl;
    usleep(1000);
    sharecpu(thread);
  }
}

int main() { 
  startThread(main1);
  cout << "Back to Main" << endl;
  startThread(main2);
  for(int i = 0; i < 5; i++){
        cout << "Main says hello" << endl;
        usleep(100);
        sharecpu(0);
  }
  return 0;
}
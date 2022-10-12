#include <iomanip>
#include <iostream>
using namespace std;

// struct ThreadState{
//     uint64_t rax,rbx,rcx,rdx,rdi;
// };


//look at code in chapter 13

typedef void ThreadFun(int threadNum);

struct ThreadState{
  uint64_t rax,rbx,rcx,rdx,rdi;
  //8 bytes off of each other
  //rdx linux, rcx windows(?)
  //try compiling with -S flag
  
};
void saveState(ThreadState *t){
  save:
  asm("mov %rax,0(%rdi)");
  asm("mov %rbx,8(%rdi)");
  asm("mov %rcx,16(%rdi)");
  asm("mov %rdx,24(%rdi)");
  asm("mov %rdi,32(%rdi)");
}
void restoreState(ThreadState *t){
  restore:
  asm("mov 0(%rdi),%rax");
  asm("mov 8(%rdi),%rbx");
  asm("mov 16(%rdi),%rcx");
  asm("mov 24(%rdi),%rdx");
  asm("mov 32(%rdi),%rdi");
}

void startingThread(ThreadState *t){
  ThreadState t;
  startingThread(&t);
  saveState(&t);
  restoreState(&t);
  cout << hex << ((long) &t) << ' ' << t.rdi << endl;
}

int main(){
    ThreadState t;
    startingThread(&t);
}
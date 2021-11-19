//
//
//  InfixPostfix
//
//   Created by Antoun, Sherine on 11/11/21.
//  2021 Antoun, Sherine
//
//  Header file: stackADT.h

#ifndef H_StackADT 
#define H_StackADT
  
template <class Type>
class stackADT 
{
public:
    virtual void initializeStack() = 0;
       stack<char> testStack = NULL;
       
       //Method to initialize the stack to an empty state.
       //Postcondition: Stack is empty

    virtual bool isEmptyStack() const = 0;
      while (!testStack.empty())
      {
        return true;
      }
      else 
        return false;
      
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.

    virtual bool isFullStack() const = 0;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.

    virtual void push(const Type& newItem) = 0;
      if(isEmptyStack() == false)//and !full
      {
        return;
      }
      else
      {
        testStack.pop(newItem);
      }
      
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem 
      //               is added to the top of the stack.

    virtual Type top() const = 0;
      while(!testStack.empty())//and !full
      {
        testStack.top();
      }
      else
      {
        cout << "There's nothing on the top"<<endl;
        return 0;
      }
      
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //               terminates; otherwise, the top element
      //               of the stack is returned.

    virtual void pop() = 0;
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top 
      //               element is removed from the stack.
};
        
#endif

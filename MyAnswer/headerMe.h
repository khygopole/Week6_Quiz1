//Header file: myStack.h

#ifndef H_StackType 
#define H_StackType 
 
#include <iostream>
#include <cassert>

#include "headerYou.h"

using namespace std;
  
template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&); 
      //Overload the assignment operator.

    void p1();
    bool p2() const;
    bool p3() const;
    void p4(const Type& newItem); 
    Type p5() const;
    void p6();
    stackType(int stackSize = 100); 
    stackType(const stackType<Type>& otherStack); 
      //copy constructor

    ~stackType(); 
      //destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack 
      //               elements is deleted.
      
      bool operator==(const stackType<Type>& otherStack) const;

private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    Type *list;       //pointer to the array that holds the
                      //stack elements

    void copyStack(const stackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
};


template <class Type>
void stackType<Type>::p1()
{
    stackTop = 0;
}


template <class Type>
bool stackType<Type>::p2() const
{
    return(stackTop == 0);
}

template <class Type>
bool stackType<Type>::p3() const
{
    return(stackTop == maxStackSize);
} 

template <class Type>
void stackType<Type>::p4(const Type& newItem)
{
    if (!p3())
    {
        list[stackTop] = newItem;   
        stackTop++; 
    }
    else
        cout << "Cannot add to a full stack." << endl;
}

template <class Type>
Type stackType<Type>::p5() const
{
    assert(stackTop != 0);          
    return list[stackTop - 1];      
}

template <class Type>
void stackType<Type>::p6()
{
    if (!p2())
        stackTop--;                 
    else
        cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
stackType<Type>::stackType(int stackSize) 
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to 
                                    //the value specified by
                                    //the parameter stackSize

    stackTop = 0;                   //set stackTop to 0
    list = new Type[maxStackSize];  //create the array to
                                    //hold the stack elements
}//end constructor

template <class Type>
stackType<Type>::~stackType() //destructor
{
    delete [] list; //deallocate the memory occupied 
                    //by the array
}//end destructor

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{ 
    delete [] list;				   
    maxStackSize = otherStack.maxStackSize;		   
    stackTop = otherStack.stackTop;			   
	  
    list = new Type[maxStackSize];		   			   

        //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)  
        list[j] = otherStack.list[j];
} //end copyStack


template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}//end copy constructor

template <class Type>
const stackType<Type>& stackType<Type>::operator=
   					(const stackType<Type>& otherStack)
{ 
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this; 
} //end operator=         

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"



/******
 * In this file, provide all of the definitions of the stack functions as described in stack.h.
 *
 * ****/


/*****FUNCTION PROTOTYPES**********/

//Malloc a new StackImp, malloc an array of Elements of size maximumStackSize (store the address in stackElements pointer), set maxSize to be maximumStackSize, initialize iCount to be 0, and return a pointer to the StackImp.
Stack newStack(int maximumStackSize){

    //Creating array of an struct
    StackImp *X_stack=  malloc( sizeof(StackImp));
    X_stack->maxSize = MAX_SIZE; 
    // set counter to 0.
    X_stack->count= 0;
    X_stack->stackElements = (Element *) malloc(X_stack->maxSize *sizeof(Element));
    // return the pointer to the stack
    return X_stack;
}


//Free stackElements and then free the Stack s.



//Push a new Element e onto the Stack s.  Print an error message if the stack was already full.
void push(Stack s, Element e){

    // if count is greather or equal stack is full
    if(s->maxSize <= s->count){
        s->maxSize *=2;
        s->stackElements = realloc(s->stackElements,s->maxSize * sizeof(Element));
    }
        //storing
        s->stackElements[s->count] = e;
        //increment the count of the stack
        s->count++;
    
}


//Pop an element off the stack and return the element's value.
Element pop(Stack s){

     if( isEmptyStack(s) == TRUE){
        
        printf("Stack is empty. Pop fail..\n");
    }else{
        
        //decrementing stack counter
        s->count--;
        //poping element store on the stack 
       return s->stackElements[s->count];   
    }
  
}


//Return true (1) if stack is empty and false (0) otherwise.
int isEmptyStack(Stack s){

     if (s->count==0){
        return TRUE;// T=1
    }
    else{
     return FALSE; //F=0 
    }
}


//Return the value of the top element of the stack (without removing it).
Element topElement(Stack s){

      if(! isEmptyStack(s)){
        //get element on top the stack whether is an operand or an operator
        return s->stackElements[s->count ];
      
    }else{
        
       printf(" Nothing on TOP of the stack.\n");
    }
    
}


// print the stack
void printStack(Stack s)
{
    int i;
    for (i = 0; i < s->maxSize; ++i)
    {
        printf("%d ", s->stackElements[i]);
    }
    printf("\n");
    //freeStack do not eleminate the garbare that come with print
    //freeStack(s);
}

void freeStack(Stack s){

    //free stackElement first which is pointer to a pointer
    free(s->stackElements);
    free(s);
}
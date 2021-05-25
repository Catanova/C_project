

#include "Stack_1.h"
#define MAX_SIZE 5
#define T 1
#define F 0


/******
 * In this file, provide all of the definitions of the stack functions as described in stack.h.
 *
 * ****/



//Malloc a new StackImp, malloc an array of Elements of size maximumStackSize (store the address in stackElements pointer), set maxSize to be maximumStackSize, initialize count to be 0, and return a pointer to the StackImp.
Stack newStack(int maximumStackSize){

    //Creating array of an struct
    StackImp *X_stack= (StackImp *) malloc( sizeof(StackImp));
    X_stack->maxSize =MAX_SIZE; 
    // set counter to 0.
    X_stack->count= 0;
    X_stack->stackElements = (Element *) malloc(MAX_SIZE *sizeof(Element));
    // return the pointer to the stack
    return X_stack;
}





//Push a new Element e onto the Stack s, and increment the count variable.  Print an error message if the stack was already full.
void push(Stack s, Element e){
    // if maxSize containt 100 chararcter or more the sctack is full
    if(s->maxSize <= s->count){
        printf("Stack is full.\n");
    }else{
        //storing
        s->stackElements[s->count] = e;
        //increment the count of the stack
        s->count++;
    }
}


//Pop an element off the stack, decrement the count variable, and return the element's value.
Element pop(Stack s){
    
    if(isEmpty(s)){
        
        printf("Stack is empty. Pop fail..\n");
    }else{
        
        //decrementing stack counter
        s->count--;
        //poping element store on the stack 
       return s->stackElements[s->count];   
    }
  
}


//Return true (1) if stack is empty and false (0) otherwise.
int isEmpty(Stack s){
   
    //Return -1 only if stack is empty otherwise it is false
    if (s->count==0){
        return 1;// T=1
    }
    else{
     return 0; //F=0 
    }
}


//Return the value of the top element of the stack (without removing it).
Element topElement(Stack s){
     
    if(!isEmpty(s)){
        //get element on top the stack whether is an operand or an operator
        return s->stackElements[s->count ];
      
    }else{
        
       printf(" Nothing on TOP of the stack.\n");
    }
    

}

void printStack(Stack s){
    int e;
    for(e=0; e<s->maxSize; e++){
         printf("%d ", s->stackElements[e]);
    }
    printf("\n");
}
void print_char(Stack s){
    int e;
    for(e=0; e<s->maxSize; e++){
         printf("%c ", s->stackElements[e]);
    }
    printf("\n");
}


//Free stackElements and then free the Stack s.
void freeStack(Stack s){
    //free stackElement first which is pointer to a pointer
    free(s->stackElements);
    free(s);
}
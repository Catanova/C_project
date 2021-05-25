

#include "Stack_1.h"


int main()
{
 
    int size;
    Stack s= newStack(5);
    Element el_0, el_1 ,el_2,el_3,el_4,el_5, el_6,el_7,el_8,el_9,el_10;

    el_0.operand =10;
    el_1.operand =20;
    el_2.operand =40;
    el_3.operand =60;
    el_4.operand =70;
    el_5.operand =80;

    //push onto the stack the operand only
    push(s, el_0);
    push(s, el_1);
    push(s, el_2);
    pop(s); //  pop remove 40
    push(s, el_3);
    push(s, el_4);
    push(s, el_5);

    // printStack print only integer
    printStack(s);

    //the maximum size of the stack is 5 
    Stack s1= newStack(5);
    el_6.operation = '/';
    el_7.operation = '+';
    el_8.operation = '-';
    el_9.operation = '*';
    el_10.operation = '&';
    
    // push onto the stack character and symbol only.
    push(s1,el_6);
    push(s1,el_7);
    push(s1,el_8);
    push(s1,el_9);
    push(s1,el_10);
    
    //print_char print symbol  and character
    print_char(s1);
   
   
    freeStack(s);
    freeStack(s1);
    

    return 0;
}
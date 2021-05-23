#include "Queue.h"

/******
 * In this file, provide all of the definitions of the queue functions as described in Queue.h.
 *
 * ****/

//Malloc a new QueueImp, set the head and foot pointers to NULL, and return it's address.
Queue newQueue(){
    QueueImp* my_Q = malloc(sizeof(QueueImp));
    my_Q->head = NULL;
    my_Q->foot = NULL;
    return my_Q;
}

//Free each node that remains in the Queue and then free q itself.
void freeQueue(Queue q){
    NodeLL *temp = q->head;
    while(temp!=NULL){
        NodeLL *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    q->head = NULL;
    q->foot = NULL;
}

//Allocate a new node and store "value" as the Element in the node.  Return the address of the node.
NodeLL *allocateNode(Element value){

    NodeLL* n = ( NodeLL*)malloc(sizeof(NodeLL));
    n->element=value;
    n->next=NULL;
    return n;
}

//Call allocateNode() to get a new node that contains "value" and append it to the "foot end" of the queue.  Make sure to consider "edge cases" (e.g., when the queue is currently empty).
void enqueue(Queue q, Element value){
    
    NodeLL *node = allocateNode(value);
    if(isEmpty(q)){
        q->head = node;
        q->foot = node;
    }
    else{
        q->foot->next = node;
        q->foot = q->foot->next;
    }
}

//Remove the node at the "head" end of the queue, and return the value of the element stored in this node through an element e that is passed by reference.
//Functionally return TRUE (1) if the dequeue was successful and return FALSE (0) if it was not successful (i.e., the queue was empty).
//Remember to consider any "edge cases" (e.g., when the queue becomes empty after this dequeue).


int dequeue(Queue q){
    
    if(isEmpty(q))
        return FALSE;
    NodeLL * node = q->head;
    if(q->head == q->foot){
        q->head = NULL;
        q->foot = NULL;
    }
    else{
        q->head = q->head->next;
    }
    //*e =  node->element;
    free(node);
    return TRUE;
}

//Return the value of the element stored in the first node of the queue without removing the node itself (similar to topElement() for Stacks).
//Return the value through e that is passed by reference, and return TRUE (1) if the call was successful and return FALSE (0) if it was not successful (i.e., the queue was empty).
int frontElement(Queue q, Element *e){
  if(isEmpty(q)){
        return FALSE;
    }
    *e = q->head->element;
    return TRUE;
}

//Return TRUE (1) if the queue is empty, otherwise return FALSE (0).
int isEmpty(Queue q){
   return q->head == NULL;
}



void printQ(Queue q){

    if(q->foot ==NULL){
        printf("Queue is empty.\n");
    }
    else{
        NodeLL *p = q->head;
        
        while (p!=NULL)
        {
            printf("%d %d\n", p->element.arrivalTime, p->element.patientID);
            p = p->next;
        }
        printf("\n");    
    }
}
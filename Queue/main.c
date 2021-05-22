#include <stdio.h>
#include <string.h>
#include "Queue.h"

int main(){
  
   Queue myQ = newQueue();
   Element el_1, el_2,el_3,el_4;
   el_1.arrivalTime = 3;
   el_1.patientID= 3333;

   el_2.arrivalTime = 4;
   el_2.patientID= 4444;

   el_3.arrivalTime = 5;
   el_3.patientID= 5555;

   el_4.arrivalTime = 6;
   el_4.patientID= 6666;

   //nothing is on the queue and if statement should print
   printQ(myQ);
   
   

    // putting on the queue
   enqueue(myQ,el_1);
   enqueue(myQ,el_2);
   enqueue(myQ,el_3);

   printf("Queue before deletion:\n");
   printQ(myQ);

//dequeue or delete 
// dequeue element is passed by reference  so it takes the address of element(dequeue(Queue q, Element *e))
   dequeue(myQ,&el_1);

   printf("Queue after deletion:\n");
   enqueue(myQ,el_4);

   printQ(myQ);
   

  
    return 0;
}

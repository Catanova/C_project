

#include "stdio.h"
#include "stdlib.h"  // malloc , calloac

typedef struct {

    int id;
    char *info;
}Element;

typedef struct Node{
    Element el;
    struct Node * next;

}Node;

typedef struct {
    Node *my_head;
}LinkImp;

typedef LinkImp * LinkedList;


Node *memoryAllocaion(Element el);
void insert_by_order(LinkedList ptr, Element el);
void printing(LinkedList ptr);

void front(LinkedList ptr, Element el);
void mid(LinkedList ptr, Element el);
void end(LinkedList ptr, Element el);
void insert_by_order_1(LinkedList ptr, Element el);


int main(){

    printf("Hello worl..\n");

    LinkedList l = (LinkedList)malloc(sizeof(LinkImp));
    Element  el1,el2,el3, el4, el5;

    el1.id = 29;
    el1.info = "rdf";
    el2.id =45;
    el2.info = "fxs";
    
    el3.id = 87;
    el3.info = "gza";

    el4.id =9; 
    el4.info = "olo";
    el5.id =3;
    el5.info = "hhh";

    insert_by_order(l, el4);
    insert_by_order(l, el5);

    insert_by_order(l, el1);

    insert_by_order(l, el2);

    insert_by_order(l, el3);
    printing(l);



}


Node *memoryAllocaion(Element el){

    Node *pNew = (Node*) malloc(sizeof(Node));
    if(pNew == NULL){
        printf("error while allocating memory.\n");
    }

    pNew->el= el;
    pNew->next = NULL;
    return pNew;
}

void insert_by_order(LinkedList ptr, Element el){

    // when list is empty 

    if(ptr->my_head == NULL){

        Node * pNew = memoryAllocaion(el);
        ptr->my_head = pNew;
    }
    else{
        // when there is only one node
        if(ptr->my_head->next == NULL){
            if(el.id < ptr->my_head->el.id){

                Node* pNew = memoryAllocaion(el);
                pNew->next = ptr->my_head;
                ptr->my_head = pNew;
            }
            else{
                // 
                Node *pNew = memoryAllocaion(el);
                ptr->my_head->next = pNew;
            }


        }else{
            Node *temp = ptr->my_head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            // add at the front
            if (el.id < ptr->my_head->el.id){

                Node *pNew = memoryAllocaion(el);
                pNew->next = ptr->my_head;
                ptr->my_head = pNew;
            }
            else if (el.id >= temp->el.id){

                Node* pNew = memoryAllocaion(el);
                temp->next = pNew;
            }
            else{
                if(temp->el.id < el.id && temp->next->el.id >= el.id){

                    Node *pNew = memoryAllocaion(el);
                    pNew->next = temp->next;
                    temp->next = pNew;
                }
                else{
                    temp = temp->next;
                }
            }
        }
    }


}
void printing(LinkedList ptr){

    Node* temp = ptr->my_head;
    while(temp != NULL){

        printf("%s %d\n", temp->el.info, temp->el.id);
        temp = temp->next;

    }
}


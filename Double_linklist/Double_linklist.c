
#include "stdio.h"
#include "stdlib.h" // malloc , calloc, realloc



typedef struct  Node
{
    /* data */
    int number;
    struct Node *next, *prev;
    
}Node;

typedef struct 
{
    /* data */
    Node *my_head;
}LinkImp;

typedef LinkImp* LinkList;

Node* allocate_memory(int my_number);
Node* search_node(LinkList ptr_list, int my_number);
void insertion(LinkList ptr_list, int my_number);
void printing(LinkList ptr_list);

int main(){

LinkList ptr_list = (LinkList) malloc(sizeof(LinkImp));

insertion(ptr_list, 1);
insertion(ptr_list, 35);
insertion(ptr_list, 80);
insertion(ptr_list, 7);
insertion(ptr_list, 80);
insertion(ptr_list, 3);
insertion(ptr_list, 199);

printing(ptr_list);
}


Node* allocate_memory(int my_number){

    Node* pNew = (Node*)malloc(sizeof(Node));
    if (pNew == NULL){

        printf("Error allocating memory....\n");
    }
    pNew->number = my_number;
    pNew->next = NULL;
    return pNew;
}
Node* search_node(LinkList ptr_list, int my_number){

    // start node front the head 
    Node* my_node ;
    for(my_node = ptr_list->my_head; my_node != NULL; my_node = my_node->next){

        return my_node;
    }
    return NULL;
}
void insertion(LinkList ptr_list, int my_number){

    Node* temp = ptr_list->my_head;

    if (temp == NULL){

        Node * pNew = allocate_memory(my_number);
        ptr_list->my_head = pNew;
    }
    else{

        // there is only node in our list
        // inserting in front off one node
        if (ptr_list->my_head->number >= my_number){

            Node *pNew = allocate_memory(my_number);
            
            pNew->next = ptr_list->my_head;
            pNew->next->prev = pNew;
            ptr_list->my_head = pNew; 
        }
        else{

                // inserting in the middle
            Node* p = ptr_list->my_head;
            while (p->next != NULL){
                
                if(p->number < my_number && p->next->number >= my_number){

                    Node* pNew = allocate_memory(my_number);
                    pNew->next = p->next;
                    pNew->next->prev = pNew;
                    p->next = pNew;
                    pNew->prev = p;
                }
                p = p->next;
            }
            // insert at the end 

            Node *pNew = allocate_memory(my_number);
            p->next = pNew;
            pNew->prev = p;
        }
    }
}
void printing(LinkList ptr_list){

    Node* temp = ptr_list->my_head;

    while(temp != NULL){

        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");

}



#include "stdio.h"
#include "stdlib.h"


typedef struct {

	int id;
	
	char* persona;	
} Element;


typedef struct NODE
{

	Element element;
	struct NODE* next;
	
} NODE;

typedef struct {
	
	NODE* head;
}Link_Imp;

typedef Link_Imp* Linked;


NODE* allocateNode(Element element);

void insertLLBegin(Linked list, Element element); // insert the element in the beginning of the list
void insertLLEnd(Linked list, Element element); 
void printLL(Linked list);

int main(){


 printf("hello world.\n");
 
 Linked xyz = (Linked)malloc(sizeof(Link_Imp));
    xyz->head = NULL;
    Element e1;
    Element e2;
    Element e3;
    Element e4;
    
    e1.persona = "abc";
    e1.id = 101;
    e2.persona = "bcd";
    e2.id = 102;
    e3.persona = "cde";
    e3.id = 103;
    e4.persona = "def";
    e4.id = 104;
    
    printLL(xyz);
}

void insertLLBegin(Linked list, Element element)
{
    // check if the list is empty
    if (list->head == NULL)
    {
        NODE* new = allocateNode(element);
        list->head = new;
    }
    else
    {
        NODE* new = allocateNode(element);
        new->next = list->head;
        list->head = new;
    }
}

void insertLLEnd(Linked list, Element element)
{
    // check if the list is empty
    if (list->head == NULL)
    {
        NODE* new = allocateNode(element);
        list->head = new;
    }
    else
    {
        NODE* p = list->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        NODE* new = allocateNode(element);
        p->next = new;
    }

}

void printLL(Linked list)
{
    NODE* p = list->head;
    while (p != NULL)
    {
        printf("(%s, %d) ", p->element.persona, p->element.id);
        p = p->next;
    }
    printf("\n");
}






 /************************************************************************
BinarySearchTree.h

Purpose:
Define constants used in the project.
Struct definitions for a general Binary Search Tree.
Define function prototypes used by general Binary Search Trees.
************************************************************************/
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>


//#define constant values
#define MAX_URL_LENGTH 50

#define TRUE 1
#define FALSE 0


//typedef for the Element struct which constains a c string to store a URL in the BrowserList
typedef struct
{
int accountNumber;
double accountBalance;
} Element;


//Typedef for a node in the doubly linked list (has next and previous pointers).
typedef struct NodeT
{
Element element;
struct NodeT *left;
struct NodeT *right;
} NodeT;

//Typedef for a binary search tree implementation.
//Contains a pointer to the root node of the tree.
typedef struct
{
NodeT *root;
} BinarySearchTreeImp;

typedef BinarySearchTreeImp *BinarySearchTree;


/*****Prototypes*******/

//Malloc a new BinarySearchTreeImp and return it's address.
BinarySearchTree newBinarySearchTree();


//Free the BinarySearchTree and any nodes that still exist in the tree.
void freeBinarySearchTree(BinarySearchTree tree);


//Allocate a new node and store "value" as the Element in the node. Return the address of the node.
NodeT *allocateNode(Element value);


//Given a BinarySearchTree and a searchValue, return a pointer to the node in the tree that contains searchValue if you find it or return NULL if it does not exist.  I recommend writing a secondary function to recursively search the tree.
NodeT *search(BinarySearchTree tree, int searchValue);



//Create a node to store the given Element and add it as a leaf in the BinarySearchTree.  Do not worry about balancing the tree for this project.
//Return true if the insert worked successfully, and return false if the node already existed in the tree.  I recommend writing a secondary function to recursively
//search for where to insert the node as discussed in class.
int insert(BinarySearchTree tree, Element value);


//Print the key values of all nodes in the subtree rooted at p in increasing order.  I recommend writing a secondary function to recursively traverse the nodes.
void printInOrder(BinarySearchTree tree);


//Print the key values of all nodes in the subtree rooted at p according to a preorder traversal.  I recommend writing a secondary function to recursively traverse the nodes.
void printPreOrder(BinarySearchTree tree);

//Recursivly print the key values of all nodes in the subtree rooted at p in increasing order.
//void printInOrder(NodeT *p);

//Recursivly print the key values of all nodes in the subtree rooted at p according to a preorder traversal.
//void printPreOrder(NodeT *p);

void printInOrderr(NodeT *p);
void printPreOrderr(NodeT *p);

NodeT* searching(NodeT *ptr, int searchValue);

#endif
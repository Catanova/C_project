
#include "BinarySearchTree.h"
//Malloc a new BinarySearchTreeImp and return it's address.
BinarySearchTree newBinarySearchTree(){

BinarySearchTree tree = (BinarySearchTree)malloc(sizeof(BinarySearchTreeImp));
tree->root = NULL;
return tree;
}



//Free the BinarySearchTree and any nodes that still exist in the tree.  I recommend creating another "helper" function to recursively free all the nodes in the tree using a postorder traversal as discussed in class.
void freeBinarySearchTree(BinarySearchTree tree){

    free_BST_Node(tree->root);
    free(tree);
}




//Allocate a new node and store "value" as the Element in the node. Return the address of the node.
NodeT *allocateNode(Element value){
    NodeT* n = (NodeT*)malloc(sizeof(NodeT));
    n->element = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

//Given a BinarySearchTree and a searchValue, return a pointer to the node in the tree that contains searchValue if you find it or return NULL if it does not exist.  I recommend writing a secondary function to recursively search the tree.
NodeT *search(BinarySearchTree tree, int searchValue){


    if(tree->root == NULL){
        return;
    }
    return searching(tree->root, searchValue);
}

//Create a node to store the given Element and add it as a leaf in the BinarySearchTree. Do not worry about balancing the tree for this project.
//Return true if the insert worked successfully, and return false if the node already existed in the tree.
int insert(BinarySearchTree tree, Element value){
    
   NodeT* node = allocateNode(value);
    NodeT* temp_node;
    if(tree->root == NULL){
        tree->root = node;
        return TRUE;
    }
    else{
        temp_node = tree->root;
        while(temp_node != NULL){
            
            if(temp_node->element.accountNumber == value.accountNumber)
                return FALSE;
            else if(value.accountNumber < temp_node->element.accountNumber){
                if(temp_node->left == NULL){
                    temp_node->left = node;
                    return TRUE;
                }
                else
                    temp_node = temp_node->left;
            }
            else{
                if(temp_node->right == NULL){
                    temp_node->right = node;
                    return TRUE;
                }
                else
                    temp_node = temp_node->right;
            }
        }
    }

    //
    return FALSE;
}



//Print the key values of all nodes in the subtree rooted at p in increasing order.  I recommend writing a secondary function to recursively traverse the nodes.
void printInOrder(BinarySearchTree tree){

    printInOrderr(tree->root);
}

void printPreOrder(BinarySearchTree tree){

    printPreOrderr(tree->root);
}


//Recursivly print the key values of all nodes in the subtree rooted at p according to a preorder traversal.


void printInOrderr(NodeT *p)
{
    if(p == NULL ) 
        return;
  
    printInOrderr(p->left);
    printf("%d %.2f \n", p->element.accountNumber, p->element.accountBalance);
    printInOrderr(p->right);
}

void printPreOrderr(NodeT *p)
{
    if(p == NULL ) 
        return;

    printf("%d %.2f \n", p->element.accountNumber, p->element.accountBalance);
   
    printPreOrderr(p->left);
    printPreOrderr(p->right);
}

///_______________________________///////////////////

// Teacher sugestion: 
void free_BST_Node(NodeT* n){

    if (n == NULL){
        return;
    }
    free_BST_Node(n->left);
    free_BST_Node(n->right);
    free(n);
}

NodeT *searching(NodeT *ptr, int searchValue){
    if(ptr == NULL)
        
        return ;

    else if( searchValue == ptr->element.accountNumber ){
        
        return ;
    }

    else if(searchValue < ptr->element.accountNumber){

        return searching(ptr->left, searchValue);
    }

    else if ((searchValue > ptr->element.accountNumber)){
        return searching(ptr->right, searchValue); 
    }
}
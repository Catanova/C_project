#include "BinarySearchTree.h"

#include <stdio.h>
#include <string.h>
int main()
{
  


    

  
    FILE *myfile = fopen("smallInput.txt", "r");
    if(myfile == NULL){
        printf("Error opening  file \n");
        return 1;
    }
    char str_1[100];
    char str_print[10];
    char str_preorder[10];
    char str_create[20];
    int account;
    float d;
    float e;
   
    int value;
    BinarySearchTree tree_1 = newBinarySearchTree();

    //BinarySearchTree tree_3 = newBinarySearchTree();
    char command_3[10];
    Element el_1,el_2;
    

    // fscanf take the the number of string in the line otherwise is wrong
    //  
    

    
        while(fscanf(myfile,"%s",str_create)==1){

            if(strcmp(str_create, "CREATE")==0){
                //while(fscanf(myfile,"%d", &el_1.key)==1){
                    fscanf(myfile,"%d ", &el_1.accountNumber);
                    el_1.accountBalance = 0.00;
                    if (insert(tree_1,el_1)){
                            //printf("CREATE: %d %f\n", el_1.accountNumber, el_1.accountBalance);
                    }
                
                }
                else{
                    printPreOrderr(tree_1->root);
                    break;
            } // insert next loop right
            
        }

        //printf("InOrder Traversal\n");
        printInOrderr(tree_1->root);
        //printPreOrderr(tree_1->root);

        /*
        while(fscanf(myfile," %s %d %f",str_create,&el_2, &d )==3){
            el_2.accountBalance = d;

            if (insert(tree_1,el_2)){
                printf("SALES: %d %f\n", el_2.key, el_2.accountBalance);
            }
            else{
                    helper_printPreOrder(tree_1->pRoot);
                break;
            }

        
        }*/

    

            
            /*
            else if(strcmp(str_create,"PRINT")==0){
                fscanf(myfile,"%s", str_create);
                if(strcmp(str_create,"PREORDER")==0){
                        fscanf(myfile,"%s", str_create);
                        if(strcmp(str_create,"SALE")==0){
                            fscanf(myfile, " %s %d %f",str_1,&el_2.key, &d );
                            el_2.accountBalance = d;
                            if(insert(tree_1,el_2)){
                                printf("SALE INSERTED: %d %f\n", el_2.key, el_2.accountBalance);
                            }

                        }else{
                            helper_printInOrder(tree_1->pRoot);
                            break;
                    }
                }
            }*/
            /*    
            else if(strcmp(str_create,"PRINT")==0){
                if(strcmp(str_create,"INORDER")==0){
                    
                    helper_printInOrder(tree_1->pRoot);
                }else{
                    helper_printPreOrder(tree_1->pRoot);
                }

            }
            */
    


/*
    // fscanf take "PRINT" make equal to str_print
    fscanf(myfile,"%s %s",str_print, str_preorder);
    // now we know str_print it exactly equal to print so we can compare
    if(strcmp(str_print,"PRINT")==0 && strcmp(str_preorder,"PREORDER")==0 ){
        while(fscanf(myfile, " %s %d %f",str_1,&el_2.key, &d )==3){
            el_2.accountBalance = d;
            if (insert(tree_1,el_2)){
                    printf("SALE INSERTED: %d %f\n", el_2.key, el_2.accountBalance);
            }
        }
    }
           
    
    //
    //helper_printInOrder(tree_3->pRoot);// new tree_3 is account number change
  */  
    
    return 0;
}
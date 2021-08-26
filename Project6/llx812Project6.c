#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/*******************
In this project, we will implement the HeapSort
algorithm to sort an array of 200,000 integers

Function prototypes listed below.
**********************/

//heapSort takes arrayToSort, an int pointer to an array that we need to sort,
//and n, the size of the array, and puts the elements
//of arrayToSort into non-decreasing order using a heap to repeatedly
//find the largest element that we have not yet placed into the 
//"sorted portion" of arrayToSort.
void heapSort(int *arrayToSort, int n);


//Given index i, return the index of the left child of i.
int leftChild(int i);


//Given index i, return the index of the right child of i.
int rightChild(int i);


//Given index i, return the index of the parent of i.
int parent(int i);


//Given an array of integers, makeHeap arranges the elements 
//int a valid heap configuration where each number is 
//greater than both of its children.
void makeHeap(int *heap, int n);


//heapifyUp is used to restore the heap to a valid configuration
//after inserting a new value at the end of the heap.  i
//is the index of the new value.  While it is larger than
//its parent, swap the value with the parent (or stop when
//it becomes the root and does not have a parent).
void heapifyUp(int *heap, int i);



//heapifyDown is used to restore the heap to a valid configuration
//after removing the largest value at the top of the heap.  After
//removing the maximum element at the top of the heap, we would
//have swapped a value from the bottom of the heap into the top position.
//This value may be smaller than some of its children.  If so, 
//we need to swap this value with the larger of its two children.
//Stop when it's larger than all of its children (or when it no longer
//has any children).
void heapifyDown(int *heap, int n, int i);



double my_floor_2(double num);


int main()
{
    
    //Creating an array of size 200,000 and filling it

    //with random values between 0 and 999,999.

    int n = 200000;

    int t  = 200000;

    int *arrayToSort = (int*)malloc(n*sizeof(int));

    int *My_Sort = (int*)malloc(t*sizeof(int));

    int e;

    for(e=0; e<t; e++){

        //arrayToSort[i] = rand() % 1000000;

        My_Sort[e] = rand() % 1000000;


    }


    heapSort( My_Sort,t);

    int e1;

    for(e1=0; e1<t; e1++){

        

        printf("%d \n",My_Sort[e1]);

    

    }

 

    //free(arrayToSort);

    free(My_Sort);

        

    return 0;
}






void heapSort(int *My_Sort, int t){

    

    // max heap


    makeHeap(My_Sort,t);

    int e;
    for ( e = t - 1; e > 0; e--) 

    {

        
        //swapping
        int tmp=My_Sort[0];


        My_Sort[0]=My_Sort[e];
        My_Sort[e]=tmp;

 

        //calling heapifyDown function

        heapifyDown(My_Sort, e, 0);

 

    }

    

    

}




//Given index i, return the index of the left child of i.
int leftChild(int e){
	
	
	return 2*e+1;

    return 0;
}



//Given index i, return the index of the right child of i.
int rightChild(int e){
	
	
	
    return 2*e+2;
    return 0;
}


double my_floor_2(double num)
{
    if(num < 0)
        return (int)num - 1;
    else
        return (int)num;
}


//Given index i, return the index of the parent i.
int parent(int e){
	
	
	return my_floor_2((e-1)/2);
    return 0;
}




void makeHeap(int *heap, int t){
    
    int e;
    for (e = t / 2 - 1; e >= 0; e--)
        heapifyDown(heap, t, e);
    
}





void heapifyUp(int *heap, int e){
    
     int pt=parent(e);
    if(heap[pt]>heap[e])
    {
        //swapping heap[p] with heap[i]
        int tmp=heap[pt];
        heap[pt]=heap[e];
        heap[e]=tmp;
        heapifyUp(heap,pt);
    }
    
    
    
}




void heapifyDown(int *heap, int t, int e){
    
    
     int largest_value = e; 
    int left = leftChild(e);
    int right = rightChild(e);
    if (left < t && heap[left] > heap[largest_value]){
        largest_value = left;
    }
        
    if (right < t && heap[right] > heap[largest_value]){
         largest_value = right;
    }
       
    if (largest_value!= e) {
        int tmp =heap[largest_value];
        heap[largest_value] =heap[e];
        heap[e]=tmp;
        heapifyDown(heap, t, largest_value);
    }
    
}

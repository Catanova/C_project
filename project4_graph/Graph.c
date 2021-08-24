#include "Graph.h"


/******
 * In this file, provide all of the definitions of the graph functions as described in Graph.h.
 *
 * ****/

/*****Prototypes*******/

//Given the number of vertices of the graph, allocate the nxn adjacency matrix and initialize every edge to 0 (i.e. the edges aren't there initially).
//Return the address of the graph.
Graph newGraph(int n){
    
    GraphImp* My_graph = malloc(sizeof(GraphImp));
    My_graph->n = n;
    My_graph->adjacencyM = (int**) malloc(n *sizeof(int*));
    int e,s;
    for(e = 0; e < My_graph->n; e++ ){

        My_graph->adjacencyM[e] = (int*) malloc( n * sizeof(int));
    }

    // initialize 2d array to 0.
    int row,col;
    for(row = 0; row < n; row++){
        for( col = 0; col < n; col++){
            My_graph->adjacencyM[row][col] = 0;
        }
    }
    return My_graph;
}

//Free the adjacency matrix and then the graph itself.
void freeGraph(Graph g){

    // number of vertex in row 0 1 2 3 4 5 6 7 8
    int row;
    for ( row =0; row < g->n; row++){
        free(g->adjacencyM[row]);
    }
    free(g->adjacencyM);
    free(g);
}

//Add the edge e to the graph g.
void addEdge(Graph g, Edge e){

    g->adjacencyM[e.fromVertex] [e.toVertex] = 1;
}

//Given graph g and vertex v, scan the adjacency matrix and return the first edge in g such that v is the "fromVertex" of the edge.

//Return -1 if there is no such edge.
Edge firstAdjacent(Graph g, Vertex v){
    // number of vertex  0 1 2 3 4 5 6 7 8
    
    Edge ed, ed_1;
    int e;
    for ( e =0; e < g->n; e++){
        
        if(g->adjacencyM[v][e] ==1){
                
            ed.fromVertex = v;
            ed.toVertex =e;
            return ed;
        }
    } 
    

    ed_1.fromVertex = v;
    ed_1.toVertex = -1;
    return ed_1;
    
}

//Given graph g and vertex e, scan the adjacency matrix and return the next edge after e in g such that e.fromVertex is the "fromVertex" of the edge.
//Return -1 if there is no such edge.
Edge nextAdjacent(Graph g, Edge e){

    Vertex src = e.fromVertex;
    Vertex dest = e.toVertex;

    Vertex v ;
    Edge ed, ed_1;

    //we find the edge return the edge
    
    for (v = dest +1; v < g->n; v++){
        
        //if (g->adjacencyM[src][v] == 1){
        if (g->adjacencyM[src][v]){

            ed.fromVertex = src;  
            ed.toVertex =v;
            return ed;
        }  
    }
    
    ed_1.fromVertex =src;
    ed_1.toVertex =-1;
    
    return ed_1;
    //return NULL;
   
   
}

//Print the sequence of vertices on a shortest path in g starting from start and ending at destination.  
//A shortest path should be computed using the Breadth First Search (BFS) algorithm that maintains the parents of each vertex in the shortest path tree as defined in class.  
//BFS can be implemented directly in this function, or you may create a new function for BFS.
void shortestPath(Graph g, Vertex start, Vertex destination){

    int * already_visited = (int*)malloc(g->n * sizeof(int));
    int * Parent = (int*)malloc(g->n * sizeof(int));

    int s; 
    //initializing visited
    for (s = 0; s < g->n ; s++){
        already_visited [s] =0;
    }

    int s_1; 
    //initializing parent 
    for (s_1 = 0; s_1 < g->n ; s_1++){
        Parent [s_1] =  -1;
    }

   
    Edge e;
    Vertex tempV, CurV;
    Queue myQ = newQueue();
    enqueue(myQ, start);
    already_visited[start] = 1;

    Vertex Cur;
  
    while(dequeue(myQ, &CurV)){
        for(e = firstAdjacent(g,CurV); e.toVertex !=-1; e = nextAdjacent(g,e) ){
            
            tempV = e.toVertex;
            //tempV = CurV;
            if(already_visited[tempV] == 0 ){
                
                
                enqueue(myQ,tempV );
                already_visited[tempV] = 1;
                Parent[tempV] = CurV;
              
        
            }
        }
        
    }


  

  
   
    Vertex current;
    current = destination;
        Stack myStack = newStack(g->n);
        
        // while loop break when reach startin value
        // the stack is not putting start value because to avoid two child with  same parent
            while(current != start ){
                
                push(myStack,current);
                current = Parent[current]; 
                     
            }
        
        printf("Shortest path from %d to %d: ", current, destination);  

        // pop doesn't have start value 
        //so print starting value before pop print
        printf("%d", start);
        
        //Vertices on the path will be in the stack.
        //printf("The shortest path is %d", start);
        while(isEmptyStack(myStack) == FALSE){
            
            
            printf(" -> %d",pop(myStack));
        }
        
    printf("\n");

    
    freeQueue(myQ);
    freeStack(myStack);

}


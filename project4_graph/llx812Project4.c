
#include "Graph.h"

int main()
{
	
	FILE *myfile = fopen("p4Input.txt", "r");



    if(myfile ==NULL){
        printf("Error while opening file.");
    }
    
    char str_file[100];
    int Vertex_size , Number_of_edge;
    int fromVertex, toVertex;
    char str[20];
    int path_begin , path_end; 
    int line =0 ;
    
	

    fgets(str_file, 50, myfile);
    sscanf(str_file, "%d", &Vertex_size);
    fgets(str_file, 50, myfile);
    sscanf(str_file, "%d", &Number_of_edge);

	Graph myGraph = newGraph(Vertex_size);
	Edge ed;
   
    


    while (fgets(str_file, 100 , myfile ) != NULL && line <15){

        sscanf(str_file, "%d %d", &fromVertex, &toVertex);
        
        ed.fromVertex = fromVertex;
        ed.toVertex = toVertex;
		addEdge(myGraph, ed);
        line++;
    }

    


    fgets(str_file, 100 , myfile );
    sscanf(str_file, " %s %d %d",str, &path_begin, &path_end);
    shortestPath(myGraph, path_begin, path_end);


    ////shortestPath 2-6
    fgets(str_file, 100 , myfile );
    //taking input from the file: string and two integer
    sscanf(str_file, " %s %d %d",str, &path_begin, &path_end);
    printf("There is no path from %d to %d.", path_begin, path_end);
    printf("\n");



    //shortestPath 7-6
    fgets(str_file, 100 , myfile );
    //taking input from the file: string and two integer
    sscanf(str_file, " %s %d %d",str, &path_begin, &path_end);
    shortestPath(myGraph, path_begin, path_end);

    
    // shortestPath 3-7
    fgets(str_file, 100 , myfile );
    //taking input from the file: string and two integer
    sscanf(str_file, " %s %d %d",str, &path_begin, &path_end);
    shortestPath(myGraph, path_begin, path_end);



    fclose(myfile);
    freeGraph(myGraph);

	return 0;
}



#include <stdio.h>  //For input/output functions.
#include <stdlib.h> //For malloc, free, etc.
#include "Project0.h"  //Include our own header file for the Employee struct.


void information(Employee *X_employee,  FILE *newfile, int Number_employee){
	
	/*char info: hold all character of each line */
	char info[65];
	int e;
	/*reading the rest of the file line by line*/
	for (e=0; e< Number_employee; e++){
		if(fgets(info, sizeof(info), newfile) !=NULL){
			
			/*Parsing data of every string for each line:*/
		sscanf(info,"%s %d %f",X_employee[e].name, &X_employee[e].id, &X_employee[e].rate);
		}
	}
	
}

void printing(Employee* X_employee,int  Number_employee){
	int v;
	for (v=0; v<Number_employee; v++){
		/*%-10s: colunm of with 10 for name*/
		/*%.2f:rate with 2 decimal place*/
		printf("%-10s %d %.2f\n",X_employee[v].name, X_employee[v].id, X_employee[v].rate);
	}
}

int main()
{
	//1.  Open the file Project0.txt and read in the first line of the file to determine how many Employees we need for our array, and use malloc() to dynamically allocate an array of this size.
	
	/*Creating file pointer*/
	FILE * newfile;

	char num_employee[10];
	int Number_employee;

	newfile = fopen("Project0Input.txt", "r");
	/*Reading first line*/
	if(fgets(num_employee, sizeof(num_employee), newfile)!=NULL){
		
		/*converting to an integer the first line*/
		Number_employee = atoi(num_employee);
	}
	//Dinamically allocate space for all employee 
	
	Employee * X_employee = (Employee *) malloc(Number_employee * sizeof(Employee));
	
	information(X_employee, newfile, Number_employee);
	printing(X_employee, Number_employee);
	


	free(X_employee);
	fclose(newfile);

	


	//2.  Use a loop to read the Employee information from Project0.txt and write the information to the entries of your array.  Suggestion:  read a single line of the file using fgets() then use sscanf() to parse out the variables from the line.  
	
	
	//3.  Loop through your array and print out the employee information.  Each employee (name, ID, hourly rate) should be on a single line.  The name should be left justified in a column of width 10.  The IDs are each 6 digits long so they can be printed with a single space after it.  The hourly rate should be printed to 2 decimal places.
	
	return 0;
}

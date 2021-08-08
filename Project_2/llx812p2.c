#include <stdio.h>
#include <string.h>
#include "Queue.h"

int main(){
    FILE *fp = NULL, *fp1 = NULL;
    fp = fopen("p2Input.txt", "r");
    if(fp == NULL){
        printf("Unable to open input file");
        return -1;
    }
    fp1 = fopen("P2Output.txt", "w");
    if(fp1 == NULL){
        printf("Cannot open file for output.\n");
        return -1;
    }

    Queue checkin_Q= newQueue();
    Queue vaccine_Q = newQueue();

    int currentTime = 0;
    int checkinTableTime[5] = {0};
    Patient* checkinTable[5] = {NULL};
    int vaccineTableTime[10] = {0};
    Patient* vaccineTable[10] = {NULL};
    int observationTime[60] = {0};
    Patient* observationTable[60] = {NULL};
    int lastPatientTime = 0;
    while(currentTime - lastPatientTime  <=100 ){ // 100 is enough for given input to complete all the patients
        int arrivalTime, id;
        char eCheckInStr[4];
        if(fscanf(fp,"%d%d%s", &arrivalTime, &id, eCheckInStr) != EOF) {
            int eCheckIn ;
            if (!strcmp(eCheckInStr, "yes"))
                eCheckIn = 1;
            else
                eCheckIn = 0;

            Patient patient;
            patient.eCheckIn = eCheckIn;
            patient.patientID = id;
            if(currentTime == 0){
                currentTime = arrivalTime;
            }
            lastPatientTime = arrivalTime;
            patient.arrivalTime = arrivalTime;
            enqueue(checkin_Q, patient);
        }

        //decrement time patients at checkin table
        for(int i=0; i<5; i++){
            if(checkinTable[i]!=NULL){
                checkinTableTime[i]  -= 1;
            }
        }
        // check if there any patient completed checkin time.
        for(int i=0;i<5; i++){
            if(checkinTable[i] != NULL && checkinTableTime[i] == 0){
                enqueue(vaccine_Q, *(checkinTable[i]));
                checkinTable[i] = NULL;
            }
        }
        //if there is any checkin table available dequeue from checkin queue and put in checkin table with respective time.
        for(int i= 0 ; i<5; i++){
            if(checkinTable[i] == NULL){
                if(!isEmpty(checkin_Q)) {
                    Patient *patient = (Patient*) malloc(sizeof(Patient));
                    dequeue(checkin_Q, patient);
                    checkinTable[i] = patient;
                    if(patient->eCheckIn == 0)
                        checkinTableTime[i] = 10;
                    else
                        checkinTableTime[i] = 4;
                }
                else{
                    break;
                }
            }
        }
        //decrement time for vaccination
        for(int i=0; i<10; i++){
            if(vaccineTable[i] != NULL) {
                vaccineTableTime[i] -= 1;
            }
        }

        //check if anyone completed vaccination. remove them from vaccinationa and insert them in observation table.
        int j = 0;
        for(int i=0;i<10; i++){
            if(vaccineTable[i] != NULL && vaccineTableTime[i] == 0){
                for(;j<1000; j++){ ///////j miss
                    if(observationTable[j] == NULL){
                        observationTable[j] = vaccineTable[i];
                        vaccineTable[i] = NULL;
                        observationTime[j] = 30;
                        break;
                    }
                }
            }
        }

        //if there are any vaccination table available dequeue from vaccination queue and put in vaccination table;
        for(int i=0; i<10; i++){
            if(vaccineTable[i] == NULL ) {
                if(!isEmpty(vaccine_Q)) {
                    Patient *patient = (Patient*) malloc(sizeof(Patient));
                    dequeue(vaccine_Q, patient);
                    vaccineTable[i] = patient;
                    vaccineTableTime[i] = 10;
                }
                else{
                    break;
                }
            }
        }
        //decrement observation time.
        for(int j = 0;j<60; j++){
            if(observationTable[j] != NULL)
                observationTime[j] -= 1;
        }
        //check if anyone completed Observation Put output them and update last time;
        for(int j = 0;j<60; j++){
            if(observationTable[j] != NULL && observationTime[j] == 0){
                fprintf(fp1, "Patient %d arrived at time %d  and completed Observation at time %d\n",
                        observationTable[j]->patientID, observationTable[j]->arrivalTime, currentTime);

                printf("Patient %d arrived at time %d  and completed Observation at time %d\n",
                        observationTable[j]->patientID, observationTable[j]->arrivalTime, currentTime);
                observationTable[j] = NULL;
            }
        }
        currentTime ++;

    }
    fclose(fp);
    fclose(fp1);
    return 0;
}
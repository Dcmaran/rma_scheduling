#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char* const process_status[] = {"F", "H", "L", "K"};
                                        /*    0    1    2    3   */
void printExecutionByRate(char process_name, int und, char status){
    printf("[%s] for %d units - %s", process_name, und, status);
}


void printLostDeadLines(char process_name, int deadlines){
    printf("[%s] %d", process_name, deadlines);
}


struct Process
{
    int priority;
    int time_execution;
    char process_name;

    /* count parameters */
    int deadlines;
    int complete_executions;
    int executed_ut;

    //Process *next;
};



/* process** inputProcessList(char file_name, int argc){

    if (argc > 2)
    {
        fprintf(stderr, "invalid parameters");
        exit(EXIT_FAILURE);
    }
    else
    {
        FILE* file = fopen(file_name, "r");

        if (file == NULL)
        {
            fprintf(stderr, "error opening file");
            exit(EXIT_FAILURE);
        }
        else
        {
            fscanf()
        }
        
        
    }
    
    

} */
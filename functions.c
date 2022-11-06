#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

typedef struct
{
    int period;
    int execution_time;
    char *process_name;

    /* count parameters */
    int deadlines;
    int complete_executions;
    int executed_ut;
    int executed_total;
    int period_count;
    int killed;
    int in_hold;
    
    /*flag status*/
    int are_using;
    int pause_count_period;

}Process;


FILE* openFile(char* file_name){
    FILE* file = fopen(file_name, "r");

    if (file == NULL)
    {
        fprintf(stderr, "File does not exist\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        return file;
    }

}


void parse_command_by_space(char **args, char *command)
{
    char *separator;

    separator = strtok(command, " ");

    int count = 0;

    while (separator != NULL)
    {
        args[count] = strdup(separator);
        separator = strtok(NULL, " ");
        count++;
        
    }
    
}


int separateLines(int count_line, char *file_name, char line[MAX_LEN][MAX_LEN]){
    FILE* file = openFile(file_name);

    while (!feof(file) && !ferror(file)){
        if (fgets(line[count_line], MAX_LEN, file) != NULL){   
            if (line[count_line][strlen(line[count_line]) - 1] == '\n')
            {
                line[count_line][strlen(line[count_line]) - 1] = '\0'; 
            }
            count_line++;
        }
    }
    fclose(file);

    return count_line;
}

void inputProcessInfo(char* file_name, char line[MAX_LEN][MAX_LEN], int count_line, Process processes_list_args[count_line - 1]){

    char *separated_line[MAX_LEN];

    Process process_aux;
    
    for (int i = 0; i < count_line - 1; i++)
    {
        parse_command_by_space(separated_line, line[i + 1]);

        int period = atoi(separated_line[1]);
        int execution_time = atoi(separated_line[2]);
        char *name = separated_line[0];
    
        process_aux.process_name= name;
        process_aux.period = period;
        process_aux.execution_time = execution_time;
        process_aux.deadlines = 0;
        process_aux.executed_ut = 0;
        process_aux.complete_executions = 0;
        process_aux.period_count = 0;
        process_aux.killed = 0;
        process_aux.executed_total = 0;
        process_aux.in_hold = 0;
        process_aux.pause_count_period = 0;
        processes_list_args[i] = process_aux;
    }
      
} 

void printProcess(int count_line, Process process[count_line - 1], int i){

    printf("Task Name - %s\n", process[i].process_name);
    printf("Period - %d\n", process[i].period);
    printf("Execution Time - %d\n", process[i].execution_time);
    printf("Deadlines - %d\n", process[i].deadlines);
    printf("Unity time - %d\n", process[i].executed_ut);
    printf("Complete Executions - %d\n", process[i].complete_executions);
    printf("Period Count - %d\n", process[i].period_count);
    printf("Process killed - %d\n", process[i].killed);
}

void sortProcess(Process process_list[], int count_process)
{
    int i, j;
    Process temp;
    
    for (i = 0; i < count_process - 1; i++)
    {
        for (j = 0; j < (count_process - 1-i); j++)
        {
            if (process_list[j].period > process_list[j + 1].period)
            {
                temp = process_list[j];
                process_list[j] = process_list[j + 1];
                process_list[j + 1] = temp;
            } 
        }
    }
}
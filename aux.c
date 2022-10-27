#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

//static const char* const process_status[] = {"F", "H", "L", "K"};

typedef struct
{
    int period;
    int execution_time;
    char *process_name;

    /* count parameters */
    int deadlines;
    int complete_executions;
    int executed_ut;

}Process;


FILE* openFile(char* file_name){
    FILE* file = fopen(file_name, "r");

    if (file == NULL)
    {
        fprintf(stderr, "File does not exist");
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


void printExecutionByRate(char *process_name, int und, char* status){
    printf("[%s] for %d units - %s", process_name, und, status);
}


void printLostDeadLines(char *process_name, int deadlines){
    printf("[%s] %d", process_name, deadlines);
}


int separateLines(int count_line, char *file_name, char line[MAX_LEN][MAX_LEN]){
    FILE* file = openFile(file_name);

    while (!feof(file) && !ferror(file)){
        if (fgets(line[count_line], MAX_LEN, file) != NULL){   
            if (line[count_line][strlen(line[count_line]) - 1] == '\n')
            {
                line[count_line][strlen(line[count_line]) - 1] = '\0'; 
            }
            printf("%s\n", line[count_line]);
            count_line++;
        }
    }
    fclose(file);

    return count_line;
}

void inputProcessInfo(char* file_name, char line[MAX_LEN][MAX_LEN], int count_line, Process *processes_list_args[count_line - 1]){
    
    char *separated_line[MAX_LEN];

    printf("%d", count_line);

    Process *processes_list[50];
    
    for (int i = 0; i < count_line - 1; i++)
    {
        parse_command_by_space(separated_line, line[i + 1]);

        int period = atoi(separated_line[1]);
        int execution_time = atoi(separated_line[2]);
        char *name = separated_line[0];
    
        processes_list[i]->process_name = name;
        processes_list[i]->period = period;
        processes_list[i]->execution_time = execution_time;

        printf("%s", processes_list[i]->process_name);
        printf("%d", processes_list[i]->period);
        printf("%d", processes_list[i]->execution_time);
        
    }

    processes_list_args = processes_list;
    exit(EXIT_SUCCESS);
      
} 
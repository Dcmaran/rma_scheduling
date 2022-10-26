#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
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


int count_linesFileLines(FILE* file){
    
    int count_lines = 0;

    char c;

    if (file == NULL)
    {
        fprintf(stderr, "File does not exist");
        exit(EXIT_FAILURE);
    }
  
    for (c = getc(file); c != EOF; c = getc(file))
        if (c == '\n')
            count_lines = count_lines + 1;
  
    return count_lines;
}


void parse_command_by_space(char **args, char *command)
{
    args[0] = strtok(command, " ");

    int count = 0;

    while (args[count] != NULL)
    {
        args[++count] = strtok(NULL, " ");
    }
    
}


void printExecutionByRate(char *process_name, int und, char* status){
    printf("[%s] for %d units - %s", process_name, und, status);
}


void printLostDeadLines(char *process_name, int deadlines){
    printf("[%s] %d", process_name, deadlines);
}


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


Process** inputProcessInfo(Process** process_list_arg, char* file_name){
    int count_line = 0;
    
    char *separated_line[MAX_LEN];
    char line[MAX_LINES][MAX_LINES];

    FILE* file = openFile(file_name);

    while (!feof(file) && !ferror(file)){
        if (fgets(line[count_line], MAX_LEN, file) != NULL){   
            if (line[count_line][strlen(line[count_line]) - 1] == '\n')
            {
                line[count_line][strlen(line[count_line]) - 1] = '\0'; 
            }
             
            count_line++;
            printf("%d", count_line);
        }
    }
    fclose(file);

    Process *processes_list[count_line - 1];

    for (int i = 0; i < count_line - 1; i++)
    {
        int j = 0;
        parse_command_by_space(separated_line, line[i + 1]);

        //printf("%s\n", separated_line[0]);
        //printf("%s\n", separated_line[1]);
        //printf("%s\n", separated_line[2]);

        int period = atoi(separated_line[1]);
        int execution_time = atoi(separated_line[2]);
        char *name = separated_line[0];
        
        processes_list[i]->process_name = name;
        processes_list[i]->period = period;
        processes_list[i]->execution_time = execution_time;
    }
    
    printf("%s ", processes_list[0]->process_name);
    printf("%d ", processes_list[0]->period);
    printf("%d ", processes_list[0]->execution_time);
    
    printf("%s ", processes_list[1]->process_name);
    printf("%d ", processes_list[1]->period);
    printf("%d ", processes_list[1]->execution_time);

    printf("%s ", processes_list[2]->process_name);
    printf("%d ", processes_list[2]->period);
    printf("%d ", processes_list[2]->execution_time);

    process_list_arg = processes_list;
    
    return processes_list_arg;
} 
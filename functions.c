#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

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


Process** inputProcessInfo(char* file_name){
    int processes_count;
    int line = 0;
    
    char *separated_line[MAX_LEN];

    FILE* file;
    char data[MAX_LINES][MAX_LEN];
    file = fopen(file_name, "r");

    while (!feof(file) && !ferror(file)){
    if (fgets(data[line], MAX_LEN, file) != NULL)
        line++;
    }

    Process *processes_list[line - 1];

    for (int i = 0; i < line - 1; i++){
        parse_command_by_space(separated_line, data[i+1]);

        processes_list[i]->process_name = separated_line[0];
        processes_list[i]->period = atoi(separated_line[1]);
        processes_list[i]->execution_time = atoi(separated_line[2]);
    }

    for (int i = 0; i < line - 1 ; i++)
    {
        printf("%s\n", processes_list[i]->process_name);
        printf("%d\n", processes_list[i]->period);
        printf("%d\n", processes_list[i]->execution_time);
    }
    
    fclose(file);

} 
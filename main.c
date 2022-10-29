#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aux.c"

#define MAX_LEN 1000

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Invalid number of arguments");
        exit(EXIT_FAILURE);
    }
    
    if (argv[1] == NULL)
    {
        printf("First parameter invalid. Try use this format: 'rate [file_name.txt]'");
        exit(EXIT_FAILURE);
    }
    
    int total_time_count = 0;
    int total_time;
    int count_line = 0;
    char line[MAX_LEN][MAX_LEN];
    char *separated_line[MAX_LEN];

    count_line = separateLines(count_line, argv[1], line);
    
    Process process_list[count_line - 1];

    inputProcessInfo(argv[1], line, count_line, process_list);
    
    bsortDesc(process_list, count_line - 1);
    

    total_time = atoi(line[0]);

    //printf("Clock - %d", clocks);    
    int index_process = 0;

    for (int total_time_count = 0; total_time_count <= total_time; total_time_count++)
    {
    
        process_list[index_process].executed_ut++;

        if (process_list[index_process].executed_ut == process_list[index_process].execution_time)
        {
            process_list[index_process].complete_executions++;
            printf("[%s] for %d units - F\n", process_list[index_process].process_name, process_list[index_process].executed_ut);
            process_list[index_process].executed_ut = 0;
            index_process += 1;

            if (index_process == count_line - 1)
            {
                index_process = 0;
            }

        }
           
    }

    for (int i = 0; i < count_line - 1; i++)
    {
        printProcess(count_line - 1, process_list, i);
    }
    
    
    return 0;
}

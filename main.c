#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aux.c"

#define MAX_LEN 1000

int main(int argc, char const *argv[])
{
    /*                  validate parameters
    if (argc > 2)
    {
        printf("Invalid number of arguments");
        exit(EXIT_FAILURE);
    }
    
    if (strncmp(argv[0], "rate", srtlen("rate")) != 0)
    {
        printf("First parameter invalid. Try use this format rate [file_name.txt]");
        exit(EXIT_FAILURE);
    }
                                                                                        */
    
    
    int clocks_count = 0;
    int clocks;
    int count_line = 0;
    char line[MAX_LEN][MAX_LEN];
    char *separated_line[MAX_LEN];

    count_line = separateLines(count_line, "input.txt", line);
    
    Process process_list[count_line - 1];

    inputProcessInfo("input.txt", line, count_line, process_list);
    
    bsortDesc(process_list, count_line - 1);
    printProcess(count_line, process_list, 0);]

    do
    {
        
    } while (clocks_count < clocks);
    
    return 0;
}

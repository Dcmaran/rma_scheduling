#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

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
    
    Process process_list;
    int clocks_count = 0;
    int clocks;


    /* READ INPUT FILE / ALLOCATE IN STRUCT */;
    inputProcessInfo("input.txt");

    /*
    do
    {
        
    } while (clocks_count < clocks);
    */

    return 0;
}

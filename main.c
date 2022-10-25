#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char* const process_status[] = {"F", "H", "L", "K"};
                                        /*    0    1    2    3   */

int main(int argc, char const *argv[])
{
    if (strncmp(argv[0], "rate", strlen("rate")) != 0)
    {
        fprintf(stderr, "Invalid first argument. expected rate [input_file]");
        exit(EXIT_FAILURE);
    }
    
    int clocks_count = 0;
    int clocks;

    /* READ INPUT FILE / ALLOCATE IN STRUCT */

    do
    {
        
    } while (clocks_count < clocks);
    

    return 0;
}

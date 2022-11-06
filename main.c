#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

#define MAX_LEN 1000

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Invalid number of arguments\n");
        exit(EXIT_FAILURE);
    }
    
    if (argv[1] == NULL)
    {
        printf("First parameter invalid. Try use this format: 'rate [file_name.txt]'\n");
        exit(EXIT_FAILURE);
    }
    
    int total_time_count = 0;
    int total_time;
    int count_line = 0;
    char line[MAX_LEN][MAX_LEN];
    char *separated_line[MAX_LEN];
    int aux = 0;
    int idle_count = 0;
    int index_process = 0;

    FILE *out_file = fopen("rate_dcmr.out", "w");

    count_line = separateLines(count_line, argv[1], line);
    
    Process process_list[count_line - 1];

    inputProcessInfo(argv[1], line, count_line, process_list);
    
    sortProcess(process_list, count_line - 1);
    
    total_time = atoi(line[0]);
 
    fprintf(out_file, "EXECUTION BY RATE\n");


    for (int total_time_count = 1; total_time_count <= total_time; total_time_count++)
    {
        //printf("%d\n", total_time_count);
        
        if (aux < idle_count)
        {

        if (total_time_count == total_time)
        
            for (int i = 0; i < count_line - 1; i++)
            {
                if (process_list[i].period_count == total_time)
                {
                    process_list[i].killed = 1;
                }
                
            }
                      
            aux++;
            continue;
        }
        
        if (aux == idle_count)
        {
            idle_count = 0;
            aux = 0;    
        }

        process_list[index_process].executed_total++;
        process_list[index_process].executed_ut++;
        
            if (total_time_count == total_time)
            {
                for (int i = 0; i < count_line - 1; i++)
                {
                    if (process_list[i].executed_total < process_list[i].execution_time)
                    {
                        process_list[i].killed = 1;
                    }

                    if (process_list[i].period_count == total_time)
                    {
                        process_list[i].killed = 1;
                    }
                    
                }

                fprintf(out_file, "[%s] for %d units - K\n", process_list[index_process].process_name, process_list[index_process].executed_ut);
                printf("[%s] for %d units - K\n", process_list[index_process].process_name, process_list[index_process].executed_ut);
                
                break;
            }      
        //printf("%s - count %d\n", process_list[index_process].process_name ,process_list[index_process].period_count);

        //printf("Process name [%s] process execute total time %d process execute time%d - period %d\n\n\n", process_list[index_process].process_name, process_list[index_process].executed_total, process_list[index_process].executed_ut, process_list[index_process].period_count);

        if (process_list[index_process].executed_total == process_list[index_process].execution_time)
        {
            process_list[index_process].complete_executions++;
            fprintf(out_file, "[%s] for %d units - F\n", process_list[index_process].process_name, process_list[index_process].executed_ut);
            printf("[%s] for %d units - F\n", process_list[index_process].process_name, process_list[index_process].executed_ut);

            process_list[index_process].executed_ut = 0;
            process_list[index_process].executed_total = 0;
            
            if (process_list[index_process].in_hold == 0)
            {
               process_list[index_process].period_count = process_list[index_process].period + process_list[index_process].period_count; 
            }
            
            process_list[index_process].in_hold = 0;

            
            //printf("%s - count %d\n", process_list[index_process].process_name ,process_list[index_process].period_count);
            
            for (int i = 0; i < count_line - 1; i++)
            {
                if (process_list[i].in_hold == 1 && i > index_process)
                {
                    index_process = i;
                }    
            }

            if (process_list[index_process].in_hold == 0)
            {
                
                if (total_time_count > process_list[index_process+1].period_count)
                {
                    if (index_process == count_line - 1)
                    {  
                        index_process = index_process;
                    }
                    else
                    {   
                        index_process += 1;
                    }
                     
                }
                else
                {
                    idle_count = process_list[0].period_count - total_time_count;
                    fprintf(out_file, "idle for %d units\n", idle_count);
                    printf("idle for %d units\n", idle_count);

                    index_process = 0;
                    continue;
                }
                
            }
                      
            if (index_process == count_line - 1)
            {                
                if (process_list[0].period_count != total_time_count)
                {
                    idle_count = process_list[0].period_count - total_time_count;
                    fprintf(out_file, "idle for %d units\n", idle_count);
                    printf("idle for %d units\n", idle_count);

                    index_process = 0;
                    continue;
                }

                if (process_list[0].period_count <= total_time_count)
                {
                    index_process = 0;
                }
                
   
                else
                {
                    index_process = index_process;
                    process_list[index_process].period_count = process_list[index_process].period + process_list[index_process].period_count;
                }
                                              
            }
            
        }
        
        else if (process_list[index_process].executed_total < process_list[index_process].execution_time)
        {
            for (int i = 0; i < count_line - 1; i++)
            {
                if (process_list[i].period_count == total_time_count && process_list[i].period_count != 0)
                {
                    if (i < index_process)
                    {   
                        fprintf(out_file, "[%s] for %d units - H\n", process_list[index_process].process_name, process_list[index_process].executed_ut);
                        printf("[%s] for %d units - H\n", process_list[index_process].process_name, process_list[index_process].executed_ut);

                        process_list[index_process].period_count = process_list[index_process].period + process_list[index_process].period_count;
                        process_list[index_process].executed_ut = 0;
                        process_list[index_process].in_hold = 1;
                        index_process = i;

                    }

                    else
                    {
                        index_process = index_process;
                        continue;
                    }
                    
                }

                continue;
            }
                               
            if (process_list[index_process].period_count == total_time_count)
            {
                if (process_list[index_process].executed_total < process_list[index_process].execution_time && process_list[index_process].execution_time - process_list[index_process].executed_total + total_time_count < total_time && process_list[index_process].executed_total != 0)
                {
                    fprintf(out_file, "[%s] for %d units - L\n", process_list[index_process].process_name, process_list[index_process].execution_time - process_list[index_process].executed_total);
                    printf("[%s] for %d units - L\n", process_list[index_process].process_name, process_list[index_process].execution_time - process_list[index_process].executed_total);

                    process_list[index_process].executed_total = 0;
                    process_list[index_process].executed_ut = 0;
                    process_list[index_process].deadlines++;
                    process_list[index_process].executed_total = 0;
        
                }
                         
            }
            
        }
        
    }
    
    fprintf(out_file, "\nLOST DEADLINES\n");

    for (int i = 0; i < count_line - 1; i++)
    {
        fprintf(out_file, "[%s] %d\n", process_list[i].process_name, process_list[i].deadlines);
    } 
    
    fprintf(out_file, "\nCOMPLETE EXECUTION\n");

    for (int i = 0; i < count_line - 1; i++)
    {
        fprintf(out_file, "[%s] %d\n", process_list[i].process_name, process_list[i].complete_executions);
    }

    fprintf(out_file, "\nKILLED\n");

    for (int i = 0; i < count_line - 1; i++)
    {
        fprintf(out_file, "[%s] %d\n", process_list[i].process_name, process_list[i].killed);

        if (i = count_line - 2)
        {
            fprintf(out_file, "[%s] %d", process_list[i].process_name, process_list[i].killed);
        }
        
    } 

    fclose(out_file);

    return 0;
}

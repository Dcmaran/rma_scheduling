    for (int total_time_count = 0; total_time_count <= total_time; total_time_count++)
    {   
        process_list[index_process].executed_ut++;

        printf("%d\n", total_time_count);
        for (int i = 0; i < count_line; i++)
        {
            process_list[i].period_count++;
        }
    
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

        else if (process_list[index_process].executed_ut < process_list[index_process].execution_time)
        {   
                             
            for (int i = 0; i < count_line - 1; i++)
            {
                if (process_list[i].period_count == process_list[i].period)
                {
                    if (i < index_process)
                    {
                        if (process_list[index_process].executed_ut < process_list[index_process].execution_time)
                        {
                            printf("[%s] for %d units - H\n", process_list[index_process].process_name, process_list[index_process].executed_ut);
                            
                        }
                        
                        index_process = i;
                        process_list[i].period_count = 0;

                    }
                    
                }
                
                if (process_list[index_process].period_count == process_list[index_process].period)
                {
                    if (process_list[index_process].executed_ut < process_list[index_process].execution_time)
                    {
                        printf("[%s] for %d units - L\n", process_list[index_process].process_name, process_list[index_process].execution_time - process_list[index_process].executed_ut);
                        process_list[index_process].deadlines++;
                        process_list[index_process].executed_ut = 0;
                        process_list[index_process].period_count = 0;
                    }
                         
                }
                       
            }
        }
    }
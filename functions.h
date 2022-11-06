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

}Process;

int count_linesFileLines(FILE* file);

void parse_command_by_space(char **args, char *command);

void printLostDeadLines(char *process_name, int deadlines);

FILE* openFile(char* file_name);

int separateLines(int count_line, char *file_name, char line[MAX_LEN][MAX_LEN]);

struct Process** inputProcessInfo(char* file_name);

void sortProcess(Process process_list[], int count_process);

void inputProcessInfo(char* file_name, char line[MAX_LEN][MAX_LEN], int count_line, Process processes_list_args[count_line - 1]);

int count_linesFileLines(FILE* file);

void parse_command_by_space(char **args, char *command);

void printExecutionByRate(char *process_name, int und, char* status);

void printLostDeadLines(char *process_name, int deadlines);

FILE* openFile(char* file_name);

struct Process** inputProcessInfo(char* file_name);
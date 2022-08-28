#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char* getInfo(char* line, int num);
int readFile(char* filename);





int readFile(char* filename) {
    //https://stackoverflow.com/questions/12911299/read-csv-file-in-c
    FILE* stream = fopen(filename, "r");
 
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        printf("Field 3 would be %s\n", getInfo(tmp, 3));
        // NOTE strtok clobbers tmp
        free(tmp);
    }

    return 0;
}

const char* getInfo(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
        tok && *tok;
        tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
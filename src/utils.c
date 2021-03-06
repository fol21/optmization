#include "../include/utils.h"

/**
 * 
 * * Split string into an array of strings by a delimiter char
 *  
 */
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    int count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = (char**)malloc(sizeof(char*) * count);

    if (result)
    {
        int idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

void scanf_until_int(const char* format, int* ref)
{
     fflush(stdin);
     int scan = scanf(format, &ref);
     while (scan !=1)
     {
          printf("Escolha um numero inteiro !\n");
          fflush(stdin);
          scan = scanf(format, &ref);
     };
}

#ifndef IO_UTILS_H
#define IO_UTILS_H  

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <assert.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))



char** str_split(char* a_str, const char a_delim);
void scanf_until_int(const char* format, int* ref);

#endif // !1

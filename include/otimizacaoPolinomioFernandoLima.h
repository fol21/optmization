#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


int lenght(double* array);
int compare (const void * a, const void * b);
double*  optimize(double* coef, int order, int* range);

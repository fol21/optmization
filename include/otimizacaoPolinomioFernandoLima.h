#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


typedef struct LinSpaceVector
{
    double* vector;   
    int size;
} LinSpaceVector;


LinSpaceVector* linSpace_populate(double begin, double end, double step, LinSpaceVector* lsv);
int compare (const void * a, const void * b);
double calculaMaximo(double* coef, int order, double* range, double* xmax);
int findIndex( const double a[], int size, double value )

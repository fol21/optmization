#ifndef OTIMIZACAO_POLINOMIO_FERNANDO_LIMA_H
#define OTIMIZACAO_POLINOMIO_FERNANDO_LIMA_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include <assert.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
#define POS_INFINITE 1*pow(10,10)
#define NEG_INFINITE -1*pow(10,10)



typedef struct LinSpaceVector
{
    double* vector;   
    int size;
} LinSpaceVector;


LinSpaceVector* linSpace_populate(double begin, double end, double step, LinSpaceVector* lsv);
double calculaMaximo(double* coef, int order, double* range, double* xmax);
double calculaMinimo(double* coef, int order, double* range, double* xmin);
char** str_split(char* a_str, const char a_delim);

#endif

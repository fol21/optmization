#include "../include/otimizacaoPolinomioFernandoLima.h"

int lenght(double* array)
{
    return sizeof(array)/sizeof(array[0]);
}

int compare (const void * a, const void * b)
{
  return ( *(double*)a - *(double*)b );
}


double*  optimize(double* coef, int order, int* range)
{
    double* buffer = (double*)malloc(100*sizeof(double));
    for(int i =range[0]; i <= range[2] ;i++)
    {
		buffer[i] = 0;
		int l =NELEMS(coef);
        for(int j= 0; j < lenght(coef);j++)
        {
            buffer[i] += pow(coef[j],(j+1))*i;
        }

    }

    //sort buffer
    qsort (buffer, lenght(buffer), sizeof(double), compare);
    double min = buffer[0];
    double max = buffer[lenght(buffer)];


    double local[2] = {min,max};
    return local;
}

/*
    * Retorna vetor linear com step definido
    * També retorna o tamanho do vetor por referência
*/
double* linSpace(double begin, double end, double step, int* size)
{
    double* vector = (double*) malloc(sizeof(double));
    vector[0] = begin;
    int count = 2;
    for(double i = begin+step; i <= end  ;i = i + step)
    {
		vector = (double*)realloc(vector, count*sizeof(double));
		vector[count-1] = i;
		count++;
    }
    *size = count;
    return vector;
}

double calculaMaximo(double* coef, int order, double* range, double* xmax)
{
    
}


// int main()
// {
//     printf("[Begin Optimization]\n");
    
//     double* local;
//     double coef[5] = {1,2,3,4,5};
//     int range[2] = {1,100};

//     local = optimize(coef,lenght(coef), range);

//     printf("[min = %f , max = %f]", local[0], local[1]);
//     return 0 ;
// }

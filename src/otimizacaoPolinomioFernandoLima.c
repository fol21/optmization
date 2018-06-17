#include "../include/otimizacaoPolinomioFernandoLima.h"


/*
* Retorna vetor linear com step definido
*/
LinSpaceVector* linSpace_populate(double begin, double end, double step, LinSpaceVector* lsv)
{
    // lsv->vector = (double*) malloc(sizeof(double));
    // lsv->vector[0] = begin;
    int count = 1;
    for(double i = begin; i <= end  ;i = i + step)
    {
		lsv->vector = (double*)realloc(lsv->vector, count*sizeof(double));
		lsv->vector[count-1] = i;
		count++;
    }
    lsv->size = count-1;
    return lsv;
}



/*
* Tenta encotrar o index do valor especificado
! retorna -1 caso o valor não seja encontrado
*/
int findIndex( const double a[], int size, double value )
{
    int index = 0;

    while ( index < size && a[index] != value ) ++index;

    return ( index == size ? -1 : index );
}

int _compare (const void * a, const void * b)
{
  return ( *(double*)a - *(double*)b );
}

double calculaMaximo(double* coef, int order, double* range, double* xmax)
{
    LinSpaceVector  v = {NULL, 0}; 
    linSpace_populate(range[0], range[1], 0.0001, &v);
    double* buffer = (double*)malloc(v.size*sizeof(double));
    for(int i = 0; i < v.size ; i++)
	{   
		buffer[i] = coef[order];
        for(int j= 0; j < order;j++)
        {
            buffer[i] += pow(v.vector[i],(order-j))*coef[j];
        }
        printf(" max = %f ", buffer[i]);
	}
    double sorted_buffer = buffer;
    //sort buffer
    qsort (sorted_buffer, v.size, sizeof(double), _compare);
    double ymax  = sorted_buffer[v.size-1];
    index_max = findIndex(buffer, v.size, ymax);
    *xmax = v[index_max];

    return ymax;
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

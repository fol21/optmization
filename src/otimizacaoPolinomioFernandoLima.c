#include "../include/otimizacaoPolinomioFernandoLima.h"


/**
* * Retorna vetor linear com step definido 
* * ex : linSpace_populate(1,10,2) = [1,3,5,7,9]
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

/**
 * * Calcula Máximos comparando cada resultado do polinomio com o próximo
 * * returna o valor maximo
 */
double calculaMaximo(double* coef, int order, double* range, double* xmax)
{
    LinSpaceVector  v = {NULL, 0}; 
    linSpace_populate(range[0], range[1], 0.0001, &v);
    double* buffer = (double*)malloc(v.size*sizeof(double));
    
    double  ymax = NEG_INFINITE;
    int index_max = -1;
    
    for(int i = 0; i < v.size ; i++)
	{   
		buffer[i] = coef[order];
        for(int j= 0; j < order;j++)
        {
            buffer[i] += pow(v.vector[i],(order-j))*coef[j];
        }
        if(buffer[i] > ymax)
		{
			ymax = buffer[i];
			index_max = i;	
		}
        //printf(" max = %f ", buffer[i]);
	}
    *xmax = v.vector[index_max];

    return ymax;
}

/**
 * * Calcula Mínimo comparando cada resultado do polinomio com o próximo
 * * returna o valor minimo
 */
double calculaMinimo(double* coef, int order, double* range, double* xmin)
{
    LinSpaceVector  v = {NULL, 0}; 
    linSpace_populate(range[0], range[1], 0.0001, &v);
    double* buffer = (double*)malloc(v.size*sizeof(double));
    double  ymin = POS_INFINITE;
    int index_min = -1;
    for(int i = 0; i < v.size ; i++)
	{   
		buffer[i] = coef[order];
        for(int j= 0; j < order;j++)
        {
            buffer[i] += pow(v.vector[i],(order-j))*coef[j];
        }
        //printf(" max = %f ", buffer[i]);
        if(buffer[i] < ymin)
		{
			ymin = buffer[i];
			index_min = i;	
		}
	}
    double* sorted_buffer = buffer;
    //sort buffer
    *xmin = v.vector[index_min];

    return ymin;
}



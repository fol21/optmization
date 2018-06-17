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

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
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
        size_t idx  = 0;
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


#include <stdio.h>
#include "include\otimizacaoPolinomioFernandoLima.h"


int main(int argc, char** argv) {
	printf("[Begin Optimization]\n");
    
    double xmax;
    double xmin;
    //double coef[6] = {1,0,-10,0,30,0};
    double range[2] ;
    int grau = 0;
    
 
    char* nums = "1,2,3";
    char** tokens;
    double* coef = NULL;
    int coef_count = 0;
    
	printf("\nEscolha coeficientes:  ex: 1,0,-10,0,30,0\n");
    scanf("%[^\n]", nums);
    
    tokens = str_split(nums, ',');
	
    if (tokens)
    {
        for (int i = 0; *(tokens + i); i++)
        {
        	coef = (double*)realloc(coef, (i+1)*sizeof(double));
        	coef[i] = atof(*(tokens + i));
            printf("month=[%f]\n", coef[i]);
            free(*(tokens + i));
            coef_count++;
        }
        free(tokens);
    }
    
    printf("\nEscolha o valor inicial do intervalo: ");
    scanf("%f", &range[0]);
    printf("\nEscolha o valor final do intervalo: ");
    scanf("%f", &range[1]);

    double ymax = calculaMaximo(coef,coef_count-1, range, &xmax);
    double ymin = calculaMinimo(coef,coef_count-1, range, &xmin);

	
    printf("~\n[xmax = %f  , ymax = %f]\n", xmax, ymax);
    printf("~\n[xmin = %f  , ymin = %f]\n", xmin, ymin);


    return 0 ;
}

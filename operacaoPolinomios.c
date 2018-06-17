#include <stdio.h>
#include "include\otimizacaoPolinomioFernandoLima.h"


int main(int argc, char** argv) {
	printf("[Begin Optimization]\n");
    
    double xmax;
    double xmin;
    double range[2] ;
    int grau = 0;
    
 	printf("\nEscolha grau do polinomio: ");
 	scanf("%d", &grau);
	printf("\n");
	double coefs[grau+1] ;
	
	for(int i = 0; i <= 5 ; i++)
	{
		printf("\nEscolha Coeficiente de grau %d: ", grau-i);
 		scanf("%lf", &coefs[i]);
	
	}
	
    printf("\nEscolha o valor inicial do intervalo: ");
    scanf("%lf", &range[0]);
    printf("\nEscolha o valor final do intervalo: ");
    scanf("%lf", &range[1]);

    double ymax = calculaMaximo(coefs,grau, range, &xmax);
    double ymin = calculaMinimo(coefs,grau, range, &xmin);

	
    printf("~\n[xmax = %f  , ymax = %f]\n", xmax, ymax);
    printf("~\n[xmin = %f  , ymin = %f]\n", xmin, ymin);


    return 0 ;
}

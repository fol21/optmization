#include <stdio.h>
#include "include\otimizacaoPolinomioFernandoLima.h"


int main(int argc, char** argv) {
	printf("[Begin Optimization]\n");
    
    double xmax;
    double xmin;
    double range[2] ;
    int grau = 0;
    int scan;
	
	//Escolhe Grau
 	printf("\nEscolha grau do polinomio: ");
 	fflush(stdin);
     scan = scanf("%d", &grau);
     while (scan !=1)
     {
          printf("Escolha um numero inteiro !\n");
          fflush(stdin);
          scan = scanf("%d", &grau);
     };
	printf("\n");
	double coefs[grau+1] ;
	
	
	//Define os coeficientes
	for(int i = 0; i <= 5 ; i++)
	{
		printf("\nEscolha Coeficiente de grau %d: ", grau-i);
 		fflush(stdin);
		scan = scanf("%lf", &coefs[i]);
		while (scan !=1)
    	 {
          printf("Escolha um numero !\n");
          fflush(stdin);
          scan = scanf("%f", &coefs[i]);
     	};
	
	}
	
	// Define intervalos
    printf("\nEscolha o valor inicial do intervalo: ");
    fflush(stdin);
    scan = scanf("%lf", &range[0]);
	while (scan !=1)
    {
        printf("Escolha um numero !\n");
        fflush(stdin);
        scan = scanf("%lf", &range[0]);
    };
    printf("\nEscolha o valor final do intervalo: ");
    fflush(stdin);
    scan = scanf("%lf", &range[1]);
	while (scan !=1)
    {
        printf("Escolha um numero !\n");
        fflush(stdin);
        scan = scanf("%lf", &range[1]);
    };
	
	//Calculo de minimos e maximos
    double ymax = calculaMaximo(coefs,grau, range, &xmax);
    double ymin = calculaMinimo(coefs,grau, range, &xmin);

	
    printf("~\n[xmax = %f  , ymax = %f]\n", xmax, ymax);
    printf("~\n[xmin = %f  , ymin = %f]\n", xmin, ymin);


    return 0 ;
}

#include <stdio.h>
#include "include\otimizacaoPolinomioFernandoLima.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	printf("[Begin Optimization]\n");
    
    double xmax;
    double coef[5] = {1,2,3,4,5};
    double range[2] = {1,5};

    double ymax = calculaMaximo(coef,NELEMS(coef)-1, range, &xmax);

    printf("~\n[min = %f  , max = %f]", xmax, ymax);

    // your code goes here
    // LinSpaceVector v = {NULL,0};

    // linSpace_populate(2, 10, 0.0001, &v);
	// printf("%d \n", v.size);
	// for(int n = 0; n < v.size ; ++n)
	// {
    //     printf("%f ", v.vector[n]);
	// }
    return 0 ;
}

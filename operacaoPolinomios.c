#include <stdio.h>
#include "include\otimizacaoPolinomioFernandoLima.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	printf("[Begin Optimization]\n");
    
    double* local;
    double coef[5] = {1,2,3,4,5};
    int range[2] = {1,100};

    local = optimize(coef,NELEMS(coef), range);

    printf("[min = %f , max = %f]", local[0], local[1]);
    return 0 ;
}

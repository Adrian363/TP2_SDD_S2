#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "queue.h"
#include "stack.h"
#include "cnp.h"


int main(){

    tval_stack ni=5;
    tval_stack pi=3;
    int res_rec=0;
    int res_iter=0;
    double time_spent = 0.0;

    /***** Appel de la fonction CNP recursive *****/

    clock_t begin = clock();
    res_rec=CNP_REC(ni, pi);
    clock_t end_process = clock();
    time_spent = (double)(end_process - begin) / CLOCKS_PER_SEC;
    printf("\nTemps de process: %f secondes\n", time_spent);
    printf("Resultat par la fonction itérative est %d\n", res_rec);

    /***** Appel de la fonction CNP non recursive *****/
    
    /*Relevé du temps de départ*/
    begin = clock();
    res_iter=CNP_ITER(ni,pi);

    /* Relevé du temps de fin*/
    end_process = clock();

    /* Calcul du temps de process */
    time_spent = (double)(end_process - begin) / CLOCKS_PER_SEC;

    printf("\nTemps de process: %f secondes\n", time_spent);
    printf("Resultat par la fonction itérative est  %d\n", res_iter);
}

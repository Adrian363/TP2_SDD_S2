#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "queue.h"
#include "stack.h"
#include "cnp.h"
#define FORMAT_VAL "%d" 

int main(){

    /* Déclrations pour la partie CNP*/

    tval_stack ni;
    tval_stack pi;
    int res_rec=0;
    int res_iter=0;

    /* Déclarations pour la gestion du temps d'éxecution des fonctions*/
    clock_t begin;
    clock_t end_process;
    double time_spent = 0.0;

    /* Quelques tests sur la pile avec la fonction suivante: (Commentés pour ne pas surchager la sortie)*/

    test_stack(8);
    /*test_stack(20);*/
    /*test_stack(0);*/
    /*test_stack(-2);*/

    /* Une fonction de test pour vérifier le fonctionnement de la file: (Commentés pour ne pas surchager la sortie)*/

    test_queue(8);
    /*test_queue(20);*/
    /*test_queue(0);*/
    /*test_queue(-2);*/

    
    /***** Appel de la fonction CNP recursive *****/
    printf("Choisir un n pour la fonction CNP: \n");
    scanf(FORMAT_VAL, &ni);
    printf("Choisir un p pour la fonction CNP: \n");
    scanf(FORMAT_VAL, &pi);

    if(ni>=pi && pi>=0){

        /***** Appel de la fonction CNP recursive *****/

        /*Relevé du temps de départ*/
        begin = clock();
        res_rec=CNP_REC(ni, pi);

        /* Relevé du temps de fin*/
        end_process = clock();
        
        time_spent = (double)(end_process - begin) / CLOCKS_PER_SEC;
        printf("\nTemps de process: %f secondes\n", time_spent);
        printf("Resultat par la fonction recursive est %d\n", res_rec);

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
    else{
        printf("N et P ne correspondent pas aux criteres.\n");
    }
    
    return 1;
}

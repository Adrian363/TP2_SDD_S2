#include "cnp.h"
#include "stack.h"

             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                        cnp.c                          */
             /*            Fichier contenant les fonctions CNP        */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/


/****************************************/
/* Lexique CNP_REC:                     */ 
/* ni= entier                           */
/* pi=entier                            */ 
/* ni>=pi et pi>=0                      */
/****************************************/      

int CNP_REC(int ni, int pi){
    if(ni==pi || pi==0){
        return 1;
    }
    else{
        return CNP_REC(ni-1,pi)+CNP_REC(ni-1, pi-1);
    }
}

/****************************************/
/* Lexique CNP_ITER:                    */ 
/* ni= entier                           */
/* pi=entier                            */
/* ni>=pi et pi>=0                      */
/* state= entier, code de retour erreur */ 
/*  lors de l'empilage et dépilage      */
/* end= entier qui indique que l'on a   */
/* a fini d'exectuter tous les contextes*/
/* ret= entier, valeur de retour de CNP */
/* stack_memory= pointeur vers une pile */
/*  qui contiendra les contextes        */
/****************************************/

int CNP_ITER(int ni, int pi){
    int state=0;
    t_stack *stack_memory=initStack(10);
    int end=0;
    /*Si on mets pas ret a 1 des le debut on va retourner 0 si on on appel CNP(n,p) avec n=p*/
    int ret=0;

    while(end==0){
        while(ni!=pi && pi!=0){  
            stack(stack_memory, ni);
            stack(stack_memory, pi);
            ni=ni-1;

        }
        ret++;
        if( isEmpty(stack_memory)==0){
            unstack(stack_memory, &pi, &state);
            unstack(stack_memory, &ni, &state);
            pi=pi-1;
            ni=ni-1;
        }
        else{
            end=1;
        }
    }
    freeStack(stack_memory);
    return ret;
}
 


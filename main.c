#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include <time.h> 


int CNP(int n, int p){
    int res;
    if(n==p || p==0){
        return 1;
    }
    else{
        res=CNP(n-1,p)+CNP(n-1, p-1);
    }
}

int main(){

    tval_stack ni=5;
    tval_stack pi=3;
    int state=0;
    t_stack *stack_memory=initStack(10);
    int end=0;
    /*Si on mets pas ret a 1 des le debut on va retourner 0 si on on appel CNP(n,p) avec n=p*/
    int ret=1;
    int res_bis=0;
    double time_spent = 0.0;

    clock_t begin = clock();

    while(end==0){
        while(ni!=pi && pi>0){
            printf("OK 2\n");
            printf("%d %d \n", ni, pi);
            stack(stack_memory, ni);
            stack(stack_memory, pi);
            ni=ni-1;

        }
        if( isEmpty(stack_memory)==0){
            printf("OK 3\n");
            unstack(stack_memory, &pi, &state);
            unstack(stack_memory, &ni, &state);
            printf("+1\n");
            pi=pi-1;
            ni=ni-1;
            ret++;
        }
        else{
            end=1;
        }
    }

    clock_t end_process = clock();
    printf("%d\n", ret);
    time_spent = (double)(end_process - begin) / CLOCKS_PER_SEC;
    printf("%f secondes\n", time_spent);

    freeStack(stack_memory);

    begin = clock();
    res_bis=CNP(5,3);
    end_process = clock();
    time_spent = (double)(end_process - begin) / CLOCKS_PER_SEC;
    printf("%f secondes\n", time_spent);

    printf("%d\n", res_bis);
}

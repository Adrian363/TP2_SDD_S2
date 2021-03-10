#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"



int main(){

    tval_stack ni=3;
    tval_stack pi=2;
    int state=0;
    t_stack *stack_memory=initStack(10);
    int end=0;
    int ret=0;

    while(end==0){
        while(ni!=pi && pi!=0){
            printf("OK 2\n");
            stack(stack_memory, ni);
            stack(stack_memory, pi);
            ni=ni-1;

        }
        if( isEmpty(stack_memory)==0){
            printf("OK 3\n");
            unstack(stack_memory, &pi, &state);
            unstack(stack_memory, &ni, &state);
            pi=pi-1;
            ni=ni-1;
            ret++;
        }
        else{
            end=1;
        }
    }
    printf("%d\n", ret);


    freeStack(stack_memory);

    
}

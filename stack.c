#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int maxSize;
    int numElem;
    int *headStack;
}t_stack;

t_stack *initStack(int maxSize){
    t_stack *stack;
    int defaultAlloc=0;
    stack=malloc(sizeof(t_stack));
    if(stack!=NULL){
        stack->maxSize=maxSize;
        stack->numElem=-1;
        stack->headStack=malloc(maxSize*sizeof(int));

        if(stack->headStack==NULL){
            free(stack);
            stack=NULL;  
        }
    }
    return stack;
}

void freeStack(t_stack *head){
    free(head->headStack);
    free(head);
    head=NULL;
}

int isEmpty(t_stack *head){
    int retVal=0;
    if (head->numElem==-1){
        retVal=1;
    }
    
    return retVal;
}

int isFull(t_stack *head){
    int retVal=0;
    if(head->numElem==(head->maxSize-1)){
        retVal=1;
    }
    return retVal;
}
/* Voir en cours
void top()
*/

int stack(t_stack *head, int val){
    int state=1;

    if(isFull(head)==0){
        head->numElem+=1;
        *(head->headStack+head->numElem)=val;
        state=1;
    }

    return state;
}

void unstack(t_stack *head, int *ad_unstack_val, int *state){
    *state=1; // va rester à 1 si on ne peut pas dépiler
    if(isEmpty(head)==0){
        *ad_unstack_val=*(head->headStack+head->numElem);
        head->numElem--;
        *state=0;
    }

}
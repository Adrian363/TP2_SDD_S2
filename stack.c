#include <stdio.h>
#include <stdlib.h>
#define FORMAT "%d" 

typedef int tval_stack; 

typedef struct stack{
    int maxSize;
    int numElem;
    tval_stack *headStack;
}t_stack;




t_stack *initStack(int maxSize){
    t_stack *stack;
    stack=malloc(sizeof(t_stack));
    if(stack!=NULL){
        stack->maxSize=maxSize;
        stack->numElem=-1;
        stack->headStack=malloc(maxSize*sizeof(tval_stack));

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

    return(head->numElem==-1);
}

int isFull(t_stack *head){
    return (head->numElem==(head->maxSize-1));
    
}
/* Donne la valeur contenu dans le sommet*/

void top(t_stack *head, tval_stack *value, int *state){
    *state=1;

    if(isEmpty(head)==0){
        *value=*(head->headStack+head->numElem); 
        *state=0;   
        }
}


int stack(t_stack *head, tval_stack val){
    int state=1;

    if(isFull(head)==0){
        head->numElem+=1;
        *(head->headStack+head->numElem)=val;
        state=1;
    }

    return state;
}

void unstack(t_stack *head, tval_stack *ad_unstack_val, int *state){
    *state=1; // va rester à 1 si on ne peut pas dépiler
    if(isEmpty(head)==0){
        *ad_unstack_val=*(head->headStack+head->numElem);
        head->numElem--;
        *state=0;
    }
    else{
        printf("Stack Empty\n");
    }


}

int main(){
    tval_stack val_stack;
    int state=0;
    t_stack *stack1=initStack(5);
    stack(stack1, 3);
    unstack(stack1,&val_stack, &state);
    printf(FORMAT, val_stack);
    printf("\n");
    unstack(stack1,&val_stack, &state);
    freeStack(stack1);
}

#ifndef stack_h
#define stack_h
#include <stdio.h>
#include <stdlib.h>
#define FORMAT_S "%d \n" 


typedef int tval_stack; 

typedef struct stack{
    int maxSize;
    int numElem;
    tval_stack *headStack;
}t_stack;

t_stack *initStack(int maxSize);

void freeStack(t_stack *head);

int isEmpty(t_stack *head);

int isFull(t_stack *head);

void top(t_stack *head, tval_stack *value, int *state);

int stack(t_stack *head, tval_stack val);

void unstack(t_stack *head, tval_stack *ad_unstack_val, int *state);

#endif

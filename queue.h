#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#define FORMAT_Q "%d \n" 

typedef int tval_queue; 


typedef struct queue{
    int maxSize;
    int numElem;
    int firstElem;
    int lastElem;
    tval_queue *headStack;
}t_queue;

t_queue *initQueue(int maxSize);

void freeQueue(t_queue *head);

int isEmptyQ(t_queue *head);

int isFullQ(t_queue *head);

int add_value(t_queue *head, tval_queue val);

void get_val(t_queue *head, tval_queue *ad_val, int *state);

#endif 
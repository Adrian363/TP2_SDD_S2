#include "queue.h"

t_queue *initQueue(int maxSize){
    t_queue *queue;
    queue=malloc(sizeof(t_queue));
    if(queue!=NULL){
        queue->maxSize=maxSize;
        queue->numElem=-1;
        queue->firstElem=0;
        queue->lastElem=maxSize-1; // comme ça ça pointe sur le dernire elem
        queue->headStack=malloc(maxSize*sizeof(tval_queue));

        if(queue->headStack==NULL){
            free(queue);
            queue=NULL;  
        }
    }
    return queue;
}

void freeQueue(t_queue *head){
    free(head->headStack);
    free(head);
    head=NULL;
}

int isEmptyQ(t_queue *head){

    return (head->numElem==-1);
}

int isFullQ(t_queue *head){
    return (head->numElem==head->maxSize-1);
}


int add_value(t_queue *head, tval_queue val){
    int state=0;
    if(isFullQ(head)==0){
        head->numElem+=1;
        *(head->headStack+(head->firstElem+head->numElem)%head->maxSize)=val;
        head->lastElem+=1;
        state=1;
    }

    return state;
}


void get_val(t_queue *head, tval_queue *ad_val, int *state){
    *state=1; // va rester à 1 si on ne peut pas dépiler
    if(isEmptyQ(head)==0){
        *ad_val=*(head->headStack+(head->firstElem)%head->maxSize);
        head->numElem--;
        head->firstElem+=1;
        *state=0;
    }
}

void test_queue(int maxSize){

    printf("\n Few test on the queue \n\n");
    tval_queue value;
    int state;

    t_queue *queue=initQueue(maxSize);

    /*Try to insert more values than the maxSize*/
    for (int i=0; i<maxSize+2; i++){
        state=add_value(queue, i);
        if(state==0)
        {
            printf("Queue full ! \n");
        }

    }

    /*Get a value to free a bloc*/
    get_val(queue, &value, &state ); 
    printf("\nValue remove from the front of the queue \n\n");
    printf(FORMAT_Q, value);

    /*Add a new value in the free bloc*/
    state=add_value(queue, 6);

    /*Get all the values in the queue*/
    printf("\nValue in the queue: \n");
    for (int i=0; i<maxSize; i++){
        get_val(queue, &value, &state );
        printf(FORMAT_Q, value);
        printf("-> "); 
    }
    printf("\n\n");
    freeQueue(queue);
}



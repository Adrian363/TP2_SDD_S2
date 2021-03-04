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
    else{
        printf("Queue full ! \n");
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



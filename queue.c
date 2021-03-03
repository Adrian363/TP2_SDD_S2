#include <stdio.h>
#include <stdlib.h>


typedef struct queue{
    int maxSize;
    int numElem;
    int firstElem;
    int lastElem;
    int *headStack;
}t_queue;

t_queue *initQueue(int maxSize){
    t_queue *queue;
    int defaultAlloc=0;
    queue=malloc(sizeof(t_queue));
    if(queue!=NULL){
        queue->maxSize=maxSize;
        queue->numElem=-1;
        queue->firstElem=0;
        queue->lastElem=0;
        queue->headStack=malloc(maxSize*sizeof(int));

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

int add_value(t_queue *head, int val){
    int state=0;
    if(isFullQ(head)==0){
        *(head->headStack+(head->firstElem+head->numElem)%head->maxSize)=val;
        head->numElem+=1;
        head->lastElem+=1;
        state=1;
    }

    return state;
}

void get_val(t_queue *head, int *ad_val, int *state){
    *state=1; // va rester à 1 si on ne peut pas dépiler
    if(isEmptyQ(head)==0){
        *ad_val=*(head->headStack+(head->firstElem)%head->numElem);
        head->numElem--;
        head->firstElem+=1;
        *state=0;
    }

}

int main(){
    printf("OK");
}
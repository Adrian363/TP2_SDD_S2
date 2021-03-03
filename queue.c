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
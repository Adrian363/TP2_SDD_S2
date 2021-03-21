#include "queue.h"

/*********************************************************/
/*                   Adrian Cottais 2021                 */
/*-------------------------------------------------------*/
/*                        queue.c                        */
/*                  Traitement d'une file                */
/*                   PROGRAMME PRINCIPAL                 */
/*********************************************************/

/****************************************/
/* Lexique initQueue:                   */
/* queue: pointeur de la file           */
/* queue->maxSize: entier qui stocke    */
/*  le nb max de places dans la         */
/*  file                                */
/* queue->numElem: entier, nb élements  */
/*  déjà empilés.                       */
/* queue->firstElem: entier indiquant   */
/* la place du 1er élement              */
/* queue->lastElem: entier indiquant    */
/*  la place du dernier élement         */
/* queue->headQueue: pointeur vers la   */
/*  tête de la file                     */
/* maxSize: Entier contenant la taille  */
/*  max de la file                      */
/****************************************/

t_queue *initQueue(int maxSize)
{
    t_queue *queue;
    queue = malloc(sizeof(t_queue));
    if (queue != NULL)
    {
        queue->maxSize = maxSize;
        queue->numElem = -1;
        queue->firstElem = 0;
        queue->lastElem = maxSize - 1; // comme ça ça pointe sur le dernier elem
        queue->headQueue = malloc(maxSize * sizeof(tval_queue));

        if (queue->headQueue == NULL)
        {
            free(queue);
            queue = NULL;
        }
    }
    return queue;
}

/****************************************/
/* Lexique freeQueue:                   */
/* head: pointeur vers l'ensemble de    */
/*  la file                             */
/*  head->headQueue: pointeur vers la   */
/*   tête de la file                    */
/****************************************/


void freeQueue(t_queue *head)
{
    free(head->headQueue);
    free(head);
    head = NULL;
}

/****************************************/
/* Lexique isEmptyQ:                    */
/* head: pointeur vers l'ensemble de    */
/*  la file                             */
/*  head->numElem: entier, nb élements  */
/*  déjà dans la file.                  */
/****************************************/

int isEmptyQ(t_queue *head)
{

    return (head->numElem == -1);
}

/****************************************/
/* Lexique isFullQ:                     */
/* head: pointeur vers l'ensemble de    */
/*  la file                             */
/* head->numElem: entier, nb élements   */
/*  déjà dans la file.                  */
/* head->maxSize: entier qui stocke     */
/*  le nb max de places dans la         */
/*  file                                */
/****************************************/

int isFullQ(t_queue *head)
{
    return (head->numElem == head->maxSize - 1);
}

/****************************************/
/* Lexique add_value:                   */
/* head: pointeur vers l'ensemble de    */
/*  la file                             */
/*  val: Valeur à insérer dans la file  */
/*  state: Entier qui contiendra le code*/
/*  de retour de la fonction            */
/* head->numElem: entier, nb élements   */
/*  déjà dans la file                   */
/*  head->headQueue: pointeur vers la   */
/*   tête de la file                    */
/* head->maxSize: entier qui stocke     */
/*  le nb max de places dans la         */
/*  file                                */
/* head->firstElem: entier indiquant   */
/* la place du 1er élement              */
/****************************************/

int add_value(t_queue *head, tval_queue val)
{
    int state = 0;
    if (isFullQ(head) == 0)
    {
        head->numElem += 1;
        *(head->headQueue + (head->firstElem + head->numElem) % head->maxSize) = val;
        head->lastElem += 1;
        state = 1;
    }

    return state;
}

/****************************************/
/* Lexique get_val:                     */
/* head: pointeur vers l'ensemble de    */
/*  la pile                             */
/*  ad_val: adresse de stockage         */
/*   de la valeur défilée               */
/*  state: adresse de stockage de type  */
/*   entier qui contiendra le code de   */
/*   retour de la fonction              */
/* head->numElem: entier nb élements    */
/*  déjà empilés.                       */
/* head->headQueue: pointeur vers la    */
/*   tête de la pile                    */
/* head->firstElem: entier indiquant    */
/* la place du 1er élement              */
/* head->maxSize: entier qui stocke     */
/*  le nb max de places dans la         */
/*  file                                */
/****************************************/

void get_val(t_queue *head, tval_queue *ad_val, int *state)
{
    *state = 1; // va rester à 1 si on ne peut pas dépiler
    if (isEmptyQ(head) == 0)
    {
        *ad_val = *(head->headQueue + (head->firstElem) % head->maxSize);
        head->numElem--;
        head->firstElem += 1;
        *state = 0;
    }
}

/****************************************/
/* Lexique test_queue:                  */
/* maxSize: entier, nb de places max    */
/*  dans la file.                       */
/* state: entier qui contiendra les    */
/*  codes retours                       */
/* value: type de la file, variable     */
/*  qui servira pour la récupération des*/
/*  valeurs de la file                  */
/* queue: pointeur vers la file         */
/****************************************/

void test_queue(int maxSize)
{
    /*Vérification que l'on veut une file de plus de 0 élements*/
    if (maxSize > 0)
    {
        printf("\n Few test on the queue \n\n");
        tval_queue value;
        int state;

        t_queue *queue = initQueue(maxSize);

        /* On test la file si on insère plus de valeurs que de places*/

        for (int i = 0; i < maxSize + 2; i++)
        {
            state = add_value(queue, i);
            if (state == 0)
            {
                /* Si file pleine, on verra ce message apparaître*/
                printf("Queue full ! \n");
            }
        }

        /* Test de la fonction de récupération d'une valeur dans la file et donc libération d'une place*/
        get_val(queue, &value, &state);
        printf("\nValue remove from the front of the queue \n\n");
        printf(FORMAT_Q, value);

        /*On ajoute une nouvelle valeur dans la place libre*/
        state = add_value(queue, 6);

        /* On sort toutes les valeurs de la file et on les affichent*/
        printf("\nValue in the queue: \n");
        for (int i = 0; i < maxSize; i++)
        {
            get_val(queue, &value, &state);
            printf(FORMAT_Q, value);
            printf("-> ");
        }
        printf("\n\n");
        /* Finalement, on libère la file*/
        freeQueue(queue);
    }
    else
    {
        printf("On ne peut pas créer une file de 0 éléments ou moins \n");
    }
}

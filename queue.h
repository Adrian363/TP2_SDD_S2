#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#define FORMAT_Q "%d " 


             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                        queue.c                        */
             /*            Fichier entêtes traitement d'une file      */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/

/***************************************/
/* Definition d'un typedef qui         */
/* représente le type des donnees dans */
/* la file. Modifiable selon les       */
/* donnée.                             */
/***************************************/

typedef int tval_queue; 

/***************************************/
/* Définition de la structure qui sera */
/* utilisée pour stocker la taille de  */
/* la pile, le nombre d'éléments,      */
/* insérés, la place du premier et     */
/* dernier élément ainsi qu'un pointeur*/
/*vers le debut de cette pile          */
/***************************************/

typedef struct queue{
    int maxSize;
    int numElem;
    int firstElem;
    int lastElem;
    tval_queue *headQueue;
}t_queue;

/***************************************/
/* Fonction qui crée une file avec     */
/* comme paramètres le nombre maximal  */
/* de valeurs à stocker.               */
/***************************************/

t_queue *initQueue(int maxSize);

/***************************************/
/* Fonction qui permet de libérer la   */
/* pile ainsi que la structure qui     */
/* permet de stocker la taille max, nb */
/* d'éléments... passage de la tête de */ 
/* l'ensemble en paramètre             */
/***************************************/

void freeQueue(t_queue *head);

/***************************************/
/* Fonction qui permet de renseigner si*/
/* la file est vide ou non             */
/***************************************/
int isEmptyQ(t_queue *head);

/***************************************/
/* Fonction qui permet de renseigner si*/
/* la file est pleine ou non           */
/***************************************/

int isFullQ(t_queue *head);

/***************************************/
/* Fonction qui permet d'ajouter une   */
/* valeur apres les autres.            */
/***************************************/

int add_value(t_queue *head, tval_queue val);

/***************************************/
/* Fonction qui permet de recuperer et */
/* retirer la 1ère valeur dans la file */
/***************************************/ 

void get_val(t_queue *head, tval_queue *ad_val, int *state);

/***************************************/
/* Fonction qui permet de tester le    */
/* bon fonctionnement d'une file pour  */
/*l'initialisation, l'insertion,       */
/* la sortie d'une valeur,             */
/* la file pleine et                   */
/* la libération de la file.           */
/* Paramètre: taille de la file        */
/***************************************/

void test_queue(int maxSize);


#endif 

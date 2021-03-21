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
/* represente le type des donnees dans */
/* la file. Modifiable selon les       */
/* donnees                             */
/***************************************/

typedef int tval_queue; 

/***************************************/
/* Définition de la structure qui sera */
/* utilisee pour stocker la taille de  */
/* la pile, le nombre d'elements,      */
/* inseres, la place du premier et     */
/* dernier elenent ainsi qu'un pointeur*/
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
/* Fonction qui creer une file avec    */
/* comme parametres le nombre maximal  */
/* de valeurs a stocker.               */
/***************************************/

t_queue *initQueue(int maxSize);

/***************************************/
/* Fonction qui permet de liberer la   */
/* pile ainsi que la structure qui     */
/* permet de stocker la taille max, nb */
/* d'elements... passage de la tete de */ 
/* l'ensemble en parametre             */
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
/* retirer la 1ere valeur dans la file */
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

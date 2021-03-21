#ifndef stack_h
#define stack_h
#include <stdio.h>
#include <stdlib.h>
#define FORMAT_S "%d " 


             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                        stack.h                        */
             /*          Fichier entêtes traitement d'une pile        */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/

             
/***************************************/
/* Définition d'un typedef qui         */
/* représente le type des données dans */
/* la pile. Modifiable selon les       */
/* données                             */
/***************************************/

typedef int tval_stack; 

/***************************************/
/* Définition de la structure qui sera */
/* utilisée pour stocker la taille de  */
/* la pile, le nombre d'éléments       */
/* insérés ainsi qu'un pointeur vers le*/
/* début de cette pile                 */
/***************************************/

typedef struct stack{
    int maxSize;
    int numElem;
    tval_stack *headStack;
}t_stack;


/***************************************/
/* Fonction qui crée une pile avec     */
/* comme paramètres le nombre maximal  */
/* de valeurs à stocker.               */
/***************************************/

t_stack *initStack(int maxSize);

/***************************************/
/* Fonction qui permet de libérer la   */
/* pile ainsi que la structure qui     */
/* permet de stocker la taille max, nb */
/* d'elements. Passage de la tête de   */ 
/* l'ensemble en paramètre             */
/***************************************/


void freeStack(t_stack *head);

/***************************************/
/* Fonction qui permet de renseigner si*/
/* la pile est vide ou non             */
/***************************************/

int isEmpty(t_stack *head);

/***************************************/
/* Fonction qui permet de renseigner si*/
/* la pile est pleine ou non           */
/***************************************/

int isFull(t_stack *head);

/***************************************/
/* Fonction qui permet de recuperer    */
/* la valeur en sommet de la pile si   */
/* elle n'est pas vide sans la retirer */
/***************************************/

void top(t_stack *head, tval_stack *value, int *state);

/***************************************/
/* Fonction qui permet d'empiler une   */
/* valeur sur le sommet de la pile     */
/***************************************/

int stack(t_stack *head, tval_stack val);

/***************************************/
/* Fonction qui permet de depiler une  */
/* valeur sur le sommet de la pile     */
/***************************************/

void unstack(t_stack *head, tval_stack *ad_unstack_val, int *state);

/***************************************/
/* Fonction qui permet de tester le    */
/* bon fonctionnement d'une pile pour  */
/*l'initialisation, l'insertion,       */
/* le dépilement, la pile pleine et    */
/* la libération de la pile.           */
/* Paramètre: taille de la pile        */
/***************************************/

void test_stack(int maxSize);



#endif

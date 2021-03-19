#include "stack.h"

/*********************************************************/
/*                   Adrian Cottais 2021                 */
/*-------------------------------------------------------*/
/*                        stack.c                        */
/*                 Traitement d'une pile                 */
/*                   PROGRAMME PRINCIPAL                 */
/*********************************************************/

/****************************************/
/* Lexique initStack:                   */
/* stack: pointeur de la pile           */
/* stack->maxSize: entier qui stocke    */
/*  le nb max de places dans la         */
/*  pile                                */
/* stack->numElem: entier nb élements   */
/*  déjà empilés.                       */
/* stack->headStack: pointeur vers la   */
/*  tête de la pile                     */
/* maxSize: Entier contenant la taille  */
/*  max de la pile                      */
/****************************************/

t_stack *initStack(int maxSize)
{
    t_stack *stack;
    stack = malloc(sizeof(t_stack));
    if (stack != NULL)
    {
        stack->maxSize = maxSize;
        stack->numElem = -1;
        stack->headStack = malloc(maxSize * sizeof(tval_stack));

        if (stack->headStack == NULL)
        {
            free(stack);
            stack = NULL;
        }
    }
    return stack;
}

/****************************************/
/* Lexique freeStack:                   */
/* head: pointeur vers l'ensemble de    */
/*  la pile                             */
/*  head->headStack: pointeur vers la   */
/*   tête de la pile                    */
/****************************************/

void freeStack(t_stack *head)
{
    free(head->headStack);
    free(head);
    head = NULL;
}

/****************************************/
/* Lexique isEmpty:                     */
/* head: pointeur vers l'ensemble de    */
/*  la pile                             */
/*  head->numElem: entier nb élements   */
/*  déjà empilés.                       */
/****************************************/
int isEmpty(t_stack *head)
{

    return (head->numElem == -1);
}

/****************************************/
/* Lexique isFull:                      */
/* head: pointeur vers l'ensemble de    */
/*  la pile                             */
/* head->numElem: entier nb élements    */
/*  déjà empilés.                       */
/* head->maxSize: entier qui stocke     */
/*  le nb max de places dans la         */
/*  pile                                */
/****************************************/

int isFull(t_stack *head)
{
    return (head->numElem == (head->maxSize - 1));
}

/****************************************/
/* Lexique top:                         */
/* head: pointeur vers l'ensemble de    */
/*  la pile                             */
/*  value: Pointeur vers la variable    */
/*   de stockage du sommet de la pile   */
/*  state: pointeur vers la variable    */
/*   qui contiendra le code de retour   */
/*   de la fonction                     */
/* head->numElem: entier nb élements    */
/*  déjà empilés.                       */
/*  head->headStack: pointeur vers la   */
/*   tête de la pile                    */
/****************************************/

void top(t_stack *head, tval_stack *value, int *state)
{
    *state = 1;

    if (isEmpty(head) == 0)
    {
        *value = *(head->headStack + head->numElem);
        *state = 0;
    }
}

/****************************************/
/* Lexique stack:                       */
/* head: pointeur vers l'ensemble de    */
/*  la pile                             */
/*  val: Valeur à insérer dans la pile  */
/*  state: Entier qui contiendra le code*/
/*  de retour de la fonction            */
/* head->numElem: entier nb élements    */
/*  déjà empilés.                       */
/*  head->headStack: pointeur vers la   */
/*   tête de la pile                    */
/****************************************/

int stack(t_stack *head, tval_stack val)
{
    int state = 0;

    if (isFull(head) == 0)
    {
        head->numElem += 1;
        *(head->headStack + head->numElem) = val;
        state = 1;
    }

    return state;
}

/****************************************/
/* Lexique unstack:                     */
/* head: pointeur vers l'ensemble de    */
/*  la pile                             */
/*  ad_unstack_val: adresse de stockage */
/*   de la valeur dépilée               */
/*  state: adresse de stockage de type  */
/*   entier qui contiendra le code de   */
/*   retour de la fonction              */
/* head->numElem: entier nb élements    */
/*  déjà empilés.                       */
/* head->headStack: pointeur vers la    */
/*   tête de la pile                    */
/****************************************/

void unstack(t_stack *head, tval_stack *ad_unstack_val, int *state)
{
    *state = 1; // va rester à 1 si on ne peut pas dépiler
    if (isEmpty(head) == 0)
    {
        *ad_unstack_val = *(head->headStack + head->numElem);
        head->numElem--;
        *state = 0;
    }
}

/****************************************/
/* Lexique test_stack:                  */
/* maxSize: entier, nb de places max    */
/*  dans la pile.                       */
/* state: entier qui contriendra les    */
/*  codes retours                       */
/* value: type de la pile, variable     */
/*  qui servira pour la récupération des*/
/*  valeurs de la file                  */
/* stack_1: pointeur vers la pile       */
/****************************************/

void test_stack(int maxSize)
{

    /*Vérification l'on veut une pile de plus de 0 élements*/
    if (maxSize > 0)
    {
        printf("\nFew tests on the stack \n \n");
        tval_stack value;
        int state;
        t_stack *stack_1 = initStack(maxSize);

         /* On test la pile si on insère plus de valeurs que de places*/
        for (int i = 0; i < maxSize + 2; i++)
        {
            state = stack(stack_1, i);
            if (state == 0)
            {   
                /* Si pile pleine, on verra ce message apparaître*/
                printf("Stack full ! \n");
            }
        }

        /* Test de la fonction de récupération d'une valeur dans la pile et donc libération d'une place*/
        unstack(stack_1, &value, &state);
        printf("\nValue remove from the top of the stack \n\n");
        printf(FORMAT_S, value);
        printf("\n");

        /*On ajoute une nouvelle valeur dans la place libre*/
        state = stack(stack_1, 6);

        /* On sort toutes les valeurs de la pile et on les affichent*/
        printf("Value in the stack: \n");
        for (int i = 0; i < maxSize; i++)
        {
            unstack(stack_1, &value, &state);
            printf(FORMAT_S, value);
            printf("-> ");
        }
        printf("\n\n");
        freeStack(stack_1);
    }
    else
    {
        printf("On ne peut pas créer une pile de 0 éléments ou moins \n");
    }
}

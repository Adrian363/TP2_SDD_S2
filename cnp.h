#ifndef cnp_h
#define cnp_h

#include <stdio.h>
#include <stdlib.h>

             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                        cnp.h                          */
             /*     Fichier contenant les entêtes des fonctions CNP   */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/

/***************************************/
/* Fonction CNP_REC avec en paramètre  */
/*  ni et pi. ni>=pi et pi>=0          */
/* Fonction à dérécursifier            */
/***************************************/

int CNP_REC(int n, int p);

/***************************************/
/* Fonction CNP_ITER avec en paramètre */
/* ni et pi. ni>=pi et pi>=0           */
/* Version itérative de CNP_REC        */
/***************************************/

int CNP_ITER(int ni, int pi);


#endif

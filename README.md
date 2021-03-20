# TP2 SDD - Cottais Adrian - G22

## Objectif du TP:

Le but de ce TP est dans premier temps de créer les modules de gestion d'une pile et d'une file. Ensuite, il faut coder la fonction CNP() qui est récursive et la transformer en une fonction itérative.
En option, on peut comparer les temps d'execution des deux fonctions.

## Schéma et description des structures de données utilisées

### Structure n°1 (Contexte général):

Mise en place d'une pile de maximum n éléments. En entête de cette pile, on retrouve un bloc de 3 mots mémoires dans lesquels il y a:

- Le nombre max de place dans la pile n
- Le nombre de place prise dans la pile initialisé à -1
- Un pointeur vers le début de la pile

Mettre une photo

### Structure n°2 (Contexte général):

Mise en place d'une file de maximum n éléments. En entête de cette pile, on retrouve un bloc de 5 mots mémoires dans lesquels il y a:

- Le nombre max de place dans la file n
- Le nombre de place prise dans la pile initialisé à -1
- La place du premier élement dans la file
- La place du dernier élement dans la file
- Un pointeur vers le début de la file

Mettre une photo

Pour la dérécursification de la fonction CNP, on utilisera un pile pour stocker le contexte de n et p.

## Nature des entrées du Programme:

### Choix de n et p pour CNP:

Les 2 uniques entrées du programme sont une valeur n et une valeur p qui seront utilisée par les fonctions CNP(). Elle seront demandées à l'utilisateur par une boîte de dialogue.
Les contraintes pour ces valeurs sont:
- n>=p
- p>=0

Si les critères demandés ne sont pas respectés, un message d'erreur sera affiché.

## Détail des fichiers du programme:

### Organisation du code source:

**queue.h**: Fichier d'entêtes pour le traitement d'une file.
**queue.c**: Fichier de fonctions pour le traitement d'une file.
**stack.h**: Fichier d'entêtes pour le traitement d'une pile.
**stack.c**: Fichier de fonctions pour le traitement d'une pile.
**cnp.h**: Fichier d'entêtes pour les fonctions CNP.
**cnp.c**: Fichier de fonctions CNP.
**TP2.c**: Fichier main avec l'appel aux différentes fonctions pour tester la pile/file et l'appel aux fonctions CNP().


### Détail du Makefile:

```
    CC=gcc
    OPT= -c -ansi -pedantic -Wall
    tp2 : tp2.o cnp.o queue.o stack.o
	    $(CC) -o TP2 tp2.o cnp.o queue.o stack.o
    tp2.o : TP2.c
	    $(CC) $(OPT) TP2.c 
    cnp.o : cnp.c cnp.h
	    $(CC) $(OPT) cnp.c 
    matrix.o : queue.c queue.h
	    $(CC) $(OPT) queue.c
    linked_list.o : stack.c stack.h
	    $(CC) $(OPT) stack.c
    clair :
	    rm tp2.o basics.o matrix.o linked_list.o
    propre : clair
	    rm tp2
        
```

## Détail des fonctions

### Fonctions stack.c:

**Fonction initStack(int maxSize)**:
```
    Allocation bloc de tête de taille;
    Si bloque est alloué:
        Stockage de la taille max dans la première case;
        Mise à -1 de la seconde case;
        Allocation de la pile de taille maxSize dans la case pointeur;
        
        Si pile non allouée:
            Libérer(bloc de tête);
        Fsi
    Fsi
    
    Retour bloc de tête;
                
```

**Procédure freeStack(t_stack *head)**:
```
    Libérer pile;
    Libérer bloc de tête;
```
**Fonction isEmpty(t_stack *head)**:
```
    Retourner 1 si nb élem insérés égale à -1;
```

**Fonction isFull(t_stack *head)**:
```
    Retourner 1 si (nb elem insérés) égale à (taille max)-1;
```

**Procédure top(t_stack *head, tval_stack *value, int *state)**:
```
    Etat prend la valeur 1;
    Si la pile n'est pas vide:
        Valeur prend la valeur au sommet de la pile;
        Etat prend la valeur 0;
    Fsi
```
**Fonction stack(t_stack *head, tval_stack val)**:
```
    Etat prend la valeur 1;
    Si pile pas pleine:
        Incrementation du nb de valeurs dejà insérées de 1;
        Sommet de la pile prend la val à insérer;
        Etat prend la valeur 0;
    Fsi
    Retourner Etat;
```


**Procédure unstack(t_stack *head, tval_stack *ad_unstack_val, int *state)**:
```
    Etat prend la valeur 1;
    Si pile pas vide:
        Récupération de la valeur au sommet de la pile
        Décrementation du nb de valeurs dejà insérées de 1;
        Etat prend la valeur 0;
    Fsi
    
```

**Procédure void test_stack(int maxSize)**:
```
    Si maxSize > 0:
    
        Creation pile de taille maxSize avec initStack;
        Pour i de 0 à maxSize-1+2 
        (+2 permet de tester le fonctionnement si on met plus de valeurs que de     places dispo) 
            Appel fonction stack() avec i comme val à insérer;
            Si insertion non réussite:
                Ecrire "Pile pleine";
            Fsi
        Fin Pour 
    
        Appel de la fonction unstack() pour libérer une place au sommet;
        Affichage de la valeur récupérée;
        Appel de la fonction stack() pour rajouter une valeur au sommet;
    
        Pour i de 0 n-1:
            Appel unstack();
            Affichage valeur récupérée;
        Fin Pour
    
        Appel de freeStack() pour libérer la matrice;
    Sinon:
        Afficher "Pile de 0 éléments impossible"
    Fsi
    
```

### Fonctions queue.c:


**Fonction initQueue(int maxSize)**:
```
    Allocation bloc de tête de taille 5;
    Si bloc est alloué:
        Stockage de la taille max dans la première case;
        Mise à -1 de la seconde case;
        Mise à 0 de la troisième case;
        Mise à maxSize-1 de la quatrième case;
        Allocation de la file de taille maxSize dans la case pointeur;
        
        Si file non allouée:
            Libérer(bloc de tête);
        Fsi
    Fsi
    
    Retour bloc de tête;
```

**Procédure freeQueue(t_queue *head)**:
```
    Libérer file;
    Libérer bloc de tête;
```

**Fonction isEmptyQ(t_queue *head)**:
```
    Retourner 1 si nb élem insérés égale à -1;
```

**Fonction isFullQ(t_queue *head)**:
```
    Retourner 1 si (nb elem insérés) égale à (taille max)-1;
```

**Fonction add_value(t_queue *head, tval_queue val)**:
```
    Etat prend 0;
    Si la file est pas pleine:
        Incrementation du nb de valeurs dejà insérées de 1;
        Sommet de la file prend la val à insérer;
        Incrementation du nb de valeurs dejà insérées de 1;
        Etat prend la valeur 1;
```
**Procédure get_val(t_queue *head, tval_queue *ad_val, int *state)**:
```
    state prend la valeur 1;
    Si file pas vide:
        Récupération de la valeur au début de la file;
        Décrementation du nb de valeurs dejà insérées de 1;
        Incrémentation de la place du 1er element de 1;
        state prend la valeur 0;
    Fsi
        
```
**Procédure test_queue(int maxSize)**:
```
    Si maxSize > 0:
    
        Creation file de taille maxSize avec initStack;
        Pour i de 0 à maxSize-1+2 
        (+2 permet de tester le fonctionnement si on met plus de valeurs que de     places dispo) 
            Appel fonction add_value() avec i comme val à insérer;
            Si insertion non réussite:
                Ecrire "File pleine";
            Fsi
        Fin Pour 
    
        Appel de la fonction get_val() pour libérer dans la file;
        Affichage de la valeur récupérée;
        Appel de la fonction add_value pour rajouter une valeur dans la file;
    
        Pour i de 0 maxSize-1:
            Appel get_val();
            Affichage valeur récupérée;
        Fin Pour
    
        Appel de freeQueue() pour libérer la file;
    Sinon:
        Afficher "File de 0 éléments impossible"
    Fsi
    
```

### Fonctions cnp.c:


**Fonction CNP_REC(int n, int p)**:
```
    Si n=p ou p=0:
        retouner 1;
    Sinon:
        retourner CNP_REC(n-1, p)+CNP_REC(n-1, p-1);
    Fsi
```

Schéma des appels avec n=5 et p=3:

![](https://i.imgur.com/01ZWY6z.png)

Pour obtenir la fonction en mode itérative, il faut appliquer la méthode du cours.

![](https://i.imgur.com/2dgqnka.png)
On supprime ensuite l'appel récursif terminal en ajoutant des variables locales ni et pi et en ajoutant une boucle.

![](https://i.imgur.com/DEyYhYD.png)

Pour supprimer, l'appel récursif non terminal, on sauvegarde le contexte en empilant les valeurs de ni et pi, on décrémente de 1 ni et ajoute une boucle de retour vers le début. Cependant, on ne passe plus par la partie qui remplace l'appel récursif terminal.

![](https://i.imgur.com/s6hrXsh.png)

Pour régler ce problème, quand on a fini d'éxecuter les appels récursifs terminaux, c'est à dire quand pi=ni ou pi=0, on va alors vérifier si la pile est vide ou non. On ajoute +1 à la variable de retour.
Si elle est non vide, on va dépiler le contexte et décrémenter ni et pi de 1 et recommence le cycle. 
Si la pile est vide, alors toutes les éxecutions sont finies et on retourne la variable de retour contenant le résultat de la fonction CNP.

![](https://i.imgur.com/B0osZNb.png)

**Fonction CNP_ITER(int ni, int pi)**
```
    Initialisation d'une pile de N places (10 pour CNP(5,3) suffisent);
    Variable fin prend 0;
    Variable ret prend 0;
    
    Tant que fin différent de 1:
        Tant que ni!=pi et pi!0:
            Empiler ni et pi;
            Décrémenter de 1 ni;
        Fin tant que
        Incrémenter ret de 1;
        Si pile non vide:
            Dépiler pi et ni;
            Décrementer ni et pi de 1;
        Sinon:
            fin prend la valeur 1;
        Fsi
    Fin tant que
    Libérer pile;
    Retourner ret;
            
``` 

### Detail TP2.c (main):

```
    
```

## Tests 

### Tests sur les fonctions de la pile:

Comme détaillé plus haut, la procédure test_stack() permet de tester toutes les fonctions créees pour la pile.

Lorsqu'elle est appelée dans le main, il faut préciser en paramètre le nombre de places souhaitées dans la pile. 
Cette fonction va permettre d'insérer des élements, même plus que prévu pour voir si les messages d'erreurs fonctionnent correctement, de retirer une valeur au sommet et d'en rajouter une pour voir s'il y a n'y a pas de problèmes d'insertion. Enfin, on dépile toutes les valeurs et on les affichent puis on fini par libérer la pile.

Si on choisi un nombre de places n>0(exemple:8):

**Appel de la fonction dans le main:**
```
    test_stack(8);
```
**Résultats:**
```
    Few tests on the stack 
 
    Stack full ! 
    Stack full ! 

    Value remove from the top of the stack 

    7 
    Value in the stack: 
    6 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> 
```

Explications: 
On essaie d'insérer n+2 valeurs dans la pile donc on reçoit 2 messages d'erreurs "Stack full ! " car ces 2 valeurs n'ont pas pu être insérées faute de place.

Ensuite on récupère la valeur au sommet qui est donc "7" et qui correspond bien à la 8ème valeur dans la pile.
Ensuite la valeur 6 est rajoutée au sommet et on dépile tous les éléments de la pile ce qui donne: "6 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 ->".

Enfin, avec valgrind, on peut voir que tous les blocs mémoires alloués ont été libérés.

**Mettre photo**

On peut refaire le test avec n=20 par exemple:

```
    test_stack(20);
```
#### Résultats:
```
    Few tests on the stack 
 
    Stack full ! 
    Stack full ! 

    Value remove from the top of the stack 

    19 
    Value in the stack: 
    6 -> 18 -> 17 -> 16 -> 15 -> 14 -> 13 -> 12 -> 11 -> 10 -> 9 -> 8 -> 7  -> 6 -> 5 -> 4 -> 
    3 -> 2 -> 1 -> 0 ->
```

 **Mettre photo valgrind**
 
 Si on veut tester avec un nombre de place n=0 ou n<0:
 
 ```
     test_stack(0);
     test_stack(-2);
 ```
**Résultats:**
 
````
     On ne peut pas créer une pile de 0 éléments ou moins 
    On ne peut pas créer une pile de 0 éléments ou moins
```` 
On obtient bien les 2 messages d'erreurs nous indiquant que l'on ne peut pas créer une file avec n<=0 éléments.

### Tests sur les fonctions de la file:

Comme détaillé plus haut, la procédure test_queue() permet de tester toutes les fonctions créees pour la file.

Lorsqu'elle est appelée dans le main, il faut préciser en paramètre le nombre de places souhaitées. 
Cette fonction va permettre d'insérer des élements, même plus que prévu pour voir si les messages d'erreurs fonctionnent correctement, de retirer une valeur en début de file et d'en rajouter une dans la place libérée. Enfin, on récupère toutes les valeurs et on les affichent puis on fini par libérer la file.

Si on choisi un nombre de places n>0(exemple:8):

**Appel de la fonction dans le main:**

 ```
     test_queue(8);
 ```

#### Résultats:
 
````
    Few tests on the queue 

    Queue full ! 
    Queue full ! 

    Value remove from the front of the queue 

    0 
    Value in the queue: 
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 6 -> 
````
**Explications:** 

On essaie d'insérer n+2 valeurs dans la file donc on reçoit 2 messages d'erreurs "Queue full ! " car ces 2 valeurs n'ont pas pu être insérées faute de place.

Ensuite on récupère la valeur en tête de file qui est donc "0" et qui correspond bien à la 1ère valeur dans la file.
Ensuite la valeur 6 est rajoutée en fin de file et on récupère tous les éléments de la file ce qui donne: "1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 6 ->".

Enfin, avec valgrind, on peut voir que tous les blocs mémoires alloués ont été libérés.

**Mettre photo valgrind**

On peut refaire le test avec n=20 par exemple:

```
    test_queue(20);
```

** Résultats:**
```
    Few test on the queue 

    Queue full ! 
    Queue full ! 

    Value remove from the front of the queue 

    0 
    Value in the queue: 
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> 13 -> 14 -> 15 
    -> 16 -> 17 -> 18 -> 19 -> 6 -> 
```

**Mettre photo valgrind**
 
 Si on veut tester avec un nombre de place n=0 ou n<0:
 
 ```
     test_queue(0);
     test_queue(-2);
 ```
 #### Résultats:
 
````
     On ne peut pas créer une file de 0 éléments ou moins 
    On ne peut pas créer une file de 0 éléments ou moins
```` 
On obtient bien les 2 messages d'erreurs nous indiquant que l'on ne peut pas créer une file avec n<=0 éléments.


### Tests sur les fonctions CNP:

Pour tester les fonctions CNP, les seuls tests que l'on peut faire sont:

- Tester si n < p
- Tester si n=p dès le premier appel
- Tester si n=val et p=0 dès le premier appel
- Tester avec les valeurs n=5 et p=3 et voir si l'on obtient bien le même résultat que la trace d'éxecution.
- Tester avec des valeurs négatives.

Les valeurs de n et p sont à renseigner dans le terminal lorsqu'elles ont demandées.

Les variables res_rec et res_iter permettent de stocker respectivement les valeurs des fonctions CNP.

**Avec n<p**

Appel des fonctions avec n=3 et p=5:

```
    res_rec=CNP_REC(3, 5);
    res_iter=CNP_ITER(3,5);
```

**Résultat**:

Le message suivant est affiché dans le terminal:
```
    N et P ne correspondent pas aux criteres.
```
En effet, n doit être supérieur ou égal à p ce qui n'est pas le cas ici.

**Remarque:** Ce message est affiché grâce au main et non au fonction CNP qui sont supposées être appelées avec des valeurs correctes. La vérification est donc faite par le main avant d'appeler les fonctions.


**Avec n=p dès le premier appel:**

Appel des fonctions avec n=1 et p=1:

```
    res_rec=CNP_REC(1, 1);
    res_iter=CNP_ITER(1,1);
```

**Résultats:**
```
    Temps de process: 0.000003 secondes
    Resultat par la fonction recursive est 1

    Temps de process: 0.000002 secondes
    Resultat par la fonction itérative est  1
```

Le résultat obtenu par les 2 fonctions est bien 1 car comme n=p, on retourne directement 1 avec la fonction récursive. Pour la fonction itérative on pas besoin d'empiler/dépiler le contexte, la variable de retour est mise à 1 directement et est retournée.

Si on essaie avec des plus grandes valeurs de n et de p:

```
    res_rec=CNP_REC(20, 20);
    res_iter=CNP_ITER(20,20);
```

**Résultats:**
```
    Temps de process: 0.000002 secondes
    Resultat par la fonction recursive est 1

    Temps de process: 0.000001 secondes
    Resultat par la fonction itérative est  1
```
On obtient bien le même résultat par les 2 fonctions.

Remarque: Si on n et p très grand, il se peut que la version itérative ne fonctionne pas correctement car il y aura pas assez de place pour stocker tous les contextes. Pour cela, au lieu de créer une pile de 10 places, il faut augmenter ce nombre.

**Avec n=val et p=0 dès le premier appel**:

```
    res_rec=CNP_REC(2, 0);
    res_iter=CNP_ITER(2,0);
```

**Résultats:**
```
    Temps de process: 0.000003 secondes
    Resultat par la fonction recursive est 1

    Temps de process: 0.000001 secondes
    Resultat par la fonction itérative est  1
```

On se retrouve dans un cas similaire à celui d'avant, comme p=0 alors la fonction récursive retourne directement 1. De même, la fonction itérative n'a pas besoin d'empiler/dépiler les contextes et retourne directement 1.

**Avec les valeurs n=5 et p=3**:

```
    res_rec=CNP_REC(5, 3);
    res_iter=CNP_ITER(5,3);
```
**Résultats**

```
    Temps de process: 0.000003 secondes
    Resultat par la fonction recursive est 10

    Temps de process: 0.000002 secondes
    Resultat par la fonction itérative est  10
```

D'après les résultats des 2 fonctions, on obtient bien la même valeur que par le schéma d'éxecution fait plus haut.

**Avec n et p négatifs:**

Dans le main, la condition pour pouvoir éxecuter les fonctions CNP est la suivante:
```
 if (ni>=pi && pi>=0)...
```

Dans cette condition, il faut que p soit supérieur ou égal à 0 et n>p. Donc obligatoirement n supérieur ou égal à 0 aussi.

Si n et p négatifs, le message suivant est affiché:
```
    N et P ne correspondent pas aux criteres.
```
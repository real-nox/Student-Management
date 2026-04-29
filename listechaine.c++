#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int num;
    struct Noeud *suivant;
} noeud;

void Affichage(noeud *);
void Ajout_fin(noeud **);
void Ajout_debut(noeud **);

main()
{
    noeud *liste = NULL;
    Ajout_fin(&liste);
    Ajout_fin(&liste);
    /*Ajout_debut(&liste);
    Ajout_debut(&liste);*/
    Affichage(liste);
}

void Affichage(noeud *l)
{
    noeud *tmp = l;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->num);
        tmp = tmp->suivant;
    }
}

void Ajout_fin(noeud **l)
{
    noeud *n = (noeud *)malloc(sizeof(noeud));
    printf("Entrer un nombre n:\t");
    scanf("%d", &(n->num));
    n->suivant = NULL;

    if (*l == NULL)
    {
        printf("here");
        *l = n;
        return;
    }
    else
    {
        noeud *tmp = *l;
        while (tmp->suivant != NULL)
        {
            printf("%h", tmp->suivant);
            tmp = tmp->suivant;
        }
        tmp->suivant = n;
        return;
    }
}

void Ajout_debut(noeud **l) {
    if (*l == NULL) {
        noeud *n = (noeud *) malloc(sizeof(noeud));
        n->suivant = NULL;
        printf("Entrer num :\t");
        scanf("%d", &(n->num));
        *l = n;
    } else {
        noeud *n = (noeud *) malloc(sizeof(noeud));
        n->suivant = *l;
        printf("Entrer num :\t");
        scanf("%d", &(n->num));
        *l = n;
    }
    return;
}
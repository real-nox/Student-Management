#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int num;
    struct Noeud *suivant;
} noeud;

void Affichage(noeud *);
int GetNumNoeud(noeud *);

void Ajout_fin(int, noeud **);
void Ajout_milieu(int, noeud **, int);
void Ajout_debut(int, noeud **);

main()
{
    noeud *liste = NULL;
    Ajout_fin(100, &liste);
    Ajout_fin(200, &liste);
    Ajout_fin(300, &liste);
    Ajout_fin(400, &liste);
    /*Ajout_debut(&liste);
    Ajout_debut(&liste);*/
    Affichage(liste);

    printf("\n");
    Ajout_milieu(250, &liste, 3);
    Affichage(liste);
    Ajout_milieu(5900, &liste, 6);
    printf("\n");
    Ajout_milieu(0, &liste, 0);
    Ajout_milieu(50, &liste, 1);
    Affichage(liste);
    Ajout_milieu(25, &liste, -1);
    Affichage(liste);
}

void Affichage(noeud *l)
{
    noeud *tmp = l;
    while (tmp != NULL)
    {
        printf("%d\t", tmp->num);
        tmp = tmp->suivant;
    }
}

int GetNumNoeud(noeud *l)
{
    int dim = 0;

    noeud *tmp = l;
    while (tmp != NULL)
    {
        tmp = tmp->suivant;
        dim++;
    }

    return dim;
}

void Ajout_debut(int nbr, noeud **l)
{
    noeud *n = (noeud *)malloc(sizeof(noeud));
    if (n != NULL)
    {
        n->num = nbr;
        n->suivant = *l;
        *l = n;
    }
}

void Ajout_milieu(int nbr, noeud **l, int pos)
{
    int dim = GetNumNoeud(*l);

    if (dim == 0 || pos == 0)
    {
        Ajout_debut(nbr, l);
    }
    else if (pos > 0 && pos <= dim)
    {
        noeud *n = (noeud *)malloc(sizeof(noeud));
        if (n != NULL)
        {
            n->num = nbr;

            if (*l == NULL)
                *l = n;

            else
            {
                noeud *tmp = *l;
                for (int i = 1; i < pos - 1; i++)
                {
                    if (tmp->suivant != NULL)
                    {
                        tmp = tmp->suivant;
                    }
                }

                n->suivant = tmp->suivant;
                tmp->suivant = n;
            }
        }
    }
    else if (pos == dim + 1)
    {
        Ajout_fin(nbr, l);
    }
    else
    {
        printf("\nL'emplacement n'existe pas! pour la position %d\n", dim);
    }
}

void Ajout_fin(int nbr, noeud **l)
{
    noeud *n = (noeud *)malloc(sizeof(noeud));
    if (n != NULL)
    {
        n->num = nbr;
        n->suivant = NULL;

        if (*l == NULL)
            *l = n;
        else
        {
            noeud *tmp = *l;
            while (tmp->suivant != NULL)
                tmp = tmp->suivant;
            tmp->suivant = n;
        }
    }
}
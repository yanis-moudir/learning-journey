#include<stdio.h>
#include<stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t{
int donnee;
cellule_t *suivant;
};
/*cellule_t *Creer_cellule(int d)
{
    cellule_t *el;
    el=malloc(sizeof(cellule_t));
    el->donnee=d;
    el->suivant=NULL;
    return el;*/
cellule_t* Creer_cellule(int d) 
{
    cellule_t *nouvelle = (cellule_t*)malloc(sizeof(cellule_t));  // Allocation mémoire
    if (nouvelle == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
        nouvelle->donnee = d;  // Initialisation de la donnée
        nouvelle->suivant = NULL;  // Pas de cellule suivante
        return nouvelle;
}
void Afficher_liste_int(cellule_t *liste){
    /* Affiche les champs donnee des elements de la liste */
    cellule_t *cell = liste;
    while (cell != NULL) {
    printf("%d ", cell->donnee);
    cell = cell->suivant;
    }
    printf("\n");
    }
    int main() {
    cellule_t *nCell1=NULL, *nCell2=NULL, *nCell3=NULL;
    nCell1 = Creer_cellule(1);
    nCell2 = Creer_cellule(2);
    nCell3 = Creer_cellule(3);
    /* Breakpoint 1 ICI, Dessiner la memoire, tas et pile*/
    nCell1->suivant = nCell2;
    nCell2->suivant = nCell3;
    /* Breakpoint 2 ICI, Dessiner la memoire, tas et pile*/
    /* Afficher la liste en partant de chaque variable, definir la tete et la queue */
    Afficher_liste_int(nCell1);
    return 0;
    /* cellule_t *tete = Creer_cellule(1);  // Tête de liste
    tete->suivant = Creer_cellule(2);    // Ajout de la 2e cellule
    tete->suivant->suivant = Creer_cellule(3);  // Ajout de la 3e cellule

    Afficher_liste_int(tete);  // Affiche "1 2 3"*/
    }
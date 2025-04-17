#include<stdio.h>
#include<stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t {
    int donnee;
    cellule_t *suivant;
};

int listes_identiques(cellule_t *liste1, cellule_t *liste2) {
    cellule_t *c1 = liste1;
    cellule_t *c2 = liste2;

    while (c1 != NULL && c2 != NULL) {
        if (c1->donnee != c2->donnee) {
            return 0;  // Éléments différents
        }
        c1 = c1->suivant;
        c2 = c2->suivant;
    }

    // Si les deux listes sont épuisées en même temps
    return (c1 == NULL && c2 == NULL);
}
int est_incluse(cellule_t *liste1, cellule_t *liste2) {
    cellule_t *c1 = liste1;
    cellule_t *c2 = liste2;
    while (c1 != NULL && c2 != NULL) {
        if (c1->donnee < c2->donnee) {
            return 0;  // Élément de liste1 absent dans liste2
        } else if (c1->donnee == c2->donnee) {
            c1 = c1->suivant;  // Élément trouvé, passe au suivant dans liste1
        }
        c2 = c2->suivant;  // Continue dans liste2 dans tous les cas
    }

    // Si liste1 est entièrement parcourue, elle est incluse
    return (c1 == NULL);
}



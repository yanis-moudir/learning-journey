#include<stdio.h>
#include<stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t{
int donnee;
cellule_t *suivant;
};
int len(cellule_t *cell)
{
    cellule_t *cel = cell;
    int r=0;
    while(cel!=NULL)
    {
        r++;
        cel=cel->suivant;
    }
    return r;
}
int existe(cellule_t *liste, int val) {
    cellule_t *current = liste;
    while (current != NULL) {
        if (current->donnee == val) {
            return 1;  // Valeur trouvée
        }
        current = current->suivant;
    }
    return 0;  // Valeur absente
}
cellule_t* Renvoyer_element_debut(cellule_t *liste, int val) {
    cellule_t *current = liste;
    while (current != NULL) {
        if (current->donnee == val) {
            return current;  // Retourne le premier élément trouvé
        }//current est un ponteur donc quand on demande une fonction qui return un pointeur il faut returner le nom du struct 
        current = current->suivant;
    }
    return NULL;  // Non trouvé
}
/*cellule_t* Renvoyer_dernier_debut(cellule_t *liste, int val) {
    cellule_t *current = liste;
    while (current != NULL) {
        if (current->donnee == val && current->suivant==NULL) {
            return current;  // Retourne le premier élément trouvé
        }//current est un ponteur donc quand on demande une fonction qui return un pointeur il faut returner le nom du struct 
        current = current->suivant;
    }
    return NULL;  // Non trouvé
}*/
//la bon reponse est d initialiser une variable on on la modifie jusqua arivver a la dernier elemnt 
cellule_t* Renvoyer_element_fin(cellule_t *liste, int val) {
    cellule_t *last = NULL;
    cellule_t *current = liste;
    while (current != NULL) {
        if (current->donnee == val) {
            last = current;  // Mise à jour de la dernière occurrence
        }
        current = current->suivant;
    }
    return last;
}
cellule_t* Renvoyer_dernier_element(cellule_t *liste) {
    if (liste == NULL) return NULL;  // Liste vide

    cellule_t *current = liste;
    while (current->suivant != NULL) {  // S'arrête au dernier élément
        current = current->suivant;
    }
    return current;
}
void Modifier_element(int val, int pos, cellule_t *liste) {
    cellule_t *current = liste;
    int i = 0;
    while (current != NULL && i < pos) {
        current = current->suivant;
        i++;
    }
    if (current != NULL) {  // Si la position existe
        current->donnee = val;
    }
}


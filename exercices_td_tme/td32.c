#include<stdio.h>
#include<stdlib.h>
typedef struct _cellule_t cellule_t;
struct _cellule_t{
int donnee;
cellule_t *suivant;
};
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
cellule_t* Liberer_liste(cellule_t* liste)
{
    cellule_t*tmp;
    while(liste!=NULL)
    {
        tmp=liste;
        liste=liste->suivant;
        free(tmp);
    }
    return NULL ;
}
/*cellule_t* Supprimer_en_pos(int pos, cellule_t *liste)
{
    cellule_t* precedent = NULL;
    cellule_t* courant = liste;
    int compteur = 0;
    
    // Parcours jusqu'à la position souhaitée ou fin de liste
    while (courant != NULL && compteur < pos) {
        precedent = courant;
        courant = courant->suivant;
        compteur++;
    }
    free(precedent);
}*/
cellule_t* Supprimer_en_pos(int pos, cellule_t *liste) {
    // Cas spécial: liste vide ou position négative
    if (liste == NULL || pos < 0) {
        return liste;
    }
    
    // Cas spécial: suppression en tête
    if (pos == 0) {
        cellule_t* new_head = liste->suivant;
        free(liste);
        return new_head;
    }
    
    cellule_t* precedent = NULL;
    cellule_t* courant = liste;
    int compteur = 0;
    
    // Parcours jusqu'à la position souhaitée
    while (courant != NULL && compteur < pos) {
        precedent = courant;
        courant = courant->suivant;
        compteur++;
    }
    
    // Si on a trouvé l'élément à supprimer
    if (courant != NULL) {
        precedent->suivant = courant->suivant;
        free(courant);
    }
    
    return liste; // Retourne la tête de liste (peut avoir changé si suppression en tête)
}

//td33.c
cellule_t* filtre_pair(cellule_t* liste) {
    cellule_t* courant = liste;
    cellule_t* precedent = NULL;
    cellule_t* tmp;
    
    while (courant != NULL) {
        if (courant->donnee % 2 == 0) { // Si l'élément est pair
            if (precedent == NULL) { // Cas de suppression en tête
                tmp = courant;
                courant = courant->suivant;
                liste = courant; // Mise à jour de la tête de liste
                free(tmp);
            } else { // Cas de suppression au milieu ou fin
                tmp = courant;
                precedent->suivant = courant->suivant;
                courant = courant->suivant;
                free(tmp);
            }
        } else { // Élément impair, on continue
            precedent = courant;
            courant = courant->suivant;
        }
    }
    
    return liste;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct _cellule_t cellule_t;
struct _cellule_t{
int donnee;
cellule_t *suivant;
};
cellule_t* Renvoyer_element_debut_rec(int val, cellule_t*liste)
{
    if (liste->donnee==val){return liste;}
    if (liste->suivant==NULL){return NULL ;}
    return Renvoyer_element_debut_rec(val,liste->suivant);
}
cellule_t *Inserer_fin_rec(int d, cellule_t *liste)
{
    cellule_t* new=maaloc(sizeof(cellule_t));
    new->donnee=d;
    new->suivant=NULL;
    if(liste==NULL){return new;}// cas de liste vide 
    if(liste->suivant==NULL)// donc on est a la fin de la liste 
    {
        liste=new;
        return liste;
    }
    return Inserer_fin_rec(d,liste->suivant);//on avance au prochain 
}
/*
cellule_t* Inserer_fin_rec(int d, cellule_t* liste) {
    if (liste == NULL) {
        cellule_t* nouveau = malloc(sizeof(cellule_t));  // Création cellule
        nouveau->donnee = d;
        nouveau->suivant = NULL;
        return nouveau; // La liste était vide → nouveau devient la tête
    }

    // Sinon, on continue jusqu'à la fin
    liste->suivant = Inserer_fin_rec(d, liste->suivant);
    return liste; // On relie le reste et on remonte le pointeur tête
}
*/
/*un autre corrigé 
cellule_t *Inserer_fin_rec(int d, cellule_t *liste) {
    cellule_t* new = malloc(sizeof(cellule_t)); // allocation correcte
    new->donnee = d;
    new->suivant = NULL;

    // Cas de liste vide → on retourne juste le nouveau
    if (liste == NULL) return new;

    // Cas où on est à la dernière cellule
    if (liste->suivant == NULL) {
        liste->suivant = new;  // On attache la nouvelle cellule à la fin
        return liste;          // On retourne la tête (inchangée)
    }

    // Appel récursif : on continue jusqu’à la fin
    liste->suivant = Inserer_fin_rec(d, liste->suivant);
    return liste;
}
 */
cellule_t* Supprimer_en_pos_rec(int pos, cellule_t* liste) {
    if (liste == NULL) return NULL;          // Liste vide → rien à faire

    if (pos == 0) {
        cellule_t* temp = liste->suivant;    // On saute la cellule courante
        free(liste);                         // On libère la mémoire
        return temp;                         // Nouvelle tête
    }

    // On continue en décrémentant la position
    liste->suivant = Supprimer_en_pos_rec(pos - 1, liste->suivant);
    return liste;
}

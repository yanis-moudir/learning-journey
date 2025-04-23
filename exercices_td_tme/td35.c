#include<stdio.h>
#include<stdlib.h>
typedef struct _cellule_t cellule_t;
struct _cellule_t{
int donnee;
cellule_t *suivant;
};
cellule_t* Inserer_tete(int d, cellule_t* liste) {
    cellule_t* nouvelle = Creer_cellule(d); // Crée une nouvelle cellule avec la donnée d
    nouvelle->suivant = liste; // La nouvelle cellule pointe vers l'ancienne tête
    return nouvelle; // Retourne la nouvelle tête de liste
}
cellule_t *Creer_liste_positifs(cellule_t *liste)
{
    cellule_t *new=NULL;
    while(liste!=NULL)
    {
        if (liste->donnee >0)
        {
            Inserer_tete(liste->donnee,new);
        }
        liste=liste->suivant;
    }
    return new;

}
cellule_t *Creer_liste_positifs_rec(cellule_t *liste)
{
    if (liste == NULL) return NULL;
    cellule_t* suite = Creer_liste_positifs_rec(liste->suivant);

    if (liste->donnee > 0) {
        return Inserer_tete(suite, liste->donnee);
    } else {
        return suite;
    }
}
cellule_t* Garder_positifs(cellule_t* liste) {
    // Si la liste est vide, on retourne directement NULL
    if (liste == NULL) return NULL;

    // 🔁 Supprimer les éléments non positifs qui sont en tête de la liste
    while (liste != NULL && liste->donnee <= 0) {
        cellule_t* temp = liste;     // On garde le pointeur sur la cellule à supprimer
        liste = liste->suivant;      // On avance le pointeur de tête vers le suivant
        free(temp);                  // On libère la mémoire de l’ancienne tête
    }

    // À ce stade, soit la liste est vide, soit elle commence par un élément strictement positif
    cellule_t* courant = liste;      // On crée un pointeur pour parcourir le reste de la liste

    // 🔁 Parcours du reste de la liste
    while (courant != NULL && courant->suivant != NULL) {
        // Si l’élément suivant n’est pas strictement positif
        if (courant->suivant->donnee <= 0) {
            cellule_t* temp = courant->suivant;   // On garde l’élément à supprimer
            courant->suivant = temp->suivant;     // On saute cet élément dans la chaîne
            free(temp);                            // On libère sa mémoire
        } else {
            courant = courant->suivant;           // Sinon on avance simplement
        }
    }

    return liste; // On retourne la nouvelle tête de la liste (modifiée ou pas)
}

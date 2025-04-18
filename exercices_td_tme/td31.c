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
/*cellule_t *Insere_tete(cellule_t *liste,int d)
{
    cellule_t *tete=malloc(sizeof(cellule_t));
    tete=Creer_cellule(d);
    liste->donnee=tete;
    liste=liste->suivant;
    return liste;
    
}*/
//il faudrer creer une novelle liste qui commence par l elemnt creer puis aprés il ya cette liste 
cellule_t* Inserer_tete(int d, cellule_t* liste) {
    cellule_t* nouvelle = Creer_cellule(d); // Crée une nouvelle cellule avec la donnée d
    nouvelle->suivant = liste; // La nouvelle cellule pointe vers l'ancienne tête
    return nouvelle; // Retourne la nouvelle tête de liste
}
/*cellule_t*Inserer_fin_it(int d,cellule_t*liste)
{
    cellule_t* nouvelle=Creer_cellule(d);
    while(liste!=NULL)
    {
        liste=liste->suivant;
    }
    liste->suivant=nouvelle;
    return liste ;  
}*/
cellule_t* Inserer_fin_it(int d, cellule_t* liste) {
    cellule_t* nouvelle = Creer_cellule(d);
    
    // Cas spécial: liste vide
    if (liste == NULL) {
        return nouvelle;
    }
    
    // Parcours jusqu'à la fin de la liste
    cellule_t* courant = liste;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    // Ajoute la nouvelle cellule à la fin
    courant->suivant = nouvelle;
    return liste;
}
//vaut mieux creer un current que travailler diret avec la rgumende la fonction 
/*Inserer_en_pos(int d, int pos, cellule_t *liste)
{
    cellule_t *element=Creer_cellule(d);
    int i=0;
    cellule_t* courant = liste;
    while(i<pos)
    {
        courant=courant->suivant;
        i++;
    }
    courant->suivant=element;
    courant->suivant->suivant=courant;
    while(courant!=NULL)
    {
        courant=courant->suivant;
    }

    return courant;
}*/
cellule_t* Inserer_en_pos(int d, int pos, cellule_t* liste)
{
    cellule_t* nouvelle = Creer_cellule(d);
    
    // Cas spécial: insertion en tête ou liste vide
    if (pos == 0 || liste == NULL) {
        nouvelle->suivant = liste;
        return nouvelle;
    }
    
    cellule_t* precedent = NULL;
    cellule_t* courant = liste;
    int compteur = 0;
    
    // Parcours jusqu'à la position souhaitée ou fin de liste
    while (courant != NULL && compteur < pos) {
        precedent = courant;
        courant = courant->suivant;
        compteur++;
    }
    // apres cette boucle on arive on elemnt de pos pos qui sera enrigistre en precedenat et le courant c'est l
    // elemnt en pos pos +1
    
    // Insertion de la nouvelle cellule
    precedent->suivant = nouvelle;
    nouvelle->suivant = courant;//on continue le reste de la liste 
    
    return liste;
}
int main() {
    cellule_t *tete = NULL;
    int i;
    
    // Test insertion en tête
    for(i = 0; i < 5; i++) {
        tete = Inserer_tete(i, tete);
    }
    Afficher_liste_int(tete); // Doit afficher 4 3 2 1 0
    
    // Test insertion en fin
    for(i = 5; i < 10; i++) {
        tete = Inserer_fin_it(i, tete);
    }
    Afficher_liste_int(tete); // Doit afficher 4 3 2 1 0 5 6 7 8 9
    
    // Test insertion en position
    tete = Inserer_en_pos(-1, 2, tete); // Insertion au milieu
    Afficher_liste_int(tete); // Doit afficher 4 3 -1 2 1 0 5 6 7 8 9
    
    tete = Inserer_en_pos(-2, 0, tete); // Insertion en tête
    Afficher_liste_int(tete); // Doit afficher -2 4 3 -1 2 1 0 5 6 7 8 9
    
    tete = Inserer_en_pos(-3, 20, tete); // Insertion en fin (position > taille)
    Afficher_liste_int(tete); // Doit afficher -2 4 3 -1 2 1 0 5 6 7 8 9 -3
    
    // Test liste vide
    cellule_t *vide = NULL;
    vide = Inserer_en_pos(42, 3, vide); // Insertion dans liste vide
    Afficher_liste_int(vide); // Doit afficher 42
    
    return 0;
}
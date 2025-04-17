#include <stdio.h>
#include <stdlib.h>
#include "listes_entiers.h"

cellule_t * creerListe(int n) {
/* cree une liste de n entiers saisi par l'utilisateur
  renvoie l'adresse du premier element de la liste */
  int i;
  int val;
  cellule_t *tete=NULL;
  cellule_t *ptr;
  
  printf("Saisie des %d elements de la liste\n",n);
  for (i=0; i < n; i++) {
    printf("Element %d :",i+1);
    scanf("%d",&val);
    ptr=malloc(sizeof(cellule_t));
    ptr->donnee = val;
    ptr->suivant = tete;
    tete = ptr;
  }
  return tete;
}
int nb_occurences(int val, cellule_t *liste)
{
    cellule_t *el=liste;
    el=malloc(sizeof(cellule_t));
    int occur=0;
    while(el!=NULL)
    {
        if( el->donnee==val){occur++;}
        el=el->suivant;
    }
    return occur;
}
int tous_plus_grand(int val, cellule_t *liste)
{
    while(liste!=NULL)
    {
        if(liste->donnee<val){return 0;}
        liste=liste->suivant;
    }
    return 1;
}

   /* int max=liste->donnee;
    while(liste!=NULL)
    {
        if(liste->donnee>max){max=liste->donnee;}
        liste=liste->suivant;
    }
    while(liste!=NULL)
    {
        if(liste->donnee==max){return liste;}
    }
}*/
cellule_t* Maximum(cellule_t *liste)
{
if (liste == NULL) return NULL; // si la liste est vide on retourne NULL
cellule_t *max = liste; // on initialise max avec la première cellule
liste = liste->suivant; // on passe à la suivante
while (liste != NULL) { // tant qu’on n’est pas à la fin
  if (liste->donnee > max->donnee) // si on trouve une plus grande valeur
    max = liste; // on met à jour le max
  liste = liste->suivant; // on avance
}
return max; // on retourne le pointeur vers le max
}
/*int Renvoyer_val_element_pos(int pos, cellule_t* liste)
{
    if (liste == NULL) return NULL;
    int i=0;
    while(liste!=NULL)
    {
        if(i==pos){return liste->donnee;}
        liste=liste->suivant;
        i++;
    }

}*/
int Renvoyer_val_element_pos(int pos, cellule_t* liste) {
    int i = 0; // compteur de position
    while (i < pos) { // tant qu’on n’est pas arrivé à la position
      liste = liste->suivant; // on avance
      i++; // on incrémente
    }
    return liste->donnee; // on retourne la valeur du champ donnee
  }
  //il a utiliser cette methode car pour la premiere ca donne une boucle infini ou bien qlq chose de ce sense
  
  
cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2)
{
    if(liste1==NULL){return liste2;}
    else if (liste2==NULL){return liste1;}
    else if (liste1==NULL && liste2==NULL){return NULL;}
    cellule_t *tmp = liste1; // pointeur temporaire pour parcourir liste1
    while (tmp->suivant != NULL) { // on va jusqu’au dernier élément de liste1
      tmp = tmp->suivant; // on avance
    }
    tmp->suivant = liste2; // on relie la fin de liste1 au début de liste2
    return liste1; // on retourne la tête de liste1 (modifiée)
}
int nb_maximum(cellule_t *liste) {
    if (liste == NULL) return 0; // si vide, 0 occurrences
  
    int max = liste->donnee; // on initialise le max
    int count = 1; // on commence le compteur à 1
    liste = liste->suivant; // on passe au suivant
  
    while (liste != NULL) { // on parcourt la liste
      if (liste->donnee > max) { // si nouvelle valeur max
        max = liste->donnee; // on met à jour
        count = 1; // on remet le compteur à 1
      } else if (liste->donnee == max) {
        count++; // sinon on ajoute une occurrence
      }
      liste = liste->suivant; // on avance
    }
    return count; // on retourne le nombre d’occurrences max
  }
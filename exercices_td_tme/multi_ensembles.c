#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"

  
/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun élément n'a la valeur val */
element_t * Recherche_val(element_t *ensemble, int val)
{
    element_t *current=ensemble; //je sait pas pourquoi mais apparament il faut pas travailler avec la liste donner en
    while(ensemble!=NULL)       //parametre mais il faut juste creer une autre qui sont identiques 
    {
        if(current->valeur=val){return current;}
        current=current->suivant;
    }
    return NULL;        
}

/* Ajoute l'element val en tete de l'ensemble s'il n'apparait pas dans l'ensemble, augmente sa frequence de 1 sinon */
element_t * Ajout_tete_ensemble(element_t *ensemble, int val, int freq)
{
    element_t *existant=recherche_val(ensemble,val);
    if(existant!=NULL)
    {
        existant->frequence +=freq;
        return ensemble;
    }
    else
    {
        element_t *nouveau=malloc(sizeof(element_t));
        if(nouveau==NULL){printf("erreur d allocation");}
        nouveau->valeur=val;
        nouveau->frequence=freq;
        nouveau->suivant=ensemble;
        return nouveau ;
    }
    return NULL;
}


/* Affche tous les elements d'un ensemble avec leur frequence */
void Affiche_ensemble(element_t *ensemble) {
  element_t *ptr = ensemble;
  
  while (ptr != NULL) {
    printf("val : %d, frequence : %d\n",ptr->valeur,ptr->frequence);
    ptr=ptr->suivant;
  }
}

/* Saisie des n elements d'un ensemble */
element_t * Creation_ensemble(int n) {
  element_t *ensemble=NULL;
  
  int i = 0;
  int val;
  
  for (i=0; i < n; i++) {
    printf("Saisie d'un entier: ");
    scanf("%d",&val);
    ensemble=Ajout_tete_ensemble(ensemble,val,1);
  }
  return ensemble;
}
/*element_t *Supprime_total_element_ensemble(element_t *ensemble,int val)
{
    element_t *existant = Recherche_val(ensemble,val);
    if(existant==NULL)
    {
        return ensemble;
    }
    else
    {
        element_t *nouveau=ensemble;
        while(nouveau!=NULL){
        if(ensemble->valeur==val)
        {
            free(ensemble);
            ensemble=ensemble->suivant;
        }   
    }
    return ensemble;
    }
}*/
element_t * Supprime_total_element_ensemble(element_t *ensemble, int val) {
    element_t *courant = ensemble;
    element_t *precedent = NULL;
    
    while (courant != NULL) {
        if (courant->valeur == val) {
            if (precedent == NULL) { // Suppression en tête
                element_t *tmp = courant;
                ensemble = courant->suivant;
                courant = ensemble;
                free(tmp);
            } else { // Suppression au milieu ou fin
                element_t *tmp = courant;
                precedent->suivant = courant->suivant;
                courant = courant->suivant;
                free(tmp);
            }
            // On sort après avoir trouvé et supprimé l'élément
            return ensemble;
        } else {
            precedent = courant;
            courant = courant->suivant;
        }
    }
    
    return ensemble; // Valeur non trouvée, pas de modification
}
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
// Fonction qui supprime complètement un élément d’un multi-ensemble (liste chaînée)
// Peu importe la fréquence : il ne doit plus apparaître dans la liste
element_t* Supprime_total_element_ensemble(element_t* ensemble, int val) {
    // Cas spécial : si la liste n’est pas vide ET que l’élément à supprimer est le premier
    if (ensemble != NULL && ensemble->valeur == val) {
        element_t* temp = ensemble->suivant; // On sauvegarde le deuxième élément
        free(ensemble);                    // On libère la mémoire de l’élément supprimé
        return temp;                       // On retourne le nouveau début de liste
    }

    // On initialise un pointeur pour parcourir la liste
    element_t* courant = ensemble;

    // On parcourt tant qu’on n’est pas à la fin et qu’on n’a pas trouvé la valeur
    while (courant != NULL && courant->suivant != NULL) {
        // Si l’élément suivant est celui à supprimer
        if (courant->suivant->valeur == val) {
            element_t* temp = courant->suivant;      // On garde l’élément à supprimer
            courant->suivant = temp->suivant;      // On saute cet élément dans la liste
            free(temp);                            // On libère sa mémoire
            break;                                 // On sort de la boucle, car la valeur est supprimée
        }
        courant = courant->suivant; // On avance dans la liste
    }

    return ensemble; // On retourne le début de la liste (modifié ou non)
}
// Fonction qui diminue la fréquence d’un élément ou le supprime s’il n’en reste qu’un
element_t* Supprime_element_ensemble(element_t* ensemble, int val) {
    // Cas spécial : si la liste n’est pas vide ET que la valeur à supprimer est en tête
    if (ensemble != NULL && ensemble->valeur == val) {
        if (ensemble->frequence > 1) {
            ensemble->frequence--;  // On diminue simplement la fréquence
            return ensemble;        // Pas de suppression de nœud
        } else {
            element_t* temp = ensemble->suivant; // On garde le suivant
            free(ensemble);                    // On supprime l’élément
            return temp;                       // On retourne le nouveau début de liste
        }
    }

    // On crée un pointeur pour parcourir la liste
    element_t* courant = ensemble;

    // On parcourt jusqu’à la fin ou jusqu’à trouver la valeur
    while (courant != NULL && courant->suivant != NULL) {
        // Si l’élément suivant est celui à traiter
        if (courant->suivant->valeur == val) {
            if (courant->suivant->frequence > 1) {
                courant->suivant->frequence--; // On réduit la fréquence
            } else {
                element_t* temp = courant->suivant;      // Sauvegarde pour libération
                courant->suivant = temp->suivant;      // On supprime de la chaîne
                free(temp);                            // Libération mémoire
            }
            break; // Traitement fait, on quitte
        }
        courant = courant->suivant; // On continue à parcourir la liste
    }

    return ensemble; // On retourne la tête de la liste
}
element_t *Ajout_ensemble_trie(element_t * ensemble,int val,int freq)
{
    element_t *existant=Recherche_val(ensemble,val);
    if(existant!=NULL)
    {
        existant->frequence+=freq;
        existant->suivant;
        return ensemble;
    }
    element_t *nouveau=malloc(sizeof(element_t));
    nouveau->valeur=val;
    nouveau->frequence=freq;
    nouveau->suivant=NULL;

    if(ensemble==NULL || val<ensemble->valeur)
    {
        nouveau->suivant=ensemble;
        return nouveau ;
    }
    element_t *courant=ensemble;
    while(courant!=NULL && courant->suivant<val)
    {
        courant=courant->suivant;
    }
    nouveau->suivant=courant->suivant;
    courant->suivant=nouveau;
    return nouveau ;
}
element_t *Supprime_element_ensemble_trie(element_t *ensemble , int val)
{
    element_t *existant=Recherche_val(ensemble,val);
    if(existant!=NULL && existant->frequence >1)
    {
        existant->frequence--;
        existant->suivant;
        return ensemble;
    }
    if(ensemble==NULL){return NULL;}
    element_t *courant=ensemble;
    while(courant!=NULL && courant->suivant<val)
    {
        courant=courant->suivant;
    }
    
    element_t *tmp=courant->suivant;
    free(tmp);
    courant=courant->suivant;
    return courant;
}
element_t* Supprime_element_ensemble_trie(element_t* ensemble, int val) {
    // Si la liste est vide, on retourne NULL directement
    if (ensemble == NULL) return NULL;

    // Cas spécial : l'élément est en tête de liste
    if (ensemble->valeur == val) {
        if (ensemble->frequence > 1) {
            ensemble->frequence--; // On diminue la fréquence
            return ensemble;
        } else {
            element_t* temp = ensemble->suivant; // Sauvegarde du suivant
            free(ensemble);                    // Libération mémoire
            return temp;                       // Le suivant devient la nouvelle tête
        }
    }

    element_t* courant = ensemble;

    // Parcours tant que la liste continue et que la valeur n'est pas dépassée
    while (courant->suivant != NULL && courant->suivant->valeur <= val) {
        if (courant->suivant->valeur == val) {
            if (courant->suivant->frequence > 1) {
                courant->suivant->frequence--; // On diminue juste la fréquence
            } else {
                element_t* temp = courant->suivant;       // Élément à supprimer
                courant->suivant = temp->suivant;       // On saute l’élément
                free(temp);                             // Libération mémoire
            }
            break; // On a trouvé et traité l'élément
        }
        courant = courant->suivant; // On avance dans la liste
    }

    return ensemble; // On retourne le début de la liste
}
element_t* Supprime_total_element_ensemble_trie(element_t* ensemble, int val) {
    // Si la liste est vide, rien à faire
    if (ensemble == NULL) return NULL;

    // Cas spécial : suppression en tête de liste
    if (ensemble->valeur == val) {
        element_t* temp = ensemble->suivant; // Sauvegarde du suivant
        free(ensemble);                    // Libération mémoire
        return temp;                       // Nouveau début de liste
    }

    element_t* courant = ensemble;

    // Parcours de la liste pour trouver l’élément à supprimer
    while (courant->suivant != NULL && courant->suivant->valeur <= val) {
        if (courant->suivant->valeur == val) {
            element_t* temp = courant->suivant;       // Élément à supprimer
            courant->suivant = temp->suivant;       // On le retire de la liste
            free(temp);                             // Libération mémoire
            break;                                   // Suppression faite
        }
        courant = courant->suivant; // Passage à l’élément suivant
    }

    return ensemble; // On retourne la tête (inchangée)
}
int Inclus(element_t *e1, element_t *e2) {
    // On parcourt tous les éléments de e1
    while (e1 != NULL) {
        // Si e2 est vide alors que e1 ne l’est pas, ce n’est pas inclus
        if (e2 == NULL) return 0;

        // Si la valeur de e1 est plus petite → elle n’existe pas dans e2
        if (e1->valeur < e2->valeur) return 0;

        // Si la valeur est identique, on compare les fréquences
        if (e1->valeur == e2->valeur) {
            // Si la fréquence de e1 est plus grande → e1 non inclus
            if (e1->frequence > e2->frequence) return 0;

            // Avancer les deux pointeurs
            e1 = e1->suivant;
            e2 = e2->suivant;
        } else {
            // Si e2->valeur est plus petit, avancer dans e2
            e2 = e2->suivant;
        }
    }

    // Si on a terminé e1 sans erreur, alors il est inclus dans e2
    return 1;
}
int Intersection_vide(element_t *e1, element_t *e2) {
    // Parcours simultané des deux listes
    while (e1 != NULL && e2 != NULL) {
        // Si on trouve une valeur commune, l’intersection n’est pas vide
        if (e1->valeur == e2->valeur) return 0;

        // On avance le pointeur dont la valeur est la plus petite
        if (e1->valeur < e2->valeur) {
            e1 = e1->suivant;
        } else {
            e2 = e2->suivant;
        }
    }

    // Si on n’a trouvé aucune valeur commune
    return 1;
}



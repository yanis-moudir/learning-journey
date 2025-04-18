#include <stdio.h>
#include "multi_ensembles.h"

int main() {
    element_t *ensemble = NULL;

     // Test d'ajout d'éléments
     ensemble = Ajout_tete_ensemble(ensemble, 10, 1);
     ensemble = Ajout_tete_ensemble(ensemble, 20, 2);
     ensemble = Ajout_tete_ensemble(ensemble, 10, 3); // Doit augmenter la fréquence de 10
     
     printf("Contenu de l'ensemble après ajouts:\n");
     Affiche_ensemble(ensemble);
     
     // Test de recherche
     int val_recherche = 20;
     element_t *trouve = Recherche_val(ensemble, val_recherche);
     if (trouve != NULL) {
         printf("\nValeur %d trouvée avec fréquence %d\n", 
                trouve->valeur, trouve->frequence);
     } else {
         printf("\nValeur %d non trouvée\n", val_recherche);
     }
     
     // Test avec une valeur non existante
     val_recherche = 30;
     trouve = Recherche_val(ensemble, val_recherche);
     if (trouve == NULL) {
         printf("Valeur %d non trouvée (comme attendu)\n", val_recherche);
     }
     
     // Test de création d'ensemble
     printf("\nCréation d'un nouvel ensemble:\n");
     element_t *ensemble2 = Creation_ensemble(3); // Saisie interactive de 3 valeurs
     Affiche_ensemble(ensemble2);
     
     // Libération de la mémoire (à implémenter si nécessaire)
     
     
  return 0;
}
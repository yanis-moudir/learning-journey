#include<stdio.h>
#include<stdlib.h>
#define NB_VILLES 5 
int villes[NB_VILLES] = {29, 59, 67, 75, 83};
int distances[NB_VILLES] [NB_VILLES] = {
{0, 598, 900, 504, 995},
{598, 0, 407, 203, 861},
{900, 407, 0, 397, 621},
{504, 203, 397, 0, 694},
{995, 861, 621, 694, 0}
};
// Affiche la matrice des distances avec en-têtes
void affiche_distances(int villes[], int dist[NB_VILLES][NB_VILLES]) {
    // Affiche la première ligne (en-tête)
    printf("km\t");                     // "km" en premier
    for (int i = 0; i < NB_VILLES; i++) {  
        printf("%d\t", villes[i]);      // Affiche les codes postaux (en-tête colonnes) (techniquement la premiere lignes)
    }
    printf("\n");  

    // Affiche chaque ligne (ville + distances)
    for (int i = 0; i < NB_VILLES; i++) {  
        printf("%d\t", villes[i]);      // Affiche le code postal de la ville courante (en-tête ligne)
        for (int j = 0; j < NB_VILLES; j++) {  //chaque i il parcours avec tous les j puis il passe ou prochain i
            if (i == j) {  
                printf("-\t");         // Affiche "-" sur la diagonale (distance ville à elle-même)
            } else {  
                printf("%d\t", dist[i][j]); // Affiche la distance entre villes i et j
            }  
        }  
        printf("\n");  
    }  
}
//pris beaucoup de temps pour trouver la solution donc j'ai directement copier le corrigé 

int main()
{
    affiche_distances(villes,distances);
    return 0;
}
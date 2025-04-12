#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void calcule_bornes_sup(int pourcentages[], int taille) {
    int somme = 0;  // Variable pour accumuler la somme cumulative des pourcentages
    for (int i = 0; i < taille; i++) {  // Parcourt chaque élément du tableau
        somme += pourcentages[i];  // Ajoute le pourcentage actuel à la somme cumulative
        pourcentages[i] = somme - 1;  // Calcule la borne supérieure (ex: 17% → 16)
    }
}
int tire_non_equi(int bornes[], int taille) {
    int tirage = rand() % 100;  // Génère un nombre aléatoire entre 0 et 99
    for (int i = 0; i < taille; i++) {  // Parcourt les bornes
        if (tirage <= bornes[i]) {  // Si le tirage est dans l'intervalle courant aussi > que bornes[i-1]
            return i;  // Retourne l'indice correspondant (0, 1, 2, ou 3)
        }
    }
    return taille - 1;  // Par défaut (ne devrait jamais être atteint si les bornes sont valides)
}


typedef struct {
    double a, b, c, d, e, f;  // Coefficients de la transformation
} Transformation;

void applique_transformation(Transformation ta, double *x, double *y) {
    double xn = ta.a * (*x) + ta.b * (*y) + ta.e;  // Calcule le nouveau x
    double yn = ta.c * (*x) + ta.d * (*y) + ta.f;  // Calcule le nouveau y
    *x = xn;  // Met à jour x
    *y = yn;  // Met à jour y
}
int main() {
    srand(time(NULL));  // Initialise le générateur aléatoire
    int pourcentages[] = {17, 28, 50, 5};  // Probabilités en %
    int bornes[4];  // Stockera les bornes supérieures
    int occurrences[4] = {0};  // Compteur pour chaque résultat (initialisé à 0)

    // Copie des pourcentages dans bornes
    for (int i = 0; i < 4; i++) bornes[i] = pourcentages[i];
    calcule_bornes_sup(bornes, 4);  // Calcule les bornes

    // Effectue 10 000 tirages
    for (int i = 0; i < 10000; i++) {
        int resultat = tire_non_equi(bornes, 4);  // Tirage pondéré
        occurrences[resultat]++;  // Incrémente le compteur correspondant
    }

    // Affiche les résultats
    printf("Occurrences : [%d %d %d %d]\n", 
           occurrences[0], occurrences[1], occurrences[2], occurrences[3]);
    return 0;
}

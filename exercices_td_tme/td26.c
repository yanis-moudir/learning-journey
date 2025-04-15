#include <stdio.h>
#include <string.h>  // Pour strcpy

#define TAILLE_COULEUR 11  // 10 caractères + '\0'

typedef struct {
    int x, y;               // Coordonnées
    char couleur[TAILLE_COULEUR];  // Couleur
} point;


typedef struct {
    point coin_bas_gauche;  // Coin inférieur gauche
    point coin_haut_droit;  // Coin supérieur droit
    char couleur_traits[TAILLE_COULEUR];  // Couleur des bords
    char couleur_fond[TAILLE_COULEUR];    // Couleur de fond
} rectangle;
int main() {
    rectangle mon_rectangle;
    
    // Initialisation des coins
    mon_rectangle.coin_bas_gauche.x = 100;
    mon_rectangle.coin_bas_gauche.y = 200;
    strcpy(mon_rectangle.coin_bas_gauche.couleur, "rouge");
    
    mon_rectangle.coin_haut_droit.x = 300;
    mon_rectangle.coin_haut_droit.y = 2;
    strcpy(mon_rectangle.coin_haut_droit.couleur, "rouge");
    
    // Couleurs du rectangle
    strcpy(mon_rectangle.couleur_traits, "rouge");
    strcpy(mon_rectangle.couleur_fond, "blanc");
    
    return 0;
}
int point_dans_rectangle(point p, rectangle r) {
    return (p.x >= r.coin_bas_gauche.x && p.x <= r.coin_haut_droit.x) &&
           (p.y >= r.coin_haut_droit.y && p.y <= r.coin_bas_gauche.y);
}
int minimum(int a, int b) { return (a < b) ? a : b; }
int maximum(int a, int b) { return (a > b) ? a : b; }

rectangle intersection_rectangles(rectangle r1, rectangle r2) {
    rectangle inter;
    
    // Calcul des coins de l'intersection
    inter.coin_bas_gauche.x = maximum(r1.coin_bas_gauche.x, r2.coin_bas_gauche.x);
    inter.coin_bas_gauche.y = minimum(r1.coin_bas_gauche.y, r2.coin_bas_gauche.y);
    inter.coin_haut_droit.x = minimum(r1.coin_haut_droit.x, r2.coin_haut_droit.x);
    inter.coin_haut_droit.y = maximum(r1.coin_haut_droit.y, r2.coin_haut_droit.y);
    
    // Couleurs fixées à noir
    strcpy(inter.coin_bas_gauche.couleur, "noir");
    strcpy(inter.coin_haut_droit.couleur, "noir");
    strcpy(inter.couleur_traits, "noir");
    strcpy(inter.couleur_fond, "noir");
    
    return inter;
}

#include<stdio.h>
#include<stdlib.h>
/*int recher_dicho(int tab[],int valeur)
{
    int taille=sizeof(tab)/sizeof(int);
    int g =tab[0],d=tab[taille],i,milieu=tab[taille/2 +1];
    if(valeur==milieu){return 1;}
    else if (valeur<milieu)
    {
        if (valeur >g){return 1;}
        else{return 0;}
    }
    else if(valeur>milieu)
    {
        if(valeur<d){return 1;}
        else{return 0;}
    }
}*/
int recherche_dichotomique_iterative(int tab[], int taille, int x) {
    int g = 0;                  // Borne gauche initiale
    int d = taille - 1;         // Borne droite initiale

    while (g <= d) {            // Tant que l'intervalle est valide
        int milieu = (g + d) / 2; // Calcule le milieu

        if (tab[milieu] == x) { // Élément trouvé
            return 1;
        } else if (tab[milieu] > x) { // Chercher à gauche
            d = milieu - 1;
        } else {                // Chercher à droite
            g = milieu + 1;
        }
    }
    return 0;                   // Élément non trouvé
}
int recherche_dichotomique_recursive(int tab[], int g, int d, int x) {
    if (g > d) {                // Cas de base : intervalle vide
        return 0;
    }

    int milieu = (g + d) / 2;   // Calcule le milieu

    if (tab[milieu] == x) {     // Élément trouvé
        return 1;
    } else if (tab[milieu] > x) { // Chercher à gauche
        return recherche_dichotomique_recursive(tab, g, milieu - 1, x);
    } else {                    // Chercher à droite
        return recherche_dichotomique_recursive(tab, milieu + 1, d, x);
    }
}
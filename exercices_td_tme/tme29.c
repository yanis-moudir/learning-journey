#include<stdio.h>
#include<stdlib.h>
//je pense a utiliser in chaine de caractére qui a que des lettres mais ca n'existe pas en C
//aussi c'est un peut lent d'utilise une chaine de caractére 
//peut étre deux fonction différente 
int est_caractere(char c)
{
    char caracteres[27]={'a','z','e','r','t','y','u','i','o','p','q','s','d','f','g','h','j','k','l','m','w','x','c','v','b','n','\0'};
    int i;
    for(i=0;i<27;i++)
    {
        if (caracteres[i]==c){return 1;}
    }
    return 0;
}
void affiche_char(char *mot)
{
    int i;
    for(i=0;mot[i]!='\0';i++)
    {
        if(est_caractere(mot[i])){printf("%c \t",mot[i]);}

    }
    printf("\n");
}
char *affiche_modifier(char *mot)
{
    int i,j=0;
    char *new_mot= malloc(sizeof(mot));                 //le pense qu'il faut faire un malloc mais pas sur 
    for(i=0;mot[i]!='\0';i++)
    {
        if(est_caractere(mot[i]))
        {
            new_mot[j]=mot[i];
            j++;
        }
    }
    new_mot[j+1]='\0';
    return new_mot;
}
void filtrer_en_place(char *chaine) {
    int j = 0;
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (isalpha(chaine[i])) {
            chaine[j++] = chaine[i];  // Déplace les lettres au début
        }
    }
    chaine[j] = '\0';  // Termine la chaîne
}
int main()
{
    char mot[8]="ab55rop";
    affiche_char(mot);
    printf("%s\n",affiche_modifier(mot));
    return 0;
}
/*remarque totale 
donc ppour la deuxiéme question il a calculer le nombre de lettr pour faire une allocation malloc exacte 
puis tous est vrair de ma part 
aussi il a fait appelle a la fonction isalpha de la bibliiothéque ctype qui va tous seule seule verifier si c'est un caractére
aussi toujours verifier les allocation avec null ou pas 
*/

//corrigé 
/*#include <stdio.h>
#include <ctype.h>  // Pour isalpha()

// Fonction qui affiche uniquement les lettres d'une chaîne
void afficher_lettres(const char *chaine) {
    // Parcourt la chaîne jusqu'au caractère nul '\0'
    for (int i = 0; chaine[i] != '\0'; i++) {
        // Vérifie si le caractère est une lettre (majuscule ou minuscule)
        if (isalpha(chaine[i])) {
            printf("%c", chaine[i]);  // Affiche le caractère si c'est une lettre
        }
    }
    printf("\n");  // Saut de ligne après l'affichage
}
#include <stdlib.h>  // Pour malloc()

// Fonction qui renvoie une nouvelle chaîne contenant uniquement les lettres
char *filtrer_lettres(const char *chaine) {
    // Compte le nombre de lettres dans la chaîne
    int nb_lettres = 0;
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (isalpha(chaine[i])) {
            nb_lettres++;
        }
    }

    // Alloue de la mémoire pour la nouvelle chaîne (+1 pour '\0')
    char *resultat = malloc((nb_lettres + 1) * sizeof(char));
    if (resultat == NULL) {
        return NULL;  // Échec de l'allocation
    }

    // Remplit la nouvelle chaîne avec les lettres
    int j = 0;
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (isalpha(chaine[i])) {
            resultat[j++] = chaine[i];
        }
    }
    resultat[j] = '\0';  // Termine la chaîne

    return resultat;
}
// Fonction qui filtre la chaîne en place (sans allocation)
void filtrer_en_place(char *chaine) {
    int j = 0;
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (isalpha(chaine[i])) {
            chaine[j++] = chaine[i];  // Déplace les lettres au début
        }
    }
    chaine[j] = '\0';  // Termine la chaîne
}*/
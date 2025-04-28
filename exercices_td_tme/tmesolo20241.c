/* Nous souhaitons determiner l'indice de la permiere occurence d'une valeur donnee dans un tableau d'entiers
   
- Completez la fonction indOcc pour qu'elle retourne l'indice de la premiere occurence d'une valeur donnee dans un tableau d'entier
  La fonction doit prendre en parametres le tableau, sa taille et la valeur recherchee. Si la valeur n'apparait pas dans le tableau, la fonction doit retourner -1.

- Completez la fonction main pour afficher le resultat. Le message affiche doit dependre du resultat de l'appel
  a la fonction indOcc. N'oubliez pas de remplacer les ... en parametre des appels a printf.

Les elements du tableau, sa taille et la valeur recherchee (VAL) sont definis par des primitives #define,
ces valeurs seront modifiees pour tester votre programme. 
Vous pouvez les modifier pour effectuer des tests.
*/

#include <stdio.h>

#define VALTAB {1,4,5,7,8,5,2}
#define TAILLE_TAB 7
#define VAL 2

int  indOcc(int *tab,int taille,int donnee) 
{
    int indice_valeur;
    for(int i=0;i<taille;i++)
    {
        if(tab[i]==donnee){indice_valeur=i;return indice_valeur;}
    }
    return -1;

}

int main () {
  int taille=TAILLE_TAB,donnee=VAL;
  int tab[TAILLE_TAB] = VALTAB;
 
  printf ("L'indice de la premiere occurence de %d est %d\n",VAL,indOcc(tab,taille,donnee));
  
  printf ("Il n'y a pas d'occurence de %d dans le tableau\n",3);
 
  return 0;
}

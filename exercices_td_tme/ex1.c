/* Nous souhaitons compter le nombre de valeurs d'un tableau, d'entiers strictement positifs, 
multiples d'une valeur donnee (VAL).

- Completez la fonction nbMultiples pour qu'elle retourne le nombre de valeurs du tableau 
multiples d'une valeur val. La fonction doit prendre en parametres le tableau, sa taille et la valeur val

- Completez la fonction main pour afficher le resultat. Le message affiche doit dependre du resultat de l'appel
  a la fonction nbMultiples. N'oubliez pas de remplacer les ... en parametre des appels a printf.

Les elements du tableau,sa taille et la valeur a laquelle comparer les elements du tableau 
sont definis par des primitives #define, ces valeurs seront modifiees
pour tester votre programme. Vous pouvez les modifier pour effectuer des tests.
*/

#include <stdio.h>

#define VAL 2
#define VALTAB {3,5,6,8,9,10}
#define TAILLE 6

int nbMultiples(int *tab, int taille, int val) {
	/* hypothese : le tableau contient des valeurs strictement positives */
  int compteur=0;
  for(int i=0;i<taille;i++)
  {
    if(tab[i]%val==0)
    {
      compteur++;
    }
  }                                                            
	return  compteur;
}

int main() {
  /* NE MODIFIEZ PAS L'INSTRUCTION SUIVANTE
  ELLE PERMET D'INITIALISER LE TABLEAU */
  int tab[] = VALTAB; 
  /* Affichage */
  if(nbMultiples(tab,TAILLE,VAL)!=0){
  printf("Le nombre de multiples de %d est %d\n",VAL, nbMultiples(tab,TAILLE,VAL));}
  else{
  printf("Le tableau ne contient aucun multiple de %d\n",VAL);}
  
  
  
  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

/* Ajoute un nouveau caractere en tete de la liste listeCaracteres, le caractere et sa frequence sont passes en parametre.
Retourne la nouvelle tete de liste */
caractere* ajouterCaractereTete(char c, int freq, caractere* listeCaracteres){
	caractere *new=malloc(sizeof(caractere));
	new->caract=c;
	new->frequence=freq;
	new->suivant=listeCaracteres;
	return new;
}

/* affiche les caracteristiques d'un caractere */
/* NE PAS MODIFIER LA FONCTION */
void afficherCaractere(caractere *c){
  printf("caractere : %c, frequence : %d\n",c->caract,c->frequence);
}

/* Affiche les caracteristiques de tous les elements de la liste listeCaracteres */
void afficherListe(caractere* listeCaracteres)
{
	caractere *ptr=listeCaracteres;
	while(ptr!=NULL)
	{
		printf("caractere : %c, frequence : %d\n",ptr->caract,ptr->frequence);
		ptr=ptr->suivant;
	}
}

/* Retourne le caractere qui a la frequence la plus elevee, si plusieurs caracteres sont concernes,
 retourne le dernier de la liste. Retourne le caractere '0' si la liste est vide */
char maxFrequence(caractere *listeCaracteres) 
{
	if(listeCaracteres==NULL){return '0';}
	caractere *ptr=listeCaracteres;
	int max=ptr->frequence;
	char maxfreq;
	ptr=ptr->suivant;
	while(ptr!=NULL)
	{
		if(ptr->frequence>=max)
		{
			max=ptr->frequence;
			maxfreq=ptr->caract;
		}
		ptr=ptr->suivant;
	}
	return maxfreq;
}

/* Retourne le pointeur sur la premiere apparition du caractere passe en parametre dans la liste listeCaracteres.
Retourne NULL si le caractere n'est pas dans la liste */
caractere* chercherCaractere(char c, caractere* listeCaracteres) 
{
	caractere *ptr=listeCaracteres;
	while(ptr!=NULL)
	{
		if(ptr->caract=c)
		{
			return ptr;
		}
		ptr=ptr->suivant;
	}	
	return NULL;
}
  
/* Cree et retourne la liste associee a la chaine de caracteres passee en parametre. 
Chaque element de la liste doit correspondre a un caractere de la chaine et a sa 
frequence d'apparition dans la chaine. Chaque caractere de la chaine ne doit apparaitre qu'une fois dans la liste */
caractere* frequenceCaracteres(char * chaine)
{
	int i = 0;
	caractere *liste = NULL;
	while(chaine[i] != '\0'){
		caractere *c = chercherCaractere(chaine[i], liste);
		if(c == NULL){
			liste = ajouterCaractereTete(chaine[i], 1, liste);
		} else {
			c->frequence = c->frequence +1;
		}
		i+=1;
	}
 	return liste;
}


/* Supprime de la liste listeCaracteres tous les caracteres dont la frequence est egale a zero. Retourne la tete de liste.
La fonction doit liberer la memoire.
Si la chaine passee en parametre est vide, le fonction doit retourner NULL */
caractere *supprimeZero(caractere *listeCaracteres){	
	caractere *liste = listeCaracteres, *pred = NULL, *tmp = NULL, *ens = liste;
	
	
	
	while(liste != NULL){
		if(liste->frequence == 0){
			tmp = liste;
			if(pred != NULL){
				pred->suivant = liste->suivant; 
				
			}else {
				ens = liste->suivant;
			}
			liste = liste->suivant;
			free(tmp);
		}
		else {
			pred = liste;
			liste = liste->suivant;	
		}
		
	
	}		
		
 	return ens;
}
int main() {
	caractere *liste= NULL;
	ajouterCaractereTete('a',2,liste);
	// test 1
	afficherCaractere(liste);
	ajouterCaractereTete('b',4,liste);
	ajouterCaractereTete('c',0,liste);
	ajouterCaractereTete('d',1,liste);
	ajouterCaractereTete('e',3,liste);
	//test 2
	afficherListe(liste);

	return 0;
}
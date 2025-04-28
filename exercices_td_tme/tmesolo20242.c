/* Nous nous interessons a des listes de scores de matchs, chaque match est caracterise par l'identifiant entier des deux equipes
 (l'equipe1 est celle qui joue a domicile), et le score de chaque equipe */

typedef struct _match match;

typedef struct _match {
  int equipe1;
  int equipe2;
  int scoreEquipe1;
  int scoreEquipe2;
  match* suivant;
} match;

/* Ajoute un nouveau match (dont les caracteristiques sont passees en parametre) en tete de liste.
Retourne la nouvelle tete de liste */
match *ajouterMatchTete(int eq1, int eq2, int score1, int score2, match *listeMatchs);

/* Affiche les caracteristiques d'un match */
void afficherMatch(match *m);

/* Affiche les caracteristiques de tous les matchs de la liste listeMatchs */
void afficherListe(match *listeMatchs);

/* Retourne un pointeur sur le match avec la plus grosse difference de score. Si la plus grosse difference de score est la
 mmeme pour plusieurs matchs, la fonction retourne un pointeur sur le dernier rencontre.
Retourne NULL si tous les matchs ont un score nul */
match *maximumDifference(match *listeMatchs);

/* Retourne un pointeur sur le premier match de la liste remporte a domicile par l'equipe passee en parametre
 (l'equipe1 est l'equipe qui joue a dimicile). 
Retourne NULL si l'equipe n'a remporte aucun match a domicile ou n'a participe a aucun match)*/
match *matchGagne(int equipe, match *listeMatchs);
  
/* Supprime de la liste tous les matchs concernant l'equipe passee en parametre, retourne la tete de liste apres suppression.
 La fonction doit liberer la memoire */
match *disqualifierEquipe(int equipe, match *listeMatchs);

/* Cree et retourne la tete de la liste comprenant une copie de tous les matchs remportes a l'exterieur.
Retourne NULL si aucun match n'a ete remporte a l'exterieur */
match *victoireExterieur(match *listeMatchs);
#include <stdio.h>
#include <stdlib.h>


/* Ajoute un nouveau match (dont les caracteristiques sont passees en parametre) en tete de liste.
Retourne la nouvelle tete de liste */
match *ajouterMatchTete(int eq1, int eq2, int score1, int score2, match *listeMatchs) {
  match *new=malloc(sizeof(match));
  new->equipe1=eq1;
  new->equipe2=eq2;
  new->scoreEquipe1=score1;
  new->scoreEquipe2=score2;
  new->suivant=listeMatchs;
  return new;//juste
}

/* Affiche les caracteristiques d'un match */
/* NE PAS MODIFIER CETTE FONCTION */
void afficherMatch(match *m) {
  printf("Equipe1 : %d, Equipe2 : %d, Score1 : %d, Score2 : %d\n",m->equipe1, m->equipe2,m->scoreEquipe1, m->scoreEquipe2);  
}

/* Affiche les caracteristiques de tous les matchs de la liste listeMatchs */
void afficherListe(match *listeMatchs){
    while(listeMatchs!=NULL)
    {
        afficheMatch(listeMatchs);
        listeMatchs=listeMatchs->suivant;
    }
 
}//juste 

/* Retourne un pointeur sur le match avec la plus grosse difference de score. Si la plus grosse difference de score est 
la mmeme pour plusieurs matchs, la fonction retourne un pointeur sur le premier rencontre.
Retourne NULL si tous les matchs ont un score nul */
match *maximumDifference(match *listeMatchs) 
{
  match *ptr=listeMatchs,*retour=NULL;
  int compteur=0 ;
  while(ptr!=NULL){
  if(ptr->scoreEquipe1 != ptr->scoreEquipe2)
  {
    if((ptr->scoreEquipe1 > ptr->scoreEquipe2) && (ptr->scoreEquipe1- ptr->scoreEquipe2 > compteur))
    {
      compteur =ptr->scoreEquipe1- ptr->scoreEquipe2;
      retour=ptr;
      ptr=ptr->suivant;
    }
    else if ((ptr->scoreEquipe2 > ptr->scoreEquipe1) && (ptr->scoreEquipe2- ptr->scoreEquipe1 > compteur))
    {
      compteur=ptr->scoreEquipe2- ptr->scoreEquipe1;
      retour=ptr;
      ptr=ptr->suivant;
    }
    else {ptr=ptr->suivant;}
  }
  else{
  ptr=ptr->suivant;}
}
return ptr;
}
/* Retourne un pointeur sur le premier match de la liste remporte a domicile par l'equipe passee en parametre 
(l'equipe1 est l'equipe qui joue a dimicile). 
Retourne NULL si l'equipe n'a remporte aucun match a domicile ou n'a participe a aucun match)*/
match *matchGagne(int equipe, match *listeMatchs) {
  match *courant=listeMatchs;
  int score=courant->scoreEquipe1-courant->scoreEquipe2;
  while (courant!=NULL)
  {
    if(courant->equipe1=equipe && score > 0)
    {
        return courant;
    }
    courant=courant->suivant;
  }
  return NULL;
}

/* Supprime de la liste tous les matchs concernant l'equipe passee en parametre, retourne la tete de 
liste apres suppression. La fonction doit liberer la memoire */
match *disqualifierEquipe(int equipe, match *listeMatchs) 
{
  match *ptr=listeMatchs,*pred=NULL,*temp=NULL;
  while(ptr!=NULL)
  {
    if(ptr->equipe1==equipe || ptr->equipe2==equipe)
    {
      if(pred==NULL)
      {
        listeMatchs=listeMatchs->suivant;
      }
      else
      {
        pred->suivant=ptr->suivant;
      }
      temp=ptr;
      ptr=temp->suivant;
      free(temp);
    }
   
    else
    {
      pred=ptr;
      ptr=ptr->suivant;
    }
     
  }
  return listeMatchs;
}
/* Cree et retourne la tete de la liste comprenant une copie de tous les matchs remportes a l'exterieur.
Retourne NULL si aucun match n'a ete remporte a l'exterieur */
match *victoireExterieur(match *listeMatchs){
  return NULL;
}
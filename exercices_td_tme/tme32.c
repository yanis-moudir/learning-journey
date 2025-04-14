#include<stdio.h>
#include<stdlib.h>
int recherche_iterative(int tab[],int taille,int valeur)
{
    int i;
    for(i=0;i<taille;i++)
    {
        if(tab[i]=valeur){return 1;}
    }
    return 0;
}
int recherche_recursive(int *tab,int taille,int valeur)
{
    if(*tab=valeur){return 1;}
    if (taille==0){return 0;}
    return recherche_dichotomique(tab+1,taille-1,valeur);//a chaque fois en decremente la taille jusqu'a a rriveé a 0 
//si on trouve pas le bon element 
}
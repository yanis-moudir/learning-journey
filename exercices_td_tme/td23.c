#include<stdio.h>
#include<stdlib.h>
int indice_min(int tab[], int taille)
{
    int i;
    int min=tab[0];
    for(i=0;i<taille;i++)
    {
        if(tab[i]<min){min=tab[i];}
    }
    for(i=0;i<taille;i++)// pas besoin de faire  2 boucles au méme temps faut juste alloue l'indice dans une autre variable 
    {
        if(tab[i]=min){return i;}
    }
}
int indice_min_pos(int tab[], int taille)
{
    int i;
    int min=0;
    for(i=0;i<taille;i++)
    {
        if(tab[i]<min && tab[i]>=0){min=tab[i];}// comme la premiere fonction juste on a ajouter une condition 
    }
    for(i=0;i<taille;i++)
    {
        if(tab[i]=min){return i;}
    }
}
/*int indice_min(int tab[], int taille) {  
    if (taille <= 0) return -1;  
    int min_index = 0;  
    for (int i = 1; i < taille; i++) {  
        if (tab[i] < tab[min_index]) min_index = i;  
    }  
    return min_index;  
}  

int indice_min_positif(int tab[], int taille) {  
    int min_pos_index = -1;  
    for (int i = 0; i < taille; i++) {  
        if (tab[i] >= 0 && (min_pos_index == -1 || tab[i] < tab[min_pos_index])) {  
            min_pos_index = i;  
        }  
    }  
    return min_pos_index;  
}  
*/
int main ()
{
    int tab[]={7,-6,3,6,7,5,9};
    printf("premier indice %d\n",indice_min(tab,7));
    printf("premier indice %d\n",indice_min_pos(tab,7));

}

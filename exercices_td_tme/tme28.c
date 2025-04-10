#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NB_AMIS 4
#define NB_JOURS 7
void init_tableau(double tab[NB_AMIS][NB_JOURS])
{
    int i,j;
    for(i=0;i<NB_AMIS;i++)
    {
        for(j=0;j<NB_JOURS;j++)
        {
            tab[i][j]=0.0;
        }
    }
}
void montant_journnée(double tab[NB_AMIS][NB_JOURS],int jour)
{
    int payeur=rand()%NB_AMIS;
    int montant=50-rand()%21;
    int part = (double)montant/NB_AMIS;
    for(int i=0;i<NB_AMIS;i++)
    {
        if (i==payeur){tab[i][jour]+=montant-part;}
        else{tab[i][jour]-=part;}
    }
    printf("Jour %d : %d paye %d\n", jour+1, payeur, montant);
}



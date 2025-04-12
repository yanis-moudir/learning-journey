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
void afficherTableau(double tab[NB_AMIS][NB_JOURS]) {
    // Affiche les numéros des jours
    printf("|");
    for (int j = 0; j < NB_JOURS; j++) {
        printf(" %d", j + 1);
    }
    printf("\n--------------------------------------------------------------------\n");

    // Affiche les soldes pour chaque ami
    for (int i = 0; i < NB_AMIS; i++) {
        printf("%d |", i);
        for (int j = 0; j < NB_JOURS; j++) {
            printf(" %5.2f", tab[i][j]); // Affiche le solde formaté
        }
        printf("\n");
    }
}
//on ne peut pas entrer des constant tant que paramétre de la fonction 
double calculer_solde_total(double soldes[NB_AMIS][NB_JOURS], int ami) {
    double total = 0.0;
    for (int j = 0; j < NB_JOURS; j++) {
        total += soldes[ami][j];
    }
    return total;
}

int main() {
    srand(time(NULL));
    double soldes[NB_AMIS][NB_JOURS];
    
    /* Question 1 */
    initialiser_soldes(soldes);
    
    /* Question 2 */
    for (int j = 0; j < NB_JOURS; j++) {
        gerer_journee(soldes, j);
    }
    
    /* Question 3 */
    afficher_soldes(soldes);
    
    /* Question 4 */
    printf("\nSoldes finaux:\n");
    for (int i = 0; i < NB_AMIS; i++) {
        double solde = calculer_solde_total(soldes, i);
        printf("Ami %d : %6.2f euros\n", i, solde);
    }
    
    return 0;
}



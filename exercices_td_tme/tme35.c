#include<stdio.h>
#include<stdlib.h>


typedef struct{
    char nom[10];
    float densite;
    float distance;
    int nb_sat;
}planete;

void AffichePlanete(planete planete)
{
    printf("Nom: %s \t |",planete.nom);
    printf("Densite: %.3f\t |",planete.densite);
    printf("Distance du soleil: %.4f |",planete.distance);
    printf("nombre de satellites : %d \t |",planete.nb_sat);
    printf("\n");
}
void AfficheToutesPlanete(planete *tab , int taille)
{
    int i;
    for(i=0;i<taille;i++)
    {
        AffichePlanete(tab[i]);
    }
}
void ModifieDensite(planete planete,float newdensite)
{
    planete.densite=newdensite;
}
int main()
{
    planete soleil={"soleil",22.3,24.5,30};
    AffichePlanete(soleil);
    ModifieDensite(soleil,25);
    return 0;
}
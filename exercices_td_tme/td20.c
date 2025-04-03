#include<stdio.h>
#include<stdlib.h>
int compte(char mot[],char cr)
{
    int i,compteur=0;
    for(i=0;mot[i]!='\0';i++)
    {
        if(mot[i]==cr){compteur++;}

    }
    return compteur ;
}
void affiche_occure(char mot[])
{
    int i,compteur=0;
  
    for(i=0;mot[i]!='\0';i++)
    {
        printf("l'occurence de %c est %d\n",mot[i],compte(mot,mot[i]));
    }
}
//premier main
/*int main(){
    char mot []="bbbcca";
    affiche_occure(mot);
    return 0;
}*/
/*lesson apris de la question 1 est qu'ont peut faire les meme condition du while sur les for */


//question 2
void affiche_occur_sans_doublons(char *chaine) {  
    int deja_vu[256] = {0};                   // Tableau pour marquer les caractères déjà traités (ASCII étendu)
    for (int i = 0; chaine[i] != '\0'; i++) {  
        if (!deja_vu[(unsigned char)chaine[i]]) {  // Si le caractère n'a pas été traité
            int nb = compte(chaine, chaine[i]);    // Compte ses occurrences
            printf("%c : %d\n", chaine[i], nb);    // Affiche le résultat
            deja_vu[(unsigned char)chaine[i]] = 1;  // Marque comme "déjà vu"
        }
    }
}
//donc pour si je voit u'un on veut eviter des repetetions ou des doublures il faut toujours pensée a utilisé un booléen (en c c'est soit 0 ou 1)


//question3
//pseude
/*pour chercher la postion il faut construire un tableau qui va enrigistre chaque caracteére avec son nombre 
d'occurrence puis a la fin on imprime du  plus grand jusqu'a a plus petit */
void position (char* mot )
{
    
}

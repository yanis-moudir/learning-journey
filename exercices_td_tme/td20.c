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
/*nonnn on crée une variable max et on l'incrémente si on trouve plus grand */
int position (char* mot )
{
    int max=mot[0],max_pos;
    for(int i=0;mot[i]!='\0';i++)
    {
        if(compte(mot,mot[i])>max)
        {
            max=mot[i];
            max_pos=i;
        }
    }   
    return max_pos;
}
// je l'ai fait tous seul !!!
//question 4
int pos_optimise(char *mot)
{
    int max=-1,max_pos=-1;
    int deja_vu[256] = {0};                   // Tableau pour marquer les caractères déjà traités (ASCII étendu)
    for (int i = 0; mot[i] != '\0'; i++) 
    {
        if(!deja_vu[(unsigned char)mot[i]]&&compte(mot,mot[i])>max)
        {
            max=mot[i];
            max_pos=i;
            deja_vu[(unsigned char)mot[i]]=1;
        }
    }
    return max_pos;
}
//apparament j'ai mal compris la question 4 mais voici la solution 
void affiche_occur_optimise(char *chaine) {  
    int occurrences[256] = {0};              // Tableau pour stocker les occurrences de chaque caractère ASCII
    for (int i = 0; chaine[i] != '\0'; i++) {  
        occurrences[(unsigned char)chaine[i]]++;  // Incrémente le compteur du caractère courant
    }
    for (int i = 0; i < 256; i++) {         // Parcourt tous les caractères ASCII
        if (occurrences[i] > 0) {            // Si le caractère existe dans la chaîne
            printf("%c : %d\n", i, occurrences[i]);  // Affiche son occurrence
        }
    }
}
int main() {  
    char test[] = "bonjour";                 // Chaîne de test
    printf("Question 1 (avec doublons):\n");
    affiche_occure(test);                     // Test Question 1
    printf("\nQuestion 2 (sans doublons):\n");
    affiche_occur_sans_doublons(test);       // Test Question 2
    printf("\nQuestion 3 (plus frequent):\n");
    affiche_occur_optimise(test);            // Test Question 4
    return 0;
}
// il y avait juste un petit probléme dans la nomation de la fonction 3


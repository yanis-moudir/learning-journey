#include<stdio.h>
#include<stdlib.h>
int nombre_mots(char *mot)
{
    int i,compteur=0,est_mot=0;
    for(i=0;mot[i]!='\0';i++)
    {
        if(mot[i]==" ")
        {
            if(!est_mot)
            {
                compteur ++;
                est_mot=1;
            }
        }
        else{ est_mot=0;}
    }
    return compteur;
}
int main() {
    // Tests avec différents cas
    const char *test1 = "  Hello   world  ";  // 2 mots (espaces avant/après/multiples)
    const char *test2 = "Bonjour";            // 1 mot (pas d'espaces)
    const char *test3 = "   ";                // 0 mot (que des espaces)
    const char *test4 = "a b c d";            // 4 mots (séparés par un espace)

    printf("Test 1 : \"%s\" → %d mots\n", test1, nombre_mots(test1));
    printf("Test 2 : \"%s\" → %d mots\n", test2, nombre_mots(test2));
    printf("Test 3 : \"%s\" → %d mots\n", test3, nombre_mots(test3));
    printf("Test 4 : \"%s\" → %d mots\n", test4, nombre_mots(test4));

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MIN 1
#define MAX 12

int init_tab(int tab_brut[])
{
    srand(time(NULL));
    int taille = MIN + rand() % (MAX - MIN + 1);        //int taille=MAX %rand()-(MIN+1);
    int tab_brut[taille+1];
    for(int i=0;i<taille;i++)
    {
        tab_brut[i]=rand()%2;
    }
    tab_brut[taille]=-1;
    return taille+1;
}
void afficher_tab(int tab[]) {
    for (int i = 0; tab[i] != -1; i++) {
        printf("%d ", tab[i]);
    }
    printf("-1\n");
}
int compress_tab(int tab_brut[], int tab_compress[]) {
    int i_brut = 0, i_compress = 0;

    while (tab_brut[i_brut] != -1) {
        int valeur = tab_brut[i_brut];//nouvelle valeur 
        int compte = 1;

        // Compter les occurrences consécutives
        while (tab_brut[i_brut + 1] == valeur) //pour chaqu valeur sa compte aprés 
        {
            compte++;                           //puis on incrémente i_brut qui est le nouveau indice 
            i_brut++;                           //
        }

        // Écrire dans tab_compress
        if (compte >= 2) 
        {
            tab_compress[i_compress++] = compte;//on incrément i_compress par 1
            tab_compress[i_compress++] = valeur;//et on l'incrémente encore par 1
        }
        else 
        {
            tab_compress[i_compress++] = valeur;  // Cas d'un seul élément
        }

        i_brut++;
    }

    tab_compress[i_compress] = -1;  // Fin de la séquence compressée
    return i_compress + 1;  // Nombre de cases utilisées
}
int decompress_tab(int tab_brut[], int tab_compress[]) {
    int i_brut = 0, i_compress = 0;

    while (tab_compress[i_compress] != -1) {
        int courant = tab_compress[i_compress++];

        // Si le nombre est suivi d'une valeur (séquence compressée)
        if (i_compress < MAX + 1 && tab_compress[i_compress] == 0 || tab_compress[i_compress] == 1) {
            int valeur = tab_compress[i_compress++];
            for (int j = 0; j < courant; j++) {
                tab_brut[i_brut++] = valeur;
            }
        } else {
            // Valeur seule (non compressée)
            tab_brut[i_brut++] = courant;
        }
    }

    tab_brut[i_brut] = -1;  // Fin de la séquence décompressée
    return i_brut + 1;
}
int comparer_tabs(int tab1[], int tab2[]) {
    for (int i = 0; tab1[i] != -1 || tab2[i] != -1; i++) {
        if (tab1[i] != tab2[i]) return 0;  // Différence trouvée
    }
    return 1;  // Identiques
}
int main()
{
    return 0;
}
/*i_compress ++ 
ca va ecrire i_compres PUIS l'incrementer */
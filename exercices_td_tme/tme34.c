/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3
void init(char plateau[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            plateau[i][j]='_';
        }
    }
}
void afficher(char plateau[N][N])
{
    printf("\nPlateau :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", plateau[i][j]);  // Affiche chaque case
        }
        printf("\n");
    }
}
int choisir_menu12q() 
{
    printf("fait un choix \n 1. partie a 2 joueurs \n 2. partie contre l ordinateur \n 3. quitter \n selectionne le numéro de ton choix \n");
    int choix;
    scanf(" %d",&choix);
    if(choix>0 &&choix<4){return choix;}
    else{
        printf("fait un choix entre 1 et 3");choisir_menu12q();
    }
}
void jouer (char plateau[N][N], int joueur)
{   
    init(plateau);
    int i,j;
    printf("entre les cordonné en N,N");
    scanf("%d %d",&i,&j);
    if((i>0 && i<=N)&&(j<0 &&j<=N))
    {
        if(plateau[i][j]!='_'){printf("la case est déja pris entre un autre coordonnées \n");jouer(plateau,joueur);}
        else{plateau[i][j]=joueur;}
    }
    else if ((i<0||i>N)||(j<0||j>N)){printf("ce coordonées nexiste pas \n");jouer(plateau,joueur);}
}
void jouerOrdinateur(char plateau[N][N]) 
{
    int i,j;
    if( choisir_menu12q()==2)
    {
        i=rand()%N;j=rand()%N;
        if(plateau[i][j]!='_'){jouerOrdinateur(plateau);}
        else{plateau[i][j]='X'}
    }
}

int main()
{char plateau[N][N];
    init(plateau);
    afficher(plateau);
    return 0 ;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 3  // Taille du plateau de jeu (3x3)

/* Initialise le plateau de jeu avec des '_' (cases vides) */
void init(char plateau[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            plateau[i][j] = '_';  // Chaque case est initialisée à vide
        }
    }
}

/* Affiche le plateau de jeu */
void afficher(char plateau[N][N]) {
    printf("\nPlateau :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", plateau[i][j]);  // Affiche chaque case
        }
        printf("\n");  // Nouvelle ligne après chaque ligne du plateau
    }
}

/* Affiche le menu et retourne le choix de l'utilisateur */
int choisir_menu12q() {
    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Partie à 2 joueurs\n");
        printf("2. Partie contre l'ordinateur\n");
        printf("3. Quitter\n");
        printf("Sélectionnez le numéro de votre choix : ");
        scanf("%d", &choix);
        
        // Vérifie que le choix est valide (1, 2 ou 3)
        if(choix < 1 || choix > 3) {
            printf("Erreur : veuillez choisir un nombre entre 1 et 3\n");
        }
    } while(choix < 1 || choix > 3);  // Redemande tant que le choix est invalide
    
    return choix;
}

/* Permet à un joueur humain de jouer */
void jouer(char plateau[N][N], int joueur) {
    int i, j;
    char pion = (joueur == 0) ? 'X' : 'O';  // X pour joueur 0, O pour joueur 1
    
    do {
        printf("\nJoueur %d (%c), entrez les coordonnées (ligne colonne) : ", joueur, pion);
        scanf("%d %d", &i, &j);
        i--; j--;  // Conversion en indices 0-based
        
        // Vérifie que les coordonnées sont valides
        if(i < 0 || i >= N || j < 0 || j >= N) {
            printf("Coordonnées invalides. Veuillez entrer des valeurs entre 1 et %d.\n", N);
        }
        else if(plateau[i][j] != '_') {
            printf("Cette case est déjà occupée. Veuillez en choisir une autre.\n");
        }
    } while(i < 0 || i >= N || j < 0 || j >= N || plateau[i][j] != '_');
    
    plateau[i][j] = pion;  // Place le pion du joueur
}

/* Fait jouer l'ordinateur (aléatoirement) */
void jouerOrdinateur(char plateau[N][N]) {
    int i, j;
    
    do {
        i = rand() % N;  // Choix aléatoire de la ligne
        j = rand() % N;  // Choix aléatoire de la colonne
    } while(plateau[i][j] != '_');  // Continue tant que la case n'est pas vide
    
    plateau[i][j] = 'O';  // L'ordinateur joue toujours 'O'
    printf("\nL'ordinateur a joué en (%d, %d)\n", i+1, j+1);
}

/* Vérifie si un joueur a gagné */
bool partie_gagnee(char plateau[N][N]) {
    // Vérification des lignes et colonnes
    for(int i = 0; i < N; i++) {
        // Vérifie la ligne i
        if(plateau[i][0] != '_' && plateau[i][0] == plateau[i][1] && plateau[i][1] == plateau[i][2]) {
            return true;
        }
        // Vérifie la colonne i
        if(plateau[0][i] != '_' && plateau[0][i] == plateau[1][i] && plateau[1][i] == plateau[2][i]) {
            return true;
        }
    }
    
    // Vérification des diagonales
    if(plateau[0][0] != '_' && plateau[0][0] == plateau[1][1] && plateau[1][1] == plateau[2][2]) {
        return true;
    }
    if(plateau[0][2] != '_' && plateau[0][2] == plateau[1][1] && plateau[1][1] == plateau[2][0]) {
        return true;
    }
    
    return false;  // Personne n'a gagné
}

/* Vérifie si le plateau est plein (match nul) */
bool plateau_plein(char plateau[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(plateau[i][j] == '_') {
                return false;  // Trouvé une case vide
            }
        }
    }
    return true;  // Toutes les cases sont remplies
}

/* Gère le déroulement d'une partie complète */
void jouer_partie(char plateau[N][N], int nb_joueurs) {
    int tour = 0;  // Compteur de tours
    
    while(true) {
        afficher(plateau);
        
        // Tour des joueurs
        if(tour % 2 == 0) {
            jouer(plateau, 0);  // Joueur 0 (X)
        } else {
            if(nb_joueurs == 1) {
                jouerOrdinateur(plateau);  // Ordinateur (O)
            } else {
                jouer(plateau, 1);  // Joueur 1 (O)
            }
        }
        
        // Vérifie si un joueur a gagné
        if(partie_gagnee(plateau)) {
            afficher(plateau);
            printf("\nLe joueur %d a gagné !\n", (tour % 2 == 0) ? 0 : 1);
            return;
        }
        
        // Vérifie si le plateau est plein (match nul)
        if(plateau_plein(plateau)) {
            afficher(plateau);
            printf("\nMatch nul !\n");
            return;
        }
        
        tour++;  // Passe au tour suivant
    }
}

/* Fonction principale */
int main() {
    srand(time(NULL));  // Initialisation du générateur aléatoire
    char plateau[N][N];
    int choix;
    
    do {
        choix = choisir_menu12q();  // Affiche le menu
        
        if(choix != 3) {  // Si l'utilisateur ne veut pas quitter
            init(plateau);  // Initialise le plateau
            jouer_partie(plateau, choix);  // Lance la partie (1 ou 2 joueurs)
        }
    } while(choix != 3);  // Continue tant que l'utilisateur ne choisit pas de quitter
    
    printf("\nMerci d'avoir joué ! Au revoir.\n");
    return 0;
}
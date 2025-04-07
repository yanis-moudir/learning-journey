#include <stdio.h>
#include <stdlib.h>  // Pour malloc() et free()

// Convertit un entier en chaîne de caractères (allocation dynamique)
char* int_to_str(int nombre) {
    // Cas particulier : si nombre = 0
    if (nombre == 0) {
        char* str = malloc(2 * sizeof(char));  // Alloue 2 caractères ('0' + '\0')
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    // 1. Compter le nombre de chiffres
    int temp = nombre;
    int nb_chiffres = 0;
    while (temp != 0) {
        temp /= 10;// pour passer ou prochain caractére 
        nb_chiffres++;
    }

    // 2. Allouer la mémoire (nb_chiffres + 1 pour '\0')
    char* str = malloc((nb_chiffres + 1) * sizeof(char));
    if (str == NULL) {  // Échec de l'allocation
        return NULL;
    }

    // 3. Remplir la chaîne à partir des unités
    int index = nb_chiffres - 1;  // Commence par la fin
    temp = (nombre < 0) ? -nombre : nombre;  // Gère les nombres négatifs

    while (temp > 0) {
        str[index] = (temp % 10) + '0';  // Conversion chiffre → caractère ASCII
        temp /= 10;
        index--;
    }

    // 4. Ajouter le signe '-' si nécessaire
    if (nombre < 0) {
        str[0] = '-';
    }

    str[nb_chiffres] = '\0';  // Termine la chaîne
    return str;
}

// Programme de test
int main() {
    int nombres[] = {0, 123, -456, 7890};  // Nombres à tester
    for (int i = 0; i < 4; i++) {
        char* str = int_to_str(nombres[i]);
        if (str != NULL) {
            printf("Entier : %d → Chaîne : \"%s\"\n", nombres[i], str);
            free(str);  // Libère la mémoire allouée
        } else {
            printf("Erreur d'allocation pour %d\n", nombres[i]);
        }
    }
    return 0;
}
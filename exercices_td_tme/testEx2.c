#include <stdio.h>
#include "ex2.h"

/* programme de test */ 
int main() {
	caractere *liste= NULL;
	ajouterCaractereTete('a',2,liste);
	// test 1
	afficherCaractere(liste);
	ajouterCaractereTete('b',4,liste);
	ajouterCaractereTete('c',0,liste);
	ajouterCaractereTete('d',1,liste);
	ajouterCaractereTete('e',3,liste);
	//test 2
	afficherListe(liste);

	return 0;
}

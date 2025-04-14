#include<stdio.h>
#include<stdlib.h>
int est_deb(char *chaine1,char *chaine2)
{
    if(*chaine1=='\0'){return 1;}
    if(*chaine2=='\0'){return 0;}
    if(*chaine1!=*chaine2){return 0;}
    return est_deb(chaine1+1,chaine2+1);
}
int est_incluse(char *chaine1,char *chaine2)
{
    if(*chaine1=='\0'){return 1;}
    if(*chaine2=='\0'){return 0;}
    if(est_deb(chaine1,chaine2)){return 1;}
    return est_incluse(chaine1,chaine2+1);
}
int n_est_pas_deb(const char *s1, const char *s2) {
    if (*s1 == '\0') {          // s1 est vide : il est le début
        return 0;
    }
    if (*s2 == '\0') {          // s2 est vide mais pas s1 : s1 n'est pas le début
        return 1;
    }
    if (*s1 != *s2) {           // Caractères différents
        return 1;
    }
    return n_est_pas_deb(s1 + 1, s2 + 1); // Appel récursif
}


#include<stdio.h>
#include<stdlib.h>
typedef struct _element_t element_t;
struct _element_t{
int valeur;
int frequence;
element_t *suivant;
};

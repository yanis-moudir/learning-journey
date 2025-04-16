#include<stdio.h>
#include<stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t{
int donnee;
cellule_t *suivant;
};
int len(cellule_t *cell)
{
    int r=0;
    while(cell!=NULL)
    {
        r++;
        cell=cell->suivant;
    }
    return r;
}
int existe(cellule_t *cell , int val)
{
    while(cell!=NULL)
    {
        if (cell->donnee==val){return 1;}
        cell=cell->suivant;
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int comparaison_iterative(char mot1[],char mot2[])
{
    int i;
    for(i=0;i<sizeof(mot1)/sizeof(char);i++)
    {
        if(mot1[i]!=mot2[i]){return 0;}
    }
    return 1;
}
int comparaison_recursive(char *mot1,char *mot2)
{
    if(*mot1!=*mot2){return 0;}
    if(*mot1=='\0'&& *mot2=='\0'){return 1;}
    return comparaison_recursive(mot1+1,mot2+1);
}
int main()
{
    printf("resulat est %d \n",comparaison_iterative("bbbbn","bbccn"));
    printf("resulat est %d \n",comparaison_recursive("bbbbn","bbbbn"));
    return 0;
}
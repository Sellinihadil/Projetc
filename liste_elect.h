#ifndef LIST_ELECT_H_INCLUDED
#define LIST_ELECT_H_INCLUDED
#include<stdio.h>
typedef struct
{
unsigned int id_liste;
unsigned int id_tete;
unsigned int id_condidats[3]
}ElectList;



int ajouter(char *,ElectList);
int modifier(char *,int,ElectList);
int supprimer(char *,ElectList);
ElectList chercher(char *,ElectList);


#endif // LIST_ELECT_H_INCLUDED





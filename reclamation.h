#ifndef RECLAMATION_H_INCLUDED
#define RECLAMATION_H_INCLUDED 
#include <stdio.h>

typedef struct
{
int jour;
int mois;
int annee;
} Date;


typedef struct{
int Id;
Date daterec;
int Liste_elect_rec;
int num_bv;
char desc_rec [1000];
int type_rec;
} reclamation;

int ajouterrec(char * filename,reclamation c);
int modifierrec(char * filename, int Id,reclamation nouv);
int supprimerrec(char * filename,int Id);
int chercherrec(char * filename,int Id);

#endif 
   

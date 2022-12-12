#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct electeur1{
	char id[20];
	char cin[20];
  	char username[20];
  	char password[20];
  	char nom[20];
  	char prenom[20];
	char date[30];
  	char sexe[20];
  	char num_bureau[20];
}electeur1;



typedef struct observateur1{
  char nationalite[30];
  char id[30];
  char username[30];
  char password[30];
  char nom[30];
  char prenom[30];
  char appartenance[30];
  char sexe[20];
  char num_bureau[20];
}observateur1;


void lecture_electeur(FILE *f,electeur1 T[]);

void lecture_observateur(FILE *F,observateur1 t[]);

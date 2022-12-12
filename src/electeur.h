#ifndef ELECTEUR_H_INCLUDED
#define ELECTEUR_H_INCLUDED
#include <gtk/gtk.h>

typedef struct {
  	char jour[10];
  	char mois[20];
  	char annee[20];
}date;

typedef struct {
	char id[8];
	char cin[8];
  	char username[20];
  	char password[20];
  	char nom[20];
  	char prenom[20];
  	date Date;
  	char sexe[6];
  	char num_bureau[5];
	int vote;
}electeur;



void ajouter_electeur(electeur);
void supprimer_electeur(char id[]);
electeur chercher_electeur(char x[]);
void modifier_electeur(electeur);
int auto_incre_id_electeur();
#endif 	

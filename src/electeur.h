#ifndef ELECTEUR_H_INCLUDED
#define ELECTEUR_H_INCLUDED
#include <gtk/gtk.h>

typedef struct {
  	char jour[10];
  	char mois[20];
  	char annee[20];
}date;

typedef struct {
	char id[20];
	char cin[20];
  	char username[20];
  	char password[20];
  	char nom[20];
  	char prenom[20];
  	date Date;
  	char sexe[20];
  	char num_bureau[10];
	int vote;
}electeur;



void ajouter_electeur(electeur);
void supprimer_electeur(char id[]);
electeur chercher_electeur(char x[]);
void modifier_electeur(electeur);
int auto_incre_id_electeur();
#endif 	

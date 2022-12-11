#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED



typedef struct {
  char nationalite[30];
  char id[8];
  char username[30];
  char password[30];
  char nom[30];
  char prenom[30];
  char appartenance[30];
  char sexe[6];
  char num_bureau[4];
}observateur;

void ajouter_observateur(observateur);
void supprimer_observateur(char id[8]);
void modifier_observateur(observateur);
observateur chercher_observateur(char x[]);
int auto_incre_id_observateur();

#endif 	

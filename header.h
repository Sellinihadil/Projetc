#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct {
  char jour[3];
  char mois[3];
  char annee[5];
}date;
typedef struct {
  char id[8];
  char cin[8];
  char username[100];
  char password[100];
  char nom[100];
  char prenom[100];
  date d;
  char sexe[2];
  char num_bureau[4];
  char vote[2];
}electeur;

  typedef struct {
  char nationalite[30];
  char id[30];
  char username[30];
  char password[30];
  char nom[30];
  char prenom[30];
  char appartenance[30];
  char sexe[2];
  char num_bureau[4];
}observateur;
void taux ( char *filename , float *tn, float *te);
int nbe(char *filename,int id);

#endif // HEADER_H_INCLUDED

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct{
int jour;
int mois;
int annee;
}date;
typedef struct{
char municipalite[30];
int Idbureau;
char adresse[30];
int numsalle;
int Idagent;
int capaciteelecteurs;
int capaciteobservateurs;
 date date_ajout;
}bureau;
int ajouterbureau(bureau b,char *filename);
int modifierbureau( int Idbureau,bureau nouv,char *filename);
int supprimerbureau( int Idbureau,char *filename);
bureau chercher(int Idbureau,char *filename);
#endif // HEADER_H_INCLUDED

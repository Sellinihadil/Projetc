#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>

typedef struct
{
	int jour;
	int mois;
	int annee;
}date;



typedef struct //struct bureau
{
char idmunip[50];
int idbureau;
char idagent[50];
date date;
int type;
int capelect;
int capobs;
}bureau;

void ajout_bureau(bureau b);
void affichage(bureau b);
int supprimer_bureau(int idbureau);
void modifier(int idmodif,bureau b);
int cherche_id(int idbureau);
void afficher_bureau (GtkWidget * liste);
void vider (GtkWidget *liste);

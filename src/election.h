#ifndef ELECTION_INCLUDED
#define ELECTION_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>


typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    unsigned int nbr_councilers;
    unsigned int nbr_habitants;
    char name[20];
}Municipality;

typedef struct
{
    unsigned int id;
    Date date;
    Municipality municipality;
} Election;



//Election functions
int ajouterElection(char *, Election );
int modifierElection( char *, int, Election );
int supprimerElection(char *, int );
Election chercherElection(char *, int);
void showElections(GtkWidget *list);
void showElection(GtkWidget *list , int elId);
void emptyListView(GtkWidget *list);

//Municipalities functions
void getMunicipalities(char * , Municipality *municipalities);
int getMuniciplityCount(char *);
Municipality findMunicipality(char *file , char*name , int* index);

int getNextId(char *);
#endif 

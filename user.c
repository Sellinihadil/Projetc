#include <stdio.h>
#include "user.h"
#include<string.h>


int ajouter(char * filename, user u )
{
    FILE * f=fopen("utilisateurs.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %u %u %u %u %i %s %s %u %u \n",u.nom,u.prenom,u.cin,u.naissance.jour,u.naissance.mois,u.naissance.annee,u.sexe,u.login,u.password,u.bureau,u.vote);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, user* nouv )
{
    int trouve=0;
    struct user u;
    FILE * f=fopen("utilisateurs.txt", "r");
    FILE * f2=fopen("nouv->txt", "w");
    if(f!=NULL && f2!=NULL)
    
    {
        char str1[30];
        char str2[30];
        while(fscanf(f,"%s %s %u %u %u %u %i %s %s %u %u \n",&(*u.nom),&(*u.prenom),&u.cin,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,&u.sexe,&(*u.login),&(*u.password),&u.bureau,&u.vote)!=EOF);
        {
            if(u.cin== id)
            {
                strcpy(nouv->nom,u.nom);
                strcpy(nouv->prenom,u.prenom);
                fprintf(f2,"%s %s %u %u %u %u %d %s %s %u %d \n",nouv->nom,nouv->prenom,nouv->cin,nouv->naissance.jour,nouv->naissance.mois,nouv->naissance.annee,nouv->sexe,nouv->login,nouv->password,nouv->bureau,nouv->vote);
                trouve=1;
            }
            else
                fprintf(f2,"%s %s %u %u %u %u %i %s %s %u %u \n",u.nom,u.prenom,u.cin,u.naissance.jour,u.naissance.mois,(u.naissance).annee,u.sexe,u.login,u.password,u.bureau,u.vote);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv->txt", "utilisateurs");
    return trouve;

}

int supprimer_utilisateur(char * utilisateurs, int id)
{
    int trouve=0;
    struct user u;
    FILE * f=fopen(utilisateurs, "r");
    FILE * f2=fopen("nouv->txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %u %u %u \n",&(*u.nom),&(*u.prenom),&u.naissance.jour,&u.naissance.mois,&u.naissance.annee)!=EOF);
        {
            if(u.cin== id)
                trouve=1;
            else
                fprintf(f2,"%s %s %u %u %u %u %i %s %s %u %d \n",u.nom,u.prenom,u.cin,u.naissance.jour,u.naissance.mois,u.naissance.annee,u.sexe,u.login,u.password,u.bureau,u.vote);
        }
    }
    fclose(f);
    fclose(f2);
    remove(utilisateurs);
    rename("nouv->txt", utilisateurs);
    return trouve;
}

user chercher_utilisateur(char * utilisateurs, int id)
{
    struct user u;
    int trouve=0;
    FILE * f=fopen("utilisateurs", "r");
    if(f!=NULL)
    {
        while(trouve==0&& fscanf(f,"%s %s %u %u %u %u %i %s %s %u %u \n",&(*u.nom),&(*u.prenom),&u.cin,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,&u.sexe,&(*u.login),&(*u.password),&u.bureau,&u.vote)!=EOF);
        {
            if(u.cin== id)
                trouve=1;
        }
    }
    fclose(f);
    if(trouve==0)
        u.cin=-1;

    return u;

}
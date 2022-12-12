
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "electeur.h"


/*********************************AJOUTER**************************************/

void ajouter_electeur(electeur elcr)
{
  FILE *f;

  f=fopen("electeur.txt","a+");
  if (f != NULL)
  {
    elcr.vote=-1;
    fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,elcr.vote);
    fclose(f);
  }
  ajouterlogin(elcr.username,elcr.password,2);
  
}

/*********************************SUPPRIMER************************************/

void supprimer_electeur(char id[8])
{
  electeur elcr;
  FILE *f;
  FILE *f_tmp;

  f=fopen("electeur.txt","a+");
	f_tmp=fopen("electeur.tmp","w");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,
                                        elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,&elcr.vote)!=EOF)
        {
          if (strcmp(id,elcr.id)!=0)
          {
            fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,
                                        elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,elcr.vote);
          }
        }
        fclose(f);
      	fclose(f_tmp);

      	remove("electeur.txt");
      	rename("electeur.tmp","electeur.txt");
}

/*********************************MODIFIER*************************************/

void modifier_electeur(electeur m)
{
  FILE* f;
  FILE* f_tmp;
  electeur elcr;

  f=fopen("electeur.txt","r");
  f_tmp=fopen("electeur.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,&elcr.vote)!=EOF)
          {
                if (strcmp(m.id,elcr.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,elcr.vote);
                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %i \n",m.id,m.cin,m.username,m.password,m.nom,m.prenom,m.Date.jour,m.Date.mois,m.Date.annee,m.sexe,m.num_bureau,elcr.vote);
                  }

          }
          fclose(f);
          fclose(f_tmp);

          remove("electeur.txt");
          rename("electeur.tmp","electeur.txt");
  }
}

/*********************************CHERCHER*************************************/

electeur chercher_electeur(char x[])
{
  electeur elcr;
  FILE* f;
  f=fopen("electeur.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,
                                        elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,&elcr.vote)!=EOF)
          {
            if (strcmp(x,elcr.id)==0)
              {
                return elcr;
              }
          }
          fclose(f);
  }
  strcpy(elcr.id, "-1");
  return elcr;

}

/*************************ID_INCREMENT_AUTOMATIQUE*****************************/

int auto_incre_id_electeur()
{
  electeur elcr;
  FILE *f;
  int new_id=0;
  char new[8];
  f=fopen("electeur.txt","r+");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,
                                        elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,&elcr.vote)!=EOF)
        {
          strcpy(new,elcr.id);
        }
    fclose(f);
    new_id = atoi(new);
    new_id = new_id +1;
return new_id;
}




























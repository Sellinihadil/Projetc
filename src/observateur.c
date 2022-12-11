#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observateur.h"
#include "login.h"

//ajouter
void ajouter_observateur(observateur obser)
{
  FILE *f;

  f=fopen("observateur.txt","a+");

  if (f != NULL)
  {
    fprintf(f,"%s %s %s %s %s %s %s %s %s    \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance);
    fclose(f);
  }
 ajouterlogin(obser.username,obser.password,4);
}


//supprimer

void supprimer_observateur(char id[8])
{
  observateur obser;
  FILE *f;
  FILE *f_tmp;

  f=fopen("observateur.txt","a+");
	f_tmp=fopen("observateur.tmp","w");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s    \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance)!=EOF)
        {
          if (strcmp(id,obser.id)!=0)
          {
            fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s  \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance);
          }
        }
        fclose(f);
      	fclose(f_tmp);

      	remove("observateur.txt");
      	rename("observateur.tmp","observateur.txt");
}

//modifier

void modifier_observateur(observateur m)
{
  FILE* f;
  FILE* f_tmp;
  observateur obser;

  f=fopen("observateur.txt","r");
  f_tmp=fopen("observateur.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s    \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance)!=EOF)
          {
                if (strcmp(m.id,obser.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s  \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance);
                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s  \n",m.id,m.nationalite,m.username,m.password,m.nom,m.prenom,m.sexe,m.num_bureau,m.appartenance);
                  }

          }
          fclose(f);
          fclose(f_tmp);

          remove("observateur.txt");
          rename("observateur.tmp","observateur.txt");
  }
}


//recherche

observateur chercher_observateur(char x[])
{
  observateur obser;
  FILE* f;
  f=fopen("observateur.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s    \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance)!=EOF)
          {
            if (strcmp(x,obser.id)==0)
              {
                return obser;
              }
          }
          fclose(f);
  }

  strcpy(obser.id, "-1");
  return obser;
}


//Incrementation de l ID 


int auto_incre_id_observateur()
{
  observateur obser;
  FILE *f;
  int nouv_id=0;
  char new[10];
  f=fopen("observateur.txt","r+");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s    \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance)!=EOF)
        {
          strcpy(new,obser.id);
        }
    fclose(f);
    nouv_id = atoi(new);
    nouv_id = nouv_id +1;
return nouv_id;
}





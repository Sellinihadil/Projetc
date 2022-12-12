#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "interface.h"



int verifierlogin(char username[], char password[])
{
  users tableau[100];
  char util[20]; char passw[20]; int role;
  int nbline=0; int i=0;
  FILE *f;
  
  GtkWidget *panneau_admin_window;
  GtkWidget *agent_window;
  int verif =0;

  f= fopen("users.txt","r");

  if (f != NULL)
  {
    while (fscanf(f,"%s %s %d\n",util,passw,&role) != EOF)
    {
      nbline++;
      strcpy(tableau[i].nom, util);
      strcpy(tableau[i].motdepasse, passw);
      tableau[i].rol = role;
      i++;
    }
    fclose(f);
  }

  for (i=0; i<nbline; i++)
  {
    if ((strcmp(tableau[i].nom, username)== 0) && (strcmp(tableau[i].motdepasse, password)== 0))
      {
        switch (tableau[i].rol)
        {
          case 1: //Admin_window

     		  panneau_admin_window = create_panneau_admin_window ();
          gtk_widget_show (panneau_admin_window);
            break;
          case 2: //agent_window
                  agent_window = create_agent_window ();
                  gtk_widget_show (agent_window);
                  
            break;

          
        }
        verif =tableau[i].rol;
        break;
      }

  }
  return verif;
}

int verifierexistant (char username[])
{
  int verif =-1;
  users tableau[100];
  FILE *f;
  char user[20];
  int nbline=0, i;

  f= fopen("users.txt","r");

  if (f != NULL)
    {
      while (fscanf(f,"%s",user) != EOF)
      {
        
        strcpy(tableau[nbline].nom ,user);
        nbline ++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(username, tableau[i].nom) == 0)
        {
          verif = 0; //Existant
          break;
        }
      else
      {
        verif =1; //inéxistant
      }
    }
  return verif;
}

void ajouterlogin (char username[], char password[], int role)
{
  FILE *f;
  int nouveau =0;
  //char utilisateur[20]; char pwd[20]; int role;

  f= fopen("users.txt","a+");

  if (f!= NULL)
  {
    nouveau = verifierexistant(username);
    if (nouveau == 1)
      {
        fprintf(f, "%s %s %d\n",username,password,role );
      }
    fclose(f);
  }
}

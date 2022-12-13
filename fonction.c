#ifdef HAVE_CONFIG_H
#include "fonction.h"
#include <malloc.h>
#include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


enum
{
EIDMUNIP,
EIDBV,
EIDAGENT,
EJOUR,
EMOIS,
EANNEE,
ETYPE,
ECAPE,
ECAPO,
COLUMNS
};


int cherche_id(int idbureau)
{
FILE *f ;
bureau b;
int x=0;
    f=fopen("bureau.txt","r");
 if(f!=NULL)
    {
	while(fscanf(f,"%s %d %s %d %d %d %d %d %d \n",b.idmunip,&b.idbureau,b.idagent,&b.date.jour,&b.date.mois,&b.date.annee,&b.type,&b.capelect,&b.capobs)!=EOF)
	{ 
 	 if(b.idbureau!=idbureau)
{
	  x=1;
}
else
{ 
x=0;
}
}
}
fclose(f);

return x;
}

void ajout_bureau(bureau b)
{
FILE *f;
f=fopen("bureau.txt","a+");
		if(f!=NULL)
		{
			fprintf(f,"%s %d %s %d %d %d %d %d %d \n",b.idmunip,b.idbureau,b.idagent,b.date.jour,b.date.mois,b.date.annee,b.type,b.capelect,b.capobs);
			fclose(f);
		}
}	
void modifier(int idmodif,bureau b)
{
  FILE *f;
    FILE *g;
    g=NULL;
    bureau bm ;
   
    f=fopen("bureau.txt","r+");
    g=fopen("bureau_modifie.txt","a+");
	printf("2\n");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %d %s %d %d %d %d %d %d \n",bm.idmunip,&bm.idbureau,bm.idagent,&bm.date.jour,&bm.date.mois,&bm.date.annee,&bm.type,&bm.capelect,&bm.capobs)!=EOF);
        {
	printf("3\n"); 
            if(idmodif==bm.idbureau)
            {
		      	printf("4\n"); 
		       bm.type=b.type;
		       bm.capelect=b.capelect;
                       bm.capobs=b.capobs;
                       
                       
            }
            fprintf(g,"%s %d %s %d %d %d %d %d %d \n",bm.idmunip,bm.idbureau,bm.idagent,bm.date.jour,bm.date.mois,bm.date.annee,bm.type,bm.capelect,bm.capobs);
        }

    }
    fclose(g);
    fclose(f);
    remove("bureau.txt");
    rename("bureau_modifie.txt","bureau.txt");



}


int supprimer_bureau (int idbureau)
{
FILE *f ;
FILE *g;
bureau b;
int x=0;
    f=fopen("bureau.txt","r");
    g=fopen("ancien_bureau","w+");
 if(f!=NULL)
    {
	while(fscanf(f,"%s %d %s %d %d %d %d %d %d \n",b.idmunip,&b.idbureau,b.idagent,&b.date.jour,&b.date.mois,&b.date.annee,&b.type,&b.capelect,&b.capobs)!=EOF)
	{ 
 	 if(b.idbureau!=idbureau)
{
	  fprintf(g,"%s %d %s %d %d %d %d %d %d \n",b.idmunip,b.idbureau,b.idagent,b.date.jour,b.date.mois,b.date.annee,b.type,b.capelect,b.capobs);
	  x=1;
}
else
{ 
x=0;
}
}
}
fclose(f);
fclose(g);
remove("bureau.txt");
rename("ancien_bureau","bureau.txt");
return x;
}




void afficher_bureau(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char idmunip[50];
	int idbureau;
	char idagent[50];
	date date;
	int type;
	int capelect;
	int capobs;
	char ch[20];
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ID Municipalité",renderer, "text",EIDMUNIP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ID Bureau",renderer, "text",EIDBV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ID Agent",renderer, "text",EIDAGENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Authentification",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Capacité des élécteurs",renderer, "text",ECAPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Capacité des observateurs",renderer, "text",ECAPO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	
	store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	f=fopen("bureau.txt","a+");
	if (f==NULL)
	{
		return;
	}
	else
	{ f=fopen("bureau.txt","a+");
		while (fscanf(f,"%s %d %s %d %d %d %d %d %d \n",idmunip,&idbureau,idagent,&date.jour,&date.mois,&date.annee,&type,&capelect,&capobs)!=EOF)
			{
				if (type==1)
					strcpy(ch,"CIN");
				else if (type==2)
					strcpy(ch,"Passeport"); 
				else if (type==3)
					strcpy(ch,"Empreinte");
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDMUNIP,idmunip,EIDBV,idbureau,EIDAGENT,idagent,EJOUR,date.jour,EMOIS,date.mois,EANNEE,date.annee,ETYPE,ch,ECAPE,capelect,ECAPO,capobs,-1);
			}
			fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}
}
void vider (GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;

	
	char idmunip[50];
	int idbureau;
	char idagent[50];
	date date;
	int type;
	int capelect;
	int capobs;
	char ch[20];
	store=NULL;
	FILE *f;
store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ID Municipalité",renderer, "text",EIDMUNIP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	idbureau = gtk_tree_view_column_new_with_attributes(" ID Bureau",renderer, "text",EIDBV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ID Agent",renderer, "text",EIDAGENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Authentification",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Capacité des élécteurs",renderer, "text",ECAPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Capacité des observateurs",renderer, "text",ECAPO,NULL);
	store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);	
}
if (type==1)
strcpy(ch,"CIN");
else if (type==2)
strcpy(ch,"Passeport"); 
else if (type==3)
strcpy(ch,"Empreinte");

store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}



#include "treeview.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>



/* ----------------------------------------------------- TREE_VIEW_ELECTEUR ------------------------------------------------------------- */


static GtkTreeModel * create_and_fill_model_electeur (GtkWidget *treeview_electeur,electeur1 T[])
{
    GtkListStore  *store;
    GtkTreeIter    iter;
    int i,nbline=0;
    char c;
    char filename[20]="electeur.txt";
    FILE *f;
    f=fopen(filename,"r");
    while ((c=fgetc(f))!=EOF)
    {
        if (c=='\n')
        nbline++;
    }
    
    store = gtk_list_store_new (9, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING/*, G_TYPE_INT*/);
    /* ajouter une ligne et remplir les donner de lelecteur */
    for(i=0;i<nbline;i++)
    {
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter,COL_id,T[i].id,COL_cin,T[i].cin,COL_username,T[i].username,COL_password,T[i].password,COL_nom,T[i].nom,COL_prenom,T[i].prenom,COL_date,T[i].date,COL_sexe,T[i].sexe,COL_num_bureau,T[i].num_bureau/*,COL_vote,T[i].vote*/,-1);
    }
    
    return GTK_TREE_MODEL (store);
}


static GtkWidget * create_view_and_model_electeur (GtkWidget *treeview_electeur, electeur1 T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;
  

  /* --- Colonne 1 --- */
  
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"Identifiant",renderer,"text", COL_id,NULL);

  /* --- Colonne 2 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"Nom",renderer,"text", COL_nom,NULL);

  /* --- Colonne 3 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"Prenom",renderer,"text", COL_prenom,NULL);

  /* --- Colonne 4 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"CIN",renderer,"text", COL_cin,NULL);

  /* --- Colonne 5 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"date de naissance",renderer,"text", COL_date,NULL);

  /* --- Colonne 6 --- */
  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"NUM De Bureau de vote",renderer,"text", COL_num_bureau,NULL);

  /* --- Colonne 7 --- */
    col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"Login",renderer,"text", COL_username,NULL);

  /* --- Colonne 8 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"Mot de passe",renderer,"text", COL_password,NULL);

  /* --- Colonne 9 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_electeur),-1,"Genre",renderer,"text", COL_sexe,NULL);

  /* --- Colonne 10 --- 
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW (treeview_electeur),-1,"VOTE",renderer,"text", COL_vote,NULL);
*/

  model = create_and_fill_model_electeur (treeview_electeur,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_electeur), model);

  g_object_unref (model); /* destroy model automatically with view */



  return (treeview_electeur);

}

 /* ----------------------------------------------------- AFFICHER_LES_ELECTEURS ------------------------------------------------------------- */

void affichageelecteur (GtkWidget *treeview_electeur, electeur1 T[])
{

    treeview_electeur = create_view_and_model_electeur (treeview_electeur,T);
}


 
 
/* ----------------------------------------------------- TREE_VIEW_OBSERVATEUR ------------------------------------------------------------- */


static GtkTreeModel * create_and_fill_model_observateur (GtkWidget *treeview_observateur,observateur1 T[])
{
    GtkListStore  *store;
    GtkTreeIter    iter;
    int i,nbline=0;
    char c;
    char filename[20]="observateur.txt";
    FILE *f;
    f=fopen(filename,"r");
    while ((c=fgetc(f))!=EOF)
    {
        if (c=='\n')
        nbline++;
    }
    store = gtk_list_store_new (COL_observateur, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    /* ajouter une ligne et remplir les donner de lobservateur */
    for(i=0;i<nbline;i++)
    {
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter,COL_ido,T[i].id,COL_nationaliteo,T[i].nationalite,COL_usernameo,T[i].username,COL_passwordo,T[i].password,COL_nomo,T[i].nom,COL_prenomo,T[i].prenom,COL_sexeo,T[i].sexe,COL_num_bureauo,T[i].num_bureau,COL_appartenanceo,T[i].appartenance,-1);
    }
    return GTK_TREE_MODEL (store);
}


static GtkWidget * create_view_and_model_observateur (GtkWidget *treeview_observateur, observateur1 T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

 /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"Identifiant",renderer,"text", COL_ido,NULL);

  /* --- Colonne 2 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"Nationalité",renderer,"text", COL_nationaliteo,NULL);

  /* --- Colonne 3 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"NOM d'utilisateur",renderer,"text", COL_usernameo,NULL);

  /* --- Colonne 4 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"Mot De Passe",renderer,"text", COL_passwordo,NULL);

  /* --- Colonne 5 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"Nom",renderer,"text", COL_nomo,NULL);

  /* --- Colonne 6 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"Prénom",renderer,"text", COL_prenomo,NULL);

  /* --- Colonne 7 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"Sexe",renderer,"text", COL_sexeo,NULL);

  /* --- Colonne 8 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"Numéro de bureau",renderer,"text", COL_num_bureauo,NULL);

  /* --- Colonne 9 --- */
col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_observateur),-1,"appartenance",renderer,"text", COL_appartenanceo,NULL);


  model = create_and_fill_model_observateur (treeview_observateur,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_observateur), model);

  g_object_unref (model); /* destroy model automatically with view */



  return (treeview_observateur);

}

 /* ----------------------------------------------------- AFFICHER_LES_observateurS ------------------------------------------------------------- */

void affichageobservateur (GtkWidget *treeview_observateur, observateur1 T[])
{
    treeview_observateur = create_view_and_model_observateur (treeview_observateur,T);
}



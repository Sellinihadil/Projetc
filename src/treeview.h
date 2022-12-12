#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include <gtk/gtk.h>

enum
{   
    COL_id=0,
	  COL_cin,
  	COL_username,
  	COL_password,
  	COL_nom,
  	COL_prenom,
  	COL_sexe,
    COL_date,
  	COL_num_bureau,
    COLUMNS_elcteur,
    COL_vote
};
enum{
    COL_ido=0,
    COL_nationaliteo,
    COL_usernameo,
    COL_passwordo,
    COL_nomo,
    COL_prenomo,
    COL_sexeo,
    COL_num_bureauo,
    COL_appartenanceo,
    COL_observateur
};


static GtkTreeModel * create_and_fill_model_electeur (GtkWidget *treeview_electeur,electeur1 T[]);
static GtkWidget * create_view_and_model_electeur (GtkWidget *treeview_electeur, electeur1 T[]);
void affichageelecteur (GtkWidget *treeview_electeur, electeur1 T[]);


static GtkTreeModel * create_and_fill_model_observateur (GtkWidget *treeview_observateur,observateur1 T[]);
static GtkWidget * create_view_and_model_observateur (GtkWidget *treeview_observateur, observateur1 T[]);
void affichageobservateur (GtkWidget *treeview_observateur, observateur1 T[]);
void emptyElecteurTreeView(GtkWidget*);





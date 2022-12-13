#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "fonction.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

int type2=0;

void
on_button_ajouter_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_ajouter ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}


void
on_button_supprimer_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_supprimer ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}


void
on_button_afficher_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_afficher ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_modifier_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_modifier ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}



void
on_button_chercher_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"interface");
	window2 = create_window_chercher ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


int x;
void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=2;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=3;
}
void
on_button_confirmer_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
 *idmunip,*idbureau,*idagent,*jour,*mois,*annee,*type,*capelect,*capobs,*windowinterface;


bureau b;

jour=lookup_widget(objet_graphique,"spinbutton_jour");
b.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois=lookup_widget(objet_graphique,"spinbutton_mois");
b.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee=lookup_widget(objet_graphique,"spinbutton_annee");
b.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

idmunip=lookup_widget(objet_graphique,"entry_idmunip");
idbureau=lookup_widget(objet_graphique,"entry_idbureau");
idagent=lookup_widget(objet_graphique,"entry_idagent");
capelect=lookup_widget(objet_graphique,"entry_cape");
capobs=lookup_widget(objet_graphique,"entry_capo");
strcpy(b.idmunip,gtk_entry_get_text(GTK_ENTRY(idmunip)));
b.idbureau=atoi(gtk_entry_get_text(GTK_ENTRY(idbureau)));
strcpy(b.idagent,gtk_entry_get_text(GTK_ENTRY(idagent)));
b.capelect=atoi(gtk_entry_get_text(GTK_ENTRY(capelect)));
b.capobs=atoi(gtk_entry_get_text(GTK_ENTRY(capobs)));
if (x==1)
b.type=1;
else if (x==2)
b.type=2;
else if (x==3)
b.type=3;
ajout_bureau(b);

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"window_ajouter");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}

void
on_button_supp_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
*idbureau,*type,*output;
int x;
output=lookup_widget(objet_graphique,"label21");
idbureau=lookup_widget(objet_graphique,"entry5");
idbureau=atoi(gtk_entry_get_text(GTK_ENTRY(idbureau)));
x=supprimer_bureau (idbureau);
if (x==0)
gtk_label_set_text(GTK_LABEL(output),"bureau est supprimé avec succé");
else
gtk_label_set_text(GTK_LABEL(output),"bureau n'est pas supprimé");

}



void
on_button_defect_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	
	
}


void
on_button_modif_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *idbureau,*type,*vmax,*vmin;
	bureau b;
	idbureau=lookup_widget(button,"entry_modif");
	//type=lookup_widget(button,"label21");
	vmax=lookup_widget(button,"entry_nmax");
	vmin=lookup_widget(button,"entry_nmin");
	b.idbureau=atoi(gtk_entry_get_text(GTK_ENTRY(idbureau)));
	b.capelect=atoi(gtk_entry_get_text(GTK_ENTRY(vmax)));
	b.capobs=atoi(gtk_entry_get_text(GTK_ENTRY(vmin)));
	b.type=type2;
	
	printf("%d\n",type2);
	modifier(b.idbureau,b);

}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(button,"window_afficher");
window_afficher=create_window_afficher();
gtk_widget_show(window_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(window_afficher,"treeview1");
afficher_bureau(treeview1);

}


void
on_button12_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_afficher");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget
*idbureau,*type,*output;
int x;
output=lookup_widget(button,"label24");
idbureau=lookup_widget(button,"entry_d");
idbureau=atoi(gtk_entry_get_text(GTK_ENTRY(idbureau)));
x=cherche_id(idbureau);
if (x==0)
gtk_label_set_text(GTK_LABEL(output),"Le bureau existe, veillez le modifier ou le supprimer");
else
gtk_label_set_text(GTK_LABEL(output),"Le bureau n'existe pas");
}

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	type2=1;
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	type2=2;
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	type2=3;
}


void
on_button13_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_supprimer");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button14_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_modifier");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button15_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_modifier");
	window2 = create_window_afficher ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);

}


void
on_button16_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
	
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_chercher");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_check_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_chercher");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}



void
on_button17_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_ajouter");
	window2 = create_interface ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


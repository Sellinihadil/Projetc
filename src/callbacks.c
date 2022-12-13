#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "login.h"
#include "treeview.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "electeur.h"
#include "observateur.h"
#include <string.h>
#include <stdbool.h>
#include "election.h"
#include "stat.h"
#include "controle_saisie.h"

int sexe = 0;

void genre(int sexe, char msg[])
{
  if (sexe == 0)
  {
    strcpy(msg, "homme");
  }
  else if (sexe == 1)
  {
    strcpy(msg, "femme");
  }
}

void
on_modifier_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_supprimer1_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_modifier2_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_item2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void on_ajouter_electeur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *ajoutelec;
  ajoutelec = create_ajouter_electeur_window();
  gtk_widget_show(ajoutelec);
  GtkWidget *admin_pannel;
  admin_pannel = lookup_widget(objet_graphique, "admin_window");
  gtk_widget_hide(admin_pannel);
}



void on_go_modifier_electeur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *modifelec;
  modifelec = create_edit_electeur_window();
  gtk_widget_show(modifelec);
}


void on_actualiser_electeur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
   GtkWidget *Admin_window;
   GtkWidget *old;
    old=lookup_widget(objet_graphique, "admin_window");
    gtk_widget_hide(old);

   Admin_window = create_admin_window ();
   gtk_widget_show (Admin_window);

 /*  GtkWidget *ListView;
  ListView = lookup_widget(objet_graphique, "treeview_electeur");
  FILE *f;

  emptyElecteurTreeView(ListView);
  electeur1 T[200];
    
  lecture_electeur(f,T);
  affichageelecteur(ListView,T); */
}



void on_Deconnecter_admin_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *admin;
  admin = lookup_widget(objet_graphique, "admin_window");
  gtk_widget_hide(admin);
  GtkWidget *panneau;
  panneau = create_panneau_admin_window();
  gtk_widget_show(panneau);
}


void
on_annuler_electeur_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
   GtkWidget *ajouter_nouveau_electeur;
    ajouter_nouveau_electeur = lookup_widget(objet_graphique, "ajouter_electeur_window");
    gtk_widget_hide(ajouter_nouveau_electeur); 
    GtkWidget *admin;
    admin=create_admin_window();
    gtk_widget_show(admin);
}


void on_valider_electeur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *input9;
  GtkWidget *input10;
  GtkWidget *output8;
  GtkWidget *input11;
  GtkWidget *popup;
  GtkWidget *togglebutton1;
  GtkWidget *togglebutton2;

  input1 = lookup_widget(objet_graphique, "nom_electeur");
  input2 = lookup_widget(objet_graphique, "prenom_electeur");
  input3 = lookup_widget(objet_graphique, "jj_electeur");
  input4 = lookup_widget(objet_graphique, "mm_electeur");
  input5 = lookup_widget(objet_graphique, "aa_electeur");
  input7 = lookup_widget(objet_graphique, "cin_electeur");
  output8 = lookup_widget(objet_graphique, "id_electeur");
  input9 = lookup_widget(objet_graphique, "num_bureau_electeur");
  input10 = lookup_widget(objet_graphique, "login_electeur");
  input11 = lookup_widget(objet_graphique, "motdepasse_electeur");
  popup = lookup_widget(objet_graphique, "message_ajout_electeur");

  togglebutton1 = lookup_widget(objet_graphique, "homme_electeur");
  togglebutton2 = lookup_widget(objet_graphique, "femme_electeur");

  electeur el;
  int datemois = gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;
  sprintf(el.Date.mois, "%.2d", datemois);
  int datejour = gtk_combo_box_get_active(GTK_COMBO_BOX(input3)) + 1;
  sprintf(el.Date.jour, "%.2d", datejour);

  char msg[20];
  int nouveau_id = auto_incre_id_electeur();
  char no_id[10];
  sprintf(no_id, "%d", nouveau_id);
  strcpy(el.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(el.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(el.Date.annee, gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(el.cin, gtk_entry_get_text(GTK_ENTRY(input7)));
  strcpy(el.id, no_id);
  el.vote = -1;
  strcpy(el.num_bureau, gtk_entry_get_text(GTK_ENTRY(input9)));
  strcpy(el.username, gtk_entry_get_text(GTK_ENTRY(input10)));
  strcpy(el.password, gtk_entry_get_text(GTK_ENTRY(input11)));
  genre(sexe, msg);
  strcpy(el.sexe, msg);
  if ((verifierexistant(el.username) != 0)&&(controle_saisie_numero(el.cin)==1)&&(controle_saisie_annee(el.Date.annee)==1))
  {
    ajouter_electeur(el);
    gtk_label_set_text(GTK_LABEL(popup), "Ajouter avec succées");
    GtkWidget *valider;
    valider = lookup_widget(objet_graphique, "ajouter_electeur_window");
    gtk_widget_hide(valider);
    GtkWidget *admin;
    
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(popup), "Erreur ajout !");
  }

  
  
}


void on_homme_electeur_toggled(GtkToggleButton *togglebutton,
                               gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  {
    sexe = 0;
  }
}


void on_femme_electeur_toggled(GtkToggleButton *togglebutton,
                               gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  {
    sexe = 1;
  }
}



void on_femme_observateur_toggled(GtkToggleButton *togglebutton,
                                  gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  {
    sexe = 1;
  }
}












void on_annuler_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *ajouter_nouveau_observateur;
  ajouter_nouveau_observateur = lookup_widget(objet_graphique, "ajouter_observateurs_window");
  gtk_widget_hide(ajouter_nouveau_observateur);
}

void on_valider_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *input9;
  GtkWidget *input10;
  GtkWidget *output8;
  GtkWidget *input11;
  GtkWidget *popup;
  GtkWidget *togglebutton1;
  GtkWidget *togglebutton2;

  input1 = lookup_widget(objet_graphique, "nom_observateur");
  input2 = lookup_widget(objet_graphique, "prenom_observateur");
  input3 = lookup_widget(objet_graphique, "nationalite_observateur_combobox");
  input4 = lookup_widget(objet_graphique, "appartenance_observateur_combobox");
  output8 = lookup_widget(objet_graphique, "identifiant_observateur");
  input9 = lookup_widget(objet_graphique, "num_bureau_observateur");
  input10 = lookup_widget(objet_graphique, "login_observateur");
  input11 = lookup_widget(objet_graphique, "motdepasse_observateur");
  popup = lookup_widget(objet_graphique, "message_ajout_observateur");

  togglebutton1 = lookup_widget(objet_graphique, "homme_observateur");
  togglebutton2 = lookup_widget(objet_graphique, "femme_observateur");

  observateur obs;

  char msg[20];
  int nouveau_id = auto_incre_id_observateur();
  char no_id[20];
  sprintf(no_id, "%d", nouveau_id);
  strcpy(obs.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(obs.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
  int active_nationalite = gtk_combo_box_get_active(GTK_COMBO_BOX(input3)) + 1;
  sprintf(obs.nationalite, "%.2d", active_nationalite);
  int active_appartenance = gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;
  sprintf(obs.appartenance, "%.2d", active_appartenance);
  strcpy(obs.id, no_id);
  strcpy(obs.num_bureau, gtk_entry_get_text(GTK_ENTRY(input9)));
  strcpy(obs.username, gtk_entry_get_text(GTK_ENTRY(input10)));
  strcpy(obs.password, gtk_entry_get_text(GTK_ENTRY(input11)));
  genre(sexe, msg);
  strcpy(obs.sexe, msg);
  if (verifierexistant(obs.username) != 0)
  {
    ajouter_observateur(obs);
    gtk_label_set_text(GTK_LABEL(popup), "Ajouter avec succées");
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(popup), "Erreur ajout (observateur déja existe)");
  }
  GtkWidget *valider;

  valider = lookup_widget(objet_graphique, "ajouter_observateurs_window");
  gtk_widget_hide(valider);
  
}


void on_homme_observateur_toggled(GtkToggleButton *togglebutton,
                                  gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  {
    sexe = 0;
  }
}



void on_modifier_electeur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{



  GtkWidget *input;
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *input9;
  GtkWidget *input10;
  GtkWidget *input8;
  GtkWidget *input11;
  GtkWidget *popup;
  GtkWidget *togglebutton1;
  GtkWidget *togglebutton2;

  input = lookup_widget(objet_graphique, "recherche_id_electeur");
  input1 = lookup_widget(objet_graphique, "modif_nom_electeur");
  input2 = lookup_widget(objet_graphique, "modif_prenom_electeur");
  input3 = lookup_widget(objet_graphique, "modif_jj_electeur");
  input4 = lookup_widget(objet_graphique, "modif_mm_electeur");
  input5 = lookup_widget(objet_graphique, "modif_aa_electeur");
  input7 = lookup_widget(objet_graphique, "modif_cin_electeur");
  input8 = lookup_widget(objet_graphique, "modif_identifiant_electeur");
  input9 = lookup_widget(objet_graphique, "modif_num_bureau_electeur");
  input10 = lookup_widget(objet_graphique, "modif_login_electeur");
  input11 = lookup_widget(objet_graphique, "modif_motdepasse");
  popup = lookup_widget(objet_graphique, "message_edit_electeur");
  electeur el;
  char test[20];
  strcpy(test, gtk_entry_get_text(GTK_ENTRY(input)));

  togglebutton1 = lookup_widget(objet_graphique, "homme_modif_electeur");
  togglebutton2 = lookup_widget(objet_graphique, "femme_modif_electeur");
  el = chercher_electeur(test);

  int datejour = gtk_combo_box_get_active(GTK_COMBO_BOX(input3)) + 1;
  sprintf(el.Date.jour, "%.2d", datejour);
  int datemois = gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;
  sprintf(el.Date.mois, "%.2d", datemois);

  strcpy(el.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(el.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(el.Date.annee, gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(el.cin, gtk_entry_get_text(GTK_ENTRY(input7)));
  strcpy(el.username, gtk_entry_get_text(GTK_ENTRY(input10)));
  strcpy(el.password, gtk_entry_get_text(GTK_ENTRY(input11)));
  strcpy(el.num_bureau, gtk_entry_get_text(GTK_ENTRY(input9)));
  char msg[20];
  genre(sexe, msg);
  strcpy(el.sexe, msg);
  
  
  if ((strcmp(el.id, "-1") != 0)&&(controle_saisie_annee(el.Date.annee)==1)&&(controle_saisie_numero(el.cin)==1))
  {
    modifier_electeur(el);
    gtk_label_set_text(GTK_LABEL(popup), "Modification avec succées");
    GtkWidget *modif;
    
    modif=lookup_widget(objet_graphique,"edit_electeur_window");
    gtk_widget_hide(modif);
    

  }
  else
  {
    gtk_label_set_text(GTK_LABEL(popup), "Erreur Modification");

  }
}


void on_supprimer_electeur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *popup;
  popup = lookup_widget(objet_graphique, "message_edit_electeur");
  input = lookup_widget(objet_graphique, "recherche_id_electeur");
  char supprimer[20];
  strcpy(supprimer, gtk_entry_get_text(GTK_ENTRY(input)));
  if (strcmp(supprimer, "-1") != 0)
  {
    supprimer_electeur(supprimer);
    gtk_label_set_text(GTK_LABEL(popup), "Suppression avec succées");
    GtkWidget *edit;
    edit=lookup_widget(objet_graphique,"edit_electeur_window");
    gtk_widget_hide(edit);
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(popup), "Erreur De Suppression");
  }
}


void on_chercher_electeur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *input9;
  GtkWidget *input10;
  GtkWidget *input8;
  GtkWidget *input11;
  GtkWidget *popup;
  GtkWidget *togglebutton1;
  GtkWidget *togglebutton2;

  electeur el;

  input = lookup_widget(objet_graphique, "recherche_id_electeur");
  input1 = lookup_widget(objet_graphique, "modif_nom_electeur");
  input2 = lookup_widget(objet_graphique, "modif_prenom_electeur");
  input3 = lookup_widget(objet_graphique, "modif_jj_electeur");
  input4 = lookup_widget(objet_graphique, "modif_mm_electeur");
  input5 = lookup_widget(objet_graphique, "modif_aa_electeur");
  input7 = lookup_widget(objet_graphique, "modif_cin_electeur");
  input8 = lookup_widget(objet_graphique, "modif_identifiant_electeur");
  input9 = lookup_widget(objet_graphique, "modif_num_bureau_electeur");
  input10 = lookup_widget(objet_graphique, "modif_login_electeur");
  input11 = lookup_widget(objet_graphique, "modif_motdepasse");
  popup = lookup_widget(objet_graphique, "message_recherche_electeur");

  togglebutton1 = lookup_widget(objet_graphique, "homme_modif_electeur");
  togglebutton2 = lookup_widget(objet_graphique, "femme_modif_electeur");

  char id[10];
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  el = chercher_electeur(id);
  if (strcmp(el.id, "-1") == 0)
  {
    gtk_label_set_text(GTK_LABEL(popup), "Aucun électeur n'est inscrit avec cet identifiant, veuillez réessayer");
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(popup), "Id existant");
    gtk_entry_set_text(GTK_ENTRY(input10), el.username);
    gtk_entry_set_text(GTK_ENTRY(input11), el.password);
    gtk_entry_set_text(GTK_ENTRY(input1), el.nom);
    gtk_entry_set_text(GTK_ENTRY(input2), el.prenom);
    gtk_entry_set_text(GTK_ENTRY(input5), el.Date.annee);
    gtk_entry_set_text(GTK_ENTRY(input9), el.num_bureau);
    gtk_entry_set_text(GTK_ENTRY(input8), el.id);
    gtk_entry_set_text(GTK_ENTRY(input7), el.cin);
    gtk_combo_box_set_active(GTK_COMBO_BOX(input3), (atoi(el.Date.jour) - 1));
    gtk_combo_box_set_active(GTK_COMBO_BOX(input4), (atoi(el.Date.mois) - 1));
    if (strcmp(el.sexe, "homme") == 0)
    {
      gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton1), TRUE);
    }
    else if (strcmp(el.sexe, "femme") == 0)
    {
      gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton2), TRUE);
    }
  }
}


void on_homme_modif_electeur_toggled(GtkToggleButton *togglebutton,
                                     gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  {
    sexe = 0;
  }
}

void on_femme_modif_electeur_toggled(GtkToggleButton *togglebutton,
                                     gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  {
    sexe = 1;
  }
}


void on_modfier_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *output2;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *nationalite_combo;
  GtkWidget *appartenance_combo;
  GtkWidget *num_bureau_entry;

  GtkWidget *togglebutton1, *togglebutton2;

  observateur obs;
  input1 = lookup_widget(objet_graphique, "txt_chercher_observateur");
  output = lookup_widget(objet_graphique, "message_rechercher_observateur");
  output2 = lookup_widget(objet_graphique, "message_edit_observateur");
  nom_entry = lookup_widget(objet_graphique, "modif_nom_observateur");
  prenom_entry = lookup_widget(objet_graphique, "modif_prenom_observateur");
  username_entry = lookup_widget(objet_graphique, "modif_login_observateur");
  password_entry = lookup_widget(objet_graphique, "modif_motdepasse_observateur");
  nationalite_combo = lookup_widget(objet_graphique, "modif_nationalite_combobox");
  appartenance_combo = lookup_widget(objet_graphique, "modif_appartenance_combobox");
  num_bureau_entry = lookup_widget(objet_graphique, "modif_numerobureau_observateur");
  togglebutton1 = lookup_widget(objet_graphique, "homme_modif_observateur");
  togglebutton2 = lookup_widget(objet_graphique, "femme_modif_observateur");
  char id[20];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  obs = chercher_observateur(id);
  if (strcmp(obs.id, "-1") == 0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Aucun observateur n'est inscrit avec cet identifiant, veuillez réessayer");
  }
  else
  {

    strcpy(obs.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(obs.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(obs.nationalite, gtk_combo_box_get_active_text(GTK_COMBO_BOX(nationalite_combo)));
    strcpy(obs.appartenance, gtk_combo_box_get_active_text(GTK_COMBO_BOX(appartenance_combo)));
    char nationalite[30];
    char appartenance[30];
    int active_nationalite = gtk_combo_box_get_active(GTK_COMBO_BOX(nationalite_combo)) + 1;
    sprintf(nationalite, "%.2d", active_nationalite);
    int active_appartenance = gtk_combo_box_get_active(GTK_COMBO_BOX(appartenance_combo)) + 1;
    sprintf(appartenance, "%.2d", active_appartenance);

    strcpy(obs.nationalite, nationalite);
    strcpy(obs.appartenance, appartenance);

    strcpy(obs.num_bureau, gtk_entry_get_text(GTK_ENTRY(num_bureau_entry)));
    strcpy(obs.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(obs.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    char msg[20];
    genre(sexe, msg);
    strcpy(obs.sexe, msg);
    modifier_observateur(obs);

    gtk_label_set_text(GTK_LABEL(output2), "Champs modifier avec succès");

    GtkWidget *edit_observateur;
    GtkWidget *gestion;
    gestion=create_agent_window();
    edit_observateur = lookup_widget(objet_graphique, "edit_observateur_window");
    gtk_widget_hide(edit_observateur);
    gtk_widget_show(gestion);
  }
}


void on_supprimer_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *popup;
  popup = lookup_widget(objet_graphique, "message_edit_observateur");
  input = lookup_widget(objet_graphique, "txt_chercher_observateur");
  char supprimer[20];
  strcpy(supprimer, gtk_entry_get_text(GTK_ENTRY(input)));
  if (strcmp(supprimer, "-1") != 0)
  {
    supprimer_observateur(supprimer);
    gtk_label_set_text(GTK_LABEL(popup), "Suppression avec succées");
    GtkWidget *agent;
    GtkWidget *edit;
    agent=create_agent_window();
    edit=lookup_widget(objet_graphique,"edit_observateur_window");
    gtk_widget_hide(edit);
    gtk_widget_show(agent);
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(popup), "Erreur De Suppression");
  }

  GtkWidget *edit_observateur;
  edit_observateur = lookup_widget(objet_graphique, "edit_observateur_window");
  gtk_widget_hide(edit_observateur);
}


void on_chercher_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *nationalite_combo;
  GtkWidget *appartenance_combo;
  GtkWidget *num_bureau_entry;

  GtkWidget *togglebutton1, *togglebutton2;

  observateur obs;
  input1 = lookup_widget(objet_graphique, "txt_chercher_observateur");
  output = lookup_widget(objet_graphique, "message_rechercher_observateur");

  nom_entry = lookup_widget(objet_graphique, "modif_nom_observateur");
  prenom_entry = lookup_widget(objet_graphique, "modif_prenom_observateur");
  username_entry = lookup_widget(objet_graphique, "modif_login_observateur");
  password_entry = lookup_widget(objet_graphique, "modif_motdepasse_observateur");
  nationalite_combo = lookup_widget(objet_graphique, "modif_nationalite_combobox");
  appartenance_combo = lookup_widget(objet_graphique, "modif_appartenance_combobox");
  num_bureau_entry = lookup_widget(objet_graphique, "modif_numerobureau_observateur");
  togglebutton1 = lookup_widget(objet_graphique, "homme_modif_observateur");
  togglebutton2 = lookup_widget(objet_graphique, "femme_modif_observateur");
  char id[20];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  obs = chercher_observateur(id);
  if (strcmp(obs.id, "-1") == 0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Aucun observateur n'est inscrit avec cet identifiant, veuillez réessayer");
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(output), "Id existant");
    gtk_entry_set_text(GTK_ENTRY(nom_entry), obs.nom);
    gtk_entry_set_text(GTK_ENTRY(prenom_entry), obs.prenom);
    gtk_entry_set_text(GTK_ENTRY(username_entry), obs.username);
    gtk_entry_set_text(GTK_ENTRY(password_entry), obs.password);
    gtk_entry_set_text(GTK_ENTRY(num_bureau_entry), obs.num_bureau);
    gtk_combo_box_set_active(GTK_COMBO_BOX(nationalite_combo), (atoi(obs.nationalite) - 1));
    gtk_combo_box_set_active(GTK_COMBO_BOX(appartenance_combo), (atoi(obs.appartenance) - 1));

    if (strcmp(obs.sexe, "homme") == 0)
    {
      gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton1), TRUE);
    }
    else if (strcmp(obs.sexe, "femme") == 0)
    {
      gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton2), TRUE);
    }
  }
}


void
on_admin_window_show(GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *treeview_electeur;
    FILE *f; 
    electeur1 T[200];
    
    treeview_electeur = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_electeur");

    lecture_electeur(f,T);
    affichageelecteur(treeview_electeur,T);
}


void
on_agent_window_show(GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *treeview_observateur;
    FILE *f; 
    observateur1 T[200];
    
    treeview_observateur = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_observateur");

    lecture_observateur(f,T);
    affichageobservateur(treeview_observateur,T);
}


void on_deconnecter_abv_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *abv_window;
  abv_window = lookup_widget(objet_graphique, "agent_window");
  gtk_widget_hide(abv_window);
  GtkWidget *login;
  login = create_login_window();
  gtk_widget_show(login);
}

void on_ajouter_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *ajouter_nouveau_observateur;
  GtkWidget *admin_window;

  ajouter_nouveau_observateur = create_ajouter_observateurs_window();
  gtk_widget_show(ajouter_nouveau_observateur);
  admin_window = lookup_widget(objet_graphique, "agent_window");
  gtk_widget_hide(admin_window);
}


void on_go_modifier_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *edit_observateur;
  GtkWidget *gestion;
  gestion=lookup_widget(objet_graphique,"agent_window");
  gtk_widget_hide(gestion);
  edit_observateur = create_edit_observateur_window();
  gtk_widget_show(edit_observateur);
}


void on_actualiser_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *Admin_window;
   Admin_window=lookup_widget(objet_graphique,"agent_window");
   gtk_widget_hide(Admin_window);

   Admin_window = create_agent_window ();
   gtk_widget_show (Admin_window);
}


void
on_go_admin_clicked                    (GtkWidget *objet_graphique, gpointer user_data)
{   
    GtkWidget *admin_window;
    GtkWidget *panneau_window;
    panneau_window = lookup_widget(objet_graphique, "panneau_admin_window");
    gtk_widget_hide(panneau_window);
    admin_window = create_admin_window ();
    gtk_widget_show (admin_window);

}

void on_connecter_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *output;

  GtkWidget *login_window;

  char user[20];
  char pwd[20];
  int role = 0;
  char nom[30];

  input1 = lookup_widget(objet_graphique, "login");
  input2 = lookup_widget(objet_graphique, "mdp");
  output = lookup_widget(objet_graphique, "message_login");

  strcpy(user, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(pwd, gtk_entry_get_text(GTK_ENTRY(input2)));
  
  role = verifierlogin(user, pwd);

  switch (role)
  {
  case 0: // Erreur
    gtk_label_set_text(GTK_LABEL(output), "Erreur d'authetification");
    break;
  case 1: // admin_window
  {
    gtk_label_set_text(GTK_LABEL(output), "vous venez de vous connecter en tant qu'administrateur");
    login_window = lookup_widget(objet_graphique, "login_window");
    gtk_widget_hide(login_window);
  }
  case 2:  // agent_window
    gtk_label_set_text(GTK_LABEL(output), "Agent de Bureau");
    login_window = lookup_widget(objet_graphique, "login_window");
    gtk_widget_hide(login_window);

    break;
  }
}


//fichiers de iheb 

 /* 
    
    ---Election Tab state---
    
*/ 

int selectedElection = -1;
char electionFormBehavior[10] = "add";
char errorMessage[100] = "";
char confirmationMessage[100] = "";
char notificationMessage[100] = "";
char elDelTemplate[100] = "Etes vous sure vous voulez supprimer\ncette election avec id :";

void
on_addElectionBtn_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
    strcpy(electionFormBehavior , "add");
    GtkWidget *electionForm;
    electionForm = create_electionForm();
    gtk_widget_show (electionForm);
     
}



void
on_DisconnectElectionBtn_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *electionManagementWindow;
  GtkWidget *adminSpaceWindow;
  electionManagementWindow = lookup_widget(button, "adminPannel");
  gtk_widget_hide (electionManagementWindow);
  adminSpaceWindow = create_panneau_admin_window ();
  gtk_widget_show (adminSpaceWindow);
}


void
on_refreshStatsBtn_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_cancelConfimationBtn_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *confirmationWindow;
    confirmationWindow = lookup_widget(GTK_WIDGET(button), "Confirmation");
    gtk_widget_hide (confirmationWindow);
}


void
on_connectBtn_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *authWindow;
    GtkWidget *adminPannel;
    authWindow = lookup_widget(GTK_WIDGET(button), "Authentication");
    gtk_widget_hide (authWindow);
    adminPannel = create_adminPannel();
    gtk_widget_show (adminPannel);
}


void
on_electionConfirm_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *electionDateCalendar , 
        *municipalitySelection , 
        *nbrHabitantsEntry, 
        *nbrCouncillorsEntry,
        *notice,
        *electionForm,
        *notifMessage;
    
    electionDateCalendar = lookup_widget(GTK_WIDGET(button) , "electionDateCalendar");
    municipalitySelection = lookup_widget(GTK_WIDGET(button) , "municipalitySelection");
    nbrHabitantsEntry = lookup_widget(GTK_WIDGET(button) , "nbrHabitantsEntry");
    nbrCouncillorsEntry = lookup_widget(GTK_WIDGET(button) , "nbrCouncillorsEntry");

    Date date;
    gtk_calendar_get_date (GTK_CALENDAR(electionDateCalendar) , &date.year , &date.month , &date.day);
    date.month += 1;
    char name[20] = "";

    int index = gtk_combo_box_get_active (GTK_COMBO_BOX(municipalitySelection));
    if(index>-1){
        strcpy(name,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalitySelection)));
    }else {

        electionForm = lookup_widget(GTK_WIDGET(button), "electionForm");
        gtk_widget_hide (electionForm);
        notice = create_error ();
        gtk_widget_show (notice);

        return;
    }
    
    int i= 0;
    Municipality m = findMunicipality("municipalities.txt" , name , &i);
    
    Election e = {1 , date , m};
    if(strcmp(electionFormBehavior , "modify")==0){
        modifierElection( "elections.txt", selectedElection, e );
        strcpy(notificationMessage , "l'election a ete modifiée avec succes"); 

    }else{
        ajouterElection("elections.txt" , e);
        strcpy(notificationMessage , "l'election a ete ajoutée avec succes"); 

    }

    electionForm = lookup_widget(GTK_WIDGET(button), "electionForm");
    gtk_widget_hide (electionForm);
    notice = create_notice ();
    gtk_widget_show (notice);
    
    /* if(!ajouterElection("elections.txt" , e)){
        
    } */
}


void
on_electionForm_show                   (GtkWidget       *widget,
                                        gpointer         user_data)
{
    GtkWidget *municipalitySelection,
        *nbrHabitantsEntry, 
        *nbrCouncillorsEntry,
        *habitantsLabel,
        *councillorsLabel;

    municipalitySelection = lookup_widget(widget , "municipalitySelection");
    nbrHabitantsEntry = lookup_widget(widget , "nbrHabitantsEntry");
    nbrCouncillorsEntry = lookup_widget(widget , "nbrCouncillorsEntry");

    habitantsLabel = lookup_widget(widget , "habitantsLabel");
    councillorsLabel = lookup_widget(widget , "councillorsLabel");

    int municipalityCount = getMuniciplityCount("municipalities.txt");
    Municipality municipalities[municipalityCount];

    getMunicipalities("municipalities.txt" , municipalities);

    for(int i=0;i<municipalityCount;i++){
        gtk_combo_box_append_text(GTK_COMBO_BOX(municipalitySelection) , municipalities[i].name);
    }

    gtk_widget_hide (councillorsLabel);
    gtk_widget_hide (habitantsLabel);

    gtk_widget_hide (nbrHabitantsEntry);
    gtk_widget_hide (nbrCouncillorsEntry);

    //Election form behavior :

    if(strcmp(electionFormBehavior , "modify")!=0) return;
    if(selectedElection == -1) return;

    GtkWidget *electionForm = lookup_widget(widget , "electionForm");
    gtk_window_set_title (GTK_WINDOW(electionForm),"modifier election");
    GtkWidget *electionFormLabel = lookup_widget(widget , "electionFormLabel");
    char template[80] = "modifier l'election d'ID: ";
    char idStr[10];
    sprintf(idStr, "%d", selectedElection);

    char *markup;
    markup = g_markup_printf_escaped (
      "<tt><span size='large'><b>%s</b></span></tt>", 
      strcat(template,idStr)
    );

    gtk_label_set_markup(GTK_LABEL(electionFormLabel),markup);
    Election e = chercherElection("elections.txt",selectedElection);



    GtkWidget *electionDateCalendar;
    electionDateCalendar = lookup_widget(widget , "electionDateCalendar");
    gtk_calendar_select_month (GTK_CALENDAR(electionDateCalendar),e.date.month-1,e.date.year);
    gtk_calendar_select_day (GTK_CALENDAR(electionDateCalendar) , e.date.day);


    int i = 0;
    findMunicipality("municipalities.txt",e.municipality.name,&i);
    gtk_combo_box_set_active (GTK_COMBO_BOX(municipalitySelection),i);
    

}


void
on_municipalitySelection_changed       (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
    GtkWidget *municipalitySelection,
        *nbrHabitantsEntry, 
        *nbrCouncillorsEntry,
        *habitantsLabel,
        *councillorsLabel;

    municipalitySelection = lookup_widget(GTK_WIDGET(combobox) , "municipalitySelection");
    nbrHabitantsEntry = lookup_widget(GTK_WIDGET(combobox) , "nbrHabitantsEntry");
    nbrCouncillorsEntry = lookup_widget(GTK_WIDGET(combobox) , "nbrCouncillorsEntry");
    habitantsLabel = lookup_widget(GTK_WIDGET(combobox) , "habitantsLabel");
    councillorsLabel = lookup_widget(GTK_WIDGET(combobox) , "councillorsLabel");

    char name[20];
    char nbr_habitants[20]; 
    char nbr_councilers[5];
    strcpy(name,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalitySelection)));
    int index = 0;
    Municipality m = findMunicipality("municipalities.txt" , name,&index);

    gtk_widget_show (nbrHabitantsEntry);
    gtk_widget_show (nbrCouncillorsEntry);
    
    gtk_widget_show (councillorsLabel);
    gtk_widget_show (habitantsLabel);


    sprintf(nbr_habitants, "%d", m.nbr_habitants);
    sprintf(nbr_councilers, "%d", m.nbr_councilers);

    gtk_entry_set_text(GTK_ENTRY(nbrHabitantsEntry) , nbr_habitants);
    gtk_entry_set_text(GTK_ENTRY(nbrCouncillorsEntry) , nbr_councilers);
    


}


void
on_noticeOkBtn_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *notice;

    notice = lookup_widget(GTK_WIDGET(button), "notice");
    gtk_widget_hide (notice);

}


void
on_electionCancel_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *electionForm;
    electionForm = lookup_widget(GTK_WIDGET(button), "electionForm");
    gtk_widget_hide (electionForm);
}


void
on_okErrorBtn_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *errorWindow;
    errorWindow = lookup_widget(GTK_WIDGET(button), "error");
    gtk_widget_hide (errorWindow);
}


gboolean
on_AdminPannelTabs_select_page         (GtkNotebook     *notebook,
                                        gboolean         move_focus,
                                        gpointer         user_data)
{

    /* int index = gtk_notebook_get_current_page (notebook);
    FILE *f = fopen("logs.txt" , "a");

    if(f == NULL) return FALSE;

    fprintf(f,"\n%d\n" , index);
    fclose(f); */

    return FALSE;
}


void
on_AdminPannelTabs_switch_page         (GtkNotebook     *notebook,
                                        GtkNotebookPage *page,
                                        guint            page_num,
                                        gpointer         user_data)
{
    int index = gtk_notebook_get_current_page (notebook);
    /* FILE *f = fopen("logs.txt" , "a");

    if(f == NULL) return;

    fprintf(f,"%d\n" , index);
    fclose(f); */

     /* GtkWidget *electionListView;
    electionListView = lookup_widget(GTK_WIDGET(notebook), "electionListView");

    showElections(electionListView);  */
}


void
on_adminPannel_show                    (GtkWidget       *widget,
                                        gpointer         user_data)
{
    
    GtkWidget *electionListView , *adminPannel;
    adminPannel = lookup_widget(widget, "adminPannel");
    electionListView = lookup_widget(adminPannel, "electionListView");
    
    showElections(electionListView);
}
void
on_refreshBtn_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *electionListView;
    electionListView = lookup_widget(GTK_WIDGET(button), "electionListView");

    emptyListView(electionListView);
    showElections(electionListView);

}


void
on_electionListView_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

    GtkTreeIter iter;
    gchar* id;
    gchar* date;
    gchar* municipality;
    gchar *nbr_councillors;
    gchar *nbr_habitants;

    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if(gtk_tree_model_get_iter(model,&iter,path)){
        gtk_tree_model_get(model, &iter,0,&id,1,&date,2,&municipality,3,&nbr_habitants,4,&nbr_councillors,-1);

        FILE *f = fopen("logs.txt" , "a");

        if(f == NULL) return;

        fprintf(f,"%s\n" , id);
        fclose(f);

        selectedElection = atoi(id);

    }
}


void
on_delElectionBtn_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

    if(selectedElection == -1){
        strcpy(errorMessage , "Aucune election n'est selectionnée");
        GtkWidget *errorWindow;
        errorWindow = create_error();
        gtk_widget_show (errorWindow);
        return;
    }

    //Election e;
    //e = chercherElection(selectedElection);
    char idStr[10];
    sprintf(idStr, "%d", selectedElection);

    char errorStr[100] = "";
    strcat(errorStr , elDelTemplate );
    strcat(errorStr , idStr );
    strcpy(confirmationMessage,errorStr);
    GtkWidget* confirmationWindow;
    
    confirmationWindow = create_Confirmation ();
    gtk_widget_show (confirmationWindow);

    


}

void
on_error_show                          (GtkWidget       *widget,
                                        gpointer         user_data)
{
    if(strcmp(errorMessage , "")==0) return;

    GtkWidget * errorLabel;
    errorLabel = lookup_widget(widget , "errorLabel");
    gtk_label_set_text(GTK_LABEL(errorLabel) , errorMessage);
    strcpy(errorMessage , "");
}


bool confirmedDel = FALSE;

void
on_confirmationCheck_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton)){
        confirmedDel = TRUE;
    }
    else {
        confirmedDel = FALSE;
    }
}


void
on_Confirmation_show                   (GtkWidget       *widget,
                                        gpointer         user_data)
{
    if(selectedElection == -1) return;
    
    GtkWidget * confirmationLabel;
    confirmationLabel = lookup_widget(widget , "confirmationLabel");

    gtk_label_set_text(GTK_LABEL(confirmationLabel) , confirmationMessage);


}

void
on_delConfirmationBtn_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    if(!confirmedDel) {

        strcpy(errorMessage , "vous n'avez pas confirmer la suppression");
        
        GtkWidget* errorWindow;
        errorWindow = create_error ();
        gtk_widget_show (errorWindow); 

        return;
    }


    supprimerElection("elections.txt", selectedElection);
    selectedElection = -1;
    strcpy(notificationMessage , "Election supprimée avec succes");

    GtkWidget* notice , *confirmationWindow;
    notice = create_notice ();
    gtk_widget_show (notice); 

    confirmationWindow = lookup_widget(GTK_WIDGET(button),"Confirmation");
    gtk_widget_hide (confirmationWindow); 


}


void
on_notice_show                         (GtkWidget       *widget,
                                        gpointer         user_data)
{
    if(strcmp(notificationMessage , "")==0) return;

    GtkWidget * notifMessage;
    notifMessage = lookup_widget(widget , "notifMessage");
    gtk_label_set_text(GTK_LABEL(notifMessage) , notificationMessage);
    strcpy(notificationMessage , "");
}

void
on_modifyElectionBtn_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
    if(selectedElection == -1){
        strcpy(errorMessage , "Aucune election n'est selectionée");
        GtkWidget* errorWindow;
        errorWindow = create_error ();
        gtk_widget_show (errorWindow);
        return;
    }

        strcpy(electionFormBehavior , "modify");

        GtkWidget* electionForm;
        electionForm = create_electionForm ();
        gtk_widget_show (electionForm);

}

void
on_searchElectionBtn_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

    GtkWidget* idSpinEntry;
    idSpinEntry = lookup_widget(GTK_WIDGET(button),"idSpinEntry");
    int id = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(idSpinEntry));

    Election e = chercherElection("elections.txt",id);
    
    if(e.id == -1){
        char idStr[10];
        sprintf(idStr , "%d" , id);
        char temp[100]= "Election d'id ";
        strcat( temp, idStr);
        strcat(temp," n'est pas trouvée");
        strcpy(errorMessage , temp);
        GtkWidget *errorWindow = create_error ();
        gtk_widget_show (errorWindow);
        return;
    }

    //update treeview 

    GtkWidget *electionListView = lookup_widget(GTK_WIDGET(button),"electionListView");

    emptyListView(electionListView);
    showElection(electionListView , e.id);

}

void
on_electionRedirectBtn_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *adminWindow;
  GtkWidget *electionWindow;
  adminWindow = lookup_widget(GTK_WIDGET(button), "panneau_admin_window");
  gtk_widget_hide (adminWindow);
  electionWindow =  create_adminPannel ();
  gtk_widget_show (electionWindow);
}


void
on_statsWindow_show                    (GtkWidget       *widget,
                                        gpointer         user_data)
{
  GtkWidget *TPE_label , 
    *TPH_label , 
    *TPF_label , 
    *TVB_label,
    *AgeMoy_label , 
    *NbrObs_label,
    *TOL_label,
    *TOI_label;

  float  TPH_val = 0; 
  float  TPF_val = 0;
  float  TOL_val = 0;
  float  TOI_val = 0;

  char TPE_val_str[100];
  char AgeMoy_val_str[100];
  char TVB_val_str[100];
  char NbrObs_str[100];
  char TPF_val_str[100];
  char TPH_val_str[100];
  char TOL_val_str[100];
  char TOI_val_str[100];


   TPHF("electeur.txt",&TPH_val ,&TPF_val);
  taux_observateur("observateur.txt",&TOL_val,&TOI_val);

  sprintf(TPE_val_str , "%.2f" , TPE("electeur.txt")*100);
  sprintf(AgeMoy_val_str , "%d" , (int)agemoyen("electeur.txt")) ;
  sprintf(TVB_val_str , "%.2f" , NVB("electeur.txt")*100);
  sprintf(TPH_val_str , "%.2f" , TPH_val*100);    
  sprintf(TPF_val_str , "%.2f" , TPF_val*100);    
  sprintf(TOL_val_str , "%.2f" , TOL_val*100);    
  sprintf(TOI_val_str , "%.2f" , TOI_val*100);    
  sprintf(NbrObs_str , "%d" , nbobservateur("observateur.txt"));     

  TPE_label = lookup_widget(widget,"TPE_label");
  TPH_label = lookup_widget(widget,"TPH_label");
  TPF_label = lookup_widget(widget,"TPF_label");
  TVB_label = lookup_widget(widget,"TVB_label");
  AgeMoy_label = lookup_widget(widget,"AgeMoy_label");
  NbrObs_label = lookup_widget(widget,"NbrObs_label");
  TOL_label = lookup_widget(widget,"TOL_label");
  TOI_label = lookup_widget(widget,"TOI_label");

  char *markup;

  markup = g_markup_printf_escaped ("<span size='medium' color='#330'><tt><b>%s</b></tt></span>",
     strcat(TPE_val_str," %"));
  gtk_label_set_markup(GTK_LABEL(TPE_label),markup);
  
  markup = g_markup_printf_escaped ("<span size='medium' color='#330'><tt><b>%s</b></tt></span>",
     strcat(TPH_val_str," %"));
  gtk_label_set_markup(GTK_LABEL(TPH_label),markup);

  markup = g_markup_printf_escaped ("<span size='medium' color='#330'><tt><b>%s</b></tt></span>",
     strcat(TPF_val_str," %"));
  gtk_label_set_markup(GTK_LABEL(TPF_label),markup);

  markup = g_markup_printf_escaped ("<span size='medium' color='#330'><tt><b>%s</b></tt></span>",
     strcat(TVB_val_str," %"));
  gtk_label_set_markup(GTK_LABEL(TVB_label),markup);

  markup = g_markup_printf_escaped ("<span size='medium' color='#330'><tt><b>%s</b></tt></span>",
     strcat(TOL_val_str," %"));
  gtk_label_set_markup(GTK_LABEL(TOL_label),markup);

  markup = g_markup_printf_escaped ("<span size='medium' color='#330'><tt><b>%s</b></tt></span>",
     strcat(TOI_val_str," %"));
  gtk_label_set_markup(GTK_LABEL(TOI_label),markup);

  markup = g_markup_printf_escaped ("<span size='medium' color='#330'><tt><b>%s</b></tt></span>",
     strcat(AgeMoy_val_str, " ans"));
  gtk_label_set_markup(GTK_LABEL(AgeMoy_label),markup);

  markup = g_markup_printf_escaped ("<span size='medium' color='#330'><tt><b>%s</b></tt></span>",NbrObs_str);
  gtk_label_set_markup(GTK_LABEL(NbrObs_label),markup);


}


void
on_backStatsBtn_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

  GtkWidget *adminWindow;
  GtkWidget *statWindow;
  statWindow = lookup_widget(GTK_WIDGET(button), "statsWindow");
  gtk_widget_hide (statWindow);
  adminWindow =  create_panneau_admin_window ();
  gtk_widget_show (adminWindow);

}


void
on_openStatsBtn_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *adminWindow;
  GtkWidget *statWindow;
  adminWindow = lookup_widget(GTK_WIDGET(button), "panneau_admin_window");
  gtk_widget_hide (adminWindow);
  statWindow =  create_statsWindow ();
  gtk_widget_show (statWindow);
}


void
on_about_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *aboutWindow =  create_aboutApp ();
  gtk_widget_show (aboutWindow);
}


void
on_DisconnectAdminBtn_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *adminWindow;
  GtkWidget *loginWindow;
  adminWindow = lookup_widget(GTK_WIDGET(button), "panneau_admin_window");
  gtk_widget_hide (adminWindow);
  loginWindow =  create_login_window ();
  gtk_widget_show (loginWindow);
}






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
int sexe = 0;
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
   Admin_window=lookup_widget(objet_graphique,"admin_window");
   gtk_widget_hide(Admin_window);

   Admin_window = create_admin_window ();
   gtk_widget_show (Admin_window);
}



void on_Deconnecter_admin_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *admin;
  admin = lookup_widget(objet_graphique, "admin_window");
  gtk_widget_hide(admin);
  GtkWidget *login;
  login = create_login_window();
  gtk_widget_show(login);
}


void
on_annuler_electeur_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
   GtkWidget *ajouter_nouveau_electeur;
    ajouter_nouveau_electeur = lookup_widget(objet_graphique, "ajouter_electeur_window");
    gtk_widget_hide(ajouter_nouveau_electeur); 
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

  char msg[6];
  int nouveau_id = auto_incre_id_electeur();
  char no_id[8];
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
  if (verifierexistant(el.username) != 0)
  {
    ajouter_electeur(el);
    gtk_label_set_text(GTK_LABEL(popup), "Ajouter avec succées");
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(popup), "Erreur ajout (électeur déja existe)");
  }

  GtkWidget *valider;
  valider = lookup_widget(objet_graphique, "ajouter_electeur_window");
  gtk_widget_hide(valider);
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

  char msg[6];
  int nouveau_id = auto_incre_id_observateur();
  char no_id[8];
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
  char test[8];
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
  char msg[6];
  genre(sexe, msg);
  strcpy(el.sexe, msg);
  if (strcmp(el.id, "-1") != 0)
  {
    modifier_electeur(el);
    gtk_label_set_text(GTK_LABEL(popup), "Modification avec succées");
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
  char supprimer[8];
  strcpy(supprimer, gtk_entry_get_text(GTK_ENTRY(input)));
  if (strcmp(supprimer, "-1") != 0)
  {
    supprimer_electeur(supprimer);
    gtk_label_set_text(GTK_LABEL(popup), "Suppression avec succées");
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
  char id[8];

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
    char msg[6];
    genre(sexe, msg);
    strcpy(obs.sexe, msg);
    modifier_observateur(obs);

    gtk_label_set_text(GTK_LABEL(output2), "Champs modifier avec succès");

    GtkWidget *edit_observateur;
    edit_observateur = lookup_widget(objet_graphique, "edit_observateur_window");
    gtk_widget_hide(edit_observateur);
  }
}


void on_supprimer_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *popup;
  popup = lookup_widget(objet_graphique, "message_edit_observateur");
  input = lookup_widget(objet_graphique, "txt_chercher_observateur");
  char supprimer[8];
  strcpy(supprimer, gtk_entry_get_text(GTK_ENTRY(input)));
  if (strcmp(supprimer, "-1") != 0)
  {
    supprimer_observateur(supprimer);
    gtk_label_set_text(GTK_LABEL(popup), "Suppression avec succées");
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
  char id[8];

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
  admin_window = lookup_widget(objet_graphique, "admin_window");
  gtk_widget_hide(admin_window);
}


void on_go_modifier_observateur_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *edit_observateur;
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

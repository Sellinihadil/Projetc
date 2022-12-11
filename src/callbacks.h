#include <gtk/gtk.h>


void
on_modifier_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_supprimer1_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_modifier2_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_item2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_ajouter_electeur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_modifier_electeur_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_electeur_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_Deconnecter_admin_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_electeur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_valider_electeur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_homme_electeur_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_electeur_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_homme_observateur_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_observateur_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_annuler_observateur_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_valider_observateur_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_homme_observateur_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_observateur_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modifier_electeur_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_electeur_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_electeur_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_homme_modif_electeur_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_modif_electeur_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modfier_observateur_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_observateur_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_observateur_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_admin_window_show                   (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_agent_window_show                   (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_deconnecter_abv_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_observateur_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_modifier_observateur_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_observateur_clicked      (GtkButton       *button,
                                        gpointer         user_data);

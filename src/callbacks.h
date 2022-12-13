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
on_ajouter_electeur_clicked(GtkWidget *objet_graphique, gpointer user_data);

void
on_go_modifier_electeur_clicked       (GtkWidget *objet_graphique, gpointer user_data);

void
on_actualiser_electeur_clicked        (GtkWidget *objet_graphique, gpointer user_data);

void
on_Deconnecter_admin_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_annuler_electeur_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_valider_electeur_clicked           (GtkWidget *objet_graphique, gpointer user_data);

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
on_annuler_observateur_clicked        (GtkWidget *objet_graphique, gpointer user_data);

void
on_valider_observateur_clicked        (GtkWidget *objet_graphique, gpointer user_data);

void
on_homme_observateur_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_observateur_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modifier_electeur_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_supprimer_electeur_clicked         (GtkWidget *objet_graphique, gpointer user_data);

void
on_chercher_electeur_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_homme_modif_electeur_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_modif_electeur_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modfier_observateur_clicked        (GtkWidget *objet_graphique, gpointer user_data);

void
on_supprimer_observateur_clicked      (GtkWidget *objet_graphique, gpointer user_data);

void
on_chercher_observateur_clicked       (GtkWidget *objet_graphique, gpointer user_data);

void
on_admin_window_show                   (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_agent_window_show                   (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_deconnecter_abv_clicked            (GtkWidget *objet_graphique, gpointer user_data);

void
on_ajouter_observateur_clicked        (GtkWidget *objet_graphique, gpointer user_data);

void
on_go_modifier_observateur_clicked    (GtkWidget *objet_graphique, gpointer user_data);

void
on_actualiser_observateur_clicked     (GtkWidget *objet_graphique, gpointer user_data);

void
on_go_admin_clicked                   (GtkWidget *objet_graphique, gpointer user_data);

void
on_connecter_clicked                  (GtkWidget *objet_graphique, gpointer user_data);

// fichiers de iheb 

void
on_addElectionBtn_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifyElectionBtn_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_delElectionBtn_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_searchElectionBtn_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_DisconnectElectionBtn_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_refreshStatsBtn_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmationCheck_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_delConfirmationBtn_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancelConfimationBtn_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_connectBtn_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_electionConfirm_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_electionForm_show                   (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_municipalitySelection_changed       (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_noticeOkBtn_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_electionCancel_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_okErrorBtn_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_AdminPannelTabs_select_page         (GtkNotebook     *notebook,
                                        gboolean         move_focus,
                                        gpointer         user_data);

void
on_AdminPannelTabs_switch_page         (GtkNotebook     *notebook,
                                        GtkNotebookPage *page,
                                        guint            page_num,
                                        gpointer         user_data);

void
on_adminPannel_show                    (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_refreshBtn_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_refreshBtn_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_electionRefreshBtn_leave            (GtkButton       *button,
                                        gpointer         user_data);

void
on_adminPannel_show                    (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_electionListView_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_error_show                          (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_Confirmation_show                   (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_notice_show                         (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_electionRedirectBtn_clicked         (GtkButton       *button,
                                        gpointer         user_data);


void
on_statsWindow_show                    (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_backStatsBtn_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_openStatsBtn_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_about_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_DisconnectAdminBtn_clicked          (GtkButton       *button,
                                        gpointer         user_data);



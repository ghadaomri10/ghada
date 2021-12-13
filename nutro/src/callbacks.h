#include <gtk/gtk.h>


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonstatistique_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonafficher_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttona_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonm_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonpp3_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonpp1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonpp2_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrecherche_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonsa_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonna_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonnm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonsm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

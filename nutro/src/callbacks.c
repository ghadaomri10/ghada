#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "file.h"
GtkWidget *windowpp;
char id[30],idrech[30];
int s=0;
int g=0;
int k=0;
int o=0;

void
on_treeview1_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(treeview1);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}
}


void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowmodif,*windowpp;
windowpp = lookup_widget(button,"windowpp");
gtk_widget_destroy(windowpp);

windowmodif=create_windowmodif();
gtk_widget_show (windowmodif);
}


void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowajout,*windowpp;
windowpp = lookup_widget(button,"windowpp");
gtk_widget_destroy(windowpp);
windowajout=create_windowajout();
gtk_widget_show (windowajout);
}


void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
MENU M;
GtkWidget *windowpp;
	    GtkWidget *treeview1;
	    windowpp=lookup_widget(button,"windowpp");
	    treeview1=lookup_widget(windowpp,"treeview1");
	    suppression(id,M);
            affichage(treeview1);
}


void
on_buttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *windowpp;
windowpp=lookup_widget(button,"windowpp");
treeview1=lookup_widget(windowpp,"treeview1");
affichage(treeview1);
}


void
on_buttonstatistique_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowstat,*windowpp;
windowpp = lookup_widget(button,"windowpp");
gtk_widget_destroy(windowpp);
windowstat=create_windowstat();
gtk_widget_show (windowstat);
}


void
on_buttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char Menu[30];char Type[30];char x[30];
MENU M;
GtkWidget *entryajoutid;
GtkWidget *comboboxajoutmenu;
GtkWidget *entryajoutmenu;
GtkWidget *entryajoutdessert;
GtkWidget *entryajoutpp;
GtkWidget *spinbuttonajoutjj;
GtkWidget *spinbuttonajoutmm;
GtkWidget *spinbuttonajoutaa;
GtkWidget *radiobuttonna;
GtkWidget *radiobuttonsa;
GtkWidget *radiobutton1;
GtkWidget *sortiea;



spinbuttonajoutjj=lookup_widget(button, "spinbuttonajoutjj");
spinbuttonajoutmm=lookup_widget(button, "spinbuttonajoutmm");
spinbuttonajoutaa=lookup_widget(button, "spinbuttonajoutaa");
entryajoutid=lookup_widget(button,"entryajoutid");
radiobuttonsa=lookup_widget(button, "radiobuttonsa");
radiobuttonna=lookup_widget(button, "radiobuttonna");
radiobutton1=lookup_widget(button, "radiobutton1");
comboboxajoutmenu=lookup_widget(button,"comboboxajoutmenu");
entryajoutmenu=lookup_widget(button,"entryajoutmenu");
entryajoutdessert=lookup_widget(button,"entryajoutdessert");
entryajoutpp=lookup_widget(button,"entryajoutpp");
sortiea=lookup_widget(button, "label20");

strcpy(x,gtk_entry_get_text(GTK_ENTRY(entryajoutid)));
if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez un identifiant svp!");}
else if (veriff(x)==1){
	if(verifid(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"identifiant existe déja !");}

else if((verifid(x)==1)&&(s==1)){
strcpy(M.identifiant,gtk_entry_get_text(GTK_ENTRY(entryajoutid)));
strcpy(M.menu,gtk_entry_get_text(GTK_ENTRY(entryajoutmenu)));
strcpy(M.dessert,gtk_entry_get_text(GTK_ENTRY(entryajoutdessert)));
strcpy(M.pp,gtk_entry_get_text(GTK_ENTRY(entryajoutpp)));
M.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutjj));
M.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutmm));
M.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutaa));
if (k==1)
{strcpy(Type,"vegeterien");}
else if (k==2)
{strcpy(Type,"normal");}
else if (k==3)
{strcpy(Type,"diabetique");}
strcpy(Menu,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajoutmenu)));
strcpy(M.type,Menu);
strcpy(M.gluten,Type);
ajout(M);
gtk_label_set_text(GTK_LABEL(sortiea),"Ajout effectué avec succès!");
}}
s=0;}



void
on_buttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char Menu[30];char Type[30];
MENU M;
GtkWidget *comboboxmodifmenu;
GtkWidget *entrymodifmenu;
GtkWidget *entrymodifpp;
GtkWidget *entrymodifdessert;
GtkWidget *spinbuttonmodifjj;
GtkWidget *spinbuttonmodifmm;
GtkWidget *spinbuttonmodifaa;
GtkWidget *radiobuttonnm;
GtkWidget *radiobuttonsm;
GtkWidget *radiobutton2;
GtkWidget *sortiem;



spinbuttonmodifjj=lookup_widget(button, "spinbuttonmodifjj");
spinbuttonmodifmm=lookup_widget(button, "spinbuttonmodifmm");
spinbuttonmodifaa=lookup_widget(button, "spinbuttonmodifaa");
comboboxmodifmenu=lookup_widget(button,"comboboxmodifmenu");
entrymodifmenu=lookup_widget(button,"entrymodifmenu");
entrymodifpp=lookup_widget(button,"entrymodifpp");
entrymodifdessert=lookup_widget(button,"entrymodifdessert");
radiobuttonsm=lookup_widget(button, "radiobuttonsm");
radiobuttonnm=lookup_widget(button, "radiobuttonnm");
radiobutton2=lookup_widget(button, "radiobutton2");
sortiem=lookup_widget(button, "label21");

if (g==1){
strcpy(M.identifiant,id);
if (o==2)
{strcpy(Type,"vegeterien");}
else if (o==1)
{strcpy(Type,"normal");}
else if (o==3)
{strcpy(Type,"diabetique");}
strcpy(M.pp,gtk_entry_get_text(GTK_ENTRY(entrymodifpp)));
strcpy(M.dessert,gtk_entry_get_text(GTK_ENTRY(entrymodifdessert)));
strcpy(M.menu,gtk_entry_get_text(GTK_ENTRY(entrymodifmenu)));
M.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjj));
M.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifmm));
M.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifaa));
strcpy(Menu,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifmenu)));
strcpy(M.type,Menu);
strcpy(M.gluten,Type);
modification(id,M);
gtk_label_set_text(GTK_LABEL(sortiem),"Ajout effectué avec succès!");
}g=0;}


void
on_buttonafficher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
dechet D;
GtkWidget *treeview2;
GtkWidget *windowstat;
windowstat=lookup_widget(button,"windowstat");
treeview2=lookup_widget(windowstat,"treeview2");
affichage_stat(treeview2);
}


void
on_checkbuttona_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
s=1;}
}


void
on_checkbuttonm_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
g=1;}
}


void
on_buttonpp3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowstat,*windowpp;
windowstat = lookup_widget(button,"windowstat");
gtk_widget_destroy(windowstat);
windowpp=create_windowpp();
gtk_widget_show (windowpp);
}


void
on_buttonpp1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowajout,*windowpp;
windowajout = lookup_widget(button,"windowajout");
gtk_widget_destroy(windowajout);
windowpp=create_windowpp();
gtk_widget_show (windowpp);
}


void
on_buttonpp2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowmodif,*windowpp;
windowmodif = lookup_widget(button,"windowmodif");
gtk_widget_destroy(windowmodif);
windowpp=create_windowpp();
gtk_widget_show (windowpp);
}


void
on_buttonrecherche_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
MENU M;
GtkWidget *entryid;
GtkWidget *treeview1;
FILE*f;
FILE*f2;


windowpp=lookup_widget(button,"windowpp");
entryid=lookup_widget(button,"entryid");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(entryid)));
f=fopen("menu.bin","rb");

 if(f!=NULL)
 {
  while(fread(&M,sizeof(MENU),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if (strcmp(M.identifiant,idrech)==0)
     { 
     fwrite(&M,sizeof(MENU),1,f2);
     }
   
     treeview1=lookup_widget(windowpp,"treeview1");
     recherche(treeview1);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}




void
on_radiobuttonsa_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
k=1;}
}


void
on_radiobuttonna_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
k=2;}
}


void
on_radiobuttonnm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
o=1;}
}


void
on_radiobuttonsm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
o=2;}
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
k=3;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
o=3;}
}


#include <gtk/gtk.h>

typedef struct date
{
int jour;
int mois;
int annee;
}Datee;

typedef struct 
{
char type[30];
char menu[30];
char identifiant[30];
char gluten[30];
char pp[30];
char dessert[30];
Datee date;
}MENU;

typedef struct
{
char jour[20];    
char temps[20];  
char valeur[20];
}dechet;


void affichage(GtkWidget* treeview1);
void ajout(MENU M);
void suppression(char id[30], MENU M);
void recherche(GtkWidget* treeview1);
void modification(char id[30], MENU M);
void affichage_stat(GtkWidget* treeview2);
int verifid(char id[30]);
int veriff(char x[]);
void min (char x[30],char k[10]);


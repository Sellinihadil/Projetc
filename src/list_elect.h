#ifndef LIST_ELECT_H_INCLUDED
#define LIST_ELECT_H_INCLUDED

enum Orientation {
    gauche, droite , centre
}

typedef struct
{
int id;
enum Orientation orientation;
int id_tete;
int id_condidats[3]
}ElectList;



void afficher_elect_lists (GtkWidget *elect_lists);
void modif_elect_list(int id);
void del_elect_list(int id);


#endif // LIST_ELECT_H_INCLUDED

#ifndef LIST_ELECT_H_INCLUDED
#define LIST_ELECT_H_INCLUDED

enum Orientation {
    gauche, droite , centre
};

typedef struct
{
int id_liste;
enum Orientation orientation;
int id_tete;
int id_condidats[3]
}ElectList;



void afficher_elect_lists (int id_liste);
void modif_elect_list(int id_liste);
void supprimer_elect_list(int id_liste);


#endif // LIST_ELECT_H_INCLUDED



enum Orientation{gauche,centre,droite};

typedef struct {
    int id_list;
    enum Orientation orientation;
    int id_tete;
    int idCondidats[3];
}liste_electorale;
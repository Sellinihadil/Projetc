enum Appartenance {"partie politique","press","hote","societe civile","organisation mondiale"};

typedef struct{
    char nom[30];
    char prenom[30];
    char nationality[30];
    enum Appartenance appartenance[30];
    enum Sexe sexe;
}observer;
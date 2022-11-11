typedef struct Date Date;
struct  Date{ 
	unsigned int jour;
	unsigned int mois;
	unsigned int annee;
}; 

typedef struct user user ;
struct user {
	char nom[30];
	char prenom[30];
	unsigned int cin;
	struct Date naissance;
	int sexe;
	char login[30];
	char password[30];
	unsigned int bureau;
	unsigned int vote;
} ;

int ajouter(char * filename, user u );
int modifier( char * filename, int id, user* nouv );
int supprimer_utilisateur(char * utilisateurs, int id);
user chercher_utilisateur(char * utilisateurs, int id);






typedef struct {
	char nom[30];
	char prenom[30];
	int cin;
	struct Date naissance;
	enum Sexe sexe;
	char login[30];
	char password[30];
	int bureau;
} user;
typedef struct {
struct user utilisateur;
int vote;
}electeur;



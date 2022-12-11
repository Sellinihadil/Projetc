#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

typedef struct nom{
  char nom[20];
  char motdepasse[20];
  int rol;
}users ;


int verifierlogin(char username[], char password[]); 
int verifierexistant (char username[]);
void ajouterlogin (char username[], char password[], int role);


#endif 	

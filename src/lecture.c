#include "lecture.h"


/* -------------------------------------------------- lecture electeur ------------------------------------------------------------------------------------*/

void lecture_electeur(FILE *f,electeur1 T[])
{
    char filename[30]="electeur.txt";
    char id1[30];char cin1[30];char username1[30];
    char password1[30];char nom1[30];char prenom1[30];
    char jour1[30];char mois1[30];char anne1[30];
    char sexe1[30];char num_bureau1[30];
    int vote1;
    int i=0;
    f=fopen(filename,"r");
    while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i",id1,cin1,username1,password1,nom1,prenom1,jour1,mois1,anne1,sexe1,num_bureau1,&vote1)!=EOF)
    {	

        char jourm[30];
		strcat(jour1,"/");
		strcpy(jourm,strcat(jour1,mois1));
		strcat(jourm,"/");
		char date_naiss[30];
		strcpy(date_naiss,strcat(jourm,anne1));
        
        strcpy(T[i].id,id1);
	    strcpy(T[i].cin,cin1);
  	    strcpy(T[i].username,username1);
  	    strcpy(T[i].password,password1);
  	    strcpy(T[i].nom,nom1);
  	    strcpy(T[i].prenom,prenom1);
  	    strcpy(T[i].sexe,sexe1);
  	    strcpy(T[i].num_bureau,num_bureau1);
        strcpy(T[i].date,date_naiss);
    i++;
    }
    fclose(f);
}

/* -------------------------------------------------- lecture observateur ------------------------------------------------------------------------------------*/


void lecture_observateur(FILE *f,observateur1 T[])
{
    char filename[30]="observateur.txt";
    char id1[30];char nationalite1[30];char username1[30];
    char password1[30];char nom1[30];char prenom1[30];
    char appartenance1[30];char num_bureau1[30];char sexe1[30];
    printf("test1\n");
    int i=0;
    f=fopen(filename,"r");
    while (fscanf(f,"%s %s %s %s %s %s %s %s %s",id1,nationalite1,username1,password1,nom1,prenom1,sexe1,num_bureau1,appartenance1)!=EOF)
    {
        strcpy(T[i].id,id1);
        strcpy(T[i].nationalite,nationalite1);
  	    strcpy(T[i].username,username1);
  	    strcpy(T[i].password,password1);
  	    strcpy(T[i].nom,nom1);
  	    strcpy(T[i].prenom,prenom1);
        strcpy(T[i].sexe,sexe1);
        strcpy(T[i].num_bureau,num_bureau1);
  	    strcpy(T[i].appartenance,appartenance1);
    i++;
    }
    
    fclose(f);

}

    
    
    
    
    
    
    

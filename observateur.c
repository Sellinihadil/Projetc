#include "observateur.h"
#include<stdio.h>


int ajouter(char * observateurs, observer o )
{
    FILE * f=fopen("observateur.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%u %s %s %s %d %u\n",o.id,o.nom,o.prenom,o.nationality,o.appartenance,o.sexe);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * observateurs, int id, observer nouv )
{
    int trouve=0;
    observer o;
    FILE * f=fopen("observateur.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%u %s %s %s %d %u\n",&o.id,&o.nom,&o.prenom,&o.nationality,&o.appartenance,&o.sexe)!=EOF)
        {
            if(o.id== id)
            {
                fprintf(f2,"%u %s %s %s %d %u\n",nouv.id,nouv.nom,nouv.prenom,nouv.nationality,nouv.appartenance,nouv.sexe);
                trouve=1;
            }
            else
                fprintf(f2,"%u %s %s %s %d %u\n",o.id,o.nom,o.prenom,o.nationality,o.appartenance,o.sexe);

        }
    }
    fclose(f);
    fclose(f2);
    remove("observateur.txt");
    rename("nouv.txt", "observateur.txt");
    return trouve;

}
int supprimer(char * observateurs, int id)
{
    int tr=0;
    observer o;
    FILE * f=fopen("observateur.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%u %s %s %s %d %u\n",&o.id,&o.nom,&o.prenom,&o.nationality,&o.appartenance,&o.sexe)!=EOF)
        {
            if(o.id== id)
                tr=1;
            else
                fprintf(f2,"%u %s %s %s %d %u\n",o.id,o.nom,o.prenom,o.nationality,o.appartenance,o.sexe);
        }
    }
    fclose(f);
    fclose(f2);
    remove("observateur.txt");
    rename("nouv.txt", "observateur.txt");
    return tr;
}
observer chercher(char * observateurs, int id)
{
    observer o;
    int tr;
    FILE * f=fopen("observateur.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,fscanf(f,"%u %s %s %s %d %u\n",&o.id,&o.nom,&o.prenom,&o.nationality,&o.appartenance,&o.sexe)!=EOF)!=EOF)
        {
            if(o.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        o.id=-1;
    return o;

}

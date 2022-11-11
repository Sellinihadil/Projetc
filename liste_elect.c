#include "liste_elect.h"
#include<stdio.h>
int ajouter(char * "ElectList.txt",ElectList e)
{
     FILE * f=fopen("ElectList.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d\n",e.id_liste,e.id_tete,e.id_condidat);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(char * "ElectList.txt",unsigned int id_liste,ElectList nouv)
{   int tr=0;
    ElectList e;
    FILE * f=fopen("ElectList.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d\n",&e.id_liste,&e.id_tete,&e.id_condidat)!=EOF)
        {
            if(e.id_liste==e.id_liste)
            {
                fprintf(f2,"%d %d %d\n",nouv.id_liste,nouv.id_tete,nouv.id_condidat)!=EOF)
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d\n",e.id_liste,e.id_tete,e.id_condidat);

        }
    }
    fclose(f);
    fclose(f2);
    remove("ElectList.txt");
    rename("nouv.txt","ElectList.txt");
    return tr;

}
int supprimer(unsigned int id_liste,char * "ElectList.txt")
{
    int tr=0;
    ElectList e;
    FILE * f=fopen("ElectList.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d\n",&e.id_liste,&e.id_tete,&e.id_condidat)!=EOF)
        {
            if(p.id_liste!== id_liste)
                tr=1;
            else
                fprintf(f2,"%d %d %d\n",e.id_liste,e.id_tete,e.id_condidat);
        }
    }
    fclose(f);
    fclose(f2);
    remove("ElectList.txt");
    rename("nouv.txt","ElectList.txt");
    return tr;
}
ElectList chercher(char * "ElectList.txt",unsigned int id_liste)
{
ElectList;
 int tr;
    FILE * f=fopen("ElectList.txt", "r");
 if(f!=NULL )
    {
        while(tr==0&& fscanf(f,"%d %d %d",&e.id_liste,&e.id_tete,&e.id_condidat)!=EOF)
{if(e.id_liste==id_liste)
tr=1;
}
}
fclose(f);
if(tr==0)
e.id_liste=-1;
return e;

}


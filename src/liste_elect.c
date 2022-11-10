#include "liste_elect.h"
void modif_elect_list(int id_liste)
{
    int tr=0;
    ElectList e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d\n",&e.id_List,e.id_tete,&e.id_condidat)!=EOF)
        {
            if(p.id== id)
            {
                fprintf(f2,"%d %d %d\n",nouv.id_List,nouv.id_tete,nouv.id_condidat);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d\n",e.id_List,e.id_tete,e.id_condidat);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
void supprimer_elect_list(int id_liste);*
{
    int tr=0;
    ElectList e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d\n",&e.idListe,&e.id_tete,&e.id_condidat)!=EOF)
        {
            if(p.id_liste== id_liste)
                tr=1;
            else
                fprintf(f2,"%d %d %d\n",&e.idListe,e.id_tete,e.id_condidat)
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}


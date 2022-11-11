#include "reclamation.h"


int ajouterrec(char * filename, reclamation c )
{
    file * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d %s %d\n",c.Id,c.daterec,c.Liste_elect_rec,c.num_bv,c.desc_rec,c.type_rec);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifierrec( char * filename, int Id, reclamation nouv )
{
    int tr=0;
    reclamation c;
   file * f=fopen(filename, "r");
   file * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %d\n",&c.Id,&c.daterec,&c.Liste_elect_rec,&c.num_bv,&c.desc_rec,&c.type_rec)!=EOF)
        {
            if(c.Id==Id)
            {
                fprintf(f2,"%d %d %d %d %s %d\n",nouv.Id,nouv.daterec,nouv.Liste_elect_rec,nouv.num_bv,nouv.desc_rec,nouv.type_rec);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %s %d\n",c.Id,c.daterec,c.Liste_elect_rec,c.num_bv,c.desc_rec,c.type_rec);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int Id)
{
    int tr=0;
    reclamation c;
    file * f=fopen(filename, "r");
    file * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %d\n",&c.Id,&c.daterec,&c.Liste_elect_rec,&c.num_bv,&c.desc_rec,&c.type_rec)!=EOF)
        {
            if(c.Id== Id)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %s %d\n",c.Id,c.daterec,c.Liste_elect_rec,c.num_bv,c.desc_rec,c.type_rec);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
chercherrec(char * filename, int Id)
{
    reclamation c;
    int tr;
    file * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%d %d %d %d %s %d\n",&c.Id,&c.daterec,&c.Liste_elect_rec,&c.num_bv,&c.desc_rec,&c.type_rec)!=EOF)
        {
            if(c.Id==Id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        c.Id=-1;
    return c;

}







	


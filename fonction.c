#include "header.h"
#include <stdio.h>
//taux des observateurs tunisiens et etrangers
void taux ( char *filename , float *tn, float *te)
{    FILE*f=fopen(filename,"r");
 float nbtotal;
   int nbtn=0,nbet=0;
    observateur o;
if(f!=NULL)
{
while(fscanf(f,"%s%s%s%s%s%s%s%s%s",o.nationalite,o.id,o.username,o.password,o.nom,o.prenom,o.appartenance,o.sexe,o.num_bureau)!=EOF)
{
nbtotal++ ;
if (strcmp(o.nationalite,"tunisien")== 0);
{
nbtn++;
}
}
nbtn=(nbtotal-nbtn) ;
*tn=(nbtn/nbtotal)*100;
*te=((nbtotal-nbtn)/nbtotal)*100;
}
fclose(f);
}
/*le nombre d'electeur par bureau de vote*/
int nbe(char *filename,int id)
{
int nbreelecteur=0;
electeur e;
FILE * f=fopen(filename, "r");
if(f!=NULL)
{while(fscanf(f,"%s%s%s%s%s%s%s%s%s%s%s%s\n",e.id,e.cin,e.username,e.password,e.nom,e.prenom,e.d.jour,e.d.mois,e.d.annee,e.sexe,e.num_bureau)!=EOF)
{
if(e.id==id)
nbreelecteur++;
}
}
fclose(f);
return nbreelecteur;
}

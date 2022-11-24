#include "header.h"
#include <stdio.h>
int ajouterbureau(bureau b,char *filename)
{
FILE *f=fopen(filename,"a");
if (f!=NULL)
{fprintf(f,"%s%d%s%d%d%d%d\n",b.municipalite,b.Idbureau,b.adresse,b.numsalle,b.Idagent,b.capaciteelecteurs,b.capaciteobservateurs);
fclose(f);
return 1;
}
else return 0;
}
int modifierbureau( int Idbureau,bureau nouv,char *filename)
{
bureau b;
FILE *f=fopen(filename, "r");
FILE *f2=fopen("aux.txt","w");
if (f==NULL || f2==NULL)
return 0;
else
{while(fscanf(f,"%s%d%s%d%d%d%d\n",&b.municipalite,&b.Idbureau,&b.adresse,&b.numsalle,&b.Idagent,&b.capaciteelecteurs,&b.capaciteobservateurs)!=EOF)
{if(b.Idbureau!=Idbureau)
fprintf(f2,"%s%d%s%d%d%d%d\n",b.municipalite,b.Idbureau,b.adresse,b.numsalle,b.Idagent,b.capaciteelecteurs,b.capaciteobservateurs);
else
fprintf(f2,"%s%d%s%d%d%d%d\n",nouv.municipalite,nouv.Idbureau,nouv.adresse,nouv.numsalle,nouv.Idagent,nouv.capaciteelecteurs,nouv.capaciteobservateurs);
}
fclose(f);
fclose(f2);
remove(filename);
rename("aux.txt",filename);
return 1;
}
}

int supprimerbureau( int Idbureau,char *filename)
{ bureau b;
FILE *f=fopen(filename,"r");
FILE *f2=fopen("aux.txt","w");
if (f==NULL || f2==NULL)
return 0;
else
{
while(fscanf(f,"%s%d%s%d%d%d%d\n",&b.municipalite,&b.Idbureau,&b.adresse,&b.numsalle,&b.Idagent,&b.Idagent,&b.capaciteelecteurs,&b.capaciteobservateurs)!=EOF)
{
if (b.Idbureau!=Idbureau)
fprintf(f2,"%s%d%s%d%d%d%d\n",b.municipalite,b.Idbureau,b.adresse,b.numsalle,b.Idagent,b.capaciteelecteurs,b.capaciteobservateurs);
}
fclose(f);
fclose(f2);
remove(filename);
rename("aux.txt",filename);
return 1;
}
}
bureau chercher(int Idbureau,char *filename)
{ bureau b; int tr=0;
FILE *f=fopen(filename,"r");
if (f!=NULL)
{
while (fscanf(f,&b.municipalite,&b.Idbureau,&b.adresse,&b.numsalle,&b.Idagent,&b.capaciteelecteurs,&b.capaciteobservateurs)!=EOF && tr==0)
{if (Idbureau==b.Idbureau)
tr=1;
}
}
if(tr==0)
b.Idbureau=-1;
return b;
}


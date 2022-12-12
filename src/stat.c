#include "stat.h"

/*************************NBR_CONSEILLER_CALCULE_AUTOMATIQUE*****************************/
int auto_calc(char x[])
{
    int result;
    int y = atoi(x);
    if (y <= 5000)
    {
        result=10;
    }
    else if ((y > 5000) && (y <= 10000))
    {
        result=12;
    }
    else if ((y > 10000) && (y <= 25000))
    {
        result=16;
    }
    else if ((y > 25000) && (y <= 50000))
    {
        result=22;
    }
    else if ((y > 50000) && (y <= 100000))
    {
        result=30;
    }
    else if ((y > 100000) && (y <= 500000))
    {
        result=40;
    }
    else
    {
        result=60;
    }
    return result;
}

float TPE (char *filename)
{
    electeur elcr ;
    FILE *f;
    float b=0.0,v=0.0,t=0.0;
    f=fopen(filename,"r");
    if (f != NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,&elcr.vote)!=EOF)
        {
            t++;
            if(elcr.vote!=-1)
                b++;
        }
    }
    t=((float)(((b)/(t))*100));
    fclose(f);
    return (t);
}
    

void TPHF (char *filename,int *h,int *femme)
{
    electeur elcr ;
    FILE *f;
    f=fopen(filename,"r");
    float t=0.0;
    if (f != NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,&elcr.vote)!=EOF);
        t++;
        if ((strcmp(elcr.sexe,"homme")==0)&&(elcr.vote!=-1))
        {
            *h++;
        }
        else if ((strcmp(elcr.sexe,"femme")==0)&&(elcr.vote!=-1))
        {
            *femme++;
        }
    }
      fclose(f);
      *femme/=t;
      *h/=t;
}
float NVB (char *filename)
{
    electeur elcr ;
    FILE *f;
    float t=0.0,n=0.0;
    f=fopen(filename,"r");
    if (f != NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,
                                        elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,&elcr.vote)!=EOF);
        t++;
        if (elcr.vote==0)
        {
            n++;
        }
    }
      fclose(f);
    return ((t-n)/t);
}
float agemoyen(char *filename)
{
    electeur elcr ;
    FILE *f;
    f=fopen(filename,"r");
    float t=0.0,age=0;
    if (f != NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %i \n",elcr.id,elcr.cin,elcr.username,elcr.password,elcr.nom,elcr.prenom, elcr.Date.jour,elcr.Date.mois,elcr.Date.annee,elcr.sexe,elcr.num_bureau,&elcr.vote)!=EOF);
        t++;
        age+=(2022-(atoi(elcr.Date.annee)));
    }
      fclose(f);
      return (age/t);
}
int nbobservateur(char *filename)
{
    observateur obser ;
    FILE *f;
    float t=0.0,n=0.0;
    f=fopen(filename,"r");
    if (f != NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s    \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance)!=EOF);
        t++;
    }
      fclose(f);
    return (t);
}
void taux_observateur(char *filename,float *tn,float *te)
{
    observateur obser ;
    FILE *f;
    float t=0.0;
    f=fopen(filename,"r");
    if (f != NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s    \n",obser.id,obser.nationalite,obser.username,obser.password,obser.nom,obser.prenom,obser.sexe,obser.num_bureau,obser.appartenance)!=EOF);
        t++;
        if (strcmp(obser.nationalite,"local")==0)
        {
            *tn++;
        }
        else
            *te++;
        
    }
      fclose(f);
    *tn/=t;
    *te/=t;
}

 //Le taux de participation des électeur
 //Le nombre de votes pour chaque liste électorale
 //Les listes selon l’ordre de votes


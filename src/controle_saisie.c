#include "controle_saisie.h"


int controle_saisie_numero(char x[20])
{
int b=0;int a=0;
a=digital(x);
if (a==0)
{return 0;}
else {
b=atoi(x);
printf("%d",b);
if((b>9999999)&&(b<=99999999))
{
  return 1;}
else {return 0;}
}
}

int controle_saisie_annee(char x[20])
{
int a=0;int b=0;
b=digital(x);
if(b==0)
{return 0;}
else{
a=atoi(x);
if ((2022-a)>18){
  return 1;     }
else {return 0;}
}
}



int digital(char x[20])
{
int res=0;
int i,a;
a=strlen(x);
for(i=0;i<=a;i++)
  {
    if (isdigit(x[i])!=0)
    {
      res=res+1;
    }
  }
  if(res==a)
      {return 1;}
    else {return 0;}

}

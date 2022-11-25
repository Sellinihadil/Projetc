#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{ float pourcent;
 float tn,te;
int k;
observateur o1={"tunisien",345,67,"kkk","slim","kefi","isi","f",4};
taux("observateur.txt",&tn,&te);
printf ("le taux d'observateurs etrangers est egale a=%f\n",te);
printf ("le taux d'observateurs tunisiens est egale a=%f\n",tn);
electeur e1={445,765,65,"KIH","lilia","chebbi","samedi","mai",2010,"f",6};
electeur e2={45,75,5,"KIl","nour","ali","samedi","juillet",2000,"f",3};
k=nbe("electeur.txt",445);
 printf("le nombre d'electeurs par bureau de vote=%d\n",k);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    bureau b1={"Ariana",234,"Menzah",2,654,13,5};
    bureau b2={"Tunis",454,"Cite",3,987,16,7};
    bureau b3;
    int x;
    x=ajouterbureau(b1,"bureau.txt");
    if (x==1)
        printf("\n ajout d'un bureau avec succees!!");
    else printf("\n echec d'ajout");
    x=modifierbureau( 234,b2,"bureau.txt");
    if(x==1)
        printf("\nModifie avec succes");
        else printf("\n echec modification");
        x=supprimerbureau("bureau.txt",234);
        if(x==1)
        printf("\n suppression avec succes");
        else printf("\n echec de suppression");
   
b1=chercher(234,"bureau.txt");
if (b1.Idbureau==-1)
printf("bureau inexistant");
else
printf("%s%d%s%d%d%d%d\n",b1.municipalite,b1.Idbureau,b1.adresse,b1.numsalle,b1.Idagent,b1.capaciteelecteurs,b1.capaciteobservateurs);
  return 0;
}

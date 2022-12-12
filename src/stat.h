#include <stdlib.h>
#include <stdio.h>
#include "electeur.h"
#include "observateur.h"

#include "election.h"
#include "reclamation.h"
#include <string.h> 



int auto_calc(char x[]);
float TPE (char *filename);
void TPHF (char *filename,int *h,int *femme);
float NVB (char *filename);
float agemoyen(char *filename);
int nbobservateur(char *filename);
void taux_observateur(char *filename,float *tn,float *te);
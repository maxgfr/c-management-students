#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURE */

typedef struct {
	char idbat[2];
	int maxlogement;
	int logementrestant;
	char nom[32];
	char adresse[100];
	int cp;
}Cite;


/*FONCTIONS*/
Cite lireCite (FILE *flot);
int fcharg (Cite tab[]);
void afficherCite(Cite A);
void afficherTableau(Cite tab[], int nb);
void sauvCite (FILE *flot, Cite *tab,int nb);

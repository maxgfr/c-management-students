#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURE */

typedef struct {
	char idchamb[5];
	int type;
	int disponibilite;
}Logement;

/* FONCTIONS */

Logement lireLog (FILE *flot);

Logement** chargeLog (int *nbLog, int *taillemax);

void afficherLog (Logement l);
void afficherToutLog (Logement *tlog[], int nb);

void triDichLog (Logement **T, int n);
void fusDichLog (Logement **R, Logement **S, Logement **T, int n, int m);
void copiDichLog (Logement **T, Logement **R, int i,int j);

int rechDichLog (char *id, Logement **tab , int nbLog);

Logement** ajoutLog (Logement *tlog[], int *nbLog, int *taillemax);
void decalerADroiteLog (Logement *tlog[], int val, int nb);

Logement** supLog (Logement *tlog[], int *nbLog);
void decalerAGaucheLog (Logement *tlog[], int val, int nb);

void sauvLog (Logement *tlog[], int nb);
Logement** restLog (int *nb);

Logement** modifLog (Logement *tlog[], int *nbLog);



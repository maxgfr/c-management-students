#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURE */

typedef struct {
	char idchamb[5];
	char idbat[2];
	int etage;
	int numchambre;
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

void viderBuffer(void);

void triDichLogTYP (Logement **T, int n);
void fusDichLogTYP (Logement **R, Logement **S, Logement **T, int n, int m);
int rechDichLogTYP (int num, Logement **tab , int nbLog);

void triDichLogDIS (Logement **T, int n);
void fusDichLogDIS (Logement **R, Logement **S, Logement **T, int n, int m);
int rechDichLogDIS (int num, Logement **tab , int nbLog);

void triDichLogCIT (Logement **T, int n);
void fusDichLogCIT (Logement **R, Logement **S, Logement **T, int n, int m);
int rechDichLogCIT (char *c, Logement **tab , int nbLog);

void triDichLogETA (Logement **T, int n);
void fusDichLogETA (Logement **R, Logement **S, Logement **T, int n, int m);
int rechDichLogETA (int num, Logement **tab , int nbLog);

void triDichLogNUM (Logement **T, int n);
void fusDichLogNUM (Logement **R, Logement **S, Logement **T, int n, int m);
int rechDichLogNUM (int num, Logement **tab , int nbLog);



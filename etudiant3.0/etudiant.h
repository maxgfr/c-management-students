#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURE */

typedef struct {
	int jour;
	int mois;
	int annee;
}Date;

typedef struct {
	char idetud[6];
	char prenom[32];
	char nom[32];
	Date datenaiss;
	char etablissement[22];
	int bourse;
	char batpref[2];
	int etat;
	int choix;
}Etudiant;

/* FONCTIONS */

Etudiant lireEtu (FILE *flot);

Etudiant** chargeEtu (char fichier[],int *nbEtu, int *taillemax);

void afficherEtu (Etudiant e);
void afficherToutEtu (Etudiant *tetud[], int nb);

void triDichEtu (Etudiant **T, int n);
void fusDichEtu (Etudiant **R, Etudiant **S, Etudiant **T, int n, int m);
void copiDichEtu (Etudiant **T, Etudiant **R, int i,int j);

int rechDichEtu (char *id, Etudiant *tetud[], int nbEtu);

Etudiant** ajoutEtu (Etudiant *tetud[], int *nbEtu, int *taillemax);
void decalerADroiteEtu (Etudiant **tetud, int val, int nb);

Etudiant** supEtu (Etudiant *tetud[], int *nbEtu);
void decalerAGaucheEtu (Etudiant **tetud, int val, int nb);

void sauvEtu (Etudiant **tetud, int nb);
Etudiant** restEtu (int *nb);

Etudiant** modifEtu (Etudiant *tetud[], int *nbEtu);

void viderBuffer(void);

void triDichEtuECH (Etudiant **T, int n);
void fusDichEtuECH (Etudiant **R, Etudiant **S, Etudiant **T, int n, int m);
int rechDichEtuECH (int num, Etudiant *tetud[], int nbEtu);



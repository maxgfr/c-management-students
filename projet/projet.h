#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////* STRUCTURES *////////////////////////////////////

typedef enum {faux,vrai}Booleen;

/* POUR ETUDIANT */
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


/* POUR DEMANDE */
typedef struct {
	char idetud[6];
	char idchamb[5];
	int demande;
}Demande;

typedef struct maillond {
	Demande d;
	struct maillond *suiv;
}MaillonD, *ListeD;


/*POUR LOGEMENT*/
typedef struct {
	char idchamb[5];
	char idbat[2];
	int etage;
	int numchambre;
	int type;
	int disponibilite;
}Logement;


/* POUR CITE */
typedef struct {
	char idbat[2];
	int maxlogement;
	int logementrestant;
	char nom[32];
	char adresse[100];
	int cp;
}Cite;



////////////////////////* FONCTIONS *////////////////////////////////////


/*POUR ETUDIANT*/
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
void triDichEtuECH (Etudiant **T, int n);
void fusDichEtuECH (Etudiant **R, Etudiant **S, Etudiant **T, int n, int m);
int rechDichEtuECH (int num, Etudiant *tetud[], int nbEtu);

/* POUR DEMANDE */
Demande lireDem (FILE *flot);
void afficherDem (Demande d);
ListeD newListeDem (void);
ListeD insererDem (ListeD l, Demande d);
ListeD inserTetDem (ListeD l, Demande d);
void afficherToutDem (ListeD l);
ListeD supDem (ListeD l, Demande d);
ListeD supTetDem (ListeD l);
Booleen appartientDem (ListeD l, Demande d);
Demande teteDem (ListeD l);
int longDemande (ListeD l);
void sauvDem (ListeD l);
ListeD restDem (ListeD l);
void afficherToutDemX (ListeD l);
void afficherToutDemY (ListeD l);
void afficherToutDemZ (ListeD l);
void afficherSansDem(ListeD l);

/*POUR CITE*/
Cite lireCite (FILE *flot);
int fcharg (Cite tab[]);
void afficherCite(Cite A);
void afficherTableau(Cite tab[], int nb);
void sauvCite (FILE *flot, Cite *tab,int nb);


/* POUR LOGEMENT */
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


/* POUR LE PROJET FINAL */
int menuPrincipal (void);
Booleen coAdmin (void);
int menuA (void);
int menuE (void);
void viderBuffer(void);
/* PARTIE I */
void etudiant1 (void);
void etudiant2 (void);
void etudiant3 (void);
/* PARTIE II */
ListeD mginser (ListeD li);
void admin1 (void);
void admin2 (void);
void admin3 (void);
void admin4 (void);
void admin5 (void);
void admin6 (void);
void admin7 (void);
void admin8 (void);
void admin9 (void);
void admin10 (void);
void admin11 (void);
void admin12 (void);
void admin13 (void);
void admin14 (void);
void admin15 (void);
void admin16 (void);
void admin17 (void);
void admin18 (void);
void admin19 (void);
void admin20 (void);

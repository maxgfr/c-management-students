#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURE */

typedef struct {
	char idchamb[5];
	int type;
	char idbat[2];
	int etage;
	int numchambre;
	int disponibilite;
}Logement;

typedef enum {faux,vrai}Booleen;

typedef struct maillon {
	Logement l;
	struct maillon *suiv;
}Maillon, *ListeL;

/* FONCTIONS */

Logement lireLog (FILE *flot);
void afficherLog (Logement l);

ListeL newListeLog (void);

ListeL insererLog (ListeL li, Logement l);
ListeL inserTetLog (ListeL li, Logement l);
ListeL inserQueLog (ListeL li, Logement l);

void afficherToutLog (ListeL li);

ListeL supLog (ListeL li, Logement l);
ListeL supTetLog (ListeL li);

Booleen appartientLog (ListeL li, Logement l);
Logement teteLog (ListeL li);

int longLogement (ListeL li);

void sauvLog (ListeL li);
ListeL restLog (ListeL li);

ListeL inserQueLog (ListeL li, Logement l);

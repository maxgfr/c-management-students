#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURES */

typedef enum {faux,vrai}Booleen;

typedef struct {
	char idetud[6];
	char idchamb[5];
	int demande;
}Demande;

typedef struct maillon {
	Demande d;
	struct maillon *suiv;
}Maillon, *ListeD;

/* FONCTIONS */

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

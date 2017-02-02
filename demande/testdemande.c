#include "demande.h"

/* Charge le fichier et affiche les 2 premieres demandes. */
void demande1 (void)
{
	FILE *flot;
	Demande d;
	flot=fopen("demande.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	d=lireDem(flot);
	afficherDem(d);
	d=lireDem(flot);
	afficherDem(d);
	fclose(flot);
}

/* Inserer la première ligne du fichier dans une liste PUIS l'afficher. */
void demande2 (void)
{
	FILE *flot;
	Demande d;
	ListeD l;
	flot=fopen("demande.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	d=lireDem(flot);
	l=newListeDem();
	l=insererDem(l,d);
	afficherToutDem(l);
	fclose(flot);
}

/* Inserer toute les valeurs du fichier dans une liste PUIS l'afficher. */
void demande3 (void)
{
	FILE *flot;
	Demande d;
	ListeD l;
	flot=fopen("demande.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=newListeDem();
	while (!feof(flot)) {
	d=lireDem(flot);
	l=insererDem(l,d);
	}
	afficherToutDem(l);
	fclose(flot);
}

/* Inserer deux valeurs PUIS supprime la première valeur insérée PUIS affiche la liste. */
void demande4 (void)
{
	FILE *flot;
	Demande d;
	Demande d1={"F68A1","826A",1};
	Demande d2={"DE569","356C",0};
	ListeD l;
	flot=fopen("demande.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=newListeDem();
	d=lireDem(flot);
	l=insererDem(l,d);
	d=lireDem(flot);
	l=insererDem(l,d);
	l=supDem(l,d1);
	//l=supDem(l,d2);
	afficherToutDem(l);
	fclose(flot);
}

/* Insertion toutes les valeurs + verification d'une valeur dans une liste. */
void demande5 (void)
{
	FILE *flot;
	Demande d;
	Demande d1={"DE569","356C",0};
	Booleen rep;
	ListeD l;
	flot=fopen("demande.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=newListeDem();
	while (!feof(flot)) {
	d=lireDem(flot);
	l=insererDem(l,d);
	}
	rep=appartientDem(l,d1);
	if (rep==vrai)
		printf("La demande recherchée existe.\n");
	else printf("La demande recherchée n'existe pas.\n");
	fclose(flot);
}

/* Permet d'afficher la premiere demande classé selon le critère de l'identifiant.*/
void demande6 (void)
{
	FILE *flot;
	Demande d,d1;
	Booleen rep;
	ListeD l;
	flot=fopen("demande.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=newListeDem();
	while (!feof(flot)) {
	d=lireDem(flot);
	l=insererDem(l,d);
	}
	d1=teteDem(l);
	afficherDem(d1);
	fclose(flot);
}

/* Affiche le nombre de demande totale. */
void demande7 (void)
{
	FILE *flot;
	int longueur;
	Demande d;
	ListeD l;
	flot=fopen("demande.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=newListeDem();
	while (!feof(flot)) {
	d=lireDem(flot);
	l=insererDem(l,d);
	}
	longueur=longDemande(l);
	printf("Il y a encore %d étudiants en attente. \n",longueur);
	fclose(flot);
}

/* Enregistrer des donnèes modifiées dans un fichier.bin*/
void demande8 (void)
{
	FILE *flot;
	int longueur;
	Demande d;
	Demande d1={"F68A1","826A",1};
	ListeD l;
	flot=fopen("demande.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=newListeDem();
	while (!feof(flot)) {
	d=lireDem(flot);
	l=insererDem(l,d);
	}
	l=supDem(l,d1);
	sauvDem(l);
	longueur=longDemande(l);
	printf("Il y a encore %d étudiants en attente. \n",longueur);
	fclose(flot);
}

/* Afficher et ouvrir des donnèes d'un fichier.bin qui contient des listes. */
void demande9 (void)
{
	int longueur;
	ListeD l;
	l=newListeDem();
	l=restDem(l);
	afficherToutDem(l);
	longueur=longDemande(l);
	printf("Il y a encore %d étudiants en attente. \n",longueur);
}

int main (void)
{
	//demande1();
	//demande2();
	//demande3();
	//demande4();
	//demande5();
	//demande6();
	//demande7();
	//demande8();
	//demande9();
	return 0;
}	

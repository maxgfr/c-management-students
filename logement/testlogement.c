#include "logement.h"

/* Charge le fichier et affiche les deux premiers logements. */
void logement1 (void)
{
	FILE *flot;
	Logement l;
	flot=fopen("logement.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=lireLog(flot);
	afficherLog(l);
	l=lireLog(flot);
	afficherLog(l);
	fclose(flot);
}

/* Inserer la première ligne du fichier dans une liste PUIS l'afficher. */
void logement2 (void)
{
	FILE *flot;
	Logement l;
	ListeL li;
	flot=fopen("logement.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=lireLog(flot);
	li=newListeLog();
	li=insererLog(li,l);
	afficherToutLog(li);
	fclose(flot);
}

/* Inserer toute les valeurs du fichier dans une liste PUIS l'afficher. */
void logement3 (void)
{
	FILE *flot;
	Logement l;
	ListeL li;
	flot=fopen("logement.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	li=newListeLog();
	while (!feof(flot)) {
	l=lireLog(flot);
	li=insererLog(li,l);
	}
	afficherToutLog(li);
	fclose(flot);
}

/* Inserer deux valeurs PUIS supprime la première valeur insérée PUIS affiche la liste. */
void logement4 (void)
{
	FILE *flot;
	Logement l;
	Logement l1={"826A",0,"A",8,26,0};
	Logement l2={"356C",2,"C",3,56,0};
	ListeL li;
	flot=fopen("logement.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	li=newListeLog();
	l=lireLog(flot);
	li=insererLog(li,l);
	l=lireLog(flot);
	li=insererLog(li,l);
	li=supLog(li,l1);
	//li=supLog(li,l2);
	afficherToutLog(li);
	fclose(flot);
}

/* Insertion toutes les valeurs + verification d'une valeur dans une liste. */
void logement5 (void)
{
	FILE *flot;
	Logement l;
	Logement l1={"826A",0,"A",8,26,0};
	Booleen rep;
	ListeL li;
	flot=fopen("logement.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	li=newListeLog();
	while (!feof(flot)) {
	l=lireLog(flot);
	li=insererLog(li,l);
	}
	rep=appartientLog(li,l1);
	if (rep==vrai)
		printf("Le logement recherchée existe.\n");
	else printf("Le logement recherchée n'existe pas.\n");
	fclose(flot);
}

/* Permet d'afficher la premiere logement classé selon le critère de l'identifiant.*/
void logement6 (void)
{
	FILE *flot;
	Logement l,l1;
	Booleen rep;
	ListeL li;
	flot=fopen("logement.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	li=newListeLog();
	while (!feof(flot)) {
	l=lireLog(flot);
	li=insererLog(li,l);
	}
	l1=teteLog(li);
	afficherLog(l1);
	fclose(flot);
}

/* Affiche le nombre de logement totale. */
void logement7 (void)
{
	FILE *flot;
	int longueur;
	Logement l;
	ListeL li;
	flot=fopen("logement.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	li=newListeLog();
	while (!feof(flot)) {
	l=lireLog(flot);
	li=insererLog(li,l);
	}
	longueur=longLogement(li);
	printf("Il y a encore %d logement disponible. \n",longueur);
	fclose(flot);
}

/* Enregistrer des donnèes modifiées dans un fichier.bin*/
void logement8 (void)
{
	FILE *flot;
	int longueur;
	Logement l;
	Logement l1={"826A",0,"A",8,26,0};
	ListeL li;
	flot=fopen("logement.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	li=newListeLog();
	while (!feof(flot)) {
	l=lireLog(flot);
	li=insererLog(li,l);
	}
	li=supLog(li,l1);
	sauvLog(li);
	longueur=longLogement(li);
	printf("Il y a encore %d de logements disponible. \n",longueur);
	fclose(flot);
}

/* Afficher et ouvrir des donnèes d'un fichier.bin qui contient des listes. */
void logement9 (void)
{
	FILE *flot;
	int longueur;
	ListeL li;
	li=newListeLog();
	li=restLog(li);
	afficherToutLog(li);
	longueur=longLogement(li);
	printf("Il y a encore %d logements disponible. \n",longueur);
}

int main (void)
{
	//logement1();
	//logement2();
	//logement3();
	//logement4();
	//logement5();
	//logement6();
	//logement7();
	//logement8();
	//logement9();
	return 0;
}	

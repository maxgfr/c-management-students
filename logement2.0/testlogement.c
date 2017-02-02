#include "logement.h"

/* Charge le fichier et affiche les 2 premiers logements.*/
void logement1 (void)
{
	Logement l;
	FILE *flot;
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

/* Créer un tableau de pointeurs où y'a tout les logements + affiche le tableau */
void logement2 (void)
{
	Logement **tab;
	int nbLog,taillemax,i; 
	tab=chargeLog(&nbLog, &taillemax); 
	afficherToutLog(tab,nbLog);
	printf("Le nombre d'étudiant inscrit est de : %d.\n", nbLog);
	printf("La taille maximale du tableau est de : %d.\n", taillemax);
	for (i=0;i<nbLog;i++)
		free(tab[i]);
}

/* Le tableau va être trié par l'id de la chambre ( d'abord par batiment ) */
void logement3 (void)
{
	Logement **tab;
	int nbLog,taillemax,val,i;
	tab=chargeLog(&nbLog, &taillemax); 
	triDichLog(tab,nbLog);
	afficherToutLog(tab,nbLog);
	for (i=0;i<nbLog;i++)
		free(tab[i]);
}

/* Une fois trié, nous pouvons faire une recherche dichotomique*/
void logement4 (void)
{
	Logement **tab;
	int nbLog,taillemax,val,l,i;
	char id[5];
	tab=chargeLog(&nbLog, &taillemax); 
	triDichLog(tab,nbLog);
	afficherToutLog(tab,nbLog);
	printf("\n");
	printf("Veuillez indiquer l'indentifiant de la chambre à rechercher : \n");
	scanf("%s",id);
	l=strlen(id);
	while(l!=4) {
		printf("L'identifiant a 4 caractères maximum. Réessayez :\n");
		scanf("%s%*c",id);
		l=strlen(id);
	}
	val=rechDichLog(id,tab,nbLog);
	if (val==nbLog)
		printf("Le logement avec l'id %s n'existe pas... \n",id);
	else if (strcmp(tab[val]->idchamb,id)==0)
			printf("Le logement ayant pour id : %s existe. Il a pour indice %d dans le tableau.\n",id,val);
		else printf("Le logement ayant pour id : %s n'existe pas... \n",id);
	for (i=0;i<nbLog;i++)
		free(tab[i]);
}

/*Ajout d'un logement*/
void logement5 (void)
{
	Logement **tab;
	int nbLog,taillemax,i,val;
	tab=chargeLog(&nbLog, &taillemax);  
	triDichLog(tab,nbLog);
	tab=ajoutLog(tab,&nbLog,&taillemax);
	printf("\n");
	printf("Le nombre de logement est de : %d.\n", nbLog);
	printf("La taille maximale du tableau est de : %d.\n", taillemax);
	printf("\n");
	afficherToutLog(tab,nbLog);
	for (i=0;i<nbLog;i++)
		free(tab[i]);
}
/*Suppression d'un logement*/
void logement6 (void)
{
	Logement **tab;
	int nbLog,taillemax,i,val;
	tab=chargeLog(&nbLog, &taillemax); 
	triDichLog(tab,nbLog);
	afficherToutLog(tab,nbLog);
	tab=supLog(tab,&nbLog);
	printf("\n");
	afficherToutLog(tab,nbLog);
	printf("\n");
	printf("Le nombre de logement est de : %d.\n", nbLog);
	for (i=0;i<nbLog;i++)
		free(tab[i]);
}

/*Sauvegarder dans un fichier binaire le tableau trié*/
void logement7 (void)
{
	Logement **tab;
	int nbLog,taillemax,i;
	tab=chargeLog(&nbLog, &taillemax); 
	triDichLog(tab,nbLog);
	sauvLog (tab,nbLog);
	printf("Le nombre de logement sauvegardé est de : %d.\n", nbLog);
	for (i=0;i<nbLog;i++)
		free(tab[i]);
}

/*Lire dans un fichier binaire le tableau*/
void logement8 (void)
{
	Logement **tab;
	int nb,i;
	tab=restLog(&nb);
	afficherToutLog(tab,nb);
	for (i=0;i<nb;i++)
		free(tab[i]);
}

/*Modification d'un logement*/
void logement9 (void)
{
	Logement **tab;
	int nbLog,taillemax,i,val;
	tab=chargeLog(&nbLog, &taillemax);  
	triDichLog(tab,nbLog);
	tab=modifLog(tab,&nbLog);
	printf("\n");
	afficherToutLog(tab,nbLog);
	for (i=0;i<nbLog;i++)
		free(tab[i]);
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


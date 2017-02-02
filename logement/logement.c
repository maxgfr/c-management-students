#include "logement.h"

/* 1-FONCTION DE LECTURE D'UN SEUL LOGEMENT */

Logement lireLog (FILE *flot)
{
	Logement l;
	fscanf(flot,"%s%*c",l.idchamb);
	fscanf(flot,"%d%^[a-z]",&l.type);
	fscanf(flot,"%s%*c",l.idbat);
	fscanf(flot,"%d%^[a-z]",&l.etage);
	fscanf(flot,"%d%^[a-z]",&l.numchambre);
	fscanf(flot,"%d%^[a-z]",&l.disponibilite);
	return l;
}

/* 1.5-FONCTION D'AFFICHAGE D'UN SEUL LOGEMENT */

void afficherLog (Logement l)
{
	printf("L'identifiant de la chambre est : %s :\n",l.idchamb);
	if (l.type==0)
		printf("Le logement choisi est une chambre.\n");
	else if (l.type==1)
		printf("Le logement choisi est un studio.\n");
		else if (l.type==2)
				printf("Le logement choisi est un T1.\n");
			else if (l.type==3)
					printf("Le logement choisi est une T2.\n");
				else {
					printf("Un problème est survenu. La saisie de la chambre au niveau de son type qui a été mal effectuée.\n");
					printf("Je vous invite de modifier via le programme la chambre ayant pour id : %s.\n",l.idchamb);
					exit(6);
					}
	if(strcmp(l.idbat,"A")==0)
		printf("La chambre est situé dans la résidence LES ROCHES. \n");
	else if(strcmp(l.idbat,"B")==0)
			printf("La chambre est situé dans la résidence LE STELAR. \n");
		else if(strcmp(l.idbat,"C")==0)
				printf("La chambre est situé dans la résidence LE CROUCROUS. \n");
			else {
				printf("Un problème est survenu. La saisie de la chambre au niveau de sa cité qui a été mal effectuée.\n");
				printf("Je vous invite de modifier via le programme la chambre ayant pour id : %s.\n",l.idchamb);
				exit(6); 
				}
	printf("Elle est situé à l'étage numero %d.\n",l.etage);
	printf("Le numero de la chambre est %d.\n",l.numchambre);
	if (l.disponibilite==0)
		printf("Le logement choisi est disponible.\n");
	else if (l.disponibilite==1)
		printf("Le logement choisi est occupé.\n");
		else if (l.disponibilite==2)
				printf("Le logement choisi est en travaux.\n");
			else {
					printf("Un problème est survenu. La saisie de la chambre au niveau de sa disponibilité qui a été mal effectuée.\n");
					printf("Je vous invite de modifier via le programme la chambre ayant pour id : %s.\n",l.idchamb);
					exit(6);
				}
}

/* 2- FONCTION DE CREATION DE LISTE */
ListeL newListeLog (void)
{
	ListeL li;
	li=NULL;
	return li;
}

/* 3- FONCTION D'INSERTION DES VALEURS DANS UNE LISTE */

ListeL insererLog (ListeL li, Logement l)
{
	if (li==NULL) 
		return inserTetLog(li,l); 
	if (strcmp(l.idchamb,li->l.idchamb)<0)
		return inserTetLog(li,l); 
	if (strcmp(l.idchamb,li->l.idchamb)==0)
		return li;
	if (strcmp(l.idchamb,li->l.idchamb)>0)
		return inserQueLog(li,l);
	return li;
}

ListeL inserTetLog (ListeL li, Logement l)
{
	Maillon *aux;
	aux=(Maillon*)malloc(sizeof(Maillon));
	if (aux==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	aux->l=l;
	aux->suiv=li;
	return aux;
}

ListeL inserQueLog (ListeL li, Logement l)
{
	if (li==NULL)
		return inserTetLog(li,l);
	li->suiv=inserQueLog(li->suiv,l);
	return li;
}
		
/* 4- AFFICHAGE DE LA LISTE */
void afficherToutLog (ListeL li)
{
	Logement l;
	if (li==NULL) {
		printf("\n");
		return;
	}
	afficherLog(li->l);
	afficherToutLog(li->suiv);
}

/* 5- FONCTION DE SUPPRESSION DE VALEURS DANS UNE LISTE */

ListeL supLog (ListeL li, Logement l)
{
	if (li==NULL) 
		return li; 
	if (strcmp(l.idchamb,li->l.idchamb)<0)
		return li; 
	if (strcmp(l.idchamb,li->l.idchamb)==0)
		return supTetLog(li);
	li->suiv=supLog(li->suiv,l);
	return li;
}

ListeL supTetLog (ListeL li)
{
	Maillon *m;
	if (li==NULL) {
		printf("Operation interdite.\n");
		exit(3);
	}
	m=li;
	li=li->suiv;
	free(m);
	return li;
}

/* 6- VERIFICATION */

Booleen appartientLog (ListeL li, Logement l)
{
	if (li==NULL)
		return faux;
	if (strcmp(l.idchamb,li->l.idchamb)==0)
		return vrai;
	return appartientLog(li->suiv,l);
}


/*7-AFFICHE LE PREMIER LOGEMENT DE LA LISTE (TÊTE DE LISTE)*/

Logement teteLog (ListeL li)
{
	if (li==NULL) {
		printf("Operation interdite.\n");
		exit(3);
	}
	return li->l;
}

/* 8- AFFICHE LE NOMBRE DE DEMANDE */

int longLogement (ListeL li)
{
	if (li==NULL)
		return 0;
	return longLogement(li->suiv)+1;
}

/* 9- MISE A JOUR D'AJOUT DE LA PART DES ETUDIANTS */

void sauvLog (ListeL li)
{
	FILE *flot;
	Logement l;
	flot=fopen("logement.bin", "wb");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en écriture est survenu.\n");
		exit(1);
	}
	while(li!=NULL) {
	fwrite(li->l.idchamb,sizeof(li->l.idchamb), 1,flot);
	fwrite(&li->l.type,sizeof(li->l.type),1,flot);
	fwrite(li->l.idbat,sizeof(li->l.idbat),1,flot);
	fwrite(&li->l.etage,sizeof(li->l.etage),1,flot);
	fwrite(&li->l.numchambre,sizeof(li->l.numchambre),1,flot);
	fwrite(&li->l.disponibilite,sizeof(li->l.disponibilite),1,flot);
	li=li->suiv;
	}
	fclose (flot);
}
/* 10 - FONCTION DE SAUVEGARDE */

ListeL restLog (ListeL li)
{
	FILE *flot;
	Logement l;
	flot=fopen("logement.bin", "rb");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	while(!feof(flot)) {
	fread(l.idchamb,sizeof(l.idchamb), 1,flot);
	fread(&l.type,sizeof(l.type),1,flot);
	fread(l.idbat,sizeof(l.idbat),1,flot);
	fread(&l.etage,sizeof(l.etage),1,flot);
	fread(&l.numchambre,sizeof(l.numchambre),1,flot);
	fread(&l.disponibilite,sizeof(l.disponibilite),1,flot);
	li=insererLog(li,l);
	}
	fclose(flot);
	return li;
}

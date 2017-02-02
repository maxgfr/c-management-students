#include "demande.h"

/* 1-FONCTION DE LECTURE D'UNE SEULE DEMANDE */

Demande lireDem (FILE *flot)
{
	Demande d;
	fscanf(flot,"%s%*c",d.idetud);
	fscanf(flot,"%s%*c",d.idchamb);
	fscanf(flot,"%d%^[a-z]",&d.demande); /* pour que ça évite de faire npq, comme ça s'arrête à l'espace et ça prends pas caract*/
	return d;
}

/* 1.5-FONCTION D'AFFICHAGE D'UNE SEULE DEMANDE */

void afficherDem (Demande d)
{
	printf("Pour l'étudiant d'identifiant : %s :\n",d.idetud);
	printf("Le numero de la chambre reçu a pour identifiant : %s.\n",d.idchamb);
	if (d.demande==1)
		printf("L'étudiant souhaite changer de chambre manuellement.\n");
	printf("\n");
}

/* 2- FONCTION DE CREATION DE LISTE */
ListeD newListeDem (void)
{
	ListeD l;
	l=NULL;
	return l;
}

/* 3- FONCTION D'INSERTION DES VALEURS DANS UNE LISTE */

ListeD insererDem (ListeD l, Demande d)
{
	if (l==NULL) 
		return inserTetDem(l,d); 
	if (strcmp(d.idetud,l->d.idetud)<0)
		return inserTetDem(l,d); 
	if (strcmp(d.idetud,l->d.idetud)==0)
		return l;
	l->suiv=insererDem(l->suiv,d);
	return l;
}

ListeD inserTetDem (ListeD l, Demande d)
{
	Maillon *aux;
	aux=(Maillon*)malloc(sizeof(Maillon));
	if (aux==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	aux->d=d;
	aux->suiv=l;
	return aux;
}
		
/* 4- AFFICHAGE DE LA LISTE */
void afficherToutDem (ListeD l)
{
	Demande d;
	if (l==NULL) {
		printf("\n");
		return;
	}
	afficherDem(l->d);
	afficherToutDem(l->suiv);
}

/* 5- FONCTION DE SUPPRESSION DE VALEURS DANS UNE LISTE */

ListeD supDem (ListeD l, Demande d)
{
	if (l==NULL) 
		return l; 
	if (strcmp(d.idetud,l->d.idetud)<0)
		return l; 
	if (strcmp(d.idetud,l->d.idetud)==0)
		return supTetDem(l);
	l->suiv=supDem(l->suiv,d);
	return l;
}

ListeD supTetDem (ListeD l)
{
	Maillon *m;
	if (l==NULL) {
		printf("Operation interdite.\n");
		exit(3);
	}
	m=l;
	l=l->suiv;
	free(m);
	return l;
}

/* 6- VERIFICATION */

Booleen appartientDem (ListeD l, Demande d)
{
	if (l==NULL)
		return faux;
	if (strcmp(d.idetud,l->d.idetud)==0)
		return vrai;
	return appartientDem(l->suiv,d);
}


/*7-AFFICHE LA PREMIERE DE DEMANDE LA LISTE (TÊTE DE LISTE)*/

Demande teteDem (ListeD l)
{
	if (l==NULL) {
		printf("Operation interdite.\n");
		exit(3);
	}
	return l->d;
}

/* 8- AFFICHE LE NOMBRE DE DEMANDE */

int longDemande (ListeD l)
{
	if (l==NULL)
		return 0;
	return longDemande(l->suiv)+1;
}

/* 9- MISE A JOUR D'AJOUT DE LA PART DES ETUDIANTS */

void sauvDem (ListeD l)
{
	FILE *flot;
	flot=fopen("demande.bin", "wb");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en écriture est survenu.\n");
		exit(1);
	}
	while(l!=NULL) {
	fwrite(l->d.idetud,sizeof(l->d.idetud), 1,flot);
	fwrite(l->d.idchamb,sizeof(l->d.idchamb),1,flot);
	fwrite(&l->d.demande,sizeof(l->d.demande),1,flot);
	l=l->suiv;
	}
	fclose (flot);
}

/* 10 - FONCTION DE SAUVEGARDE */

ListeD restDem (ListeD l)
{
	FILE *flot;
	Demande d;
	flot=fopen("demande.bin", "rb");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	while(!feof(flot)) {
	fread(d.idetud,sizeof(d.idetud), 1,flot);
	fread(d.idchamb,sizeof(d.idchamb),1,flot);
	fread(&d.demande,sizeof(d.demande),1,flot);
	l=insererDem(l,d);
	}
	fclose(flot);
	return l;
}


/* 11- AFFICHAGE DE LA LISTE à l'idchamb où il y a XXXX*/
void afficherToutDemX (ListeD l)
{
	Demande d;
	if (l==NULL) {
		printf("\n");
		return;
	}
	if (strcmp(l->d.idchamb,"XXXX")==0) {
		afficherDem(l->d);
	}
	afficherToutDemX(l->suiv);
}

/* 12- AFFICHAGE DE LA LISTE à l'idchamb où il y a YYYY*/
void afficherToutDemY (ListeD l)
{
	Demande d;
	if (l==NULL) {
		printf("\n");
		return;
	}
	if (strcmp(l->d.idchamb,"YYYY")==0) {
		afficherDem(l->d);
	}
	afficherToutDemY(l->suiv);
}


/* 13- AFFICHAGE DE LA LISTE à l'idchamb où il y a ZZZZ*/
void afficherToutDemZ (ListeD l)
{
	Demande d;
	if (l==NULL) {
		printf("\n");
		return;
	}
	if (strcmp(l->d.idchamb,"ZZZZ")==0) {
		afficherDem(l->d);
	}
	afficherToutDemZ(l->suiv);
}

/*14- AFFICHAFGE SANS Z SANS X SANS Y*/
void afficherSansDem(ListeD l)
{
	Demande d;
	if (l==NULL) {
		printf("\n");
		return;
	}
	if (strcmp(l->d.idchamb,"XXXX")!=0 && strcmp(l->d.idchamb,"YYYY")!=0 && strcmp(l->d.idchamb,"ZZZZ")!=0) {
		afficherDem(l->d);
	}
	afficherSansDem(l->suiv);
}





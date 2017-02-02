#include "etudiant.h"

/* 1-FONCTION DE LECTURE D'UN ETUDIANT*/

Etudiant lireEtu (FILE *flot)
{
	Etudiant e;
	fscanf(flot,"%s%*c",e.idetud); /* pour vider le buffer (enlever les assignements soit lu et non retourné)*/
	fgets(e.prenom,32,flot);
	e.prenom[strlen(e.prenom)-1]='\0';
	fgets(e.nom,32,flot);
	e.nom[strlen(e.nom)-1]='\0';
	fscanf(flot,"%d/%d/%d%*c",&e.datenaiss.jour,&e.datenaiss.mois,&e.datenaiss.annee);
	fgets(e.etablissement,22,flot);
	e.etablissement[strlen(e.etablissement)-1]='\0';
	fscanf(flot,"%d",&e.bourse);
	fscanf(flot,"%s",e.batpref);
	return e;
}

/* 2- FONCTION DE CHARGEMENT DANS UN TABLEAU DE TOUS LES ETUDIANTS */

Etudiant* chargeEtu (char fichier[],int *nbEtu, int *taillemax)
{
	Etudiant e;
	Etudiant *nouvtetud,*tetud;
	*nbEtu=0;
	*taillemax=12; /* Il y a 17 000 étudiants chaque année à Clermont-Ferrand*/
	int i=0;
	FILE *flot;
	flot=fopen(fichier,"r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	tetud=(Etudiant *)malloc(*taillemax*sizeof(Etudiant));
	if(tetud==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	e=lireEtu(flot);
	while(!feof(flot)) {
		if(*nbEtu==*taillemax) {
			nouvtetud=(Etudiant*)realloc(tetud[],(*taillemax+5)*sizeof(Etudiant));
			if(nouvtetud==NULL) {
				printf("Un problème d'allocation mémoire est survenu. \n");
				exit(2);
			}
			*taillemax=*taillemax+5;
			tetud=nouvtetud;
		}	
		tetud[*nbEtu]=e;
		*nbEtu=*nbEtu+1;
		e=lireEtu(flot);
	}
	fclose(flot);
	return tetud;
}

/* 3.1-FONCTION D'AFFICHAGE D'UN ETUDIANT */

void afficherEtu (Etudiant e)
{
	printf("%s\t",e.idetud);
	printf("%s\t",e.prenom);
	printf("%s\t",e.nom);
	printf("%d/%d/%d\t",e.datenaiss.jour,e.datenaiss.mois,e.datenaiss.annee);
	printf("%s\t",e.etablissement);
	printf("%d\t",e.bourse);
	printf("%s\t",e.batpref);
	printf("\n");
}

/* 3.2-FONCTION D'AFFICHAGE DE TOUS LES ETUDIANTS */

void afficherToutEtu (Etudiant tetud[], int nb)
{
		int i;
		for(i=0;i<nb;i++)
			afficherEtu(tetud[i]);
}

/* 4- FONCTIONS DE TRI DICHOTOMIQUE PAR IDENTIFIANT */

void triDichEtu (Etudiant *T, int n)
{
	Etudiant *R,*S;
	if (n==1)
		return;
	R=(Etudiant*)malloc((n/2)*sizeof(Etudiant));
	S=(Etudiant*)malloc((n-n/2)*sizeof(Etudiant));
	if (R==NULL || S==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	copiDichEtu(T,R,0,n/2);
	copiDichEtu(T,S,n/2,n);
	triDichEtu(R,n/2);
	triDichEtu(S,n-n/2);
	fusDichEtu(R,S,T,n/2,n-n/2);
	free(R);
	free(S);
}


void fusDichEtu (Etudiant *R, Etudiant *S, Etudiant *T, int n, int m)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<n && j<m) {
		if(strcmp(R[i].idetud,S[j].idetud)<0) {
				T[k]=R[i];
				k=k+1;
				i=i+1;
		}
		else {
			T[k]=S[j];
			k=k+1;
			j=j+1;
		}
	}
	while(i<n) {
		T[k]=R[i];
		i=i+1;
		k=k+1;
	}
	while(j<m) {
		T[k]=S[j];
		j=j+1;
		k=k+1;
	}
}

void copiDichEtu (Etudiant *T, Etudiant *R, int i,int j)
{
	int k=0;
	while(i<j) {
		R[k]=T[i];
		i=i+1;
		k=k+1;
	}
}

/* 5- FONCTION DE RECHERCHE DICHOTOMIQUE PAR IDENTIFIANT (necessite tableau trié) */

int rechDichEtu (char *id, Etudiant tetud[], int nbEtu)
{
	int inf,sup,m;
	inf=0;
	sup=nbEtu-1;
	while(inf<=sup)
	{
		m=(inf+sup)/2;
		if(strcmp(id,tetud[m].idetud)==0)
			return m;
		if(strcmp(id,tetud[m].idetud)<0)
			sup=m-1;
		else inf=m+1;
	}
return inf;
}

/* 6 FONCTIONS POUR AJOUTER UN ETUDIANT (INSCRIPTION) */


Etudiant* ajoutEtu (Etudiant tetud[], int *nbEtu, int *taillemax)
{
	int val,nb,l;
	Etudiant *nouv;
	Etudiant e;
	/*ETAPE 1 : Saisie d'information basique en vérifiant bien que l'id est unique et 5 caractères maximum*/
	printf("INSCRIPTION :\n");
	printf("Saisissez un identifiant composé de 5 caractères :\n");
	scanf("%s%*c",e.idetud);
	l=strlen(e.idetud);
	while(l!=5) {
		printf("L'identifiant a 5 caractères maximum. Réessayez :\n");
		scanf("%s%*c",e.idetud);
		l=strlen(e.idetud);
	}
	nb=*nbEtu;
	val=rechDichEtu(e.idetud,tetud,nb);
	if (val==*nbEtu)
		printf("L'idenfiant %s est disponible. \n",e.idetud);
	else if (strcmp(tetud[val].idetud,e.idetud)==0) {
			printf("L'idenfiant %s n'est plus disponible. \n",e.idetud);
			while (strcmp(tetud[val].idetud,e.idetud)==0) {
				printf("Saisissez un nouveau identifiant composé de 5 caractères, non utilisé par une autre personne :\n");
				scanf("%s%*c",e.idetud);
				l=strlen(e.idetud);
				while(l!=5) {
					printf("L'identifiant doit avoir 5 caractères maximum. Réessayez :\n");
					scanf("%s%*c",e.idetud);
					l=strlen(e.idetud);
				}
				val=rechDichEtu(e.idetud,tetud,nb);
			}
		}
		else printf("L'idenfiant %s est disponible. \n",e.idetud);
	printf("Saisissez votre prénom :\n");
	fgets(e.prenom,32,stdin);
	e.prenom[strlen(e.prenom)-1]='\0';
	printf("Saisissez votre nom :\n");
	fgets(e.nom,32,stdin);
	e.nom[strlen(e.nom)-1]='\0';
	printf("Saisissez votre date de naissance sous le forme jj/mm/aaaa :\n");
	scanf("%d/%d/%d%*c",&e.datenaiss.jour,&e.datenaiss.mois,&e.datenaiss.annee);
	while (e.datenaiss.jour<0 || e.datenaiss.jour>32 || e.datenaiss.mois<0 || e.datenaiss.mois>13 || e.datenaiss.annee<1900 ||  e.datenaiss.annee>2010) {
		printf("Erreur de saisie. Réessayez.\n");
		printf("Saisissez votre date de naissance sous le forme jj/mm/aaaa :\n");
		scanf("%d/%d/%d%*c",&e.datenaiss.jour,&e.datenaiss.mois,&e.datenaiss.annee);
	}
	printf("Saisissez votre établissement d'étude :\n");
	fgets(e.etablissement,22,stdin);
	e.etablissement[strlen(e.etablissement)-1]='\0';
	printf("Saisissez votre échelon boursier :\n");
	scanf("%d",&e.bourse);
	printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
	scanf("%s",e.batpref);
	l=strlen(e.batpref);
	while(l!=1) {
		printf("Une lettre au maximum. Réessayez :\n");
		scanf("%s%*c",e.batpref);
		l=strlen(e.batpref);
	}
	while (strcmp(e.batpref,"A")!=0 && strcmp(e.batpref,"B")!=0 && strcmp(e.batpref,"C")!=0) {
		printf("La lettre ne peut être que A ou B ou C.\n");
		printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
		scanf("%s",e.batpref);
		l=strlen(e.batpref);
		while(l!=1) {
			printf("Une lettre au maximum. Réessayez :\n");
			scanf("%s%*c",e.batpref);
			l=strlen(e.batpref);
		}
	}
	/*ETAPE 2 : Passons maintenant à la saisie dans le tableau*/
	/*ETAPE 2.1 : Saisie à la fin du tableau */
	if (val==*nbEtu) {
		if(*nbEtu==*taillemax) { /* au cas où on serait au maximum du tableau avant l'insertion*/
			nouv=(Etudiant*)realloc(tetud,(*taillemax+5)*sizeof(Etudiant));
			if(nouv==NULL) {		
				printf("Un problème d'allocation mémoire est survenu. \n");
				exit(2);
			}
			*taillemax=*taillemax+5;
			tetud=nouv;			
		}
		tetud[*nbEtu]=e;
		*nbEtu=*nbEtu+1;
		return tetud;
	}
	/*ETAPE 2.2 : Si nous avons un indice d'insertion, nous devons l'inserer à cet emplacement*/
	else if (strcmp(tetud[val].idetud,e.idetud)!=0) {
			if(*nbEtu==*taillemax) { /* au cas où on serait au maximum du tableau avant l'insertion*/
				nouv=(Etudiant*)realloc(tetud,(*taillemax+5)*sizeof(Etudiant));
				if(nouv==NULL) {		
					printf("Un problème d'allocation mémoire est survenu. \n");
					exit(2);
				}
				*taillemax=*taillemax+5;
				tetud=nouv;			
			}
			decalerADroiteEtu(tetud,val,nb);
			tetud[val]=e;
			*nbEtu=*nbEtu+1;
			return tetud;
		}
}

void decalerADroiteEtu (Etudiant *tetud, int val, int nb)
{
	int i;
	for(i=nb-1;i>=val;i--)
		tetud[i+1]=tetud[i];
}

/* 7-FONCTIONS POUR SUPPRIMER UN ETUDIANT (INSCRIPTION) */

Etudiant* supEtu (Etudiant tetud[], int *nbEtu)
{
	int val,nb,l;
	char id[6], rep[5];
	printf("Veuillez entrer l'identifiant de l'étudiant à supprimer.\n");
	scanf("%s%*c",id);
	l=strlen(id);
	while(l!=5) {
		printf("L'identifiant possède 5 caractères maximum. Réessayez :\n");
		scanf("%s%*c",id);
		l=strlen(id);
	}
	nb=*nbEtu;
	val=rechDichEtu(id,tetud,nb);
	while (val==*nbEtu || strcmp(id,tetud[val].idetud)!=0) {
		printf("L'identifiant recherché n'existe pas.\n");
		printf("Voulez vous quittez le programme ? (Répondez par oui ou non) \n");
		scanf("%s%*c",rep);
		if (strcmp(rep,"oui")==0) {
			printf("Bonne fin de journée.\n");
			exit(5);
		}
		printf("Veuillez entrer donc entrer un nouvel identifiant d'étudiant à supprimer.\n");
		scanf("%s%*c",id);
		l=strlen(id);
		while(l!=5) {
			printf("L'identifiant possède 5 caractères maximum. Réessayez :\n");
			scanf("%s%*c",id);
			l=strlen(id);
		}
		val=rechDichEtu(id,tetud,nb);
	}
	decalerAGaucheEtu(tetud,val,nb);
	*nbEtu=*nbEtu-1;
	return tetud;
}

void decalerAGaucheEtu (Etudiant *tetud, int val, int nb)
{
	int i;
	for(i=val;i<nb-1;i++)
		tetud[i]=tetud[i+1];
}

/* 8-FONCTION DE SAUVEGARDE */
/*binaire utilisé car il y a beaucoup d'étudiant*/

void sauvEtu (Etudiant *tetud, int nb)
{
	FILE *flot;
	flot=fopen("etudiant.bin","wb");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	fwrite(&nb,sizeof(int),1,flot);
	fwrite(tetud,sizeof(Etudiant),nb,flot);
	fclose(flot);	
}

/* 9-FONCTION DE LECTURE BINAIRE */

int restEtu (Etudiant *tetud)
{
	FILE *flot;
	int nb;
	flot=fopen("etudiant.bin","rb");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	fread(&nb,sizeof(int),1,flot);
	fread(tetud,sizeof(Etudiant),nb,flot);
	fclose(flot);
	return nb;
}

/* 10 - MODIFICATION ETUDIANT */

Etudiant* modifEtu (Etudiant tetud[], int *nbEtu)
{
	Etudiant e;
	int val,nb,l;
	char id[6], rep[4];
	/*SAISIE DE L'IDENTIFIANT*/
	printf("Veuillez entrer votre identifiant.\n");
	scanf("%s%*c",e.idetud);
	l=strlen(e.idetud);
	while(l!=5) {
		printf("L'identifiant possède 5 caractères maximum. Réessayez :\n");
		scanf("%s%*c",e.idetud);
		l=strlen(e.idetud);
	}
	nb=*nbEtu;
	val=rechDichEtu(e.idetud,tetud,nb);
	while (val==*nbEtu || strcmp(e.idetud,tetud[val].idetud)!=0) {
		printf("L'identifiant recherché n'existe pas.\n");
		printf("Voulez vous quittez le programme ? (Répondez par oui ou non) \n");
		scanf("%s%*c",rep);
		if (strcmp(rep,"oui")==0) {
			printf("Bonne fin de journée.\n");
			exit(5);
		}
		printf("Veuillez entrer donc entrer à nouveau votre identifiant à supprimer.\n");
		scanf("%s%*c",e.idetud);
		l=strlen(e.idetud);
		while(l!=5) {
			printf("L'identifiant possède 5 caractères maximum. Réessayez :\n");
			scanf("%s%*c",e.idetud);
			l=strlen(e.idetud);
		}
		val=rechDichEtu(e.idetud,tetud,nb);
	}
	/* SAISIE DES INFORMATIONS POUR L'ETUDIANT */
	printf("Saisissez votre prénom :\n");
	fgets(e.prenom,32,stdin);
	e.prenom[strlen(e.prenom)-1]='\0';
	printf("Saisissez votre nom :\n");
	fgets(e.nom,32,stdin);
	e.nom[strlen(e.nom)-1]='\0';
	printf("Saisissez votre date de naissance sous le forme jj/mm/aaaa :\n");
	scanf("%d/%d/%d%*c",&e.datenaiss.jour,&e.datenaiss.mois,&e.datenaiss.annee);
	while (e.datenaiss.jour<0 || e.datenaiss.jour>32 || e.datenaiss.mois<0 || e.datenaiss.mois>13 || e.datenaiss.annee<1900 ||  e.datenaiss.annee>2010) {
		viderBuffer(); /* ça a été ajouté au fichier original pour contrer la boucle infini */
		printf("Erreur de saisie. Réessayez.\n");
		printf("Saisissez votre date de naissance sous le forme jj/mm/aaaa :\n");
		scanf("%d/%d/%d%*c",&e.datenaiss.jour,&e.datenaiss.mois,&e.datenaiss.annee);
	}
	printf("Saisissez votre établissement d'étude :\n");
	fgets(e.etablissement,22,stdin);
	e.etablissement[strlen(e.etablissement)-1]='\0';
	printf("Saisissez votre échelon boursier :\n");
	scanf("%d",&e.bourse);
	printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
	scanf("%s",e.batpref);
	l=strlen(e.batpref);
	while(l!=1) {
		printf("Une lettre au maximum. Réessayez :\n");
		scanf("%s%*c",e.batpref);
		l=strlen(e.batpref);
	}
	while (strcmp(e.batpref,"A")!=0 && strcmp(e.batpref,"B")!=0 && strcmp(e.batpref,"C")!=0) {
		printf("La lettre ne peut être que A ou B ou C.\n");
		printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
		scanf("%s",e.batpref);
		l=strlen(e.batpref);
		while(l!=1) {
			printf("Une lettre au maximum. Réessayez :\n");
			scanf("%s%*c",e.batpref);
			l=strlen(e.batpref);
		}
	}
	tetud[val]=e;
	return tetud;
}


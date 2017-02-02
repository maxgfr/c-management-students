#include "logement.h"

/* 1-FONCTION DE LECTURE D'UN LOGEMENT */

Logement lireLog (FILE *flot)
{
	Logement l;
	fscanf(flot,"%s%*c",l.idchamb);
	fscanf(flot,"%s%*c",l.idbat);
	fscanf(flot,"%d%^[a-z]",&l.etage);
	fscanf(flot,"%d%^[a-z]",&l.numchambre);
	fscanf(flot,"%d%^[a-z]",&l.type);
	fscanf(flot,"%d%^[a-z]",&l.disponibilite);
	return l;
}

/* 2- FONCTION DE CHARGEMENT DANS UN TABLEAU DE TOUS LES LOGEMENTS */

Logement** chargeLog (int *nbLog, int *taillemax)
{
	FILE *flot;
	Logement l;
	Logement **tlog, **nouvtlog;
	*nbLog=0;
	*taillemax=20;
	flot=fopen("logement.txt","r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	l=lireLog(flot);
	tlog=(Logement **)malloc(*taillemax*(sizeof(Logement*)));
	if(tlog==NULL) {
			printf("Un problème d'allocation mémoire est survenu. \n");
			exit(2);
	}
	while(!feof(flot)) {
		if(*nbLog==*taillemax) {
			nouvtlog=(Logement **)realloc(tlog,(*taillemax+20)*sizeof(Logement *));
			if(nouvtlog==NULL) {
				printf("Un problème d'allocation mémoire est survenu. \n");
				exit(2);
			}
			*taillemax=*taillemax+20;
			tlog=nouvtlog;
		}
	tlog[*nbLog]=(Logement *)malloc(sizeof(Logement));
		if(tlog[*nbLog]==NULL) {
			printf("Un problème d'allocation mémoire est survenu. \n");
			exit(2);
		}
		*tlog[*nbLog]=l;
		*nbLog=*nbLog+1;
		l=lireLog(flot);
	}
	fclose(flot);
	return tlog;
}


/* 3.1-FONCTION D'AFFICHAGE D'UN LOGEMENT */

void afficherLog (Logement l)
{
	printf("%s\n",l.idchamb);
	if (l.type==0)
		printf("Le logement choisi est une chambre.\n");
	else if (l.type==1)
			printf("Le logement choisi est un studio.\n");
		else if (l.type==2)
				printf("Le logement choisi est un T1.\n");
			else if (l.type==3)
					printf("Le logement choisi est un T2.\n");
				else printf ("Une invalidité est présente au niveau du type du logement.\n");
	if (l.disponibilite==0)
		printf("Le logement choisi est disponible.\n");
	else if (l.disponibilite==1)
			printf("Le logement choisi est indisponible.\n");
		else if (l.disponibilite==2)
				printf("Le logement choisi est en travaux.\n");
			else if (l.disponibilite==3)
					printf("Le logement choisi est pour personne handicapée.\n");
				else printf ("Une invalidité est présente au niveau de la disponibilité du logement.\n");
	if(strcmp(l.idbat,"A")==0)
			printf("La chambre est situé dans la résidence LES ROCHES. \n");
		else if(strcmp(l.idbat,"B")==0)
				printf("La chambre est situé dans la résidence LE STELAR. \n");
			else if(strcmp(l.idbat,"C")==0)
					printf("La chambre est situé dans la résidence LE CROUCROUS. \n");
				else printf ("Une invalidité est présente au niveau de la résidence du logement.\n");
		printf("Elle est situé à l'étage numero %d.\n",l.etage);
		printf("Le numero de la chambre est %d.\n",l.numchambre);
		printf("\n");
}

/* 3.2-FONCTION D'AFFICHAGE DE TOUT LES LOGEMENTS */
void afficherToutLog (Logement *tlog[], int nb)
{
		int i;
		for(i=0;i<nb;i++)
			afficherLog(*tlog[i]);
}

/* 4- FONCTIONS DE TRI DICHOTOMIQUE PAR RESIDENCE DES CHAMBRES, PAR ETAGE PUIS PAR NUMERO */

void triDichLog (Logement **T, int n)
{
	Logement **R,**S;
	if (n==1)
		return;
	R=(Logement**)malloc((n/2)*sizeof(Logement*));
	S=(Logement**)malloc((n-n/2)*sizeof(Logement*));
	if (R==NULL || S==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	copiDichLog(T,R,0,n/2);
	copiDichLog(T,S,n/2,n);
	triDichLog(R,n/2);
	triDichLog(S,n-n/2);
	fusDichLog(R,S,T,n/2,n-n/2);
	free(R);
	free(S);
}


void fusDichLog (Logement **R, Logement **S, Logement **T, int n, int m)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<n && j<m) {
		if(strcmp(R[i]->idchamb,S[j]->idchamb)<0) {
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

void copiDichLog (Logement **T, Logement **R, int i,int j)
{
	int k=0;
	while(i<j) {
		R[k]=T[i];
		i=i+1;
		k=k+1;
	}
}

/* 5- FONCTION DE RECHERCHE DICHOTOMIQUE PAR IDENTIFIANT (necessite tableau trié) */

int rechDichLog (char *id, Logement **tab , int nbLog)
{
	int inf,sup,m;
	inf=0;
	sup=nbLog-1;
	while(inf<=sup)
	{
		m=(inf+sup)/2;
		if(strcmp(id,tab[m]->idchamb)==0)
			return m;
		if(strcmp(id,tab[m]->idchamb)<0)
			sup=m-1;
		else inf=m+1;
	}
return inf;
}

/* 6-AJOUT D'UN LOGEMENT */
Logement** ajoutLog (Logement *tlog[], int *nbLog, int *taillemax)
{
	int val,nb,lon;
	Logement **nouvtlog;
	Logement l1;
	/*ETAPE 1 : Saisie d'informations*/
	printf("AJOUT D'UN LOGEMENT:\n");
	printf("Saisissez l'identifiant du logement composé  de 4 caractères: \n");
	scanf("%s%*c",l1.idchamb);
	viderBuffer();
	lon=strlen(l1.idchamb);
	while (lon!=4 ) { 
		printf("\nL'identifiant a necessairement 4 caractères.\n");
		printf("Réessayez :\n");
		scanf("%s%*c",l1.idchamb);
	}
	/* Verfication au sein du tableau de l'unicité de l'identifiant */
	nb=*nbLog;
	val=rechDichLog(l1.idchamb,tlog,nb);
	if (strcmp(tlog[val]->idchamb,l1.idchamb)==0) {
			printf("L'idenfiant du logement %s existe déjà. \n",l1.idchamb);
			exit(6);
	}
	
	printf("Saisissez un caractère pour la résidence (A, B ou C)\n");
	scanf("%s",l1.idbat);
	lon=strlen(l1.idbat);
	while(lon!=1) {
		printf("Une lettre au maximum. Réessayez :\n");
		scanf("%s%*c",l1.idbat);
		lon=strlen(l1.idbat);
	}
	while (strcmp(l1.idbat,"A")!=0 && strcmp(l1.idbat,"B")!=0 && strcmp(l1.idbat,"C")!=0) {
		printf("La lettre ne peut être que A ou B ou C.\n");
		printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
		scanf("%s",l1.idbat);
		lon=strlen(l1.idbat);
		while(lon!=1) {
			printf("Une lettre au maximum. Réessayez :\n");
			scanf("%s%*c",l1.idbat);
			lon=strlen(l1.idbat);
		}
	}
	printf("Saisissez un caractère compris entre 0 et 8 pour l'étage\n");
	scanf("%d",&l1.etage);
	while (l1.etage<0 || l1.etage>8) {
		viderBuffer();
		printf ("Une invalidité est présente au niveau de l'étage du logement.\n");
		printf("Saisissez un caractère compris entre 0 et 8 pour l'étage\n");
		scanf("%d",&l1.etage);
	}
	printf("Saisissez deux caractères pour le numéro du logement :\n");
	scanf("%d",&l1.numchambre);
	
	printf("Saisissez 0 si le logement est une chambre ou 1 si le logement est un studio ou 2 si le logement est un T1 ou 3 si c'est un T2.\n");
	scanf("%d",&l1.type);
	while (l1.type!=0 && l1.type!=1 && l1.type!=2 && l1.type!=3) {
		viderBuffer();
		printf ("Une invalidité est présente au niveau du type du logement.\n");
		printf("Saisissez 0 si le logement est une chambre ou 1 si le logement est un studio ou 2 si le logement est un T1 ou 3 si c'est un T2.\n");
		scanf("%d",&l1.type);
	}
	printf("Saisissez 0 si le logement est disponible ou 1 si le logement est indisponible ou 2 si le logement est en travux ou 3 si c'est pour une personne handicapée\n");
	scanf("%d",&l1.disponibilite);
	while (l1.disponibilite==0 && l1.disponibilite==1 && l1.disponibilite==2 && l1.disponibilite==3) {
		viderBuffer();
		printf ("Une invalidité est présente au niveau de la disponibilité du logement.\n");
		printf("Saisissez 0 si le logement est disponible ou 1 si le logement est indisponible ou 2 si le logement est en travux ou 3 si c'est pour une personne handicapée.\n");
		scanf("%d",&l1.disponibilite);
	}
	printf("RECAPITULATIF :\n");
	afficherLog(l1);
	
	/*ETAPE 2 : Passons maintenant à la saisie dans le tableau*/
	/*ETAPE 2.1 : Saisie à la fin du tableau */
	if (val==*nbLog) {
		if(*nbLog==*taillemax) {
			nouvtlog=(Logement **)realloc(tlog,(*taillemax+20)*sizeof(Logement *));
			if(nouvtlog==NULL) {
				printf("Un problème d'allocation mémoire est survenu. \n");
				exit(2);
			}
			*taillemax=*taillemax+20;
			tlog=nouvtlog;
		}
		tlog[*nbLog]=(Logement *)malloc(sizeof(Logement));
		if(tlog[*nbLog]==NULL) {
			printf("Un problème d'allocation mémoire est survenu. \n");
			exit(2);
		}
		*tlog[*nbLog]=l1;
		*nbLog=*nbLog+1;
		return tlog;
	}
	/*ETAPE 2.2 : Si nous avons un indice d'insertion, nous devons l'inserer à cet emplacement*/
	else if (strcmp(tlog[val]->idchamb,l1.idchamb)!=0) {
			if(*nbLog==*taillemax) {
				nouvtlog=(Logement **)realloc(tlog,(*taillemax+20)*sizeof(Logement *));
				if(nouvtlog==NULL) {
					printf("Un problème d'allocation mémoire est survenu. \n");
					exit(2);
				}
				*taillemax=*taillemax+20;
				tlog=nouvtlog;
			}
			decalerADroiteLog(tlog,val,nb);
			tlog[val]=(Logement *)malloc(sizeof(Logement));
			if(tlog[val]==NULL) {
				printf("Un problème d'allocation mémoire est survenu. \n");
				exit(2);
			}
			*tlog[val]=l1;
			*nbLog=*nbLog+1;
			return tlog;
		}
}


void decalerADroiteLog (Logement *tlog[], int val, int nb)
{
	int i;
	for(i=nb-1;i>=val;i--)
		tlog[i+1]=tlog[i];
}

/* 7-FONCTIONS POUR SUPPRIMER UN LOGEMENT */

Logement** supLog (Logement *tlog[], int *nbLog)
{
	int val,nb,l;
	char id[6], rep[5];
	printf("Veuillez entrer l'identifiant de l'étudiant à supprimer.\n");
	scanf("%s%*c",id);
	l=strlen(id);
	while(l!=4) {
		printf("L'identifiant possède 4 caractères maximum. Réessayez :\n");
		scanf("%s%*c",id);
		l=strlen(id);
	}
	nb=*nbLog;
	val=rechDichLog(id,tlog,nb);
	while (val==*nbLog || strcmp(id,tlog[val]->idchamb)!=0) {
		printf("L'identifiant recherché n'existe pas.\n");
		printf("Voulez vous quittez le programme ? (Répondez par oui ou non) \n");
		scanf("%s%*c",rep);
		if (strcmp(rep,"oui")==0) {
			printf("Bonne fin de journée.\n");
			exit(5);
		}
		printf("Veuillez entrer donc entrer un nouvel identifiant de logement à supprimer.\n");
		scanf("%s%*c",id);
		l=strlen(id);
		while(l!=5) {
			printf("L'identifiant possède 4 caractères maximum. Réessayez :\n");
			scanf("%s%*c",id);
			l=strlen(id);
		}
		val=rechDichLog(id,tlog,nb);
	}
	free(tlog[val]);
	decalerAGaucheLog(tlog,val,nb);
	*nbLog=*nbLog-1;
	return tlog;
}

void decalerAGaucheLog (Logement *tlog[], int val, int nb)
{
	int i;
	for(i=val;i<nb-1;i++)
		tlog[i]=tlog[i+1];
}

/* 8-FONCTION DE SAUVEGARDE */
/*binaire utilisé car il y a beaucoup de logement*/

void sauvLog (Logement *tlog[], int nb)
{
	FILE *flot;
	int i;
	flot=fopen("logement.bin","wb");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	fwrite(&nb,sizeof(int),1,flot);
	for (i=0; i<nb ; i++) {
		fwrite(tlog[i],sizeof(Logement),1,flot);
	}
	fclose(flot);	
}

/* 9-FONCTION DE LECTURE BINAIRE */

Logement** restLog (int *nb)
{
	FILE *flot;
	Logement **tlog;
	int i;
	flot=fopen("logement.bin","rb");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	fread(nb,sizeof(int),1,flot);
	tlog=(Logement **)malloc(*nb*sizeof(Logement*));
	for (i=0; i<*nb ; i++) {
		tlog[i]=(Logement *)malloc(sizeof(Logement));
		fread(tlog[i],sizeof(Logement),1,flot);
	}
	fclose(flot);
	return tlog;
}

/* 10 - MODIFICATION LOGEMENT */

Logement** modifLog (Logement *tlog[], int *nbLog)
{
	Logement l1;
	int val,nb,lon;
	char id[6], rep[4];
	/*SAISIE DE L'IDENTIFIANT */
	printf("Veuillez entrer l'identifiant de la chambre si vous le connaissez.\n");
	scanf("%s%*c",l1.idchamb);
	lon=strlen(l1.idchamb);
	while(lon!=4) {
		printf("L'identifiant possède 4 caractères maximum. Réessayez :\n");
		scanf("%s%*c",l1.idchamb);
		lon=strlen(l1.idchamb);
	}
	nb=*nbLog;
	val=rechDichLog(l1.idchamb,tlog,nb);
	while (val==*nbLog || strcmp(l1.idchamb,tlog[val]->idchamb)!=0) {
		printf("L'identifiant recherché n'existe pas.\n");
		printf("Voulez vous quittez le programme ? (Répondez par oui ou non) \n");
		scanf("%s%*c",rep);
		if (strcmp(rep,"oui")==0) {
			printf("Bonne fin de journée.\n");
			exit(5);
		}
		printf("Veuillez entrer donc entrer un nouvel identifiant de logement à supprimer.\n");
		scanf("%s%*c",l1.idchamb);
		lon=strlen(l1.idchamb);
		while(lon!=4) {
			printf("L'identifiant possède 4 caractères maximum. Réessayez :\n");
			scanf("%s%*c",l1.idchamb);
			lon=strlen(l1.idchamb);
		}
		val=rechDichLog(l1.idchamb,tlog,nb);
	}
	/* SAISIE DES INFORMATIONS POUR MODIFIER LA CHAMBRE */

	printf("Saisissez un caractère pour la résidence (A, B ou C)\n");
	scanf("%s",l1.idbat);
	lon=strlen(l1.idbat);
	while(lon!=1) {
		printf("Une lettre au maximum. Réessayez :\n");
		scanf("%s%*c",l1.idbat);
		lon=strlen(l1.idbat);
	}
	while (strcmp(l1.idbat,"A")!=0 && strcmp(l1.idbat,"B")!=0 && strcmp(l1.idbat,"C")!=0) {
		printf("La lettre ne peut être que A ou B ou C.\n");
		printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
		scanf("%s",l1.idbat);
		lon=strlen(l1.idbat);
		while(lon!=1) {
			printf("Une lettre au maximum. Réessayez :\n");
			scanf("%s%*c",l1.idbat);
			lon=strlen(l1.idbat);
		}
	}
	printf("Saisissez un caractère compris entre 0 et 8 pour l'étage\n");
	scanf("%d",&l1.etage);
	while (l1.etage<0 || l1.etage>8) {
		viderBuffer();
		printf ("Une invalidité est présente au niveau de l'étage du logement.\n");
		printf("Saisissez un caractère compris entre 0 et 8 pour l'étage\n");
		scanf("%d",&l1.etage);
	}
	printf("Saisissez deux caractères pour le numéro du logement :\n");
	scanf("%d",&l1.numchambre);
	
	printf("Saisissez 0 si le logement est une chambre ou 1 si le logement est un studio ou 2 si le logement est un T1 ou 3 si c'est un T2.\n");
	scanf("%d",&l1.type);
	while (l1.type!=0 && l1.type!=1 && l1.type!=2 && l1.type!=3) {
		viderBuffer();
		printf ("Une invalidité est présente au niveau du type du logement.\n");
		printf("Saisissez 0 si le logement est une chambre ou 1 si le logement est un studio ou 2 si le logement est un T1 ou 3 si c'est un T2.\n");
		scanf("%d",&l1.type);
	}
	printf("Saisissez 0 si le logement est disponible ou 1 si le logement est indisponible ou 2 si le logement est en travux ou 3 si c'est pour une personne handicapée\n");
	scanf("%d",&l1.disponibilite);
	while (l1.disponibilite==0 && l1.disponibilite==1 && l1.disponibilite==2 && l1.disponibilite==3) {
		viderBuffer();
		printf ("Une invalidité est présente au niveau de la disponibilité du logement.\n");
		printf("Saisissez 0 si le logement est disponible ou 1 si le logement est indisponible ou 2 si le logement est en travux ou 3 si c'est pour une personne handicapée.\n");
		scanf("%d",&l1.disponibilite);
	}
	
	printf("RECAPITULATIF :\n");
	afficherLog(l1);
	
	*tlog[val]=l1;
	return tlog;
}

void viderBuffer(void)
{
    int c=0;
    while (c != '\n' && c != EOF) {
        c=getchar();
    }
}

/* 11- FONCTIONS DE TRI DICHOTOMIQUE PAR TYPE DE LOGEMENT*/

void triDichLogTYP (Logement **T, int n)
{
	Logement **R,**S;
	if (n==1)
		return;
	R=(Logement**)malloc((n/2)*sizeof(Logement*));
	S=(Logement**)malloc((n-n/2)*sizeof(Logement*));
	if (R==NULL || S==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	copiDichLog(T,R,0,n/2);
	copiDichLog(T,S,n/2,n);
	triDichLogTYP(R,n/2);
	triDichLogTYP(S,n-n/2);
	fusDichLogTYP(R,S,T,n/2,n-n/2);
	free(R);
	free(S);
}


void fusDichLogTYP (Logement **R, Logement **S, Logement **T, int n, int m)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<n && j<m) {
		if(R[i]->type<S[j]->type) {
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


/* 12- FONCTION DE RECHERCHE DICHOTOMIQUE PAR TYPE (necessite tableau trié) */

int rechDichLogTYP (int num, Logement **tab , int nbLog)
{
	int inf,sup,m;
	inf=0;
	sup=nbLog-1;
	while(inf<=sup)
	{
		m=(inf+sup)/2;
		if(tab[m]->type==num)
			return m;
		if(num<tab[m]->type)
			sup=m-1;
		else inf=m+1;
	}
return inf;
}

/* 13- FONCTIONS DE TRI DICHOTOMIQUE PAR DISPONIBILITE DE LOGEMENT*/

void triDichLogDIS (Logement **T, int n)
{
	Logement **R,**S;
	if (n==1)
		return;
	R=(Logement**)malloc((n/2)*sizeof(Logement*));
	S=(Logement**)malloc((n-n/2)*sizeof(Logement*));
	if (R==NULL || S==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	copiDichLog(T,R,0,n/2);
	copiDichLog(T,S,n/2,n);
	triDichLogDIS(R,n/2);
	triDichLogDIS(S,n-n/2);
	fusDichLogDIS(R,S,T,n/2,n-n/2);
	free(R);
	free(S);
}


void fusDichLogDIS (Logement **R, Logement **S, Logement **T, int n, int m)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<n && j<m) {
		if(R[i]->disponibilite<S[j]->disponibilite) {
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


/* 14- FONCTION DE RECHERCHE DICHOTOMIQUE PAR DISPONIBILITE (necessite tableau trié) */

int rechDichLogDIS (int num, Logement **tab , int nbLog)
{
	int inf,sup,m;
	inf=0;
	sup=nbLog-1;
	while(inf<=sup)
	{
		m=(inf+sup)/2;
		if(tab[m]->disponibilite==num)
			return m;
		if(num<tab[m]->disponibilite)
			sup=m-1;
		else inf=m+1;
	}
return inf;
}

/* 15- FONCTIONS DE TRI DICHOTOMIQUE PAR CITE */

void triDichLogCIT (Logement **T, int n)
{
	Logement **R,**S;
	if (n==1)
		return;
	R=(Logement**)malloc((n/2)*sizeof(Logement*));
	S=(Logement**)malloc((n-n/2)*sizeof(Logement*));
	if (R==NULL || S==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	copiDichLog(T,R,0,n/2);
	copiDichLog(T,S,n/2,n);
	triDichLogCIT(R,n/2);
	triDichLogCIT(S,n-n/2);
	fusDichLogCIT(R,S,T,n/2,n-n/2);
	free(R);
	free(S);
}


void fusDichLogCIT (Logement **R, Logement **S, Logement **T, int n, int m)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<n && j<m) {
		if(strcmp(R[i]->idbat,S[j]->idbat)<0) {
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


/* 16- FONCTION DE RECHERCHE DICHOTOMIQUE PAR CITE (necessite tableau trié) */

int rechDichLogCIT (char *c, Logement **tab , int nbLog)
{
	int inf,sup,m;
	inf=0;
	sup=nbLog-1;
	while(inf<=sup)
	{
		m=(inf+sup)/2;
		if(strcmp(tab[m]->idbat,c)==0)
			return m;
		if(strcmp(c,tab[m]->idbat)<0)
			sup=m-1;
		else inf=m+1;
	}
return inf;
}

/* 17- FONCTIONS DE TRI DICHOTOMIQUE PAR NUMERO DU LOGEMENT*/

void triDichLogNUM (Logement **T, int n)
{
	Logement **R,**S;
	if (n==1)
		return;
	R=(Logement**)malloc((n/2)*sizeof(Logement*));
	S=(Logement**)malloc((n-n/2)*sizeof(Logement*));
	if (R==NULL || S==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	copiDichLog(T,R,0,n/2);
	copiDichLog(T,S,n/2,n);
	triDichLogNUM(R,n/2);
	triDichLogNUM(S,n-n/2);
	fusDichLogNUM(R,S,T,n/2,n-n/2);
	free(R);
	free(S);
}


void fusDichLogNUM (Logement **R, Logement **S, Logement **T, int n, int m)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<n && j<m) {
		if(R[i]->numchambre<S[j]->numchambre) {
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


/* 18- FONCTION DE RECHERCHE DICHOTOMIQUE PAR NUMERO LOGEMENT (necessite tableau trié) */

int rechDichLogNUM (int num, Logement **tab , int nbLog)
{
	int inf,sup,m;
	inf=0;
	sup=nbLog-1;
	while(inf<=sup)
	{
		m=(inf+sup)/2;
		if(tab[m]->numchambre==num)
			return m;
		if(num<tab[m]->numchambre)
			sup=m-1;
		else inf=m+1;
	}
return inf;
}

/* 19- FONCTIONS DE TRI DICHOTOMIQUE PAR ETAGE DU LOGEMENT*/

void triDichLogETA (Logement **T, int n)
{
	Logement **R,**S;
	if (n==1)
		return;
	R=(Logement**)malloc((n/2)*sizeof(Logement*));
	S=(Logement**)malloc((n-n/2)*sizeof(Logement*));
	if (R==NULL || S==NULL) {
		printf("Un problème d'allocation mémoire est survenu. \n");
		exit(2);
	}
	copiDichLog(T,R,0,n/2);
	copiDichLog(T,S,n/2,n);
	triDichLogETA(R,n/2);
	triDichLogETA(S,n-n/2);
	fusDichLogETA(R,S,T,n/2,n-n/2);
	free(R);
	free(S);
}


void fusDichLogETA (Logement **R, Logement **S, Logement **T, int n, int m)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<n && j<m) {
		if(R[i]->etage<S[j]->etage) {
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


/* 20- FONCTION DE RECHERCHE DICHOTOMIQUE PAR ETAGE (necessite tableau trié) */

int rechDichLogETA (int num, Logement **tab , int nbLog)
{
	int inf,sup,m;
	inf=0;
	sup=nbLog-1;
	while(inf<=sup)
	{
		m=(inf+sup)/2;
		if(tab[m]->etage==num)
			return m;
		if(num<tab[m]->etage)
			sup=m-1;
		else inf=m+1;
	}
return inf;
}

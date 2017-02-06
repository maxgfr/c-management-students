#include "projet.h"

/* PARTIE 0 - FONCTION POUR AFFICHER ET SELECTIONNER CHOIX POUR LES DIFFERENTS MENUS*/
int menuPrincipal (void)
{
	int rep;
	printf("Bienvenue sur l'interface de gestion du CROUS.\n");
	printf("\n");
	printf("1 si vous êtes un étudiant.\n");
	printf("2 si vous êtes un administrateur.\n");
	printf("9 pour fermer le programme.\n");
	printf("\n");
	scanf("%d",&rep);
	viderBuffer();
	while(rep > 9 || rep <1) {
		printf("\n");
		printf("Votre choix est incorrect.\n");
		printf("\n");
		printf("1 si vous êtes un étudiant.\n");
		printf("2 si vous êtes un administrateur.\n");
		printf("9 pour fermer le programme.\n");
		printf("\n");
		scanf("%d",&rep);
		viderBuffer();
	}
	return rep;
	printf("\n\n");
}

Booleen coAdmin (void)
{
	char idco[15];
	char mdp[15];
	printf("Saisissez votre identifiant d'administrateur :\n");
	fgets(idco,15,stdin);
	idco[strlen(idco)-1]='\0';
	printf("Saisissez maintenant votre mot de passe :\n");
	fgets(mdp,15,stdin);
	mdp[strlen(mdp)-1]='\0';
	if (strcmp(idco,"admin")==0 && strcmp(mdp,"code")==0) {
		printf("Connexion réussi.\n");
		return vrai;
	}
	else {
		printf("Identifiant ou mot de passe incorrect.\n");
		return faux;
	}
}
		
int menuA (void)
{
	int rep;
	printf("\n");
	printf("Vous souhaitez :\n");
	printf("\n");
	
	printf("1 utiliser la fonction d'attribution automatique des logements.\n"); /* en fonction de son batiment et type de logement de préférence */
	
	printf("2 enregistrer une modification de l'étudiant.\n");
	printf("3 enregistrer le depart d'un étudiant.\n");
	
	printf("4 afficher une liste des logements selon différents critères.\n");
	printf("5 afficher une liste des chambres selon différents critères poussées.\n");
	printf("6 utiliser la fonction d'attribution manuelle des logements.\n");
	printf("7 afficher et éditer la liste d'attente.\n");
	printf("8 afficher et editer les logements occupés par les étudiants.\n");
		
	printf("9 afficher toutes les demandes.\n");
	printf("10 afficher tout les logements.\n");
	printf("11 rechercher un logement.\n"); /* parmi tout les logements */
	printf("12 afficher tout les étudiants.\n");
	printf("13 rechercher un étudiant.\n"); /* parmi tout les étudiants */
	printf("14 afficher les cités.\n");
		
	printf("15 ajouter un logement.\n");
	printf("16 modifier un logement.\n");
	printf("17 supprimer un logement.\n");
		
	printf("18 charge les demandes en .txt dans un fichier binaire (à faire une seule fois).\n");
	printf("19 charge les logements en .txt dans un fichier binaire (à faire une seule fois).\n");
	printf("20 charge les etudiants en .txt dans un fichier binaire (à faire une seule fois).\n");
			
	printf("21 fermer le programme.\n");
	printf("\n");
	scanf("%d",&rep);
	viderBuffer();
	while(rep > 21 || rep <1 ){
		printf("\n");
		printf("Votre choix est incorrect.\n");
		printf("\n");
		printf("Vous souhaitez :\n");
		printf("\n");
		
		printf("1 utiliser la fonction d'attribution automatique des logements.\n"); /* en fonction de son batiment et type de logement de préférence */
	
		printf("2 enregistrer une modification de l'étudiant.\n");
		printf("3 enregistrer le depart d'un étudiant.\n");
		
		printf("4 afficher une liste des logements selon différents critères.\n");
		printf("5 afficher une liste des chambres selon différents critères poussées.\n");
		printf("6 utiliser la fonction d'attribution manuelle des logements.\n");
		printf("7 afficher et éditer la liste d'attente.\n");
		printf("8 afficher et editer les logements occupés par les étudiants.\n");
			
		printf("9 afficher toutes les demandes.\n");
		printf("10 afficher tout les logements.\n");
		printf("11 rechercher un logement.\n"); /* parmi tout les logements */
		printf("12 afficher tout les étudiants.\n");
		printf("13 rechercher un étudiant.\n"); /* parmi tout les étudiants */
		printf("14 afficher les cités.\n");
		
		printf("15 ajouter un logement.\n");
		printf("16 modifier un logement.\n");
		printf("17 supprimer un logement.\n");
		
		printf("18 charge les demandes en .txt dans un fichier binaire (à faire une seule fois).\n");
		printf("19 charge les logements en .txt dans un fichier binaire (à faire une seule fois).\n");
		printf("20 charge les etudiants en .txt dans un fichier binaire (à faire une seule fois).\n");
			
		printf("21 fermer le programme.\n");
		printf("\n");
		scanf("%d",&rep);
		viderBuffer();
	}
	return rep;
	printf("\n\n");
}

int menuE (void)
{
	int rep;
	printf("\n");
	printf("Vous souhaitez :\n");
	printf("\n");
	printf("1 vous inscrire.\n");
	printf("2 modifiez vos informations.\n");
	printf("3 vous desinscrire.\n");
	printf("9 fermer le programme.\n");
	printf("\n");
	scanf("%d",&rep);
	viderBuffer();
	while(rep > 9 || rep <1 ){
		printf("\n");
		printf("Votre choix est incorrect.\n");
		printf("\n");
		printf("Vous souhaitez :\n");
		printf("\n");
		printf("1 vous inscrire.\n");
		printf("2 modifiez vos informations.\n");
		printf("3 vous desinscrire.\n");
		printf("9 fermer le programme.\n");
		printf("\n");
		scanf("%d",&rep);
		viderBuffer();
	}
	return rep;
	printf("\n\n");
}

void viderBuffer(void)
{
    int c=0;
    while (c != '\n' && c != EOF) {
        c=getchar();
    }
}


////////////* PARTIE I : POUR ETUDIANT : *//////////////

/* ENREGISTREMENT */
void etudiant1 (void)
{
	Etudiant **tab;
	int nbEtu,taillemax,i;
	tab=restEtu(&nbEtu);
	taillemax=nbEtu;
	tab=ajoutEtu(tab,&nbEtu,&taillemax);
	sauvEtu(tab,nbEtu);
	for (i=0;i<nbEtu;i++) 
		free(tab[i]);
}

/* MODIFICATION */
void etudiant2 (void)
{
	Etudiant **tab;
	int nbEtu,i;
	tab=restEtu(&nbEtu);
	tab=modifEtu(tab,&nbEtu);	
	sauvEtu(tab,nbEtu);
	for (i=0;i<nbEtu;i++) 
		free(tab[i]);
}

/*SUPPRESSION*/
void etudiant3 (void)
{
	Etudiant **tab;
	int nbEtu,i;
	tab=restEtu(&nbEtu);
	tab=supEtu(tab,&nbEtu);
	sauvEtu(tab,nbEtu);
	for (i=0;i<nbEtu;i++) 
		free(tab[i]);
}

//////////////* PARTIE II : POUR ADMIN : *///////////////////////

/* ENREGISTRER UN LOGEMENT AUTOMATIQUEMENT */

ListeD mginser (ListeD li)
{
	/* PARTIE 0 : DECLARATION DE VARIABLES */
	int X;
	int i;
	int j;
	int cpt1,cpt3;
	/*0.1 POUR ETUDIANT */
	Etudiant **tetud;
	int nbEtu;
	int valEtu;
	/*0.2 POUR LOGEMENT*/
	Logement **tlog;
	int nbLog;
	int valLog;
	/*0.3 POUR DEMANDE */
	Demande d;
	int longueur;
	/* 0.4 POUR CITE */
	Cite tab[5];
	FILE *flot;
	int nb;
	int k;
	

	/* PARTIE 1 : CHARGER LES FICHIERS */
	/*1.1 POUR LE LOGEMENT */
	tlog=restLog(&nbLog);
	triDichLogTYP(tlog,nbLog);
	/* 1.2 POUR LES ETUDIANTS */
	tetud=restEtu(&nbEtu);
	triDichEtuECH(tetud,nbEtu);
	/* 1.3 POUR LES CITES */
	nb=fcharg(tab);
	flot=fopen("cite.txt","w");
	if (flot==NULL) {
		printf("Problème d'ouverture du fichier en écriture\n");
		exit(1);
	}
	
	/* PARTIE 2 : ACCES AUX INFORMATIONS */	
	////* PRIORITE ECHELON 7 *////
	/*rechercher l'emplacement d'un étudiant boursier 7*/	
	for (X=7;X>=0;X--) {
		for (cpt1=0;cpt1<nbEtu;cpt1++) {
			if (tetud[cpt1]->bourse==X)  {
				/*EN PREMIER LIEU : priorité aux handicapés*/
				if (tetud[cpt1]->etat==1) { 
					for(cpt3=0;cpt3<nbLog;cpt3++) {
					/* rechercher l'emplacement d'un logement où il y a le type de logement cherché par l'étu
					 * ET QUI (&&) peut acceuillir un handicapé*/
						if (tlog[cpt3]->type==tetud[cpt1]->choix && tlog[cpt3]->disponibilite==3){
							/*  maintenant parmi les logement sélectionnés, quels logements qui sont dans A ou B ou C*/
							if (strcmp(tlog[cpt3]->idbat,tetud[cpt1]->batpref)==0) {
								/* pour finir ne donner que les logements disponibles */
								if(tlog[cpt3]->disponibilite==0) {
									strcpy(d.idetud,tetud[cpt1]->idetud);
									strcpy(d.idchamb,tlog[cpt3]->idchamb);
									d.demande=1;
									tlog[cpt3]->disponibilite=1;
										/*Enlever 1 au nombre de logements restant dans la cité*/
										for (k=0;k<3;k++) {
										if (strcmp(tab[k].idbat,tetud[cpt1]->batpref)==0) {
											tab[k].logementrestant=tab[k].logementrestant-1;
										}
									}
									li=insererDem(li,d);
								}
							}
						}
					}
					/* LISTE D'ATTENTE POUR HANDICAPES*/
					for(cpt3=0;cpt3<nbLog;cpt3++) {
						/* Si son logement est indisponible*/
						if(tlog[cpt3]->disponibilite!=0) {
							/* Si il a son logement présent dans une cité différente que celle choisie initialement*/
							if (strcmp(tlog[cpt3]->idbat,tetud[cpt1]->batpref)!=0) {
								/*Si il reste plus de logement comme celui que l'étudiant voulait DANS toute les cités*/
								if (tlog[cpt3]->type!=tetud[cpt1]->choix) {
									strcpy(d.idetud,tetud[cpt1]->idetud);
									strcpy(d.idchamb,"ZZZZ");
									d.demande=1;
									li=insererDem(li,d);
								}
								strcpy(d.idetud,tetud[cpt1]->idetud);
								strcpy(d.idchamb,"YYYY");
								d.demande=1;
								li=insererDem(li,d);		
							}		
							strcpy(d.idetud,tetud[cpt1]->idetud);
							strcpy(d.idchamb,"XXXX");
							d.demande=1;
							li=insererDem(li,d);
						}	
					}
				}
				/* EN SECOND LIEU : personnes normales */
				/* rechercher l'emplacement d'un logement où il y a le type de logement cherché par l'étu*/
				for(cpt3=0;cpt3<nbLog;cpt3++) {
					if (tlog[cpt3]->type==tetud[cpt1]->choix){
						/*  maintenant parmi les logement sélectionnés, quels logements qui sont dans A ou B ou C*/
						if (strcmp(tlog[cpt3]->idbat,tetud[cpt1]->batpref)==0) {
							/* pour finir ne donner que les logements disponibles */
							if(tlog[cpt3]->disponibilite==0) {
								strcpy(d.idetud,tetud[cpt1]->idetud);
								strcpy(d.idchamb,tlog[cpt3]->idchamb);
								d.demande=0;
								tlog[cpt3]->disponibilite=1;
								/*Enlever 1 au nombre de logements restant dans la cité*/
								for (k=0;k<3;k++) {
									if (strcmp(tab[k].idbat,tetud[cpt1]->batpref)==0) {
										tab[k].logementrestant=tab[k].logementrestant-1;
									}
								}
								li=insererDem(li,d);
							}
						}
					}
				}
				/* LISTE D'ATTENTE*/
				for(cpt3=0;cpt3<nbLog;cpt3++) {
					/* Si son logement est indisponible*/
					if(tlog[cpt3]->disponibilite!=0) {
						/* Si il a son logement présent dans une cité différente que celle choisie initialement*/
						if (strcmp(tlog[cpt3]->idbat,tetud[cpt1]->batpref)!=0) {
							/*Si il reste plus de logement comme celui que l'étudiant voulait DANS toute les cités*/
							if (tlog[cpt3]->type!=tetud[cpt1]->choix) {
								strcpy(d.idetud,tetud[cpt1]->idetud);
								strcpy(d.idchamb,"ZZZZ");
								d.demande=1;
								li=insererDem(li,d);
							}
							strcpy(d.idetud,tetud[cpt1]->idetud);
							strcpy(d.idchamb,"YYYY");
							d.demande=1;
							li=insererDem(li,d);		
						}		
						strcpy(d.idetud,tetud[cpt1]->idetud);
						strcpy(d.idchamb,"XXXX");
						d.demande=1;
						li=insererDem(li,d);
					}	
				}	
			}
		}
	}	
	
													
	/*3-Liberation et sauvegarde des tableaux*/
	sauvCite(flot,tab,nb);
	for (i=0;i<nbEtu;i++)
		free(tetud[i]);
	for (j=0;j<nbLog;j++)
		free(tlog[j]);
	fclose(flot);
	return li;
}


void admin1 (void)
{
	ListeD l;
	int longueur;
	l=newListeDem();
	l=mginser(l);
	sauvDem(l);
	longueur=longDemande(l);
	afficherToutDem(l);
	printf("Il y a %d demandes qui ont été enregistrées à ce jour\n",longueur);
}

void admin2 (void)
{
	Etudiant **tab;
	int nbEtu,i;
	tab=restEtu(&nbEtu);
	tab=modifEtu(tab,&nbEtu);	
	sauvEtu(tab,nbEtu);
	printf("\nN'oubliez pas d'utiliser la fonction d'attribution automatique des logements pour pourvoir faire la mise à jour !\n");
	for (i=0;i<nbEtu;i++) 
		free(tab[i]);
}

void admin3 (void)
{
	Etudiant **tab;
	int nbEtu,i;
	tab=restEtu(&nbEtu);
	tab=supEtu(tab,&nbEtu);
	sauvEtu(tab,nbEtu);
	printf("\nN'oubliez pas d'utiliser la fonction d'attribution automatique des logements pour pourvoir faire la mise à jour !\n");
	for (i=0;i<nbEtu;i++) 
		free(tab[i]);
}


void admin4 (void)
{
	Logement **tab;
	int nbLog,val,i,num,eta,typ,dis,choix1,l,cpt1,cpt2,cpt3;
	char bat[2];
	char id[6];
	tab=restLog(&nbLog);
	
	printf("Liste des chambres selon le critère :\n");
	printf("1-De l'identifiant du logement\n");
	printf("2-De la cité\n");
	printf("3-De la disponibilité\n");
	printf("4-Du type\n");
	printf("5-POUR QUITTER\n");
	scanf("%d",&choix1);
	while (choix1<1 || choix1>5) {
		viderBuffer();
		printf("La valeur doit être necessairement comprise entre 1 et 5..\n");
		scanf("%d",&choix1);
	}
	
	
	/* IDENTIFIANT*/
	if (choix1==1) {
		triDichLog(tab,nbLog);
		afficherToutLog(tab,nbLog);
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
		else if (strcmp(tab[val]->idchamb,id)==0) {
				printf("\n");
				afficherLog(*tab[val]);
			}
			else printf("Le logement ayant pour id : %s n'existe pas... \n",id);
		}
	
	/*BATIMENT*/
	if (choix1==2) {	
		printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
		scanf("%s",bat);
		l=strlen(bat);
		while(l!=1) {
			printf("Une lettre au maximum. Réessayez :\n");
			scanf("%s%*c",bat);
			l=strlen(bat);
		}
		while (strcmp (bat,"A")!=0 && strcmp(bat,"B")!=0 && strcmp(bat,"C")!=0) {
			printf("La lettre ne peut être que A ou B ou C.\n");
			printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
			scanf("%s",bat);
			l=strlen(bat);
			while(l!=1) {
				printf("Une lettre au maximum. Réessayez :\n");
				scanf("%s%*c",bat);
				l=strlen(bat);
			}
		}
		triDichLogCIT(tab,nbLog);
		for (cpt1=0;cpt1<nbLog;cpt1++) {
			if (strcmp(tab[cpt1]->idbat,bat)==0){
				afficherLog(*tab[cpt1]);
			}
			if (strcmp(bat,tab[cpt1]->idbat)<0) { //Le tableau est trié !
				break;
			}
		}	
	}
	
	/*DISPONIBILITE*/
	if (choix1==3) {
		printf("Saisissez 0 pour un logement disponible | 1 pour un logement indisponible | 2 pour un logement est en travaux | 3 pour un logement spécialisé pour handicapés\n");
		scanf("%d",&dis);
		while (dis==0 && dis==1 && dis==2 && dis==3) {
			viderBuffer();
			printf ("Votre choix ne peut être que 0 ou 1 ou 2 ou 3.\n");
			printf("Saisissez 0 pour un logement disponible | 1 pour un logement indisponible | 2 pour un logement est en travaux | 3 pour un logement spécialisé pour handicapés\n");
			scanf("%d",&dis);
		}
		triDichLogDIS(tab,nbLog);
		for(cpt2=0;cpt2<nbLog;cpt2++) {
			if (tab[cpt2]->disponibilite==dis){
				afficherLog(*tab[cpt2]);
			}
			if (tab[cpt2]->disponibilite>dis){ //Le tableau est trié !
				break;
			}
		}
	}
	
	/*TYPE*/
	if (choix1==4) {
		printf("Saisissez 0 pour les chambres | 1 si pour les studios | 2 pour les T1 | 3 pour les T2.\n");
		scanf("%d",&typ);
		while (typ!=0 && typ!=1 && typ!=2 && typ!=3) {
			viderBuffer();
			printf ("Votre choix ne peut être que 0 ou 1 ou 2 ou 3.\n");
			printf("Saisissez 0 pour les chambres | 1 si pour les studios | 2 pour les T1 | 3 pour les T2.\n");
			scanf("%d",&typ);
		}
		triDichLogTYP(tab,nbLog);
		for(cpt3=0;cpt3<nbLog;cpt3++) {
			if (tab[cpt3]->type==typ){
				afficherLog(*tab[cpt3]);
			}
			if (tab[cpt3]->type>typ){ //Le tableau est trié !
				break;
			}
		}
	}
	
	
	/*POUR QUITTER*/
	if (choix1==5) {
		exit(15);
	}
	
	for (i=0;i<nbLog;i++)
		free(tab[i]);
}


void admin5 (void)
{
	Logement **tab;
	int nbLog,val,i,num,eta,typ,dis,choix1,l,cpt1,cpt2,cpt3,rep,cpt4;
	char bat[2];
	char id[6];
	tab=restLog(&nbLog);
	
	printf("Liste des chambres selon le critère :\n");
	printf("1 De la disponibilité\n");
	printf("2 Du batiment (possibilité d'utiliser le critère de l'étage puis de la dispobilité)\n");
	printf("3 De l'étage\n");
	printf("4 POUR QUITTER\n");
	scanf("%d",&choix1);
	
	while (choix1<1 || choix1>4) {
		viderBuffer();
		printf("La valeur doit être necessairement comprise entre 1 et 4..\n");
		scanf("%d",&choix1);
	}
	
	/*DISPONIBILITE*/
	if (choix1==1) {
		printf("Saisissez 0 pour un logement disponible | 1 pour un logement indisponible | 2 pour un logement est en travaux | 3 pour un logement spécialisé pour handicapés\n");
		scanf("%d",&dis);
		while (dis==0 && dis==1 && dis==2 && dis==3) {
			viderBuffer();
			printf ("Votre choix ne peut être que 0 ou 1 ou 2 ou 3.\n");
			printf("Saisissez 0 pour un logement disponible | 1 pour un logement indisponible | 2 pour un logement est en travaux | 3 pour un logement spécialisé pour handicapés\n");
			scanf("%d",&dis);
		}
		triDichLogDIS(tab,nbLog);
		for(cpt2=0;cpt2<nbLog;cpt2++) {
			if (tab[cpt2]->disponibilite==dis && tab[cpt2]->type==0){
				afficherLog(*tab[cpt2]);
			}
			if (tab[cpt2]->disponibilite>dis){ //Le tableau est trié !
				break;
			}
		}
	}
	
	
	
	/*BATIMENT*/
	if (choix1==2) {	
		printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
		scanf("%s",bat);
		l=strlen(bat);
		while(l!=1) {
			printf("Une lettre au maximum. Réessayez :\n");
			scanf("%s%*c",bat);
			l=strlen(bat);
		}
		while (strcmp (bat,"A")!=0 && strcmp(bat,"B")!=0 && strcmp(bat,"C")!=0) {
			printf("La lettre ne peut être que A ou B ou C.\n");
			printf("Saisissez une lettre pour le batiment A pour LES ROCHES, B pour LE STELAR , C pour LE CROUCROUS :\n");
			scanf("%s",bat);
			l=strlen(bat);
			while(l!=1) {
				printf("Une lettre au maximum. Réessayez :\n");
				scanf("%s%*c",bat);
				l=strlen(bat);
			}
		}
		triDichLogCIT(tab,nbLog);
		for (cpt1=0;cpt1<nbLog;cpt1++) {
			if (strcmp(tab[cpt1]->idbat,bat)==0 && tab[cpt1]->type==0){
				afficherLog(*tab[cpt1]);
				strcpy(tab[cpt1]->idbat,"X");
			}
		}
		printf("Voulez vous maintenant utiliser la fonction pour afficher pour un étage : 0 pour oui et 1 pour non \n");
		scanf("%d",&rep);
		if (rep==0) {
			printf("Saisissez l'étage du logement \n");
			scanf("%d",&eta);
			triDichLogETA(tab,nbLog);
			for(cpt2=0;cpt2<nbLog;cpt2++) {
				if (tab[cpt2]->etage==eta && tab[cpt2]->type==0 && strcmp(tab[cpt2]->idbat,"X")==0){
					afficherLog(*tab[cpt2]);
					tab[cpt2]->etage=10;
				}
				if (tab[cpt2]->etage>eta){ //Le tableau est trié !
					break;
				}
			}
		}
		else exit(15);
		printf("Voulez vous maintenant utiliser la fonction pour afficher pour la disponibilité : 0 pour oui et 1 pour non \n");
		scanf("%d",&rep);
		if (rep==0) {
			printf("Saisissez 0 pour un logement disponible | 1 pour un logement indisponible | 2 pour un logement est en travaux | 3 pour un logement spécialisé pour handicapés\n");
			scanf("%d",&dis);
			while (dis==0 && dis==1 && dis==2 && dis==3) {
				viderBuffer();
				printf ("Votre choix ne peut être que 0 ou 1 ou 2 ou 3.\n");
				printf("Saisissez 0 pour un logement disponible | 1 pour un logement indisponible | 2 pour un logement est en travaux | 3 pour un logement spécialisé pour handicapés\n");
				scanf("%d",&dis);
			}
			triDichLogDIS(tab,nbLog);
			for(cpt4=0;cpt4<nbLog;cpt4++) {
				if (tab[cpt4]->disponibilite==dis && tab[cpt4]->type==0 && strcmp(tab[cpt4]->idbat,"X")==0 && tab[cpt4]->etage==10){
					afficherLog(*tab[cpt4]);
				}
				if (tab[cpt4]->disponibilite>dis){ //Le tableau est trié !
					break;
				}
			}
		}	
	}
	
	
	/*ETAGE*/
	if (choix1==3) {
		printf("Saisissez l'étage du logement \n");
		scanf("%d",&eta);
		triDichLogETA(tab,nbLog);
		for(cpt2=0;cpt2<nbLog;cpt2++) {
			if (tab[cpt2]->etage==eta && tab[cpt2]->type==0){
				afficherLog(*tab[cpt2]);
			}
			if (tab[cpt2]->etage>eta){ //Le tableau est trié !
				break;
			}
		}
	}
	
	
	if (choix1==4) {
		exit(15);
	}
	
	for (i=0;i<nbLog;i++)
		free(tab[i]);
	
	
}


void admin6 (void)
{
	Logement **tlog;
	Etudiant **tetud;
	ListeD l;
	Demande d1;
	int val,nbEtu,nbLog,lo;
	char rep[4];
	
	
	l=newListeDem();
	l=restDem(l);
	tlog=restLog(&nbLog);
	triDichLog(tlog,nbLog);
	tetud=restEtu(&nbEtu);
	triDichEtu(tetud,nbEtu);
	
	
	
	printf("Bienvenue dans la fonction d'attribution de logement manuelle.\n");
	printf("Saisissez un identifiant composé de 5 caractères :\n");
		scanf("%s%*c",d1.idetud);
		lo=strlen(d1.idetud);
		while(lo!=5) {
			printf("L'identifiant a 5 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idetud);
			lo=strlen(d1.idetud);
		}
		val=rechDichEtu(d1.idetud,tetud,nbEtu);
		if (val==nbEtu){
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		if (strcmp(tetud[val]->idetud,d1.idetud)==0) 
				printf("L'idenfiant %s existe. \n",d1.idetud);
		else {
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		
		printf("Veuillez indiquer l'indentifiant de la chambre à attribuer : \n");
		scanf("%s",d1.idchamb);
		lo=strlen(d1.idchamb);
		while(lo!=4) {
			printf("L'identifiant a 4 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idchamb);
			lo=strlen(d1.idchamb);
		}
		val=rechDichLog(d1.idchamb,tlog,nbLog);
		if (val==nbLog) {
			printf("Le logement avec l'id %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		if (strcmp(tlog[val]->idchamb,d1.idchamb)==0)
				printf("Le logement ayant pour id : %s existe.\n",d1.idchamb);
		else {
			printf("Le logement ayant pour id : %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		
		if (tlog[val]->disponibilite==1) {
			printf("Malheuresement le logement est déjà occupé..\n");
			exit(9);
		}
		
		d1.demande=0;
		l=insererDem(l,d1);
		sauvDem(l);
		printf("Enregistrement confirmé ! Bonne fin de journée, merci.\n");
	
}


void admin7 (void)
{
	Logement **tlog;
	Etudiant **tetud;
	ListeD l;
	Demande d1;
	int choix1,val,nbEtu,nbLog,lo;
	char rep[4];
	
	
	l=newListeDem();
	l=restDem(l);
	tlog=restLog(&nbLog);
	triDichLog(tlog,nbLog);
	tetud=restEtu(&nbEtu);
	triDichEtu(tetud,nbEtu);
	
	
	
	printf("Bienvenue dans la fonction permettant d'afficher et éditez les listes d'attentes\n");
	printf("1 Dû à la disponibilité du logement\n");
	printf("2 Dû au batiment du logement\n");
	printf("3 Dû au type de logement\n");
	printf("4 POUR QUITTER\n");
	scanf("%d",&choix1);
	
	while (choix1<1 || choix1>4) {
		viderBuffer();
		printf("La valeur doit être necessairement comprise entre 1 et 4..\n");
		scanf("%d",&choix1);
	}
	
	if (choix1==1) {
		afficherToutDemX(l);
		printf("Maintenant voulez vous éditez une demande manuellement ? (Répondez par oui ou non) \n");
			scanf("%s%*c",rep);
			if (strcmp(rep,"non")==0) {
				printf("Bonne fin de journée.\n");
				exit(5);
			}
			
		printf("Saisissez un identifiant composé de 5 caractères :\n");
		scanf("%s%*c",d1.idetud);
		lo=strlen(d1.idetud);
		while(lo!=5) {
			printf("L'identifiant a 5 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idetud);
			lo=strlen(d1.idetud);
		}
		val=rechDichEtu(d1.idetud,tetud,nbEtu);
		if (val==nbEtu){
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		if (strcmp(tetud[val]->idetud,d1.idetud)==0) 
				printf("L'idenfiant %s existe. \n",d1.idetud);
		else {
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		
		printf("Veuillez indiquer l'indentifiant de la chambre à attribuer : \n");
		scanf("%s",d1.idchamb);
		lo=strlen(d1.idchamb);
		while(lo!=4) {
			printf("L'identifiant a 4 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idchamb);
			lo=strlen(d1.idchamb);
		}
		val=rechDichLog(d1.idchamb,tlog,nbLog);
		if (val==nbLog) {
			printf("Le logement avec l'id %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		if (strcmp(tlog[val]->idchamb,d1.idchamb)==0)
				printf("Le logement ayant pour id : %s existe.\n",d1.idchamb);
		else {
			printf("Le logement ayant pour id : %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		
		if (tlog[val]->disponibilite==1) {
			printf("Malheuresement le logement est déjà occupé..\n");
			exit(9);
		}
		
		d1.demande=0;
		l=insererDem(l,d1);
		sauvDem(l);
		printf("Enregistrement confirmé ! Bonne fin de journée, merci.\n");
	}
	
	if (choix1==2) {
		afficherToutDemY(l);
		printf("Maintenant voulez vous éditez une demande manuellement ? (Répondez par oui ou non) \n");
			scanf("%s%*c",rep);
			if (strcmp(rep,"non")==0) {
				printf("Bonne fin de journée.\n");
				exit(5);
			}
			
		printf("Saisissez un identifiant composé de 5 caractères :\n");
		scanf("%s%*c",d1.idetud);
		lo=strlen(d1.idetud);
		while(lo!=5) {
			printf("L'identifiant a 5 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idetud);
			lo=strlen(d1.idetud);
		}
		val=rechDichEtu(d1.idetud,tetud,nbEtu);
		if (val==nbEtu){
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		if (strcmp(tetud[val]->idetud,d1.idetud)==0) 
				printf("L'idenfiant %s existe. \n",d1.idetud);
		else {
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		
		printf("Veuillez indiquer l'indentifiant de la chambre à attribuer : \n");
		scanf("%s",d1.idchamb);
		lo=strlen(d1.idchamb);
		while(lo!=4) {
			printf("L'identifiant a 4 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idchamb);
			lo=strlen(d1.idchamb);
		}
		val=rechDichLog(d1.idchamb,tlog,nbLog);
		if (val==nbLog) {
			printf("Le logement avec l'id %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		if (strcmp(tlog[val]->idchamb,d1.idchamb)==0)
				printf("Le logement ayant pour id : %s existe.\n",d1.idchamb);
		else {
			printf("Le logement ayant pour id : %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		
		if (tlog[val]->disponibilite==1) {
			printf("Malheuresement le logement est déjà occupé..\n");
			exit(9);
		}
		
		d1.demande=0;
		l=insererDem(l,d1);
		sauvDem(l);
		printf("Enregistrement confirmé ! Bonne fin de journée, merci.\n");
	}
	
	if (choix1==3) {
		afficherToutDemZ(l);
		printf("Maintenant voulez vous éditez une demande manuellement ? (Répondez par oui ou non) \n");
			scanf("%s%*c",rep);
			if (strcmp(rep,"non")==0) {
				printf("Bonne fin de journée.\n");
				exit(5);
			}
		
		printf("Saisissez un identifiant composé de 5 caractères :\n");
		scanf("%s%*c",d1.idetud);
		lo=strlen(d1.idetud);
		while(lo!=5) {
			printf("L'identifiant a 5 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idetud);
			lo=strlen(d1.idetud);
		}
		val=rechDichEtu(d1.idetud,tetud,nbEtu);
		if (val==nbEtu){
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		if (strcmp(tetud[val]->idetud,d1.idetud)==0) 
				printf("L'idenfiant %s existe. \n",d1.idetud);
		else {
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		
		printf("Veuillez indiquer l'indentifiant de la chambre à attribuer : \n");
		scanf("%s",d1.idchamb);
		lo=strlen(d1.idchamb);
		while(lo!=4) {
			printf("L'identifiant a 4 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idchamb);
			lo=strlen(d1.idchamb);
		}
		val=rechDichLog(d1.idchamb,tlog,nbLog);
		if (val==nbLog) {
			printf("Le logement avec l'id %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		if (strcmp(tlog[val]->idchamb,d1.idchamb)==0)
				printf("Le logement ayant pour id : %s existe.\n",d1.idchamb);
		else {
			printf("Le logement ayant pour id : %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		
		if (tlog[val]->disponibilite==1) {
			printf("Malheuresement le logement est déjà occupé..\n");
			exit(9);
		}
		
		d1.demande=0;
		l=insererDem(l,d1);
		sauvDem(l);
		printf("Enregistrement confirmé ! Bonne fin de journée, merci.\n");
	}


	if (choix1==4) {
		printf("Bonne fin de journée.\n");
		exit(5);
	}
}


void admin8 (void)
{
	Logement **tlog;
	Etudiant **tetud;
	ListeD l;
	Demande d1;
	int val,nbEtu,nbLog,lo;
	char rep[4];
	
	l=newListeDem();
	l=restDem(l);
	
	afficherSansDem(l);
	
	printf("Maintenant voulez vous éditez une demande manuellement ? (Répondez par oui ou non) \n");
	scanf("%s%*c",rep);
	if (strcmp(rep,"non")==0) {
		printf("Bonne fin de journée.\n");
		exit(5);
	}
	
	tlog=restLog(&nbLog);
	triDichLog(tlog,nbLog);
	tetud=restEtu(&nbEtu);
	triDichEtu(tetud,nbEtu);
	
	printf("Saisissez un identifiant composé de 5 caractères :\n");
		scanf("%s%*c",d1.idetud);
		lo=strlen(d1.idetud);
		while(lo!=5) {
			printf("L'identifiant a 5 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idetud);
			lo=strlen(d1.idetud);
		}
		val=rechDichEtu(d1.idetud,tetud,nbEtu);
		if (val==nbEtu){
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		if (strcmp(tetud[val]->idetud,d1.idetud)==0) 
				printf("L'idenfiant %s existe. \n",d1.idetud);
		else {
			printf("L'idenfiant %s n'existe pas. \n",d1.idetud);
			exit(9);
		}
		
		printf("Veuillez indiquer l'indentifiant de la chambre à attribuer : \n");
		scanf("%s",d1.idchamb);
		lo=strlen(d1.idchamb);
		while(lo!=4) {
			printf("L'identifiant a 4 caractères maximum. Réessayez :\n");
			scanf("%s%*c",d1.idchamb);
			lo=strlen(d1.idchamb);
		}
		val=rechDichLog(d1.idchamb,tlog,nbLog);
		if (val==nbLog) {
			printf("Le logement avec l'id %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		if (strcmp(tlog[val]->idchamb,d1.idchamb)==0)
				printf("Le logement ayant pour id : %s existe.\n",d1.idchamb);
		else {
			printf("Le logement ayant pour id : %s n'existe pas... \n",d1.idchamb);
			exit(9);
		}
		
		if (tlog[val]->disponibilite==1) {
			printf("Malheuresement le logement est déjà occupé..\n");
			exit(9);
		}
		
		d1.demande=0;
		l=insererDem(l,d1);
		sauvDem(l);
		printf("Enregistrement confirmé ! Bonne fin de journée, merci.\n");
}
void admin9 (void)
{
	ListeD l;
	l=newListeDem();
	l=restDem(l);
	afficherToutDem(l);
}

void admin10 (void)
{
	Logement **tab;
	int nb,i;
	tab=restLog(&nb);
	triDichLog(tab,nb);
	afficherToutLog(tab,nb);
	for (i=0;i<nb;i++)
		free(tab[i]);
}

void admin11 (void)
{
	Logement **tab;
	int nbLog,val,l,i;
	char id[5];
	tab=restLog(&nbLog);
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

void admin12 (void)
{
	Etudiant **tab;
	int nb,i;
	tab=restEtu(&nb);
	afficherToutEtu(tab,nb);
	for (i=0;i<nb;i++) 
		free(tab[i]);
}

void admin13 (void)
{
	Etudiant **tab;
	int nbEtu,val,l,i;
	char id[6];
	tab=restEtu(&nbEtu);
	triDichEtu(tab,nbEtu);
	afficherToutEtu(tab,nbEtu);
	printf("\n");
	printf("Veuillez indiquer l'indentifiant de l'étudiant à rechercher : \n");
	scanf("%s",id);
	l=strlen(id);
	while(l!=5) {
		printf("L'identifiant a 5 caractères maximum. Réessayez :\n");
		scanf("%s%*c",id);
		l=strlen(id);
	}
	val=rechDichEtu(id,tab,nbEtu);
	if (val==nbEtu)
		printf("L'étudiant avec l'id %s n'existe pas... \n",id);
	else if (strcmp(tab[val]->idetud,id)==0)
			printf("L'étudiant ayant pour id : %s existe. Il s'appelle %s %s et a pour indice %d dans le tableau.\n",id,tab[val]->prenom,tab[val]->nom,val);
		else printf("L'étudiant ayant pour id : %s n'existe pas... \n",id);
	for (i=0;i<nbEtu;i++) 
		free(tab[i]);
}

void admin14 (void)
{
	Cite tab[5];
	FILE *flot;
	int nb;
	nb=fcharg(tab);
	afficherTableau(tab,nb);
}

void admin15 (void)
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

void admin16 (void)
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

void admin17 (void)
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

void admin18 (void)
{
	FILE *flot;
	ListeD l;
	Demande d;
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
	sauvDem(l);
}

void admin19 (void)
{
	Logement **tab;
	int nbLog,taillemax,i;
	tab=chargeLog(&nbLog, &taillemax); 
	triDichLog(tab,nbLog);
	sauvLog (tab,nbLog);
	for (i=0;i<nbLog;i++)
		free(tab[i]);
}

void admin20 (void)
{
	Etudiant **tab;
	int nbEtu,tailleMax,i;
	tab=chargeEtu("etudiant.txt",&nbEtu,&tailleMax);
	triDichEtu(tab,nbEtu);
	sauvEtu(tab,nbEtu);
	for (i=0;i<tailleMax;i++) 
		free(tab[i]);
}

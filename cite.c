#include "projet.h"

Cite lireCite (FILE *flot)
{
    Cite A;
    fscanf(flot,"%s",A.idbat);
    fscanf(flot, "%d%^[a-z]",&A.maxlogement);
    fscanf(flot, "%d%^[a-z]",&A.logementrestant);
    fgets(A.nom,32,flot);
    A.nom[strlen(A.nom)-1]='\0';
    fgets(A.adresse,100,flot);
    A.adresse[strlen(A.adresse)-1]='\0';
    fscanf(flot,"%d",&A.cp);
    return A;
}


int fcharg (Cite tab[])
{
    int i=0;
    FILE *flot;
    flot = fopen("cite.txt","r");
    if (flot == NULL)
    {
        printf ("probleme d'ouverture du fichier \n");
        exit(1);
    }
    while(!feof(flot))
    {
        tab[i]=lireCite(flot);
        i=i+1;
    }
    fclose(flot);
    return i;
    
}

void afficherCite(Cite A)
{
   printf("%s\t%d\t%d\t%s\t%s\t%d\n",A.idbat,A.maxlogement,A.logementrestant,A.nom,A.adresse,A.cp);

}

void afficherTableau(Cite tab[], int nb)
{
    int i;
    for(i=0;i<nb-1;i++)
        afficherCite(tab[i]);
    printf("\n");
}


void sauvCite (FILE *flot, Cite *tab,int nb)
{
	int i;
	for(i=0;i<nb-1;i++) {
		fprintf(flot,"%s\t",tab[i].idbat);
		fprintf(flot,"%d\t",tab[i].maxlogement);
		fprintf(flot,"%d\n",tab[i].logementrestant);
		fprintf(flot,"%s\n",tab[i].nom);
		fprintf(flot,"%s\n",tab[i].adresse);
		fprintf(flot,"%d\n",tab[i].cp);		
	}
}




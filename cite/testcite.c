#include "cite.h"

void test (void)
{
	Cite tab[5];
	FILE *flot;
	int nb;
	nb=fcharg(tab);
	afficherTableau(tab,nb);
	flot=fopen("cite.txt","w");
	if (flot==NULL) {
		printf("Problème d'ouverture du fichier en écriture\n");
		exit(1);
	}
	printf("\n");
	tab[2].logementrestant=tab[2].logementrestant-5;
	sauvCite(flot,tab,nb);
	afficherTableau(tab,nb);
	fclose(flot);
}


int main (void)
{
	test();
	return 0;
}	


#include "projet.h"

void global (void)
{
	int choixp,choixA,choixE;
	Booleen repA;
	choixp=menuPrincipal();
		switch(choixp) {
			case 1 :
				choixE=menuE();
					switch(choixE) {
						case 1 : 
							etudiant1();
							break;
						case 2 : 
							etudiant2();
							break;
						case 3 : 
							etudiant3();
							break;
						case 9 :
							printf("Aurevoir.\n");
							break;
						default :
							printf("Choix inconnu.\n");
							break;
					}
				break;
			case 2 :
				repA=coAdmin();
				if (repA==vrai) {
					choixA=menuA();
					switch(choixA) {
						case 1 : 
							admin1();
							break;
						case 2 : 
							admin2();
							break;
						case 3 : 
							admin3();
							break;
						case 4 : 
							admin4();
							break;
						case 5 : 
							admin5();
							break;
						case 6 : 
							admin6();
							break;
						case 7 : 
							admin7();
							break;
						case 8 : 
							admin8();
							break;
						case 9 : 
							admin9();
							break;
						case 10 : 
							admin10();
							break;
						case 11 : 
							admin11();
							break;
						case 12 : 
							admin12();
							break;
						case 13 : 
							admin13();
							break;
						case 14 : 
							admin14();
							break;
						case 15 : 
							admin15();
							break;
						case 16 : 
							admin16();
							break;
						case 17 : 
							admin17();
							break;
						case 18 : 
							admin18();
							break;
						case 19 : 
							admin19();
							break;
						case 20 : 
							admin20();
							break;
						case 21 :
							printf("Au revoir.\n");
							exit(21);
						default :
							printf("Choix inconnu.\n");
							break;
					}
				}
				else printf("Au revoir.\n");
				break;
			case 9 :
				printf("Au revoir.\n");
				exit(21);
			default :
				printf("Choix inconnu. Au revoir.\n");
				break;
		}
}

void global2 (void)
{
	int rep;
	global();
	printf("Voulez vous quitter le programme 0 pour OUI et 1 pour NON ?\n");
	scanf("%d",&rep);
	while (rep!=0 && rep!=1) {
		printf("Erreur la réponse ne peut être que 0 ou 1\n");
		printf("Voulez vous quitter le programme 0 pour OUI et 1 pour NON ?\n");
		scanf("%d",&rep);
	}
	while (rep==1) {
		global();
		printf("Voulez vous quitter le programme 0 pour OUI et 1 pour NON ?\n");
		scanf("%d",&rep);
	}
	if (rep==0) {
		exit(20);
	}
}	

int main (void)
{
	global2();
	return 0;
}	

// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"

//Partie 1
void testPile(T_Pile *P);
void testFile(T_File *F);

//Partie 2
void permut(T_Pile *P, char *chaine);
int pileValide(T_Pile *adrP);
void afficherSol(T_Pile *P, char *chaine);
int factorielle(const char *chaine);
#define passerAuPremierFils(adrP,E) empiler(adrP, E)
#define remonterAuPere(adrP, elt) depiler(adrP, elt)
#define passerAuFrereSuivant(adrP, adrE) depiler(adrP, adrE),empiler(adrP, 1+(*adrE))
#define naPlusDeFrere(adrP, adrE, TailleChaine) *sommet(adrP, adrE)==TailleChaine-1
#define noeudTerminal(adrP, TailleChaine) hauteur(adrP)==TailleChaine
#define rechercheTerminee(adrP) pileVide(adrP)


int menu()
{

int choix;
printf("\n\n\n SDA1 TP9");
printf("\n\n\n 1 : tester mon fichier pile.c");
printf("\n 2 : tester mon fichier file.c");
printf("\n 3 : afficher et compter les permutations d'une chaine");
printf("\n 4 : afficher et compter les solutions pour un échiquier ");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}

int main()
{
T_File mafile;
T_Pile mapile;
int chx;
int taille;
char chaine[20];

do
{
chx=menu();
switch (chx)
	{
	case 1 :  
		printf("Phase de test : pile");
		//testez toutes vos fonctions par un jeu de test de votre choix
		testPile(&mapile); //TP9 partie 1 : à ecrire 
		break;
	case 2 : 
		printf("phase de test : file\n");
		//testez toutes vos fonctions par un jeu de test de votre choix
		testFile(&mafile); //TP9 partie 1 : à ecrire 
		break; 
	case 3 : 
		printf("Saisir chaine à permutter : \n");
		scanf("%s",chaine); //une chaine de longueur <=MAX
		printf("\n Il y a %d permutation : \n\t", factorielle(chaine));
		permut(&mapile,chaine); //TP9 partie 2: ecrire permut
		break;
	case 4 : 
		//scanf("%d",&taille);//taille echiquier <=MAX
		//echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
		break;



	}
}while(chx!=0);

printf("\nau plaisir de vous revoir ...\n");
return 0;
}


/**
 * It tests the functions of the Pile.
 * 
 * @param P the pointer to the pile
 */
void testPile(T_Pile *P){
	T_Elt elt;
	printf("\nInitialisation pile : ");
    initPile(P);
    printf("\n\nAffiche pile en entier: ");
    afficherPile(P);
	getchar();
    printf("\ndepiler : %d", depiler(P, &elt));
	getchar();
    printf("\nAffiche pile : ");
    afficherPile(P);
	getchar();
	printf("\nEmpile valeurs de 1 à 10 : ");
    empiler(P, 1);
    empiler(P, 2);
    empiler(P, 3);
    empiler(P, 4);
    empiler(P, 5);
    empiler(P, 6);
    empiler(P, 7);
    empiler(P, 8);
    empiler(P, 9);
    empiler(P, 10);
    printf("\n Fonction empiler : %d", empiler(P, 10));
	getchar();
    printf("\n Vérification Pile pleine : ");
    afficherPile(P);
	getchar();
    printf("\nFonction depiler : %d", depiler(P, &elt));
    printf("\naffichage element depile : ");
    afficherElt(&elt);
	getchar();
    printf("\nFonction depiler : %d", depiler(P, &elt));
    printf("\nElement depile : ");
    afficherElt(&elt);
	getchar();
    printf("\nFonction sommet : ");
    afficherElt(sommet(P, &elt));
	getchar();
    printf("\nElement depile : ");
    afficherElt(&elt);
	getchar();
    printf("\nHauteur : %d", hauteur(P));
	getchar();
    printf("\nAffiche pile : ");
    afficherPile(P);
	getchar();
}


/**
 * Initialise a file, then add values 1 to 10, then print the file, then remove the first element, then
 * print the file, then add 6 more elements, then print the file, then remove all the elements, then
 * print the file, then add the first element again, then print the file, then remove the first
 * element, then print the file
 * 
 * @param F the file to be tested
 */
void testFile(T_File *F){
	T_Elt elt;
	printf("\nInitialisation file : ");
	initFile(F);
	printf("\n\nAffiche file en entier: ");
	afficherFile(F);
	printf("\ndefiler : %d", retirer(F, &elt));
	printf("\nAffiche fonction : ");
	afficherFile(F);
	printf("\nAjoute valeurs de 1 à 10 : ");
	ajouter(F, 1);
	ajouter(F, 2);
	ajouter(F, 3);
	ajouter(F, 4);
	ajouter(F, 5);
	ajouter(F, 6);
	ajouter(F, 7);
	ajouter(F, 8);
	ajouter(F, 9);
	ajouter(F, 10);
	printf("\nenfiler : %d", ajouter(F, 10));
	printf("\nFile pleine : ");
	afficherFile(F);
	printf("\ndefiler : %d", retirer(F, &elt));
	printf("\nElement defile : ");
	afficherElt(&elt);
	printf("\ndefiler : %d", retirer(F, &elt));
	printf("\nElement defile : ");
	retirer(F, &elt);
	retirer(F, &elt);
	retirer(F, &elt);
	retirer(F, &elt);
	afficherElt(&elt);
	printf("\nsommet : ");
	afficherElt(premier(F, &elt));
	printf("\nElement defile : ");
	afficherElt(&elt);
	printf("\n\nAffiche file en entier: ");
	afficherFile(F);
	printf("\n\nAjoute 6 éléments en plus: ");
	ajouter(F, 1);
	ajouter(F, 2);
	ajouter(F, 3);
	ajouter(F, 4);
	ajouter(F, 5);
	ajouter(F, 6);
	ajouter(F, 7);
	printf("\n\nAffiche file en entier: ");	
	afficherFile(F);
	printf("\n\n Retire éléménts jusqu'au 5");
	retirer(F, &elt);
	retirer(F, &elt);
	retirer(F, &elt);
	retirer(F, &elt);
	retirer(F, &elt);
	retirer(F, &elt);
	retirer(F, &elt);
	retirer(F, &elt);
	afficherFile(F);
}
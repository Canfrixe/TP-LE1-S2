#include "livre.h"

void saisirLivre(T_livre * ptrL)
{
  lireChaine("CODE : ",ptrL->code, MAX_CODE);
  lireChaine("TITRE : ", (ptrL->titre), MAX_TITRE );
  lireChaine("AUTEUR : ", (ptrL->auteur ), MAX);
  lireChaine("EDITEUR : ", (ptrL->editeur), K_MaxEdit);
  strcpy(ptrL->emprunteur.nomemprunteur," ");
  printf("ANNEE PARUTION : ");
  scanf("%d",&(ptrL->annee));
}


void afficherLivre(const T_livre *ptrL)
{
  afficherChaine("CODE : ",ptrL->code);
  printf(" - ");
  afficherChaine("TITRE : ",ptrL->titre);
  printf(" - ");
  afficherChaine("AUTEUR : ",ptrL->auteur);
  printf(" - ");
  afficherChaine("EDITEUR : ",ptrL->editeur);
  printf(" - ");
  printf("ANNEE : %d",ptrL->annee);
  printf(" - ");
  afficherChaine("EMPRUNTEUR : ",ptrL->emprunteur.nomemprunteur);
  printf("\n");
  
}


int emprunterLivre(T_livre *ptrL){
	char vide[]="";
	if(strcmp(ptrL->emprunteur.nomemprunteur,vide) !=0){
		lireChaine("EMPRUNTEUR : ", ptrL->emprunteur.nomemprunteur,K_MaxEmp);
		return 1;
	}
	return 0;
}


int rendreLivre(T_livre * ptrL){
	char nomemprunteur[K_MaxEmp];
	lireChaine("VOTRE NOM : ", nomemprunteur, K_MaxEmp);
	if(strcmp(nomemprunteur, ptrL->emprunteur.nomemprunteur) ==0){
		strcpy(ptrL->emprunteur.nomemprunteur,"");
		return 1;
	} else
		return 0;
}
 

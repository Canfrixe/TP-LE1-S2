#include "biblio.h"

void init(T_Bibliotheque *ptrB)
{
  ptrB->nbLivres=0;
  // ou (*ptrB).nbLivres=0;
}

//saisir nouveau livre (option 1)
int ajouterLivre(T_Bibliotheque *ptrB)
{
  if (ptrB->nbLivres < CAPACITE_BIBLIO) { // reste t il de la place ?
      saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
      ptrB->nbLivres++;
      return 1;
  }
  return 0;
}

//affiche bibliothèque (option 2)
int afficherBibliotheque(const T_Bibliotheque *ptrB)
{
  int i;
  if (ptrB->nbLivres == 0)
    return 0;
  else {
    for(i=0;i<ptrB->nbLivres;i++) {
      afficherLivre( &(ptrB->etagere[i]));
    }
    return 1;
  }
}

//rechercher par titre (opion 3)
int rechercheLivre(const T_Bibliotheque ptrB) {
    char titre[MAX_TITRE];
    int j = 0;
    lireChaine("Titre:", titre, MAX_TITRE);

    for(int i = 0; i < ptrB.nbLivres; i++) {
        if(strcmp(ptrB.etagere[i].titre, titre) == 0) {
            afficherLivre(&(ptrB.etagere[i]));
            j++;
        }
    }
    return j;
}


//rechercher par auteur (option 4)
int rechercheAuteur(const T_Bibliotheque *ptrB){
	T_Aut auteur;//initialisation var auteur
    int i=-1; 
    int j=0;
    lireChaine("Auteur: ",auteur,MAX);//demande nom auteur et le stocke
    while(i != ptrB->nbLivres)
    {
        i++;
        if(strcmp(auteur,ptrB->etagere[i].auteur)==0)
        {
			afficherChaine("Titre",(ptrB->etagere[i].titre));        
			j++;
        }                        
		}
    return j;
}

//supprime livre (option 5)
int suppLivre(T_Bibliotheque *ptrB){
    int i;
    T_Titre titre;
    T_Aut auteur;
    int j = 0; // 1= succès, 0 = echec
    lireChaine("Titre: ",titre, MAX_TITRE);
    lireChaine("Auteur: ",auteur, K_MaxAut);

    for(i=0;i<=ptrB->nbLivres;i++){
        if(strcmp(ptrB->etagere[i].titre,titre)==0 && strcmp(ptrB->etagere[i].auteur,auteur)==0){
            ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres-1];
            ptrB->nbLivres--;
            j= 1;
        }
    }
    return j;
}

//Emprunter un livre (option 6)	
int prendreLivre(T_Bibliotheque *ptrB) {
    char code[MAX_CODE];
    int j = 0;
    
    lireChaine("Indiquez le code du livre à emprunter:", code, MAX_CODE);

    for(int i = 0; i < ptrB->nbLivres; i++) {
        if(strcmp(ptrB->etagere[i].code, code) == 0) {
            j = emprunterLivre(&(ptrB->etagere[i]));
        }
    }

    return j;
}

//Rendre un livre (option 7)
int retournerLivre(T_Bibliotheque *ptrB) {
    char code[MAX_CODE];
    int j = 0;
    
    lireChaine("Indiquez le code du livre à rendre:", code, MAX_CODE);

    for(int i = 0; i < ptrB->nbLivres; i++) {
        if(strcmp(ptrB->etagere[i].code, code) == 0) {
            j = rendreLivre(&(ptrB->etagere[i]));
        }
    }

    return j;
}

//trier les livres (par titre) (option 8)

void triParTitre(T_Bibliotheque *ptrB) {
    T_livre titre;
    int i=0;
    int j=0;
    int k = ptrB->nbLivres;
    

    for (i=0; i<k-1; i++)
    {
        for (j=0; j<k-1-i; j++)
        {
            if (strcmp(ptrB->etagere[j].titre, ptrB->etagere[j+1].titre) > 0)
            {
                titre = ptrB->etagere[j];
                ptrB->etagere[j] = ptrB->etagere[j+1];
                ptrB->etagere[j+1] = titre;
            }
        }
    }
}

//trier les livres (par auteur) (option 9) 

void triParAuteur(T_Bibliotheque *ptrB) {
    T_livre auteur;
    int i=0;
    int j=0;
    int k = ptrB->nbLivres;
    

    for (i=0; i<k-1; i++)
    {
        for (j=0; j<k-1-i; j++)
        {
            if (strcmp(ptrB->etagere[j].auteur, ptrB->etagere[j+1].auteur) > 0)
            {
                auteur = ptrB->etagere[j];
                ptrB->etagere[j] = ptrB->etagere[j+1];
                ptrB->etagere[j+1] = auteur;
            }
        }
    }
}

//trier par livres (par annee) (option 10)

void triParAnnee(T_Bibliotheque *ptrB){
    T_livre annee;
    int i=0;
    int j=0;
    int k = ptrB->nbLivres;

    
    for (i=0; i<k-1; i++)
    {
        for(j=0; j<k-1; j++)
        {
          if ((ptrB->etagere[j].annee) > (ptrB->etagere[j+1].annee))
          {

            annee = ptrB->etagere[j];
            ptrB->etagere[j] = ptrB->etagere[j+1];
            ptrB->etagere[j+1] = annee;
          }
        }
    }
}


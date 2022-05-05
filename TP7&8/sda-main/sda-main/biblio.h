#ifndef BIBLIO_H   // compilation conditionnelle
#define BIBLIO_H

#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef T_livre T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
  T_tabloDeLivres etagere;
  int nbLivres;  // nb de livres actuellement ds la bibliotheque
} T_Bibliotheque;

//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercheAuteur(const T_Bibliotheque *ptrB);
int rechercheLivre(const T_Bibliotheque ptrB);
int suppLivre(T_Bibliotheque *ptrB);
int prendreLivre(T_Bibliotheque *ptrB);
int retournerLivre(T_Bibliotheque *ptrB);
void triParTitre(T_Bibliotheque *ptrB);
void triParAuteur(T_Bibliotheque *ptrB);
void triParAnnee(T_Bibliotheque *ptrB);

#endif

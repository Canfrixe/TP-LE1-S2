#include "pile.h"



/**
 * Initialize a pile
 * 
 * @param P the pointer to the pile
 */
void initPile( T_Pile * P) {
    P->nbElts = 0;
}


/**
 * "Return 1 if the pile is full, 0 otherwise."
 * 
 * int pileVide(const  T_Pile *P) {
 *     if (P->nbElts == 0) return 1;
 *     return 0;
 * }
 * 
 * @param P the pointer to the pile
 * 
 * @return 1 if the pile is full, 0 otherwise.
 */
int pilePleine(const  T_Pile *P) {
    if (P->nbElts == MAX) return 1;
    return 0;
}


/**
 * Return 1 if the pile is empty, 0 otherwise.
 * 
 * @param P the pointer to the pile
 * 
 * @return 1 if the pile is empty, 0 otherwise.
 */
int pileVide(const  T_Pile *P) {
    if (P->nbElts == 0) return 1;
    return 0;
}


/**
 * If the stack is not full, the element is pushed on the stack and the function returns 1. Otherwise,
 * the function returns 0
 * 
 * @param P the pointer to the pile
 * @param e the element to be pushed onto the stack
 * 
 * @return 1 if the stack is not full, 0 otherwise.
 */
int empiler( T_Pile *P, T_Elt e) {//renvoie 0 si pile pleine, sinon 1
    if (!pilePleine(P)) {
        P->Elts[P->nbElts] = e;
        P->nbElts++;
        return 1;
    }
    return 0;
}


/**
 * If the stack is not empty, the function returns 1 and the top element is copied into the given
 * parameter. Otherwise, the function returns 0
 * 
 * @param P the pointer to the stack
 * @param pelt the element to be returned
 * 
 * @return The value of the element that is being removed from the stack.
 */
int depiler( T_Pile *P, T_Elt *pelt) { //renvoie 0 si pile vide, sinon 1 
    if (!pileVide(P)) {
        P->nbElts--;
        affecterElt(pelt, &(P->Elts[P->nbElts]));
        printf("\npile non vide");
        return 1;
    }
    printf("\n pile vide");
    return 0;
}


/**
 * Given a pointer to a stack, return the top element of the stack
 * 
 * @param P the stack
 * @param pelt the element to be returned
 * 
 * @return The element at the top of the stack.
 */
T_Elt *sommet(T_Pile *P, T_Elt *pelt) {
    if (!pileVide(P)) {
        affecterElt(pelt, &(P->Elts[P->nbElts-1]));
        return pelt;
    }
    *pelt = -1;
    return pelt;
    
}

/**
 * Return the number of elements in the stack
 * 
 * @param P the pointer to the first element of the stack
 * 
 * @return The number of elements in the stack.
 */
int hauteur(const  T_Pile *P) {
    return P->nbElts;
}


/**
 * Prints the elements of the stack
 * 
 * @param P the pointer to the stack
 */
void afficherPile(  T_Pile *P){
     printf("\n---- SOMMET ----\n");
     for (int i = P->nbElts - 1; i >= 0; i--) {
        afficherElt(&(P->Elts[i]));
     }
     printf("\n---- FIN ----\n");
}
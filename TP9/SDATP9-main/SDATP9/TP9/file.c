#include "file.h" 


/**
 * Initialize the file
 * 
 * @param ptrF the pointer to the file structure
 */
void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Tete = -1;
    ptrF->Queue = -1;
}


/**
 * If the queue is empty, return 0. Otherwise, if the queue is full, return 1.
 * 
 * @param ptrF the pointer to the file
 * @param ptrE the element to be removed
 * 
 * @return 1 if the element was removed from the queue, 0 otherwise.
 */
int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    if (fileVide(ptrF)) {
        return 0; //si file vide, retourne 0
    }
    else if(ptrF->Tete == MAX-1) { //si tete est au bout de la file
        affecterElt(ptrE, &ptrF->Elts[ptrF->Tete]);
        ptrF->Tete = 0;
        return 1;
    }
    else if(ptrF->Tete == ptrF->Queue) { //si tete est égale à la queue
        affecterElt(ptrE, &ptrF->Elts[ptrF->Tete]);
        ptrF->Tete = -1;
        ptrF->Queue = -1;
        return 1;
    }
    else {
        affecterElt(ptrE, &ptrF->Elts[ptrF->Tete]);
        ptrF->Tete ++;
        return 1;
    }
}




/**
 * If the queue is full, return 0. If the queue is empty, set the head and tail to 0. If the tail is at
 * the end of the array, set the tail to 0. Otherwise, increment the tail
 * 
 * @param ptrF the pointer to the file
 * @param ptrE the element to be added to the queue
 * 
 * @return 1 if the element was added, 0 otherwise.
 */
int ajouter(T_File *ptrF,T_Elt ptrE) // si espace libre, ajout en queue
{
    if(filePleine(ptrF))
    {
        return 0;
    }
    else if (fileVide(ptrF)) {
        ptrF->Queue = 0;
        ptrF->Tete = 0;
    }
    else if(ptrF->Queue == MAX-1)
    {
        ptrF->Queue = 0;
    }
    else 
    {
        ptrF->Queue++;
    }
    ptrF->Elts[ptrF->Queue] = ptrE;
    return 1;
} 


/**
 * If the head of the queue is -1, then the queue is empty
 * 
 * @param prtF pointer to the file
 * 
 * @return 1 if the file is empty, 0 otherwise.
 */
int fileVide(const  T_File *ptrF) // qd Tete == 0 
{
    if (ptrF->Queue==-1){
        return 1;
    }
return 0;
}



/**
 * If the queue is full, return 1. Otherwise, return 0
 * 
 * @param ptrF the pointer to the file structure
 * 
 * @return 1 if the file is full, 0 otherwise.
 */
int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    if ((ptrF->Tete == 0 && ptrF->Queue == MAX-1) || ptrF->Tete - ptrF->Queue == 1){
        return 1;
    }
return 0;
}

/**
 * Given a pointer to a file, return a pointer to the first element in the file
 * 
 * @param ptrF the pointer to the file
 * @param ptrE the element to be returned
 * 
 * @return The element at the head of the file.
 */
T_Elt *premier(T_File *ptrF, T_Elt *ptrE) //valeur en tete de file
{
    affecterElt(ptrE, &ptrF->Elts[ptrF->Tete]);
    return ptrE;
}

void afficherFile(T_File *ptrF)
{
    printf("\n\n --- HEAD --- \n\n");
    
    for(int i = ptrF->Tete; i != ptrF->Queue; i++) {
        if (i == MAX) {
            i = 0;
        }
        afficherElt(&ptrF->Elts[i]);
    }
    afficherElt(&ptrF->Elts[ptrF->Queue]);
    printf("\n\n --- QUEUE --- \n\n");
}


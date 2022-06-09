#ifndef ECHIQUIERHEADER
#define ECHIQUIERHEADER

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum {
    VRAI = 1,
    FAUX = 0
} Bool;

typedef enum {
    BLANC = 0,
    NOIR = 1,
    EMPTY = 2
} Couleur;

typedef enum {
    VIDE = 0,
    PION = 1,
    CAVALIER = 2,
    FOU = 3,
    TOUR = 4,
    DAME = 5,
    ROI = 6,

} Nom;

/*Structure représantant une pièce d'un echiquier*/
typedef struct
{
    Nom nom; //Nom de la pièce
    Couleur couleur;//Couleur de la pièce 
    char aff;//Son caractère d'affichage 
    int coup;// Le nombre de coup quelle a effectué dans une partie 

} Piece;

/**
 * @brief Initialise un echiquier de la taille choisit
 *
 * @param taille -> taille de l'échiquier
 * @return Piece**
 */
Piece** initializeechiquier(int taille);

/**
 * @brief Libère la mémoire alloué pour l'échiquier
 *
 * @param taille -> taille de l'échiquier
 * @param echiquier -> Tableau à  deux dimensions de structures
 */
void freechiquier(int taille, Piece*** echiquier);

/**
 * @brief Utile dans InitializeEchiquier pour placer le roi à chaque début de partie
 *
 * @param echiquier--> structure de Pièce
 * @param taille --> taille de l'echiquier
 */
void MiseEnPlaceRoi(Piece** echiquier, int taille);

#endif
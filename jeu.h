#ifndef JEUHEADER
#define JEUHEADER

#include <echiquier.h>

/**
 * @brief Fonction permettant de vérifier les coordonnées de l'utilisateur et de remplir le tableau coordonnee permettant ainsi des manipulations avec le tableau de structure de l'échiquier
 * 
 * @param taille --> Taille de l'échiquier
 * @param coordonnee --> Tableau d'entiers destiné à  être complété par les coordonnées compréhensible par la machine
 */
void acquisitioncoordonnees(int taille, int coordonnee[2]);

/**
 * @brief Fonction utilisée dans la fonction acquisitioncoordonnées(ex si l'utilisateur rentre A5 dans un echiquier 6 par 6 la fonction permettra d'obtenir 1 : 0 )
 * 
 * @param abscisse --> abscisse de l'échiquier (colonne)
 * @param ordonnee --> ordonnée de l'échiquier (ligne)
 * @param taillechiquier --> taaille de l'échiquier
 */
void switchbase(int *abscisse, int *ordonnee, int taillechiquier);

/**
 * @brief Fonction permettant de dire si le mouvement donné par l'utilisateur pour un fou est correct
 * 
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver--> Coordonnée d'arriver entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces 
 * @return Bool--> indique si le coup est possible ou non 
 */
Bool FouVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);

/**
 * @brief Fonction se répettant dans FouMouvement 
 * 
 * @param i --> entier d'indentation
 * @param y --> ligne d'arrivée
 * @param y0 --> ligne de départ 
 * @param x --> colonne d'arrivée
 * @param x0--> colonne de départ
 * @param echiquier--> tableau de structure de pièces 
 * @return Bool --> indique si le coup est possible ou non 
 */
Bool VerificationFou(int i,int y, int y0,int x,int x0,Piece** echiquier);

 /**
  * @brief  Fonction permettant de dire si le mouvement donné par l'utilisateur pour un cavalier est correct
  * 
  * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
  * @param coordonneearriver --> Coordonnée d'arriver entrée par l'utilisateur 
  * @param echiquier -->  tableau de structure de pièces 
  * @return Bool--> indique si le coup est possible ou non 
  */
Bool CavalierVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);


Bool TourVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);
#endif

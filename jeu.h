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
 * @brief 
 * 
 * @param coordonneedepart 
 * @param coordonneearriver 
 * @param echiquier 
 * @return Bool 
 */
Bool FouMouvement(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);

/**
 * @brief 
 * 
 * @param i 
 * @param y 
 * @param y0 
 * @param x 
 * @param x0 
 * @param echiquier 
 * @return Bool 
 */
Bool VerificationFou(int i,int y, int y0,int x,int x0,Piece** echiquier);
#endif

#ifndef AFFICHAGEHEADER
#define AFFICHAGEHEADER

#include <echiquier.h>
#include <jeu.h>

/**
 * @brief Fonction qui rempli le menu de caractère ASCII de notre choix
 *
 * @param taille -> taille du menu
 * @param motifascii -> Motif ASCII que l'on choisit
 */
void asciiboucle(int taille, int motifascii);

/**
 * @brief Fonction qui rempli le menu avec les phrase de notre choix. Attention il faut que la taille des phrases
 * soit inférieur à  la taille du menu ( il faut -2 caractères sur la taille du menu), pour un affichage correct.
 *
 * @param ecriture -> Tableau de caractères que l'on veut afficher
 * @param motifascii -> Motif du cadre du Menu
 * @param temps -> Temps nécessaire à l'écriture des paramètres (optionnel)
 */
void ecritureaffichage(char * ecriture, int motifascii);

/**
 * @brief Fonction qui affiche l'échiquier de la partie en cours
 *
 * @param taille -> taille de l'échiquier
 * @param echiquier -> Tableau  à  deux dimensions de structure
 */
void affichage(int taille, Piece** echiquier);

/**
 * @brief Affiche le menu du jeu Very Bad Chess
 *
 */
void menu();

/**
 * @brief Utile dans Partie
 * 
 * @param taille  --> taille de l'échiquier (6 x 6 par exemple) 
 * @param echiquier -->  Structure de Piece 
 * @param CoordonneeInit --> Coordonnée de départ entrée par l'utilisateur
 * @param CoordonneFinit --> Coordonnée d'arrivée entrée par l'utilisateur 
 */
void CoupDansPartie(int taille,Piece** echiquier,int CoordonneeInit[2],int CoordonneeFinit[2],Couleur Joue);


/**
 * @brief Assure le bon déroulement d'une partie de Very Bad CHess
 * 
 */
void partie(int taille, Piece** echiquier);



#endif
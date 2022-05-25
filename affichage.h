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
void ecritureaffichage(char *ecriture, int motifascii);

/**
 * @brief Fonction qui affiche l'échiquier de la partie en cours
 *
 * @param taille -> taille de l'échiquier
 * @param echiquier -> Tableau  à  deux dimensions de structure
 */
void affichage(int taille, Piece **echiquier);

/**
 * @brief Affiche le menu du jeu Very Bad Chess
 *
 */
void menu();

#endif
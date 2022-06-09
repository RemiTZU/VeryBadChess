#ifndef AFFICHAGEHEADER
#define AFFICHAGEHEADER

#include <echiquier.h>
#include <jeu.h>
#include <sauvegarde.h>

/**
 * @brief Fonction permettant de vérifier les coordonnées de l'utilisateur et de remplir le tableau coordonnee
 * permettant ainsi des manipulations avec le tableau de structure de l'échiquier
 *
 * @param taille --> Taille de l'échiquier
 * @param coordonnee --> Tableau d'entiers représentant les indexs du tableau de structure(format: ligne-colonne)
 */
void acquisitioncoordonnees(int taille, int coordonnee[2]);

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
 */
void ecritureaffichage(char* ecriture, int motifascii);

/**
 * @brief Fonction qui affiche l'échiquier de la partie en cours
 *
 * @param taille -> taille de l'échiquier
 * @param echiquier -> Tableau  à  deux dimensions de structure de Pièce
 */
void affichage(int taille, Piece** echiquier);

/**
 * @brief Affiche le menu du jeu Very Bad Chess
 *
 */
void menu();

/**
 * @brief
 *
 * @param taille -> taille de l'échiquier
 * @param CoordonneeInit--> Coordonnée de départ entrée par l'utilisateur
 * @param CoordonneeFinit--> Coordonnée d'arriver entrée par l'utilisateur*
 * @param Joue --> couleur entrain de jouer 
 */
void Coup(int taille, int CoordonneeInit[2], int CoordonneeFinit[2],Couleur Joue);

/**
 * @brief Fonction booléenne servant dans partie. Sert  à savoir si un mouvement est légal sous trois conditions : la légalité du mouvement la couleur suivant le tour et l'echec à la découverte deRoi
 *
 * @param taille -> taille de l'échiquier
 * @param CoordonneeInit --> Coordonnée de départ entrée par l'utilisateur
 * @param CoordonneeFinit --> Coordonnée d'arriver entrée par l'utilisateur
 * @param MisenEchec --> Couleur du Roi mis en échec
 * @param MetEnEchec --> Couleur du Roi mis en échec
 * @param CoordonneRoi--> Coordonnées du Roi qui peut être en échec
 * @return Bool --> VRAI si le mouvement est légal
 */
Bool MouvementLegal(int taille, int CoordonneeInit[2], int CoordonneeFinit[2], Piece** echiquier, Couleur MisenEchec, Couleur MetEnEchec, int CoordonneRoi[2]);

/**
 * @brief Assure le bon déroulement d'une partie de Very Bad CHess
 *
 */
void partie(int taille, Piece** echiquier,int tour);

#endif

#ifndef AFFICHAGEHEADER
#define AFFICHAGEHEADER

#include <echiquier.h>
#include <jeu.h>


/**
 * @brief Fonction permettant de vérifier les coordonnées de l'utilisateur et de remplir le tableau coordonnee
 * permettant ainsi des manipulations avec le tableau de structure de l'échiquier
 *
 * @param taille --> Taille de l'échiquier
 * @param coordonnee --> Tableau d'entiers destiné à  être complété par les coordonnées compréhensible par la machine
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
 * @brief 
 * 
 * @param taille 
 * @param CoordonneeInit 
 * @param CoordonneeFinit 
 * @param MisenEchec 
 * @param MetEnEchec 
 * @param CoordonneRoi 
 * @return Bool 
 */
Bool MouvementLegal(int taille,int CoordonneeInit[2], int CoordonneeFinit[2],Piece** echiquier, Couleur MisenEchec, Couleur MetEnEchec, int CoordonneRoi[2]);

/**
 * @brief 
 * 
 * @param taille 
 * @param CoordonneeInit 
 * @param CoordonneeFinit 
 */
void Coup(int taille,int CoordonneeInit[2],int CoordonneeFinit[2]);


/**
 * @brief Assure le bon déroulement d'une partie de Very Bad CHess
 * 
 */
void partie(int taille, Piece** echiquier);



#endif
#ifndef JEUHEADER
#define JEUHEADER

#include <echiquier.h>

/**
 * @brief Fonction permettant de vérifier les coordonnées de l'utilisateur et de remplir le tableau coordonnee
 * permettant ainsi des manipulations avec le tableau de structure de l'échiquier
 *
 * @param taille --> Taille de l'échiquier
 * @param coordonnee --> Tableau d'entiers destiné à  être complété par les coordonnées compréhensible par la machine
 */
void acquisitioncoordonnees(int taille, int coordonnee[2]);

/**
 * @brief Fonction utilisée dans la fonction acquisitioncoordonnées(ex si l'utilisateur rentre A5 dans un echiquier 6
 * par 6 la fonction permettra d'obtenir 1 : 0 )
 *
 * @param abscisse --> abscisse de l'échiquier (colonne)
 * @param ordonnee --> ordonnée de l'échiquier (ligne)
 * @param taillechiquier --> taaille de l'échiquier
 */
void switchbase(int* abscisse, int* ordonnee, int taillechiquier);

/**
 * @brief Permet d'actualiser l'echiquier et de déplacer une pièce si le mouvement est possible
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arriver entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 */
void Mouvement(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);

/**
 * @brief Verification des mouvements d'un Fou
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver--> Coordonnée d'arriver entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool--> indique si le coup est possible ou non
 */
Bool FouVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);

/**
 * @brief Fonction se répettant dans FouVerification
 *
 * @param i --> entier d'indentation
 * @param y --> ligne d'arrivée
 * @param y0 --> ligne de départ
 * @param x --> colonne d'arrivée
 * @param x0--> colonne de départ
 * @param echiquier--> tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non
 */
Bool VerificationFou(int i, int y, int y0, int x, int x0, Piece** echiquier);

/**
 * @brief  Verification des mouvements d'un cavalier
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arrivée entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool--> indique si le coup est possible ou non
 */
Bool CavalierVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);

/**
 * @brief Verification des mouvements d'une tour
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arrivée entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non
 */
Bool TourVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);

/**
 * @brief Verification des mouvements d'un Pion
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arrivée entrée par l'utilisateur
 * @param taille --> taille de l'échiquier
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non

 */
Bool PionVerification(int coordonneedepart[2], int coordonneearriver[2], int taille, Piece** echiquier);

/**
 * @brief Verification des mouvements d'un Roi
 * 
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arrivée entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non
 */
Bool RoiVeerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);

/**
 * @brief Verification des mouvements d'une Reine
 * 
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver--> Coordonnée d'arrivée entrée par l'utilisateur 
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non
 */
Bool DameVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier);

/**
 * @brief Donne la position du Roi à l'instant t
 * 
 * @param CoordonneeRoi --> Coordonnée du roi à modifier après mouvement
 * @param Roi --> Couleur du Roi en question
 * @param taille--> taille de l'échiquier (6 x 6 par exemple) 
 * @param echiquier --> Structure de Piece 
 */
void PositionRoi(int CoordonneeRoi[2], Couleur Roi, int taille, Piece** echiquier);

/**
 * @brief Fonction utile pour la fonction EchecRoi, regroupe les mouvements de toutes les pièces 
 * 
 * @param taille --> taille de l'échiquier (6 x 6 par exemple) 
 * @param coordonnee --> Coordonnée de la case actuelle où l'on veut appliquer la fonction
 * @param coordonneeRoi--> Coordonnées aux quelles on vérifie si le roi peut être en échec   
 * @param echiquier -->  Structure de Piece 
 * @return Bool --> Indique si le roi est en echec par la pièce concernée 
 */
Bool MouvementPieceEchec(int taille,int coordonnee[2],int coordonneeRoi[2],Piece** echiquier);

/**
 * @brief Fonction qui indique si le roi d'une couleur (NOIR ou BLANC) est en échec au moment donné
 * 
 * @param taille --> taille de l'échiquier (6 x 6 par exemple)  
 * @param CoordonneeRoi --> Coordonnées du Roi dont on vérifie l'echec potentiel 
 * @param echiquier -->  Structure de Piece 
 * @param MiseEnEchec --> Couleur du Roi mis en échec potentiel
 * @param MetEnEchec --> Couleur de la pièce qui met en échec 
 * @param tailleTabtmp --> Tailledu Tableau qui met en echec le roi
 * @return int** --> tableau de deux dimensions de int qui contient les coordonnées de chaque pièce mettant en échec le roi 
 */
int** EchecRoi(int taille, int CoordonneeRoi[2], Piece** echiquier, Couleur MiseEnEchec, Couleur MetEnEchec, int* tailleTabtmp);

/**
 * @brief Fonction servant dans EchecEtMat -->indique si le Roi est bloqué à  sa place ou peut se déplacer en cas d'echec
 * 
 * @param taille --> taille de l'échiquier (6 x 6 par exemple)
 * @param CoordonneRoi  --> Coordonnées du Roi qui est en echec
 * @param MiseEnEchec--> Couleur du Roi mis en échec 
 * @param MetEnEchec --> Couleur de la pièce qui met en échec  
 * @param echiquier -->  Structure de Piece  
 * @return Bool --> Ressort Vrai si le roi peut se déplacer, l'inverse sinon
 */
Bool RoiMouvementElementaire(int taille, int CoordonneRoi[2], Couleur MiseEnEchec,Couleur MetEnEchec, Piece** echiquier);


/**
 * @brief Fonction utile dans EchecEtMat, sert à  savoir si oui ou non le Roi peut être protéger par ses coéquipiers
 * 
 * @param taille --> taille de l'échiquier (6 x 6 par exemple)
 * @param echiquier  -->  Structure de Piece 
 * @param coordonneePieceMetenEchec --> Piece qui met en échèque le roi
 * @param MetEnEchec --> Couleur de la pièce qui met en échec  
 * @param MisenEchec --> Couleur du Roi mis en échec 
 * @param coordonneeRoi --> Coordonnées du Roi qui est en echec
 * @return Bool --> ressort vrai si le contre est possible 
 */
Bool EchecEtMatContre(int taille, Piece **echiquier, int coordonneePieceMetenEchec[2], Couleur MetEnEchec, Couleur MisenEchec, int coordonneeRoi[2]);

/**
 * @brief Fonction primordiale pour la boucle de jeu 
 * 
 * @param taille  --> taille de l'échiquier (6 x 6 par exemple)
 * @param CoordonneRoi --> Coordonnées du Roi qui est en echec 
 * @param MiseEnEchec --> Couleur du Roi mis en échec 
 * @param MetEnEchec  --> Couleur du Roi mis en échec 
 * @param echiquier -->  Structure de Piece 
 * @return Bool --> ressort VRAI si le roi n'est pas en echec et mat 
 */
Bool PasEchecEtMat(int taille, int CoordonneRoi[2], Couleur MiseEnEchec, Couleur MetEnEchec, Piece** echiquier);


#endif




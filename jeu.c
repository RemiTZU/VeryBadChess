#include <jeu.h>

/* Jeu.c regroupe toutes les fonctions utilent pour les vérifications des mouvements des pièces, de l'échec, échec et mat et le contre de l'échec*/

/***********************************************************************************************************************************************************************/
/**
 * @brief Fonction utilisée dans la fonction acquisitioncoordonnées(ex si l'utilisateur rentre A5 dans un echiquier 6
 * par 6 la fonction permettra d'obtenir 1 : 0 )
 *
 * @param abscisse --> abscisse de l'échiquier (colonne)
 * @param ordonnee --> ordonnée de l'échiquier (ligne)
 * @param taillechiquier --> taaille de l'échiquier
 */
void switchbase(int* abscisse, int* ordonnee, int taillechiquier)
{
    *abscisse = *abscisse - 65;
    *ordonnee = taillechiquier - *ordonnee;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Permet d'actualiser l'echiquier et de déplacer une pièce si le mouvement est possible
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arriver entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 */
void Mouvement(Coord coordonneedepart, Coord coordonneearriver, Piece** echiquier)
{
    Piece tmp;
    tmp.aff = ' ';
    tmp.nom = 0;
    tmp.couleur = 2;
    tmp.coup = 0;

    echiquier[coordonneearriver.y][coordonneearriver.x] = echiquier[coordonneedepart.y][coordonneedepart.x];
    echiquier[coordonneedepart.y][coordonneedepart.x] = tmp;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Verification des mouvements d'un Fou
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver--> Coordonnée d'arriver entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool--> indique si le coup est possible ou non
 */
Bool FouVerification(Coord coordonneedepart, Coord coordonneearriver, Piece** echiquier)
{
    Bool verif = FAUX;

    if (coordonneedepart.x == coordonneearriver.x) {
        return verif;
    }

    int y0 = coordonneedepart.y;
    int x0 = coordonneedepart.x;
    int y = coordonneearriver.y;
    int x = coordonneearriver.x;
    int coeff = (y - y0) / (x - x0);
    int deltaY = (y - y0);

    if (abs(x0 - x) == abs(y0 - y)) {
        if (coeff > 0 && deltaY < 0) {
            int i = 1;

            while (((x0 - i != x) && (y0 - i != y)) && (echiquier[y0 - i][x0 - i].aff == ' ')) {
                i++;
            }
            verif = VerificationFou(i, y, y0, x, x0, echiquier);
        }
        if (coeff > 0 && deltaY > 0) {
            int i = 1;

            while (((x0 + i != x) && (y0 + i != y)) && (echiquier[y0 + i][x0 + i].aff == ' ')) {
                i++;
            }

            verif = VerificationFou(i, y, y0, x, x0, echiquier);
        }
        if (coeff < 0 && deltaY < 0) {
            int i = 1;

            while (((x0 + i != x) && (y0 - i != y) && (echiquier[y0 - i][x0 + i].aff == ' '))) {
                i++;
            }
            verif = VerificationFou(i, y, y0, x, x0, echiquier);
        }
        if (coeff < 0 && deltaY > 0) {
            int i = 1;

            while (((x0 - i != x) && (y0 + i != y)) && (echiquier[y0 + i][x0 - i].aff == ' ')) {
                i++;
            }
            verif = VerificationFou(i, y, y0, x, x0, echiquier);
        }
    }

    return verif;
}
/***********************************************************************************************************************************************************************/
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
Bool VerificationFou(int i, int y, int y0, int x, int x0, Piece** echiquier)
{
    Bool verif = FAUX;

    if (i != abs(y - y0)) {
        verif = FAUX;
    } else if (i == abs(y - y0) && echiquier[y][x].couleur != echiquier[y0][x0].couleur) {
        verif = VRAI;
    }
    return verif;
}

/***********************************************************************************************************************************************************************/
/**
 * @brief  Verification des mouvements d'un cavalier
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arrivée entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool--> indique si le coup est possible ou non
 */
Bool CavalierVerification(Coord coordonneedepart, Coord coordonneearriver, Piece** echiquier)
{
    Bool verif = FAUX;

    int y0 = coordonneedepart.y;
    int x0 = coordonneedepart.x;
    int y = coordonneearriver.y;
    int x = coordonneearriver.x;

    if (((abs(y0 - y) == 2 && abs(x0 - x) == 1) || (abs(y0 - y) == 1 && abs(x0 - x) == 2)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
        verif = VRAI;
    }

    return verif;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Verification des mouvements d'une tour
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arrivée entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non
 */
Bool TourVerification(Coord coordonneedepart, Coord coordonneearriver, Piece** echiquier)
{
    Bool verif = FAUX;

    int y0 = coordonneedepart.y;
    int x0 = coordonneedepart.x;
    int y = coordonneearriver.y;
    int x = coordonneearriver.x;

    if (x == x0) {
        int i = 1;
        if (y < y0) {
            while ((y != y0 - i) && echiquier[y0 - i][x].aff == ' ') {
                i++;
            }
            if ((i == abs(y0 - y)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
                verif = VRAI;
            }
        }
        if (y > y0) {
            while ((y != y0 + i) && echiquier[y0 + i][x].aff == ' ') {
                i++;
            }
            if ((i == abs(y0 - y)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
                verif = VRAI;
            }
        }
    }
    if (y0 == y) {
        int i = 1;
        if (x < x0) {
            while ((x != x0 - i) && echiquier[y][x0 - i].aff == ' ') {
                i++;
            }
            if ((i == abs(x0 - x)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
                verif = VRAI;
            }
        }
        if (x > x0) {
            while ((x != x0 + i) && echiquier[y][x0 + i].aff == ' ') {
                i++;
            }
            if ((i == abs(x0 - x)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
                verif = VRAI;
            }
        }
    }
    return verif;
}

/***********************************************************************************************************************************************************************/
/**
 * @brief Verification des mouvements d'un Pion
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arrivée entrée par l'utilisateur
 * @param taille --> taille de l'échiquier
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non

 */
Bool PionVerification(Coord coordonneedepart, Coord coordonneearriver, int taille, Piece** echiquier)
{

    Bool verif = FAUX;
    Piece tmp;
    tmp.aff = ' ';
    tmp.couleur = EMPTY;
    tmp.nom = VIDE;

    int y0 = coordonneedepart.y;
    int x0 = coordonneedepart.x;
    int y = coordonneearriver.y;
    int x = coordonneearriver.x;

    if (echiquier[y0][x0].couleur == NOIR) {
        if (echiquier[y0][x0].coup == 0) {

            if (y0 == 1) {
                if ((y0 - y == -2 || y0 - y == -1) && x == x0) {
                    verif = VRAI;
                }
            }

            if ((y0 - y) == -1 && abs(x - x0) == 1 && (echiquier[y][x].couleur != tmp.couleur) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
                verif = VRAI;
            }

            if (x == x0 && (y0 - y) == -1 && (echiquier[y][x].aff == ' ')) {
                verif = VRAI;
            }

        } else {
            if ((y0 - y) == -1 && abs(x - x0) == 1 && (echiquier[y][x].couleur != tmp.couleur) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
                verif = VRAI;
            }

            if (x == x0 && (y0 - y) == -1 && (echiquier[y][x].aff == ' ')) {
                verif = VRAI;
            }
        }
    }

    if (echiquier[y0][x0].couleur == BLANC) {
        if (echiquier[y0][x0].coup == 0) {

            if (y0 == taille - 2) {
                if ((y0 - y == 2 || y0 - y == 1) && x == x0) {
                    verif = VRAI;
                }
            }

            if ((y0 - y) == 1 && abs(x - x0) == 1 && (echiquier[y][x].couleur != tmp.couleur) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
                verif = VRAI;
            }

            if (x == x0 && (y0 - y) == 1 && (echiquier[y][x].aff == ' ')) {
                verif = VRAI;
            }

        } else {
            if ((y0 - y) == 1 && abs(x - x0) == 1 && (echiquier[y][x].couleur != tmp.couleur) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur)) {
                verif = VRAI;
            }

            if (x == x0 && (y0 - y) == 1 && (echiquier[y][x].aff == ' ')) {
                verif = VRAI;
            }
        }
    }

    return verif;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Verification des mouvements d'un Roi
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver --> Coordonnée d'arrivée entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non
 */
Bool RoiVerification(Coord coordonneedepart, Coord coordonneearriver, Piece** echiquier)
{

    Bool verif = FAUX;

    int y0 = coordonneedepart.y;
    int x0 = coordonneedepart.x;
    int y = coordonneearriver.y;
    int x = coordonneearriver.x;

    if ((x0 == x && abs(y0 - y) == 1 && echiquier[y0][x0].couleur != echiquier[y][x].couleur) || (y0 == y && abs(x0 - x) == 1 && echiquier[y0][x0].couleur != echiquier[y][x].couleur)) {

        verif = VRAI;
    } else {
        if ((abs(x0 - x) == abs(y0 - y)) && echiquier[y0][x0].couleur != echiquier[y][x].couleur) {
            verif = VRAI;
        }
    }

    return verif;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Verification des mouvements d'une Reine
 *
 * @param coordonneedepart --> Coordonnée de départ entrée par l'utilisateur
 * @param coordonneearriver--> Coordonnée d'arrivée entrée par l'utilisateur
 * @param echiquier -->  tableau de structure de pièces
 * @return Bool --> indique si le coup est possible ou non
 */
Bool DameVerification(Coord coordonneedepart, Coord coordonneearriver, Piece** echiquier)
{

    Bool verif = FAUX;
    Bool verifPartieFou = FAUX;
    Bool verifPartieTour = FAUX;

    verifPartieFou = FouVerification(coordonneedepart, coordonneearriver, echiquier);
    verifPartieTour = TourVerification(coordonneedepart, coordonneearriver, echiquier);

    if (verifPartieFou || verifPartieTour) {
        verif = VRAI;
    }

    return verif;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Donne la position du Roi à l'instant t
 *
 * @param CoordonneeRoi --> Coordonnée du roi à modifier après mouvement
 * @param Roi --> Couleur du Roi en question
 * @param taille--> taille de l'échiquier (6 x 6 par exemple)
 * @param echiquier --> Structure de Piece
 */
void PositionRoi(Coord CoordonneeRoi, Couleur Roi, int taille, Piece** echiquier)
{

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (echiquier[i][j].couleur == Roi && echiquier[i][j].nom == ROI) {
                CoordonneeRoi.y = i;
                CoordonneeRoi.x = j;
            }
        }
    }
}

/***********************************************************************************************************************************************************************/
/**
 * @brief Fonction utile pour la fonction EchecRoi, regroupe les mouvements de toutes les pièces
 *
 * @param taille --> taille de l'échiquier (6 x 6 par exemple)
 * @param coordonnee --> Coordonnée de la case actuelle où l'on veut appliquer la fonction
 * @param coordonneeRoi--> Coordonnées aux quelles on vérifie si le roi peut être en échec
 * @param echiquier -->  Structure de Piece
 * @return Bool --> Indique si le roi est en echec par la pièce concernée
 */
Bool MouvementPieceEchec(int taille, Coord coordonnee, Coord coordonneeRoi, Piece** echiquier)
{

    int l = coordonnee.y; // l pour lignes
    int c = coordonnee.x; // c pour colonnes
    Bool verif = FAUX;

    if (echiquier[l][c].nom == PION) {
        verif = PionVerification(coordonnee, coordonneeRoi, taille, echiquier);
    }
    if (echiquier[l][c].nom == CAVALIER) {
        verif = CavalierVerification(coordonnee, coordonneeRoi, echiquier);
    }
    if (echiquier[l][c].nom == FOU) {
        verif = FouVerification(coordonnee, coordonneeRoi, echiquier);
    }
    if (echiquier[l][c].nom == TOUR) {
        verif = TourVerification(coordonnee, coordonneeRoi, echiquier);
    }
    if (echiquier[l][c].nom == DAME) {
        verif = DameVerification(coordonnee, coordonneeRoi, echiquier);
    }

    if (echiquier[l][c].nom == ROI) {
        verif = RoiVerification(coordonnee, coordonneeRoi, echiquier);
    }

    return verif;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Fonction qui indique si le roi d'une couleur (NOIR ou BLANC) est en échec à un moment donné
 *
 * @param taille --> taille de l'échiquier (6 x 6 par exemple)
 * @param CoordonneeRoi --> Coordonnées du Roi dont on vérifie l'echec potentiel
 * @param echiquier -->  Structure de Piece
 * @param MiseEnEchec --> Couleur du Roi mis en échec potentiel
 * @param MetEnEchec --> Couleur de la pièce qui met en échec
 * @param tailleTabtmp --> Tailledu Tableau qui met en echec le roi
 * @return Coord* --> tableau de coordonnée de chaque pièce mettant en échec le roi
 */
Coord* EchecRoi(int taille, Coord CoordonneRoi, Piece** echiquier, Couleur MiseEnEchec, Couleur MetEnEchec, int* tailleTabtmp)
{

    Bool verif = FAUX;
    Coord Coordonnee;
    *tailleTabtmp = 1;
    int taillel = *tailleTabtmp;

    Coord* TabPieceEchec = (Coord*) malloc(sizeof(Coord) * taillel);

    if (TabPieceEchec != NULL) {
        TabPieceEchec = NULL;
        for (int i = 0; i < taille; i++) {

            for (int j = 0; j < taille; j++) {
                verif = FAUX;
                if (echiquier[i][j].couleur == MetEnEchec && echiquier[i][j].aff != ' ') {

                    Coordonnee.y = i;
                    Coordonnee.x = j;
                    verif = MouvementPieceEchec(taille, Coordonnee, CoordonneRoi, echiquier);

                    if (verif) {

                        if (taillel > 1) {

                            TabPieceEchec = realloc(TabPieceEchec, sizeof(Coord) * taillel);
                            TabPieceEchec[taillel - 1].y = i;
                            TabPieceEchec[taillel - 1].x = j;
                            taillel++;
                        }

                        if (taillel == 1) {
                            TabPieceEchec[taillel - 1].y = i;
                            TabPieceEchec[taillel - 1].x = j;
                            taillel++;
                        }
                    }
                }
            }
        }
    }

    if (TabPieceEchec == NULL) {
        free(TabPieceEchec);
        TabPieceEchec = NULL;
        *tailleTabtmp = 0;
    }

    *tailleTabtmp = taillel - 1;

    return TabPieceEchec;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Fonction servant dans EchecEtMat et dans le main -->indique si le Roi est bloqué à  sa place ou peut se déplacer en cas d'echec
 *
 * @param taille --> taille de l'échiquier (6 x 6 par exemple)
 * @param CoordonneRoi  --> Coordonnées du Roi qui est en echec
 * @param MiseEnEchec--> Couleur du Roi mis en échec
 * @param MetEnEchec --> Couleur de la pièce qui met en échec
 * @param echiquier -->  Structure de Piece
 * @return Bool --> Ressort Vrai si le roi peut se déplacer, l'inverse sinon
 */
Bool RoiMouvementElementaire(int taille, Coord CoordonneRoi, Couleur MiseEnEchec, Couleur MetEnEchec, Piece** echiquier)
{

    Bool verif = FAUX;
    Coord* TabPieceEchec;
    int tailleuseless;
    int yR = CoordonneRoi.y;
    int xR = CoordonneRoi.x;
    Coord  NewCoordonneeRoi;
    Piece vide;
    vide.nom = 0;
    vide.couleur = 2;
    vide.aff = ' ';
    Piece tmp;

    if (yR - 1 >= 0 && xR == CoordonneRoi.x && echiquier[yR - 1][xR].couleur != MiseEnEchec) {

        NewCoordonneeRoi.y = yR - 1;
        NewCoordonneeRoi.x = xR;
        tmp = echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x];
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = vide;
        TabPieceEchec = EchecRoi(taille, NewCoordonneeRoi, echiquier, MiseEnEchec, MetEnEchec, &tailleuseless);
        if (TabPieceEchec == NULL) {
            verif = VRAI;
            echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
            return verif;
        }
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
        freeTab(&TabPieceEchec, tailleuseless);
    }
    if (yR + 1 < taille && xR == CoordonneRoi.x && echiquier[yR + 1][xR].couleur != MiseEnEchec) {

        NewCoordonneeRoi.y = yR + 1;
        NewCoordonneeRoi.x = xR;
        tmp = echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x];
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = vide;
        TabPieceEchec = EchecRoi(taille, NewCoordonneeRoi, echiquier, MiseEnEchec, MetEnEchec, &tailleuseless);

        if (TabPieceEchec == NULL) {
            verif = VRAI;
            echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
            return verif;
        }
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
        freeTab(&TabPieceEchec, tailleuseless);
    }

    if (xR - 1 >= 0 && yR == CoordonneRoi.y && echiquier[yR][xR - 1].couleur != MiseEnEchec) {
        NewCoordonneeRoi.y = yR;
        NewCoordonneeRoi.x = xR - 1;
        tmp = echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x];
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = vide;
        TabPieceEchec = EchecRoi(taille, NewCoordonneeRoi, echiquier, MiseEnEchec, MetEnEchec, &tailleuseless);

        if (TabPieceEchec == NULL) {
            verif = VRAI;
            echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
            return verif;
        }
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
        freeTab(&TabPieceEchec, tailleuseless);
    }

    if (xR + 1 < taille && yR == CoordonneRoi.y && echiquier[yR][xR + 1].couleur != MiseEnEchec) {

        NewCoordonneeRoi.y = yR;
        NewCoordonneeRoi.x = xR + 1;
        tmp = echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x];
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = vide;
        TabPieceEchec = EchecRoi(taille, NewCoordonneeRoi, echiquier, MiseEnEchec, MetEnEchec, &tailleuseless);

        if (TabPieceEchec == NULL) {
            verif = VRAI;
            echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
            return verif;
        }
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
        freeTab(&TabPieceEchec, tailleuseless);
    }
    if (yR - 1 >= 0 && xR - 1 >= 0 && echiquier[yR - 1][xR - 1].couleur != MiseEnEchec) {

        NewCoordonneeRoi.y = yR - 1;
        NewCoordonneeRoi.x = xR - 1;
        tmp = echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x];
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = vide;
        TabPieceEchec = EchecRoi(taille, NewCoordonneeRoi, echiquier, MiseEnEchec, MetEnEchec, &tailleuseless);

        if (TabPieceEchec == NULL) {
            verif = VRAI;
            echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
            return verif;
        }
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
        freeTab(&TabPieceEchec, tailleuseless);
    }
    if (yR - 1 >= 0 && xR + 1 < taille && echiquier[yR - 1][xR + 1].couleur != MiseEnEchec) {

        NewCoordonneeRoi.y = yR - 1;
        NewCoordonneeRoi.x = xR + 1;
        tmp = echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x];
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = vide;
        TabPieceEchec = EchecRoi(taille, NewCoordonneeRoi, echiquier, MiseEnEchec, MetEnEchec, &tailleuseless);

        if (TabPieceEchec == NULL) {
            verif = VRAI;
            echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
            return verif;
        }
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
        freeTab(&TabPieceEchec, tailleuseless);
    }
    if (yR + 1 < taille && xR + 1 < taille && echiquier[yR + 1][xR + 1].couleur != MiseEnEchec) {

        NewCoordonneeRoi.y = yR + 1;
        NewCoordonneeRoi.x = xR + 1;
        tmp = echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x];
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = vide;
        TabPieceEchec = EchecRoi(taille, NewCoordonneeRoi, echiquier, MiseEnEchec, MetEnEchec, &tailleuseless);

        if (TabPieceEchec == NULL) {
            verif = VRAI;
            echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
            return verif;
        }
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
        freeTab(&TabPieceEchec, tailleuseless);
    }
    if (yR + 1 < taille && xR - 1 >= 0 && echiquier[yR + 1][xR - 1].couleur != MiseEnEchec) {

        NewCoordonneeRoi.y = yR + 1;
        NewCoordonneeRoi.x = xR - 1;
        tmp = echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x];
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = vide;
        TabPieceEchec = EchecRoi(taille, NewCoordonneeRoi, echiquier, MiseEnEchec, MetEnEchec, &tailleuseless);

        if (TabPieceEchec == NULL) {
            verif = VRAI;
            echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
            return verif;
        }
        echiquier[NewCoordonneeRoi.y][NewCoordonneeRoi.x] = tmp;
        freeTab(&TabPieceEchec, tailleuseless);
    }
    return verif;
}
/***********************************************************************************************************************************************************************/
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
Bool EchecEtMatContre(int taille, Piece** echiquier, Coord coordonneePieceMetenEchec, Couleur MetEnEchec, Couleur MisenEchec, Coord coordonneeRoi)
{

    Piece tmp; // utile pour les verifications
    Bool verif = FAUX;
    Bool verifEchecRoi = VRAI;
    int yp = coordonneePieceMetenEchec.y;
    int xp = coordonneePieceMetenEchec.x;
    Coord* TabPieceProtegeRoi; // utile pour stockée les coordonnées des pièces qui peuvent éventuellement protéger le
                              // Roi en prise
    int tailleTab = 0;
    Coord* tabok;
    int Tailletabok = 0; // useless
    int i = 0;
    Coord CoordonneeVerif;

    if (echiquier[yp][xp].nom == CAVALIER || echiquier[yp][xp].nom == PION) {
        i = 0;
        TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec,&tailleTab); // ici la fonction echec Roi est utilisé à l'inverse de son usage principale: c'est à dire qu'on chercher quelles pièces de la couleur du Roi mis en Echec peuvent contrer cette echec 
                        

        if (TabPieceProtegeRoi != NULL) { // Finalité --> dire si une pièce de la couleur du ROI peut prendre la pièce en question
            tmp = echiquier[yp][xp];

            while (i < tailleTab && verifEchecRoi) {

                CoordonneeVerif.y = TabPieceProtegeRoi[i].y;
                CoordonneeVerif.x = TabPieceProtegeRoi[i].x;
                Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                if (tabok == NULL) {
                    verifEchecRoi = FAUX;
                }
                Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                    echiquier); // on remet la pièce à  sa place fin de vérification
                echiquier[yp][xp] = tmp; // on remet à sa place la pièce

                if (verifEchecRoi == VRAI) {
                    freeTab(&tabok, Tailletabok);
                    Tailletabok = 0;
                }
                i++;
            }

            if (i < tailleTab) {
                verif = VRAI;
            }
        }

        freeTab(&TabPieceProtegeRoi, tailleTab);
        tailleTab = 0;
    }

    if (echiquier[yp][xp].nom == TOUR) {

        int h = 0; // indique le sens de déplacement ici vertical (sur une hauteur)
        int l = 0; // horizontal (sur une lignes);

        if (xp == coordonneeRoi.x) {

            h = abs(coordonneeRoi.y - yp);
            if (yp < coordonneeRoi.y) {

                for (int k = 0; k < h; k++) {

                    coordonneePieceMetenEchec.y = yp + k;
                    tmp = echiquier[yp + k][xp];
                    i = 0;
                    TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);

                    if (TabPieceProtegeRoi != NULL) {
                        while (i < tailleTab && verifEchecRoi) {

                            CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                            CoordonneeVerif.x = TabPieceProtegeRoi[i].x;
                            Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                            tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                            if (tabok == NULL) {
                                verifEchecRoi = FAUX;
                            }
                            Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                                echiquier); // on remet la pièce à  sa place fin de vérification
                            echiquier[yp + k][xp] = tmp; // on remet à sa place la pièce
                            if (verifEchecRoi == VRAI) {

                                freeTab(&tabok, Tailletabok);
                                Tailletabok = 0;
                            }
                            i++;
                        }

                        if (i < tailleTab) {
                            verif = VRAI;
                            freeTab(&TabPieceProtegeRoi, tailleTab);
                            tailleTab = 0;
                            return verif;
                        }
                    }
                }
            } else {

                for (int k = 0; k < h; k++) {
                    coordonneePieceMetenEchec.y = yp + k;
                    tmp = echiquier[yp - k][xp];
                    i = 0;
                    TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                    if (TabPieceProtegeRoi != NULL) {
                        while (i < tailleTab && verifEchecRoi) {

                            CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                            CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                            Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                            tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                            if (tabok == NULL) {
                                verifEchecRoi = FAUX;
                            }
                            Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                                echiquier); // on remet la pièce à  sa place fin de vérification
                            echiquier[yp - k][xp] = tmp; // on remet à sa place la pièce
                            if (verifEchecRoi == VRAI) {

                                freeTab(&tabok, Tailletabok);
                                Tailletabok = 0;
                            }
                            i++;
                        }
                        if (i < tailleTab) {
                            verif = VRAI;
                            freeTab(&TabPieceProtegeRoi, tailleTab);
                            tailleTab = 0;
                            return verif;
                        }
                    }
                }
            }
        }
        if (yp == coordonneeRoi.y) {
            l = abs(coordonneeRoi.x - xp);
            if (xp < coordonneeRoi.x) {

                for (int k = 0; k < l; k++) {
                    coordonneePieceMetenEchec.x = xp + k;
                    tmp = echiquier[yp][xp + k];
                    i = 0;
                    TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                    if (TabPieceProtegeRoi != NULL) {
                        while (i < tailleTab && verifEchecRoi) {

                            CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                            CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                            Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                            tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                            if (tabok == NULL) {
                                verifEchecRoi = FAUX;
                            }
                            Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                                echiquier); // on remet la pièce à  sa place fin de vérification
                            echiquier[yp][xp + k] = tmp; // on remet à sa place la pièce

                            if (verifEchecRoi == VRAI) {

                                freeTab(&tabok, Tailletabok);
                                Tailletabok = 0;
                            }
                            i++;
                        }
                        if (i < tailleTab) {
                            verif = VRAI;
                            freeTab(&TabPieceProtegeRoi, tailleTab);
                            tailleTab = 0;
                            return verif;
                        }
                    }
                }
            } else {

                for (int k = 0; k < l; k++) {
                    coordonneePieceMetenEchec.x = xp - k;
                    tmp = echiquier[yp][xp - k];
                    i = 0;
                    TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                    if (TabPieceProtegeRoi != NULL) {
                        while (i < tailleTab && verifEchecRoi) {

                            CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                            CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                            Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                            tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                            if (tabok == NULL) {
                                verifEchecRoi = FAUX;
                            }
                            Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                                echiquier); // on remet la pièce à  sa place fin de vérification
                            echiquier[yp][xp - k] = tmp; // on remet à sa place la pièce
                            if (verifEchecRoi == VRAI) {

                                freeTab(&tabok, Tailletabok);
                                Tailletabok = 0;
                            }
                            i++;
                        }
                        if (i < tailleTab) {
                            verif = VRAI;
                            freeTab(&TabPieceProtegeRoi, tailleTab);
                            tailleTab = 0;
                            return verif;
                        }
                    }
                }
            }
        }
    }

    if (echiquier[yp][xp].nom == FOU) {

        int dsg = 0; // diagonal supérieur gauche, va être utile pour l'écart de case entre le roi et le fou en question
        int dsd = 0;
        int dig = 0;//diagonal inférieur droite 
        int did = 0;

        if (xp - coordonneeRoi.x < 0 && yp - coordonneeRoi.y < 0) {
            dsg = abs(yp - coordonneeRoi.y);

            for (int k = 0; k < dsg; k++) {
                coordonneePieceMetenEchec.y = yp + k;
                coordonneePieceMetenEchec.x = xp + k;
                tmp = echiquier[yp + k][xp + k];
                i = 0;
                TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                if (TabPieceProtegeRoi != NULL) {
                    while (i < tailleTab && verifEchecRoi) {

                        CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                        CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                        Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                        tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                        if (tabok == NULL) {
                            verifEchecRoi = FAUX;
                        }
                        Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                            echiquier); // on remet la pièce à  sa place fin de vérification
                        echiquier[yp + k][xp + k] = tmp; // on remet à sa place la pièce
                        if (verifEchecRoi == VRAI) {
                            freeTab(&tabok, Tailletabok);
                            Tailletabok = 0;
                        }
                        i++;
                    }
                    if (i < tailleTab) {
                        verif = VRAI;
                        freeTab(&TabPieceProtegeRoi, tailleTab);
                        tailleTab = 0;
                        return verif;
                    }
                }
            }
        }

        if (xp - coordonneeRoi.x > 0 && yp - coordonneeRoi.y < 0) {
            dsd = abs(yp - coordonneeRoi.y);

            for (int k = 0; k < dsd; k++) {
                coordonneePieceMetenEchec.y = yp + k;
                coordonneePieceMetenEchec.x = xp - k;
                tmp = echiquier[yp + k][xp - k];
                i = 0;
                TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                if (TabPieceProtegeRoi != NULL) {
                    while (i < tailleTab && verifEchecRoi) {

                        CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                        CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                        Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                        tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                        if (tabok == NULL) {
                            verifEchecRoi = FAUX;
                        }
                        Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                            echiquier); // on remet la pièce à  sa place fin de vérification
                        echiquier[yp + k][xp - k] = tmp; // on remet à sa place la pièce

                        if (verifEchecRoi == VRAI) {
                            freeTab(&tabok, Tailletabok);
                            Tailletabok = 0;
                        }
                        i++;
                    }
                    if (i < tailleTab) {
                        verif = VRAI;
                        freeTab(&TabPieceProtegeRoi, tailleTab);
                        tailleTab = 0;
                        return verif;
                    }
                }
            }
        }
        if (xp - coordonneeRoi.x < 0 && yp - coordonneeRoi.y > 0) {
            dig = abs(yp - coordonneeRoi.y);

            for (int k = 0; k < dig; k++) {
                coordonneePieceMetenEchec.y = yp - k;
                coordonneePieceMetenEchec.x = xp + k;
                tmp = echiquier[yp - k][xp + k];
                i = 0;
                TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                if (TabPieceProtegeRoi != NULL) {
                    while (i < tailleTab && verifEchecRoi) {

                        CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                        CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                        Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                        tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                        if (tabok == NULL) {
                            verifEchecRoi = FAUX;
                        }
                        Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                            echiquier); // on remet la pièce à  sa place fin de vérification
                        echiquier[yp - k][xp + k] = tmp; // on remet à sa place la pièce

                        if (verifEchecRoi == VRAI) {
                            freeTab(&tabok, Tailletabok);
                            Tailletabok = 0;
                        }
                        i++;
                    }
                    if (i < tailleTab) {
                        verif = VRAI;

                        freeTab(&TabPieceProtegeRoi, tailleTab);
                        tailleTab = 0;
                        return verif;
                    }
                }
            }
        }
        if (xp - coordonneeRoi.x > 0 && yp - coordonneeRoi.y > 0) {

            did = abs(yp - coordonneeRoi.y);

            for (int k = 0; k < did; k++) {
                coordonneePieceMetenEchec.y = yp - k;
                coordonneePieceMetenEchec.x = xp - k;
                tmp = echiquier[yp - k][xp - k];
                i = 0;
                TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                if (TabPieceProtegeRoi != NULL) {
                    while (i < tailleTab && verifEchecRoi) {

                        CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                        CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                        Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                        tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                        if (tabok == NULL) {
                            verifEchecRoi = FAUX;
                        }
                        Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                            echiquier); // on remet la pièce à  sa place fin de vérification
                        echiquier[yp - k][xp - k] = tmp; // on remet à sa place la pièce

                        if (verifEchecRoi == VRAI) {
                            freeTab(&tabok, Tailletabok);
                            Tailletabok = 0;
                        }

                        i++;
                    }
                    if (i < tailleTab) {
                        verif = VRAI;

                        freeTab(&TabPieceProtegeRoi, tailleTab);
                        tailleTab = 0;

                        return verif;
                    }
                }
            }
        }
    }

    if (echiquier[yp][xp].nom == DAME) {

        int dsg = 0; // diagonal supérieur gauche vat être utile pour l'écart de case entre le roi et le fou en question
        int dsd = 0;
        int dig = 0;
        int did = 0;
        int h = 0;
        int l = 0;

        if (xp == coordonneeRoi.x) {

            h = abs(coordonneeRoi.y - yp);
            if (yp < coordonneeRoi.y) {

                for (int k = 0; k < h; k++) {

                    coordonneePieceMetenEchec.y = yp + k;
                    tmp = echiquier[yp + k][xp];
                    i = 0;
                    TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);

                    if (TabPieceProtegeRoi != NULL) {
                        while (i < tailleTab && verifEchecRoi) {

                            CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                            CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                            Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                            tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                            if (tabok == NULL) {
                                verifEchecRoi = FAUX;
                            }
                            Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                                echiquier); // on remet la pièce à  sa place fin de vérification
                            echiquier[yp + k][xp] = tmp; // on remet à sa place la pièce
                            if (verifEchecRoi == VRAI) {

                                freeTab(&tabok, Tailletabok);
                                Tailletabok = 0;
                            }
                            i++;
                        }

                        if (i < tailleTab) {
                            verif = VRAI;
                            freeTab(&TabPieceProtegeRoi, tailleTab);
                            tailleTab = 0;
                            return verif;
                        }
                    }
                }
            } else {

                for (int k = 0; k < h; k++) {
                    coordonneePieceMetenEchec.y = yp + k;
                    tmp = echiquier[yp - k][xp];
                    i = 0;
                    TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                    if (TabPieceProtegeRoi != NULL) {
                        while (i < tailleTab && verifEchecRoi) {

                            CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                            CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                            Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                            tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                            if (tabok == NULL) {
                                verifEchecRoi = FAUX;
                            }
                            Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                                echiquier); // on remet la pièce à  sa place fin de vérification
                            echiquier[yp - k][xp] = tmp; // on remet à sa place la pièce
                            if (verifEchecRoi == VRAI) {

                                freeTab(&tabok, Tailletabok);
                                Tailletabok = 0;
                            }
                            i++;
                        }
                        if (i < tailleTab) {
                            verif = VRAI;
                            freeTab(&TabPieceProtegeRoi, tailleTab);
                            tailleTab = 0;
                            return verif;
                        }
                    }
                }
            }
        }
        if (yp == coordonneeRoi.y) {
            l = abs(coordonneeRoi.x - xp);
            if (xp < coordonneeRoi.x) {

                for (int k = 0; k < l; k++) {
                    coordonneePieceMetenEchec.x = xp + k;
                    tmp = echiquier[yp][xp + k];
                    i = 0;
                    TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                    if (TabPieceProtegeRoi != NULL) {
                        while (i < tailleTab && verifEchecRoi) {

                            CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                            CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                            Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                            tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                            if (tabok == NULL) {
                                verifEchecRoi = FAUX;
                            }
                            Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                                echiquier); // on remet la pièce à  sa place fin de vérification
                            echiquier[yp][xp + k] = tmp; // on remet à sa place la pièce

                            if (verifEchecRoi == VRAI) {

                                freeTab(&tabok, Tailletabok);
                                Tailletabok = 0;
                            }
                            i++;
                        }
                        if (i < tailleTab) {
                            verif = VRAI;
                            freeTab(&TabPieceProtegeRoi, tailleTab);
                            tailleTab = 0;
                            return verif;
                        }
                    }
                }
            } else {

                for (int k = 0; k < l; k++) {
                    coordonneePieceMetenEchec.x = xp - k;
                    tmp = echiquier[yp][xp - k];
                    i = 0;
                    TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                    if (TabPieceProtegeRoi != NULL) {
                        while (i < tailleTab && verifEchecRoi) {

                            CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                            CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                            Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                            tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                            if (tabok == NULL) {
                                verifEchecRoi = FAUX;
                            }
                            Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                                echiquier); // on remet la pièce à  sa place fin de vérification
                            echiquier[yp][xp - k] = tmp; // on remet à sa place la pièce
                            if (verifEchecRoi == VRAI) {

                                freeTab(&tabok, Tailletabok);
                                Tailletabok = 0;
                            }
                            i++;
                        }
                        if (i < tailleTab) {
                            verif = VRAI;
                            freeTab(&TabPieceProtegeRoi, tailleTab);
                            tailleTab = 0;
                            return verif;
                        }
                    }
                }
            }
        }
        if (xp - coordonneeRoi.x < 0 && yp - coordonneeRoi.y < 0) {
            dsg = abs(yp - coordonneeRoi.y);

            for (int k = 0; k < dsg; k++) {
                coordonneePieceMetenEchec.y = yp + k;
                coordonneePieceMetenEchec.x = xp + k;
                tmp = echiquier[yp + k][xp + k];
                i = 0;
                TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                if (TabPieceProtegeRoi != NULL) {
                    while (i < tailleTab && verifEchecRoi) {

                        CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                        CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                        Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                        tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                        if (tabok == NULL) {
                            verifEchecRoi = FAUX;
                        }
                        Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                            echiquier); // on remet la pièce à  sa place fin de vérification
                        echiquier[yp + k][xp + k] = tmp; // on remet à sa place la pièce
                        if (verifEchecRoi == VRAI) {
                            freeTab(&tabok, Tailletabok);
                            Tailletabok = 0;
                        }
                        i++;
                    }
                    if (i < tailleTab) {
                        verif = VRAI;
                        freeTab(&TabPieceProtegeRoi, tailleTab);
                        tailleTab = 0;
                        return verif;
                    }
                }
            }
        }

        if (xp - coordonneeRoi.x > 0 && yp - coordonneeRoi.y < 0) {
            dsd = abs(yp - coordonneeRoi.y);

            for (int k = 0; k < dsd; k++) {
                coordonneePieceMetenEchec.y = yp + k;
                coordonneePieceMetenEchec.x = xp - k;
                tmp = echiquier[yp + k][xp - k];
                i = 0;
                TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                if (TabPieceProtegeRoi != NULL) {
                    while (i < tailleTab && verifEchecRoi) {

                        CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                        CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                        Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                        tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                        if (tabok == NULL) {
                            verifEchecRoi = FAUX;
                        }
                        Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                            echiquier); // on remet la pièce à  sa place fin de vérification
                        echiquier[yp + k][xp - k] = tmp; // on remet à sa place la pièce

                        if (verifEchecRoi == VRAI) {
                            freeTab(&tabok, Tailletabok);
                            Tailletabok = 0;
                        }
                        i++;
                    }
                    if (i < tailleTab) {
                        verif = VRAI;
                        freeTab(&TabPieceProtegeRoi, tailleTab);
                        tailleTab = 0;
                        return verif;
                    }
                }
            }
        }
        if (xp - coordonneeRoi.x < 0 && yp - coordonneeRoi.y > 0) {
            dig = abs(yp - coordonneeRoi.y);

            for (int k = 0; k < dig; k++) {
                coordonneePieceMetenEchec.y = yp - k;
                coordonneePieceMetenEchec.x = xp + k;
                tmp = echiquier[yp - k][xp + k];
                i = 0;
                TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                if (TabPieceProtegeRoi != NULL) {
                    while (i < tailleTab && verifEchecRoi) {

                        CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                        CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                        Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                        tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                        if (tabok == NULL) {
                            verifEchecRoi = FAUX;
                        }
                        Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                            echiquier); // on remet la pièce à  sa place fin de vérification
                        echiquier[yp - k][xp + k] = tmp; // on remet à sa place la pièce

                        if (verifEchecRoi == VRAI) {
                            freeTab(&tabok, Tailletabok);
                            Tailletabok = 0;
                        }
                        i++;
                    }
                    if (i < tailleTab) {
                        verif = VRAI;

                        freeTab(&TabPieceProtegeRoi, tailleTab);
                        tailleTab = 0;
                        return verif;
                    }
                }
            }
        }
        if (xp - coordonneeRoi.x > 0 && yp - coordonneeRoi.y > 0) {

            did = abs(yp - coordonneeRoi.y);

            for (int k = 0; k < did; k++) {
                coordonneePieceMetenEchec.y = yp - k;
                coordonneePieceMetenEchec.x = xp - k;
                tmp = echiquier[yp - k][xp - k];
                i = 0;
                TabPieceProtegeRoi = EchecRoi(taille, coordonneePieceMetenEchec, echiquier, MetEnEchec, MisenEchec, &tailleTab);
                if (TabPieceProtegeRoi != NULL) {
                    while (i < tailleTab && verifEchecRoi) {

                        CoordonneeVerif.y = TabPieceProtegeRoi[i].y; // pièce qui protege le roi
                        CoordonneeVerif.y = TabPieceProtegeRoi[i].x;
                        Mouvement(CoordonneeVerif, coordonneePieceMetenEchec, echiquier);
                        tabok = EchecRoi(taille, coordonneeRoi, echiquier, MisenEchec, MetEnEchec, &Tailletabok);
                        if (tabok == NULL) {
                            verifEchecRoi = FAUX;
                        }
                        Mouvement(coordonneePieceMetenEchec, CoordonneeVerif,
                            echiquier); // on remet la pièce à  sa place fin de vérification
                        echiquier[yp - k][xp - k] = tmp; // on remet à sa place la pièce

                        if (verifEchecRoi == VRAI) {
                            freeTab(&tabok, Tailletabok);
                            Tailletabok = 0;
                        }

                        i++;
                    }
                    if (i < tailleTab) {
                        verif = VRAI;

                        freeTab(&TabPieceProtegeRoi, tailleTab);
                        tailleTab = 0;

                        return verif;
                    }
                }
            }
        }
    }
    return verif;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief Fonction primordiale pour la boucle de jeu
 *
 * @param taille  --> taille de l'échiquier (6 x 6 par exemple)
 * @param CoordonneRoi --> Coordonnées du Roi qui est en echec
 * @param MiseEnEchec --> Couleur du Roi mis en échec
 * @param MetEnEchec  --> Couleur du Roi qui met en échec
 * @param echiquier -->  Structure de Piece
 * @return Bool --> ressort VRAI si le roi est en echec et mat
 */
Bool EchecEtMat(int taille, Coord CoordonneRoi, Couleur MiseEnEchec, Couleur MetEnEchec, Piece** echiquier)
{
    Bool verif = FAUX;
    Bool verifMvtElementaire = FAUX;
    Bool verifContre = FAUX;
    Coord* TabEchec;
    int tailletableau = 0;
    Coord CoordonnePieceMetEnEchec; // dans le cas où le roi serait effectivement en echec et qu'il ne peut
                                     // bouger
    TabEchec = EchecRoi(taille, CoordonneRoi, echiquier, MiseEnEchec, MetEnEchec, &tailletableau);

    if (TabEchec != NULL) {
        CoordonnePieceMetEnEchec.y = TabEchec[0].y;
        CoordonnePieceMetEnEchec.x = TabEchec[0].x;
        verifMvtElementaire = RoiMouvementElementaire(taille, CoordonneRoi, MiseEnEchec, MetEnEchec, echiquier);

        if (verifMvtElementaire == FAUX) {
            if(MiseEnEchec == BLANC){
                printf("\nTu mets en echec le roi BLANC !\n");
            }else{
                printf("\nTu mets en echec le roi NOIR !\n");
            }
            verifContre = EchecEtMatContre(taille, echiquier, CoordonnePieceMetEnEchec, MetEnEchec, MiseEnEchec, CoordonneRoi);
            if (verifContre == FAUX) {
                verif = VRAI;
            }
        }else{
            
            if(MiseEnEchec == BLANC){
                printf("\nTu mets en echec le roi BLANC !\n");
            }else{
                printf("\nTu mets en echec le roi NOIR !\n");
            }
        }
        freeTab(&TabEchec, tailletableau);
        tailletableau = 0;
    }

    return verif;
}
/***********************************************************************************************************************************************************************/
/**
 * @brief free des tableaux à deux dimensions mallocer
 *
 * @param tab --> tableau de deux dimension d'entiers
 * @param tailleTab--> taille du tableau (première dimension)
 */
void freeTab(Coord** tab, int tailleTab)
{
    if (tab != NULL) {
        free(*tab);
        tab = NULL;
    }
}
/***********************************************************************************************************************************************************************/
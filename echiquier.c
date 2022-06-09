#include <echiquier.h>



/******************************************************************************************************/
/**
 * @brief Initialise un echiquier de la taille choisit
 *
 * @param taille -> taille de l'échiquier
 * @return Piece**
 */
Piece** initializeechiquier(int taille)
{

    char affichagePiece[] = { ' ', 'P', 'C', 'F', 'T', 'D', 'R' };

    Piece** echiquier = (Piece**)malloc(sizeof(Piece*) * taille);

    if (echiquier != NULL) {

        for (int i = 0; i < taille; i++) {

            echiquier[i] = (Piece*)malloc(sizeof(Piece) * taille);

            if (echiquier[i] != NULL) {
                for (int j = 0; j < taille; j++) {
                    if (i < 2) {

                        echiquier[i][j].couleur = NOIR;
                        echiquier[i][j].nom = (rand() % 5 + 1);
                        echiquier[i][j].coup = 0;
                    } else if (i >= taille - 2) {
                        echiquier[i][j].couleur = BLANC;
                        echiquier[i][j].nom = (rand() % 5 + 1);
                        echiquier[i][j].coup = 0;
                    } else {
                        echiquier[i][j].couleur = EMPTY;
                        echiquier[i][j].nom = VIDE;
                        echiquier[i][j].coup = 0;
                    }
                    echiquier[i][j].aff = affichagePiece[echiquier[i][j].nom];
                }
            } else {
                fprintf(stderr, "Les pieces n'ont pas ete attribuer");
            }
        }

        MiseEnPlaceRoi(echiquier, taille);
    } else {
        fprintf(stderr, "segmentation fault");
    }

    return echiquier;
}

/******************************************************************************************************/
/**
 * @brief Libère la mémoire alloué pour l'échiquier
 *
 * @param taille -> taille de l'échiquier
 * @param echiquier -> Tableau à  deux dimensions de structures
 */
void freechiquier(int taille, Piece*** echiquier)
{

    if (echiquier != NULL) {
        for (int i = 0; i < taille; i++) {
            if ((*echiquier)[i] != NULL) {
                free((*echiquier)[i]);
                (*echiquier)[i] = NULL;
            }
        }
        free(*echiquier);
        *echiquier = NULL;
    }
}


/******************************************************************************************************/
/**
 * @brief Utile dans InitializeEchiquier pour placer le roi à chaque début de partie
 *
 * @param echiquier--> structure de Pièce
 * @param taille --> taille de l'echiquier
 */
void MiseEnPlaceRoi(Piece** echiquier, int taille)
{

    char affichagePiece[] = { ' ', 'P', 'C', 'F', 'T', 'D', 'R' };
    int R = rand() % taille;

    echiquier[0][R].aff = affichagePiece[6];
    echiquier[taille - 1][R].aff = affichagePiece[6];

    echiquier[0][R].couleur = NOIR;
    echiquier[taille - 1][R].couleur = BLANC;

    echiquier[0][R].nom = ROI;
    echiquier[taille - 1][R].nom = ROI;

    echiquier[0][R].coup = 0;
    echiquier[taille - 1][R].coup = 0;
}

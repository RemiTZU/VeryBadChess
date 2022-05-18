#include <echiquier.h>

Piece **initializeechiquier(int taille)
{

    char affichagePiece[] = {' ', 'P', 'C', 'F', 'T', 'D', 'R'};

    Piece **echiquier = (Piece **)malloc(sizeof(Piece *) * taille);

    if (echiquier != NULL)
    {

        for (int i = 0; i < taille; i++)
        {

            echiquier[i] = (Piece *)malloc(sizeof(Piece) * taille);

            if (echiquier[i] != NULL)
            {
                for (int j = 0; j < taille; j++)
                {
                    if (i < 2)
                    {

                        echiquier[i][j].couleur = NOIR;
                        echiquier[i][j].nom = (rand() % 5 + 1);
                    }
                    else if (i >= taille - 2)
                    {
                        echiquier[i][j].couleur = BLANC;
                        echiquier[i][j].nom = (rand() % 5 + 1);
                    }
                    else
                    {
                        echiquier[i][j].couleur = EMPTY;
                        echiquier[i][j].nom = VIDE;
                    }
                    echiquier[i][j].aff = affichagePiece[echiquier[i][j].nom];
                }

            }else
            {
                fprintf(stderr, "Les pieces n'ont pas ete attribuer");
            }
            }
            echiquier[0][taille / 2].aff = affichagePiece[6];
            echiquier[taille - 1][taille / 2].aff = affichagePiece[6];
        }
        else
        {
            fprintf(stderr, "segmentation fault");
        }

        return echiquier;
}

void freechiquier(int taille, Piece ***echiquier)
{

    if (*echiquier != NULL)
    {
        for (int i = 0; i < taille; i++)
        {
            if ((*echiquier)[i] != NULL)
            {
                free((*echiquier)[i]);
                (*echiquier)[i] = NULL;
            }
        }
        free(*echiquier);
        *echiquier = NULL;
    }
}

void reverse(int taille, Piece **echiquier)
{

    Piece tmp;

    for (int i = 0; i < taille; i++)
    {

        for (int j = 0; j < taille / 2; j++)
        {

            tmp = echiquier[i][j];
            echiquier[i][j] = echiquier[i][taille - j - 1];
            echiquier[i][taille - j - 1] = tmp;
        }
    }

    for (int j = 0; j < taille; j++)
    {

        for (int i = 0; i < taille / 2; i++)
        {

            tmp = echiquier[i][j];
            echiquier[i][j] = echiquier[taille - i - 1][j];
            echiquier[taille - i - 1][j] = tmp;
        }
    }
}
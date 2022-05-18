#include <affichage.h>


void ecritureaffichage(char *ecriture, int motifascii)
{

    int size = strlen(ecriture);
    printf("%c", motifascii);

    for (int i = 0; i < size; i++)
    {
        
        printf("%c", ecriture[i]);
    }

    printf("%c", motifascii);
    printf("\n");
}

void affichage(int taille, Piece **echiquier)
{
    printf("\n");
    for (int i = 0; i < taille; i++)
    {

        if (taille - i >= 10) // Condition pour eviter un décalage à partir  de 10
        {
            printf("%d", taille - i); // Affichage des coordonnées en ordonnées de la grille
            printf("%c ", 179);
        }
        else
        {

            printf(" %d", taille - i);
            printf("%c ", 179);
        }

        for (int j = 0; j < taille; j++)
        {
            printf("[%c%c]", echiquier[i][j].aff, echiquier[i][j].couleur == BLANC ? 'B' : echiquier[i][j].couleur == NOIR ? 'N': ' ');
        }

        printf("\n");
    }

    printf("    %c", 196);
    for (int k = 0; k < ((taille)*4) - 1; k++)
    {
        printf("%c", 196);
    }

    printf("\n");

    printf("     %c", 65);

    for (int k = 0; k < taille - 1; k++)
    {
        printf("   %c", k + 66); // Affichage des coordonnées en absisses
    }
}
void asciiboucle(int taille, int motifascii, float temps)
{

    for (int i = 0; i < taille; i++)
    {
        
        printf("%c", motifascii);
    }
}

void menu()
{
    int longueur = 39;
    int ascii = 205;
    char *ecriture = "**********1.Lancer une partie**********";
    char *ecriture1 = "**********2.Relancer une partie********";
    char *ecriture2 = "**********3.Quitter********************";
    float temps = 10;

    system("cls");

    printf("%c", 201);
    asciiboucle(longueur, ascii, temps);
    printf("%c", 187);

    printf("\n");

    for (int i = 0; i < 2; i++)
    {

        
        printf("%c", 186);
        asciiboucle(longueur, 219, temps);
        
        printf("%c", 186);
        printf("\n");
    }

    ecritureaffichage(ecriture, 186, temps);
    ecritureaffichage(ecriture1, 186, temps);
    ecritureaffichage(ecriture2, 186, temps);

    for (int i = 0; i < 2; i++)
    {

        
        printf("%c", 186);
        asciiboucle(longueur, 219, temps);
        
        printf("%c", 186);
        printf("\n");
    }

    printf("%c", 200);
    asciiboucle(longueur, ascii, temps);
    printf("%c", 188);

    printf("\n");
}


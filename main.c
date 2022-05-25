#include <affichage.h>

int main()
{
    // int coordonneeinit[2];
    // int coordonneefin[2];
    int n = -1;
    int taille = 0;
    char rep[20];

    system("cls");
    printf("  _____ _____   _ \n");
    printf(" |_   _|_  | | | |\n");
    printf("   | |  / /| |_| |\n");
    printf("   |_| /___|\\___/\n ");

    printf("  ___      __            _       \n");
    printf(" | _ \\_ _ /_/ ______ _ _| |_ ___ \n");
    printf(" |  _| '_/ -_(_-/ -_| ' |  _/ -_)\n");
    printf(" |_| |_| \\___/__\\___|_||_\\__\\___|\n");

    printf(" __   __              ___         _    ___ _              \n");
    printf(" \\ \\ / ___ _ _ _  _  | _ )__ _ __| |  / __| |_  ___ ______\n");
    printf("  \\ V / -_| '_| || | | _ / _` / _` | | (__| ' \\/ -_(_-(_-<\n");
    printf("   \\_/\\___|_|  \\_, | |___\\__,_\\__,_|  \\___|_||_\\___/__/__/\n");
    printf("               |__/                                       \n");

    menu();

    scanf("%s", rep);
    fflush(stdin);

    if (sscanf(rep, "%d", &n) == EOF || n <= 0 || n > 3)
    {
        do
        {

            printf("Trois choix possible (1,2,3)\n");
            scanf("%s", rep);
            fflush(stdin);

        } while ((sscanf(rep, "%d", &n) == EOF || n <= 0 || n > 3));
    }

    switch (n)
    {
    case (1):
        printf("quelle taille de dechiquier voulez vous ?\n");
        scanf("%s", rep);
        fflush(stdin);

        if (sscanf(rep, "%d", &taille) == EOF || taille < 6 || taille > 12)
        {
            do
            {
                printf("Taille echiquier possible(6/7/8/9/10/11/12) \n");
                scanf("%s", rep);
                fflush(stdin);

            } while ((sscanf(rep, "%d", &taille) == EOF || taille < 6 || taille > 12));
        }

        system("cls");
        Piece **echiquier = initializeechiquier(taille);
        affichage(taille, echiquier);
        // Acompleter
        freechiquier(taille, &echiquier);
    case (2):
        // completer
        break;
    case (3):

        printf("Oh, dommage a bientot\n");
        break;
    }

    return EXIT_SUCCESS;
}
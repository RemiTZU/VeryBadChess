#include <affichage.h>

int main()
{
    int n = -1;
    int taille = 0;
    int tour = 0;
    char rep[20];
    Piece** echiquier;
    srand(time(NULL));

    // system("cls");
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

    if (sscanf(rep, "%d", &n) == EOF || n <= 0 || n > 3) {
        do {

            printf("Trois choix possibles (1,2,3)\n");
            scanf("%s", rep);
            fflush(stdin);

        } while ((sscanf(rep, "%d", &n) == EOF || n <= 0 || n > 3));
    }

    switch (n) {
    case (1):
        printf("Quelle taille de d'%cchiquier veux-tu ?\n", 130);
        scanf("%s", rep);
        fflush(stdin);

        if (sscanf(rep, "%d", &taille) == EOF || taille < 6 || taille > 12) {
            do {
                printf("Taille d'%cchiquier possible(6/7/8/9/10/11/12) \n", 130);
                scanf("%s", rep);
                fflush(stdin);

            } while ((sscanf(rep, "%d", &taille) == EOF || taille < 6 || taille > 12));
        }

        echiquier = initializeechiquier(taille);
        partie(taille, echiquier,tour);
        freechiquier(taille,&echiquier);
        break;

    case (2):
        echiquier = LectureSauvegarde("save.txt", &taille , &tour);
        if(echiquier == NULL){
            printf("\nAucune sauvegarde existente \n");
        }else{
            partie(taille,echiquier,tour);
            freechiquier(taille,&echiquier);
        }
       
        break;
    case (3):

        printf("Oh, dommage %c bientot\n", 133);
        break;
    }

    return EXIT_SUCCESS;
}

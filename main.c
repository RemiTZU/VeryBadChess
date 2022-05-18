#include <affichage.h>

int main()
{

    int n = -1;

    int taille = 0;
    char rep[20];
    menu();

    scanf("%s", rep);

    if (sscanf(rep, "%d", &n) == EOF || n <= 0 || n > 3)
    {
        do
        {
            printf("Trois choix possible (1,2,3)\n");
            scanf("%s", rep);

        } while ((sscanf(rep, "%d", &n) == EOF || n <= 0 || n > 3));
    }

    switch (n)
    {
    case (1):
        printf("quelle taille de dechiquier voulez vous ?\n");
        scanf("%s", rep);

        if (sscanf(rep, "%d", &taille) == EOF || taille < 6 || taille > 12)
        {
            do
            {
                printf("Taille echiquier possible(6/7/8/9/10/11/12) \n");
                scanf("%s", rep);

            } while ((sscanf(rep, "%d", &taille) == EOF || taille < 6 || taille > 12));
        }

        system("cls");
        Piece **echiquier = initializeechiquier(taille);
        affichage(taille, echiquier);
        // Acompleter 
        freechiquier(taille, &echiquier);
    case(2):
    //completer
    break;
    case(3):
        
        printf("Oh, dommage a bientot\n");
        return 0;
    }
   


}
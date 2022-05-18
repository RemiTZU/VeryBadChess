#include <jeu.h>

void acquisitioncoordonnees(int taille,int coordonnee[2])
{

    char rep[50];
    char abcissetmp;
    int abcisse;
    int ordonne;

    printf("rentrer une lettre pour les abcisses et un nombre pour les ordonn%ces\n", 130);

    scanf("%s", rep);

    while (sscanf(rep, "%c%d", &abcissetmp, &ordonne) == EOF || (abcissetmp < 65 || abcissetmp > taille + 65) || (ordonne < 0 || ordonne > taille))
    {
        printf("Oups, il semblerait que les coordonn%ces rentr%ce ne soit pas valide.(exemple de coordonn%ces valident #%c%d# pour la taille %d par %d)\n", 130, 130, 130,65,taille,taille,taille);
        scanf("%s", rep);
    }

    abcisse = abcissetmp;
    switchbase(&abcisse, &ordonne, taille);

    coordonnee[0] = ordonne;
    coordonnee[1] = abcisse;
}


void switchbase(int *abscisse, int *ordonnee, int taillechiquier)
{
    *abscisse = *abscisse - 65;
    *ordonnee = taillechiquier - *ordonnee;
}
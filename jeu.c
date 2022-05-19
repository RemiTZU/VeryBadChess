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


Bool FouMouvement(int coordonneedepart[2], int coordonneearriver[2], Piece **echiquier)
{

    Bool verif = FAUX;

    if (coordonneedepart[1] == coordonneearriver[1])
    {
        return verif; // We can't divide a number by 0, furthemore a bishop can't do this type of movement
    }

    int y0 = coordonneedepart[0];
    int x0 = coordonneedepart[1];
    int y = coordonneearriver[0];
    int x = coordonneearriver[1];
    int coeff = (y - y0) / (x - x0);
    int deltaY = (y - y0);

    if (abs(x0 - x) == abs(y0 - y))
    {

        if (coeff > 0 && deltaY < 0) // here we try to obtain the direction of the Bishop on the chessboard
        {
            int i = 1;

            while (((x0 - i != x) && (y0 - i != y)) && (echiquier[y0 - i][x0 - i].aff == ' ')) //carefull with the notation x and y (y represents the lines et x the columns of the chessboard)
            {
                i++;
            }                                                                                           
            verif = VerificationFou(i,y,y0,x,x0,echiquier);                                                                                                                                                                         
        }
        if (coeff > 0 && deltaY > 0)
        {
            int i = 1;

            while (((x0 + i != x) && (y0 + i != y)) && (echiquier[y0 + i][x0 + i].aff == ' '))
            {
                i++;
            }

            verif = VerificationFou(i,y,y0,x,x0,echiquier);   
        }
        if (coeff < 0 && deltaY < 0)
        {
            int i = 1;

            while (((x0 + i != x) && (y0 - i != y) && (echiquier[y0 - i][x0 + i].aff == ' ')))
            {
                i++;
            }
            verif = VerificationFou(i,y,y0,x,x0,echiquier);  
        }
        if (coeff < 0 && deltaY > 0)
        {
            int i = 1;

            while (((x0 - i != x) && (y0 + i != y)) && (echiquier[y0 + i][x0 - i].aff == ' '))
            {
                i++;
            }
            verif = VerificationFou(i,y,y0,x,x0,echiquier);  
        }
    }

    return verif;
}

Bool VerificationFou(int i,int y, int y0,int x,int x0,Piece** echiquier){
    
    Bool verif ;

    if (i != abs(y - y0)) // that's mean that the bishop cross the road of an other piece on the chessboard
        {
            verif = FAUX;
        }
        else if (i == abs(y - y0) && echiquier[y][x].couleur != echiquier[y0][x0].couleur) // To be sure that it can not eat its M8
        {
            verif = VRAI;
        }
    return verif;
}
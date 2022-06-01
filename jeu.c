#include <jeu.h>



void acquisitioncoordonnees(int taille, int coordonnee[2])
{
    char rep[50];
    char abcissetmp;
    int abcisse;
    int ordonne;

    printf("rentrer une lettre pour les abcisses et un nombre pour les "
           "ordonn%ces\n",
           130);

    scanf("%s", rep);
    fflush(stdin);

    while (sscanf(rep, "%c%d", &abcissetmp, &ordonne) == EOF || (abcissetmp < 65 || abcissetmp > taille + 65) ||
           (ordonne < 0 || ordonne > taille))
    {
        printf("Oups, il semblerait que les coordonn%ces rentr%ce ne soit pas "
               "valide.(exemple de coordonn%ces valident #%c%d# pour la taille "
               "%d par "
               "%d)\n",
               130, 130, 130, 65, taille, taille, taille);
        scanf("%s", rep);
        fflush(stdin);
    }

    abcisse = abcissetmp;
    switchbase(&abcisse, &ordonne, taille);

    coordonnee[0] = ordonne;
    coordonnee[1] = abcisse;
}

void switchbase(int* abscisse, int* ordonnee, int taillechiquier)
{
    *abscisse = *abscisse - 65;
    *ordonnee = taillechiquier - *ordonnee;
}

void Mouvement(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier)
{
    Piece tmp;
    tmp.aff = ' ';
    tmp.nom = -1;
    tmp.nom = 0;

    echiquier[coordonneearriver[0]][coordonneearriver[1]] = echiquier[coordonneedepart[0]][coordonneedepart[1]];
    echiquier[coordonneedepart[0]][coordonneedepart[1]] = tmp;
}



Bool FouVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier)
{
    Bool verif = FAUX;

    if (coordonneedepart[1] == coordonneearriver[1])
    {
        return verif;
    }

    int y0 = coordonneedepart[0];
    int x0 = coordonneedepart[1];
    int y = coordonneearriver[0];
    int x = coordonneearriver[1];
    int coeff = (y - y0) / (x - x0);
    int deltaY = (y - y0);

    if (abs(x0 - x) == abs(y0 - y))
    {
        if (coeff > 0 && deltaY < 0)
        {
            int i = 1;

            while (((x0 - i != x) && (y0 - i != y)) && (echiquier[y0 - i][x0 - i].aff == ' '))
            {
                i++;
            }
            verif = VerificationFou(i, y, y0, x, x0, echiquier);
        }
        if (coeff > 0 && deltaY > 0)
        {
            int i = 1;

            while (((x0 + i != x) && (y0 + i != y)) && (echiquier[y0 + i][x0 + i].aff == ' '))
            {
                i++;
            }

            verif = VerificationFou(i, y, y0, x, x0, echiquier);
        }
        if (coeff < 0 && deltaY < 0)
        {
            int i = 1;

            while (((x0 + i != x) && (y0 - i != y) && (echiquier[y0 - i][x0 + i].aff == ' ')))
            {
                i++;
            }
            verif = VerificationFou(i, y, y0, x, x0, echiquier);
        }
        if (coeff < 0 && deltaY > 0)
        {
            int i = 1;

            while (((x0 - i != x) && (y0 + i != y)) && (echiquier[y0 + i][x0 - i].aff == ' '))
            {
                i++;
            }
            verif = VerificationFou(i, y, y0, x, x0, echiquier);
        }
    }

    return verif;
}



Bool VerificationFou(int i, int y, int y0, int x, int x0, Piece** echiquier)
{
    Bool verif = FAUX;

    if (i != abs(y - y0))
    {
        verif = FAUX;
    }
    else if (i == abs(y - y0) && echiquier[y][x].couleur != echiquier[y0][x0].couleur)
    {
        verif = VRAI;
    }
    return verif;
}



Bool CavalierVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier)
{
    Bool verif = FAUX;

    int y0 = coordonneedepart[0];
    int x0 = coordonneedepart[1];
    int y = coordonneearriver[0];
    int x = coordonneearriver[1];

    if (((abs(y0 - y) == 2 && abs(x0 - x) == 1) || (abs(y0 - y) == 1 && abs(x0 - x) == 2)) &&
        (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
    {
        verif = VRAI;
    }

    return verif;
}



Bool TourVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier)
{
    Bool verif = FAUX;

    int y0 = coordonneedepart[0];
    int x0 = coordonneedepart[1];
    int y = coordonneearriver[0];
    int x = coordonneearriver[1];

    if (x == x0)
    {
        int i = 1;
        if (y < y0)
        {
            while ((y != y0 - i) && echiquier[y0 - i][x].aff == ' ')
            {
                i++;
            }
            if ((i == abs(y0 - y)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
            {
                verif = VRAI;
            }
        }
        if (y > y0)
        {
            while ((y != y0 + i) && echiquier[y0 + i][x].aff == ' ')
            {
                i++;
            }
            if ((i == abs(y0 - y)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
            {
                verif = VRAI;
            }
        }
    }
    if (y0 == y)
    {
        int i = 1;
        if (x < x0)
        {
            while ((x != x0 - i) && echiquier[y][x0 - i].aff == ' ')
            {
                i++;
            }
            if ((i == abs(x0 - x)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
            {
                verif = VRAI;
            }
        }
        if (x > x0)
        {
            while ((x != x0 + i) && echiquier[y][x0 + i].aff == ' ')
            {
                i++;
            }
            if ((i == abs(x0 - x)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
            {
                verif = VRAI;
            }
        }
    }
    return verif;
}

Bool PionVerification(int coordonneedepart[2], int coordonneearriver[2], int taille, Piece** echiquier)
{

    Bool verif = FAUX;
    Piece tmp;
    tmp.aff = ' ';
    tmp.couleur = EMPTY;
    tmp.nom = VIDE;

    int y0 = coordonneedepart[0];
    int x0 = coordonneedepart[1];
    int y = coordonneearriver[0];
    int x = coordonneearriver[1];

    if (echiquier[y0][x0].coup == 0 && y0 == taille - 2)
    {
        if (abs(x0 - x) == 1 && (y0 - y) == 1 && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
        {

            verif = VRAI;
        }
        if ((y0 - y == 2 || y0 - y == 1) && x == x0)
        {
            verif = VRAI;
        }
    }

    if (echiquier[y0][x0].coup != 0 && (y0 - y) == 1 && abs(x - x0) == 1 && (echiquier[y][x].couleur != tmp.couleur) &&
        (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
    {
        verif = VRAI;
    }

    if (echiquier[y0][x0].coup != 0 && x == x0 && (y0 - y) == 1 && (echiquier[y][x].aff == ' '))
    {
        verif = VRAI;
    }

    return verif;
}




Bool RoiVeerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier){
       
    Bool verif = FAUX;

    int y0 = coordonneedepart[0];
    int x0 = coordonneedepart[1];
    int y = coordonneearriver[0];
    int x = coordonneearriver[1];

    if((x0 == x && abs(y0-y)==1 && echiquier[y0][x0].couleur != echiquier[y][x].couleur)||(y0 == y && abs(x0-x)==1 && echiquier[y0][x0].couleur != echiquier[y][x].couleur)){
        
        verif = VRAI;
    }else{
        if((abs(x0-x)==abs(y0-y)) && echiquier[y0][x0].couleur != echiquier[y][x].couleur ){
            verif = VRAI ; 
        }
    }

    return verif;

}



Bool DameVerification(int coordonneedepart[2], int coordonneearriver[2], Piece** echiquier){
    
    Bool verif = FAUX;

    int y0 = coordonneedepart[0];
    int x0 = coordonneedepart[1];
    int y = coordonneearriver[0];
    int x = coordonneearriver[1];

    if (abs(x0 - x) == abs(y0 - y))
    {
        int coeff = (y - y0) / (x - x0);
        int deltaY = (y - y0); 

        if (coeff > 0 && deltaY < 0) 
        {
            int i = 1;

            while (((x0 - i != x) && (y0 - i != y)) && (echiquier[y0 - i][x0 - i].aff == ' ')) 
            {
                i++;
            }                                                                                           
            verif = VerificationFou(i,y,y0,x,x0,echiquier); // La dame ayant une combianaison des mouvements du fou et de la tour, nous avons réutilisé la fonction seravant pour le fou                                                                                                                                                                  
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
    if(x == x0){
        int i = 1;
        if(y<y0){
            while((y != y0-i)&&echiquier[y0-i][x].aff == ' '){
                i++;
            }
            if ((i == abs(y0-y)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
            {
                verif = VRAI;
            }
            
        }
        if(y>y0){
            while((y != y0+i)&&echiquier[y0+i][x].aff == ' '){
                i++;
            }
            if ((i == abs(y0-y)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
            {
                verif =VRAI;
            }
            
        }
    }
    if(y0 == y){
        int i = 1;
        if(x<x0){
            while((x != x0-i)&&echiquier[y][x0-i].aff == ' '){
                i++;
            }
            if ((i == abs(x0-x)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
            {
                verif = VRAI;
            }
            
        }
        if(x>x0){
            while((x != x0+i)&&echiquier[y][x0+i].aff == ' '){
                i++;
            }
            if ((i == abs(x0-x)) && (echiquier[y][x].couleur != echiquier[y0][x0].couleur))
            {
                verif =VRAI;
            }
            
        }
    }
    
    return verif;
}



void PositionRoi(int CoordonneeRoi[2], Couleur Roi, int taille, Piece** echiquier)
{

    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if (echiquier[i][j].couleur == Roi && echiquier[i][j].nom == ROI)
            {
                CoordonneeRoi[0] = i;
                CoordonneeRoi[1] = j;
               
            }
        }
    }
}


Bool MouvementPieceEchec(int taille,int coordonnee[2],int coordonneeRoi[2],Piece** echiquier){
    
    int l = coordonnee[0]; // l pour lignes
    int c = coordonnee[1]; // c pour colonnes 
    Bool verif = FAUX;
    
    if (echiquier[l][c].nom == PION)
    {
       verif = PionVerification(coordonnee,coordonneeRoi,taille, echiquier);
    }
    if (echiquier[l][c].nom == CAVALIER)
    {
       verif = CavalierVerification(coordonnee,coordonneeRoi,echiquier);
    }
    if (echiquier[l][c].nom == FOU)
    {
       verif = FouVerification(coordonnee,coordonneeRoi, echiquier);
    }
    if (echiquier[l][c].nom == TOUR)
    {
       verif = TourVerification(coordonnee,coordonneeRoi,echiquier);
    }
    if (echiquier[l][c].nom ==DAME)
    {
       verif = DameVerification(coordonnee,coordonneeRoi,echiquier);
    }
    
    if (echiquier[l][c].nom ==ROI)
    {
       verif = RoiVeerification(coordonnee,coordonneeRoi,echiquier);
    }

   return verif;
}



int** EchecRoi(int taille, int CoordonneeRoi[2], Piece** echiquier, Couleur MiseEnEchec, Couleur MetEnEchec)
{

    Bool verif = FAUX;
    int Coordonne[2];
    int TailleTabEchec = 1;

    int** TabPieceEchec = (int **)malloc(sizeof(int) * TailleTabEchec);

    if (TabPieceEchec != NULL)
    {
        *TabPieceEchec = NULL;
        for (int i = 0; i < TailleTabEchec; i++)
        {

            for (int j = 0; j < TailleTabEchec; j++)
            {
                verif = FAUX;
                if (echiquier[i][j].couleur == MetEnEchec && echiquier[i][j].aff != ' ')
                {

                    Coordonne[0] = i;
                    Coordonne[1] = j;
                    verif = MouvementPieceEchec(TailleTabEchec, Coordonne, CoordonneeRoi, echiquier);

                    if (verif)
                    {
                        if (TailleTabEchec <= 1)
                        {
                            *TabPieceEchec = (int *)malloc(sizeof(int) * 2);
                            TabPieceEchec[TailleTabEchec][0] = i;
                            TabPieceEchec[TailleTabEchec][1] = j;
                            TailleTabEchec++;
                        }
                        else
                        {
                            TabPieceEchec = realloc(TabPieceEchec, sizeof(int) * TailleTabEchec);
                            TabPieceEchec[TailleTabEchec][0] = i;
                            TabPieceEchec[TailleTabEchec][1] = j;
                            TailleTabEchec++;
                        }
                    }
                }
            }
        }
    }

    if (*TabPieceEchec == NULL)
    {
        free(TabPieceEchec);
        TabPieceEchec = NULL;
    }

    return TabPieceEchec;
}
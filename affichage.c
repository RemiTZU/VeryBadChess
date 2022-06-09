#include <affichage.h>


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

void ecritureaffichage(char* ecriture, int motifascii)
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

void affichage(int taille, Piece** echiquier)
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
            printf("[%c%c]", echiquier[i][j].aff,
                   echiquier[i][j].couleur == BLANC  ? 'B'
                   : echiquier[i][j].couleur == NOIR ? 'N'
                                                     : ' ');
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
void asciiboucle(int taille, int motifascii)
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
    char* ecriture = "**********1.Lancer une partie**********";
    char* ecriture1 = "**********2.Relancer une partie********";
    char* ecriture2 = "**********3.Quitter********************";

    printf("%c", 201);
    asciiboucle(longueur, ascii);
    printf("%c", 187);

    printf("\n");

    for (int i = 0; i < 2; i++)
    {

        printf("%c", 186);
        asciiboucle(longueur, 219);

        printf("%c", 186);
        printf("\n");
    }

    ecritureaffichage(ecriture, 186);
    ecritureaffichage(ecriture1, 186);
    ecritureaffichage(ecriture2, 186);

    for (int i = 0; i < 2; i++)
    {

        printf("%c", 186);
        asciiboucle(longueur, 219);

        printf("%c", 186);
        printf("\n");
    }

    printf("%c", 200);
    asciiboucle(longueur, ascii);
    printf("%c", 188);

    printf("\n");
}

void Coup(int taille,int CoordonneeInit[2],int CoordonneeFinit[2]){
    
    printf("\nChoisis une pi%cce %c d%cplacer...\n",138,133,130);
    acquisitioncoordonnees(taille,CoordonneeInit);
    printf("\nSur quelle case veux-tu d%cplacer ta pi%ce...\n",130,138);
    acquisitioncoordonnees(taille,CoordonneeFinit);

}

Bool MouvementLegal(int taille,int CoordonneeInit[2], int CoordonneeFinit[2],Piece** echiquier, Couleur MiseEnEchec, Couleur MetEnEchec, int CoordonneRoi[2]){

    int** TableauEchec;
    int TailleEchec = 0 ;
    
    Bool verif = VRAI; 

    switch(echiquier[CoordonneeInit[0]][CoordonneeInit[1]].nom){

        case(0):
            
            verif = FAUX; 
            
            return verif;
            break;
        
        case(1):
            
            verif = PionVerification(CoordonneeInit,CoordonneeFinit,taille,echiquier);

            if(verif == FAUX){
                printf("Attention ton coup ne marche pas pour un pion\n");
                return verif;
            }
            
            
            Mouvement(CoordonneeInit,CoordonneeFinit,echiquier);
            TableauEchec = EchecRoi(taille, CoordonneRoi,echiquier, MiseEnEchec, MetEnEchec,&TailleEchec);

            if(TableauEchec != NULL){
                printf("Attention ton coup met en %cchec ton Roi",130);
                verif = FAUX;
                freeTab(&TableauEchec,TailleEchec);
                Mouvement(CoordonneeFinit,CoordonneeInit,echiquier);
                return verif;
            }
            break;
        
        case(2):
            
            verif = CavalierVerification(CoordonneeInit,CoordonneeFinit,echiquier);

            if(verif == FAUX){
                printf("Attention ton coup ne marche pas pour un cavalier\n");
                return verif;
            }
            Mouvement(CoordonneeInit,CoordonneeFinit,echiquier);
            TableauEchec = EchecRoi(taille, CoordonneRoi,echiquier, MiseEnEchec, MetEnEchec,&TailleEchec);

            if(TableauEchec != NULL){
                printf("Attention ton coup met en %cchec ton Roi",130);
                verif = FAUX;
                freeTab(&TableauEchec,TailleEchec);
                Mouvement(CoordonneeFinit,CoordonneeInit,echiquier);
                return verif;
            }
            break;
        case(3):
            verif = FouVerification(CoordonneeInit,CoordonneeFinit,echiquier);

            if(verif == FAUX){
                printf("Attention ton coup ne marche pas pour un fou\n");
                return verif;
            }
            Mouvement(CoordonneeInit,CoordonneeFinit,echiquier);
            TableauEchec = EchecRoi(taille, CoordonneRoi,echiquier, MiseEnEchec, MetEnEchec,&TailleEchec);

            if(TableauEchec != NULL){
                printf("Attention ton coup met en %cchec ton Roi",130);
                verif = FAUX;
                freeTab(&TableauEchec,TailleEchec);
                Mouvement(CoordonneeFinit,CoordonneeInit,echiquier);
                return verif;
            }
            break;
        case(4):
            verif = TourVerification(CoordonneeInit,CoordonneeFinit,echiquier);

            if(verif == FAUX){
                printf("Attention ton coup ne marche pas pour une tour\n");
                return verif;
            }
            Mouvement(CoordonneeInit,CoordonneeFinit,echiquier);
            TableauEchec = EchecRoi(taille, CoordonneRoi,echiquier, MiseEnEchec, MetEnEchec,&TailleEchec);

            if(TableauEchec != NULL){
                printf("Attention ton coup met en %cchec ton Roi",130);
                verif = FAUX;
                freeTab(&TableauEchec,TailleEchec);
                Mouvement(CoordonneeFinit,CoordonneeInit,echiquier);
                return verif;
            }
            break;

    
        case(5):
            verif = DameVerification(CoordonneeInit,CoordonneeFinit,echiquier);

            if(verif == FAUX){
                printf("Attention ton coup ne marche pas pour une dame\n");
                return verif;
            }
            Mouvement(CoordonneeInit,CoordonneeFinit,echiquier);
            TableauEchec = EchecRoi(taille, CoordonneRoi,echiquier, MiseEnEchec, MetEnEchec,&TailleEchec);

            if(TableauEchec != NULL){
                printf("Attention ton coup met en %cchec ton Roi",130);
                verif = FAUX;
                freeTab(&TableauEchec,TailleEchec);
                Mouvement(CoordonneeFinit,CoordonneeInit,echiquier);
                return verif;
            }
            break;
        case(6):  
            verif = RoiVerification(CoordonneeInit,CoordonneeFinit,echiquier);

            if(verif == FAUX){
                printf("Attention ton coup ne marche pas pour un roi\n");
                return verif;
            }
            Mouvement(CoordonneeInit,CoordonneeFinit,echiquier);
            PositionRoi(CoordonneRoi,MiseEnEchec,taille,echiquier);
            TableauEchec = EchecRoi(taille, CoordonneRoi,echiquier, MiseEnEchec, MetEnEchec,&TailleEchec);

            if(TableauEchec != NULL){
                printf("Attention ton coup met en %cchec ton Roi",130);
                verif = FAUX;
                freeTab(&TableauEchec,TailleEchec);
                Mouvement(CoordonneeFinit,CoordonneeInit,echiquier);
                PositionRoi(CoordonneRoi,MiseEnEchec,taille,echiquier);
                return verif;
            }
            break;

           
    }   
    Mouvement(CoordonneeFinit,CoordonneeInit,echiquier);
    PositionRoi(CoordonneRoi,MiseEnEchec,taille,echiquier); 
    freeTab(&TableauEchec,TailleEchec);
    return verif;
}

void partie(int taille , Piece** echiquier){

    int CoordonneeRoiBlanc[2];
    int CoordonneeRoiNoir[2];
    int coordonneeDepart[2];    
    int coordonneeArrive[2];    
    int tour = 0 ;
    

    while(EchecEtMat(taille,CoordonneeRoiBlanc,BLANC,NOIR,echiquier) == FAUX && EchecEtMat(taille,CoordonneeRoiNoir,NOIR,BLANC,echiquier) == FAUX ){
        
        affichage(taille,echiquier); 
        Coup(taille,coordonneeDepart,coordonneeArrive);

        if(tour%2==0)
        {   
            PositionRoi(CoordonneeRoiBlanc,BLANC,taille,echiquier);
            while(MouvementLegal(taille,coordonneeDepart,coordonneeArrive,echiquier,BLANC,NOIR,CoordonneeRoiBlanc) == FAUX || echiquier[coordonneeDepart[0]][coordonneeDepart[1]].couleur != BLANC)
            {       
                if( echiquier[coordonneeDepart[0]][coordonneeDepart[1]].couleur != BLANC)
                {   
                   printf("Vous avec s%clectionn%c une pi%cce qui ne t'appartient pas ou une case vide...\n",130,130,138);

                }
                Coup(taille,coordonneeDepart,coordonneeArrive);
                PositionRoi(CoordonneeRoiBlanc,BLANC,taille,echiquier);    
            }
            Mouvement(coordonneeDepart,coordonneeArrive,echiquier);
            echiquier[coordonneeArrive[0]][coordonneeArrive[1]].coup++;


           
        }
        else
        {
          PositionRoi(CoordonneeRoiNoir,NOIR,taille,echiquier);
            while(MouvementLegal(taille,coordonneeDepart,coordonneeArrive,echiquier,NOIR,BLANC,CoordonneeRoiNoir) == FAUX || echiquier[coordonneeDepart[0]][coordonneeDepart[1]].couleur != NOIR)
            {       
                if( echiquier[coordonneeDepart[0]][coordonneeDepart[1]].couleur != NOIR)
                {   
                   printf("Vous avec s%clectionn%c une pi%cce qui ne t'appartient pas ou une case vide...\n",130,130,138);

                }
                Coup(taille,coordonneeDepart,coordonneeArrive);
                PositionRoi(CoordonneeRoiNoir,NOIR,taille,echiquier);    
            }
            Mouvement(coordonneeDepart,coordonneeArrive,echiquier); 
            echiquier[coordonneeArrive[0]][coordonneeArrive[1]].coup++; 
        }

        tour++;
         
    }       

    affichage(taille,echiquier);
    if(EchecEtMat(taille,CoordonneeRoiBlanc,BLANC,NOIR,echiquier) == VRAI){
        printf("\n les Noirs gagnent par echec et mat \n");
    }
    else{
        printf("\n les Blanc gagnent par echec et mat \n");
    }
    
}
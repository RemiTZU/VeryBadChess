#include <affichage.h>

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

void CoupDansPartie(int taille,Piece** echiquier,int CoordonneeInit[2],int CoordonneeFinit[2],Couleur Joue){
    
   
    Bool verif = FAUX;

    if(echiquier[CoordonneeInit[0]][CoordonneeInit[1]].nom == PION){    
        printf("\n");
        acquisitioncoordonnees(taille,CoordonneeFinit);
        printf("\n");
        verif = PionVerification(CoordonneeInit,CoordonneeFinit,taille,echiquier);

        while(echiquier[CoordonneeFinit[0]][CoordonneeFinit[1]].couleur == Joue || verif == FAUX){
            printf(" Veuillez rentrer un coup l%cgal pour le pion",130);
            printf("\n");
            acquisitioncoordonnees(taille,CoordonneeFinit);  
            printf("\n");
            verif = PionVerification(CoordonneeInit,CoordonneeFinit,taille,echiquier);  
        }  
    }   
    
    if(echiquier[CoordonneeInit[0]][CoordonneeInit[1]].nom == CAVALIER){    
        
        printf("\n");
        acquisitioncoordonnees(taille,CoordonneeFinit);
        printf("\n");
        verif = CavalierVerification(CoordonneeInit,CoordonneeFinit,echiquier);

        while(echiquier[CoordonneeFinit[0]][CoordonneeFinit[1]].couleur == Joue || verif == FAUX){
            printf(" Veuillez rentrer un coup l%cgal pour le cavalier",130);
            printf("\n");
            acquisitioncoordonnees(taille,CoordonneeFinit);  
            printf("\n");
            verif = CavalierVerification(CoordonneeInit,CoordonneeFinit,echiquier);  
        }
    }
   
    if(echiquier[CoordonneeInit[0]][CoordonneeInit[1]].nom == FOU){    
        printf("\n");
        acquisitioncoordonnees(taille,CoordonneeFinit);
        printf("\n");
        verif = FouVerification(CoordonneeInit,CoordonneeFinit,echiquier);

        while(echiquier[CoordonneeFinit[0]][CoordonneeFinit[1]].couleur == Joue || verif == FAUX){
            printf(" Veuillez rentrer un coup l%cgal pour le fou",130);
            printf("\n");
            acquisitioncoordonnees(taille,CoordonneeFinit);  
            printf("\n");
            verif = FouVerification(CoordonneeInit,CoordonneeFinit,echiquier);  
        }
    }



    if(echiquier[CoordonneeInit[0]][CoordonneeInit[1]].nom == TOUR){   
        printf("\n");
        acquisitioncoordonnees(taille,CoordonneeFinit);
        printf("\n");
        verif = TourVerification(CoordonneeInit,CoordonneeFinit,echiquier);

        while(echiquier[CoordonneeFinit[0]][CoordonneeFinit[1]].couleur == Joue || verif == FAUX){
            printf(" Veuillez rentrer un coup l%cgal pour la tour",130);
            printf("\n");
            acquisitioncoordonnees(taille,CoordonneeFinit);  
            printf("\n");
            verif = TourVerification(CoordonneeInit,CoordonneeFinit,echiquier);  
        }
    }


    if(echiquier[CoordonneeInit[0]][CoordonneeInit[1]].nom == DAME){
        printf("\n");
        acquisitioncoordonnees(taille,CoordonneeFinit);
        printf("\n");
        verif = DameVerification(CoordonneeInit,CoordonneeFinit,echiquier);

        while(echiquier[CoordonneeFinit[0]][CoordonneeFinit[1]].couleur == Joue || verif == FAUX){
            printf(" Veuillez rentrer un coup l%cgal pour la dame",130);
            printf("\n");
            acquisitioncoordonnees(taille,CoordonneeFinit);  
            printf("\n");
            verif = DameVerification(CoordonneeInit,CoordonneeFinit,echiquier);  
        }

    }


    if(echiquier[CoordonneeInit[0]][CoordonneeInit[1]].nom == ROI){
        
        printf("\n");
        acquisitioncoordonnees(taille,CoordonneeFinit);
        printf("\n");
        verif = RoiVerification(CoordonneeInit,CoordonneeFinit,echiquier);

        while(echiquier[CoordonneeFinit[0]][CoordonneeFinit[1]].couleur == Joue || verif == FAUX){
            printf(" Veuillez rentrer un coup l%cgal pour la dame",130);
            printf("\n");
            acquisitioncoordonnees(taille,CoordonneeFinit);  
            printf("\n");
            verif = RoiVerification(CoordonneeInit,CoordonneeFinit,echiquier);  
        }    

    }
}

void partie(int taille , Piece** echiquier){

    
    int CoordonneeRoiBlanc[2];
    int CoordonneeRoiNoir[2];
    int CoordonneeDeplacementInit[2];
    int CoordonneeDeplacementFinit[2];
    Bool PasEchecEtMatBlanc = VRAI;
    Bool PasEchecEtMatNoir = VRAI;
    Bool EchecBlanc = VRAI;
    Bool EchecNoir = VRAI;
    int** tabBlanc;
    int** tabNoir;
    int tailleTabBlanc;
    int tailleTabNoir;
    
    int tour = 0;
   
    Piece tmp;

 

    while( PasEchecEtMatBlanc && PasEchecEtMatNoir ) {
        
        if(tour%2 == 0)
        {   
            
            affichage(taille,echiquier);
            PositionRoi(CoordonneeRoiBlanc,BLANC,taille,echiquier);
            while(EchecBlanc){
               
                printf("\n");
                acquisitioncoordonnees(taille,CoordonneeDeplacementInit);
                printf("\n");


                while(echiquier[CoordonneeDeplacementInit[0]][CoordonneeDeplacementInit[1]].couleur != BLANC){
                    printf("Vous ne pouvez pas d%cplacer une case vide ou une pi%cce d'une autre couleur\n",130,133);
                    acquisitioncoordonnees(taille,CoordonneeDeplacementInit);
                }

                CoupDansPartie(taille,echiquier,CoordonneeDeplacementInit,CoordonneeDeplacementFinit,BLANC);
                tmp = echiquier[CoordonneeDeplacementFinit[0]][CoordonneeDeplacementFinit[1]];
                Mouvement(CoordonneeDeplacementInit,CoordonneeDeplacementFinit,echiquier);
                tabBlanc = EchecRoi(taille,CoordonneeRoiBlanc,echiquier,BLANC,NOIR,&tailleTabBlanc); 

                if(tabBlanc != NULL){
                    Mouvement(CoordonneeDeplacementFinit,CoordonneeDeplacementInit,echiquier);
                    echiquier[CoordonneeDeplacementFinit[0]][CoordonneeDeplacementFinit[1]] = tmp;
                    printf("Vous allez mettre en %cchec votre roi, veuillez choisir une autre pièce ou un coup valable\n",130);
                    freeTab(&tabBlanc,tailleTabBlanc);
                    tailleTabBlanc = 0 ;

                }else{
                    EchecBlanc = FAUX;
                    echiquier[CoordonneeDeplacementFinit[0]][CoordonneeDeplacementFinit[1]].coup ++;
                    reverse(taille,echiquier);
                    PasEchecEtMatNoir = PasEchecEtMat(taille,CoordonneeRoiNoir,NOIR,BLANC,echiquier);
                    tour++;
                    freeTab(&tabBlanc,tailleTabBlanc);
                    tailleTabBlanc = 0 ;     
                }

            
            }  



        }
        else
        {
            affichage(taille,echiquier);
            PositionRoi(CoordonneeRoiNoir,NOIR,taille,echiquier);
            while(EchecNoir){
               
                printf("\n");
                acquisitioncoordonnees(taille,CoordonneeDeplacementInit);
                printf("\n");


                while(echiquier[CoordonneeDeplacementInit[0]][CoordonneeDeplacementInit[1]].couleur != NOIR){
                    printf("Vous ne pouvez pas d%cplacer une case vide ou une pi%cce d'une autre couleur\n",130,133);
                    acquisitioncoordonnees(taille,CoordonneeDeplacementInit);
                }

                CoupDansPartie(taille,echiquier,CoordonneeDeplacementInit,CoordonneeDeplacementFinit,NOIR);
                tmp = echiquier[CoordonneeDeplacementFinit[0]][CoordonneeDeplacementFinit[1]];
                Mouvement(CoordonneeDeplacementInit,CoordonneeDeplacementFinit,echiquier);
                tabNoir = EchecRoi(taille,CoordonneeRoiNoir,echiquier,NOIR,BLANC,&tailleTabNoir); 

                if(tabNoir != NULL){
                    Mouvement(CoordonneeDeplacementFinit,CoordonneeDeplacementInit,echiquier);
                    echiquier[CoordonneeDeplacementFinit[0]][CoordonneeDeplacementFinit[1]] = tmp;
                    printf("Vous allez mettre en %cchec votre roi, veuillez choisir une autre pièce ou un coup valable\n",130);
                    freeTab(&tabNoir, tailleTabNoir);
                    tailleTabNoir = 0 ;
                
                }else{
                    EchecNoir = FAUX;
                    echiquier[CoordonneeDeplacementFinit[0]][CoordonneeDeplacementFinit[1]].coup ++;
                    reverse(taille,echiquier);
                    PasEchecEtMatBlanc = PasEchecEtMat(taille,CoordonneeRoiBlanc,BLANC,NOIR,echiquier);
                    tour++;
                    freeTab(&tabNoir, tailleTabNoir);
                    tailleTabNoir = 0 ;     
                }

            
            }           
        }
    }

    if(PasEchecEtMatBlanc == FAUX){

        system("cls");
        printf(" _______  __    __   _______   ______     _______ .___________.   .___  ___.      ___   .___________.    __                                                           \n");
        printf("|   ____||  |  |  | |   ____| /      |   |   ____||           |   |   \\/   |     /   \\  |           |   |  |                                                          \n");
        printf("|  |__   |  |__|  | |  |__   |  ,----'   |  |__   `---|  |----`   |  \\  /  |    /  ^  \\ `---|  |----`   |  |                                                          \n");
        printf("|   __|  |   __   | |   __|  |  |        |   __|      |  |        |  |\\/|  |   /  /_\\  \\    |  |        |  |                                                          \n");
        printf("|  |____ |  |  |  | |  |____ |  `----.   |  |____     |  |        |  |  |  |  /  _____  \\   |  |        |__|                                                          \n");
        printf("|_______||__|  |__| |_______| \\______|   |_______|    |__|        |__|  |__| /__/     \\__\\  |__|        (__)                                                          \n");

        printf("____    ____  __    ______ .___________.  ______    __  .______       _______     _______   _______     _______.   .__   __.   ______    __  .______          _______.\n");
        printf("\\   \\  /   / |  |  /      ||           | /  __  \\  |  | |   _  \\     |   ____|   |       \\ |   ____|   /       |   |  \\ |  |  /  __  \\  |  | |   _  \\        /       |\n");
        printf(" \\   \\/   /  |  | |  ,----'`---|  |----`|  |  |  | |  | |  |_)  |    |  |__      |  .--.  ||  |__     |   (----`   |   \\|  | |  |  |  | |  | |  |_)  |      |   (----`\n");
        printf("  \\      /   |  | |  |         |  |     |  |  |  | |  | |      /     |   __|     |  |  |  ||   __|     \\   \\       |  . `  | |  |  |  | |  | |      /        \\   \\    \n");
        printf("   \\    /    |  | |  `----.    |  |     |  `--'  | |  | |  |\\  \\----.|  |____    |  '--'  ||  |____.----)   |      |  |\\   | |  `--'  | |  | |  |\\  \\----.----)   |   \n");
        printf("    \\__/     |__|  \\______|    |__|      \\______/  |__| | _| `._____||_______|   |_______/ |_______|_______/       |__| \\__|  \\______/  |__| | _| `._____|_______/    \n");

    }else{
        system("cls");
        printf(" _______  __    __   _______   ______     _______ .___________.   .___  ___.      ___   .___________.    __                                                           \n");
        printf("|   ____||  |  |  | |   ____| /      |   |   ____||           |   |   \\/   |     /   \\  |           |   |  |                                                          \n");
        printf("|  |__   |  |__|  | |  |__   |  ,----'   |  |__   `---|  |----`   |  \\  /  |    /  ^  \\ `---|  |----`   |  |                                                          \n");
        printf("|   __|  |   __   | |   __|  |  |        |   __|      |  |        |  |\\/|  |   /  /_\\  \\    |  |        |  |                                                          \n");
        printf("|  |____ |  |  |  | |  |____ |  `----.   |  |____     |  |        |  |  |  |  /  _____  \\   |  |        |__|                                                          \n");
        printf("|_______||__|  |__| |_______| \\______|   |_______|    |__|        |__|  |__| /__/     \\__\\  |__|        (__)                                                          \n");

        printf(" ____    ____  __    ______ .___________.  ______    __  .______       _______     _______   _______     _______.   .______    __          ___      .__   __.   ______     _______.\n");
        printf("\\   \\  /   / |  |  /      ||           | /  __  \\  |  | |   _  \\     |   ____|   |       \\ |   ____|   /       |   |   _  \\  |  |        /   \\     |  \\ |  |  /      |   /       |\n");
        printf(" \\   \\/   /  |  | |  ,----'`---|  |----`|  |  |  | |  | |  |_)  |    |  |__      |  .--.  ||  |__     |   (----`   |  |_)  | |  |       /  ^  \\    |   \\|  | |  ,----'  |   (----`\n");
        printf("  \\      /   |  | |  |         |  |     |  |  |  | |  | |      /     |   __|     |  |  |  ||   __|     \\   \\       |   _  <  |  |      /  /_\\  \\   |  . `  | |  |        \\   \\    \n");
        printf("   \\    /    |  | |  `----.    |  |     |  `--'  | |  | |  |\\  \\----.|  |____    |  '--'  ||  |____.----)   |      |  |_)  | |  `----./  _____  \\  |  |\\   | |  `----.----)   |   \n");
        printf("    \\__/     |__|  \\______|    |__|      \\______/  |__| | _| `._____||_______|   |_______/ |_______|_______/       |______/  |_______/__/     \\__\\ |__| \\__|  \\______|_______/    \n");
                                                                                                                                                                                  


    }
    
}
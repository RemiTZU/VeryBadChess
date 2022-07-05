#include <affichage.h>

/* Affichage.c regroupe toutes les fonctions affichant quelques choses à l'utilisateur: la demande des coordonnées, le menu , l'echiquier et la partie */

/***********************************************************************************************************************************************************************/

/**
 * @brief Fonction permettant de vérifier les coordonnées de l'utilisateur et de remplir le tableau coordonnee
 * permettant ainsi des manipulations avec le tableau de structure de l'échiquier
 *
 * @param taille --> Taille de l'échiquier
 * @param coord --> Structure représentant les indexs du tableau de structure(format: ligne-colonne)
 */
void acquisitioncoordonnees(int taille, Coord *coord)
{
    char rep[50];
    char abcissetmp;
    int abcisse;
    int ordonne;

    printf("Rentre une lettre pour les abcisses et un nombre pour les "
           "ordonn%ces\n",
        130);

    scanf("%s", rep);
    fflush(stdin);

    while (sscanf(rep, "%c%d", &abcissetmp, &ordonne) == EOF || (abcissetmp < 65 || abcissetmp > taille + 65) || (ordonne < 0 || ordonne > taille)) {
        printf("Oups, il semblerait que les coordonn%ces rentr%ces ne soient pas "
               "valides.(exemple de coordonn%ces valides #%c%d# pour la taille "
               "%d par "
               "%d)\n",
            130, 130, 130, 65, taille, taille, taille);
        scanf("%s", rep);
        fflush(stdin);
    }

    abcisse = abcissetmp;
    switchbase(&abcisse, &ordonne, taille);

    coord->y = ordonne;
    coord->x = abcisse;
}

/***********************************************************************************************************************************************************************/
/**
 * @brief Fonction qui rempli le menu de caractère ASCII de notre choix
 *
 * @param taille -> taille du menu
 * @param motifascii -> Motif ASCII que l'on choisit
 */
void asciiboucle(int taille, int motifascii)
{

    for (int i = 0; i < taille; i++) {

        printf("%c", motifascii);
    }
}

/***********************************************************************************************************************************************************************/

/**
 * @brief Fonction qui rempli le menu avec les phrase de notre choix. Attention il faut que la taille des phrases
 * soit inférieur à  la taille du menu ( il faut -2 caractères sur la taille du menu), pour un affichage correct.
 *
 * @param ecriture -> Tableau de caractères que l'on veut afficher
 * @param motifascii -> Motif du cadre du Menu
 */
void ecritureaffichage(char* ecriture, int motifascii)
{

    int size = strlen(ecriture);
    printf("%c", motifascii);

    for (int i = 0; i < size; i++) {

        printf("%c", ecriture[i]);
    }

    printf("%c", motifascii);
    printf("\n");
}

/***********************************************************************************************************************************************************************/

/**
 * @brief Fonction qui affiche l'échiquier de la partie en cours
 *
 * @param taille -> taille de l'échiquier
 * @param echiquier -> Tableau  à  deux dimensions de structure de Pièce
 */
void affichage(int taille, Piece** echiquier)
{   
    printf("\n");
    printf("  %c",218);
    for(int i = 0; i<taille-1;i++){
        printf("%c%c%c%c%c",196,196,196,196,194);
    }
    printf("%c%c%c%c%c\n",196,196,196,196,191);

    for(int i = 0 ; i<taille ;i++){
           
           if (taille - i >= 10) // Condition pour eviter un décalage à partir  de 10
        {
            printf("%d", taille - i); // Affichage des coordonnées en ordonnées de la grille
            printf("%c ", 179);
        } else {

            printf(" %d", taille - i);
            printf("%c ", 179);
        }
        for(int j = 0; j<taille;j++){
            printf("%c%c %c ",echiquier[i][j].aff, echiquier[i][j].couleur == BLANC ? 'B': echiquier[i][j].couleur == NOIR ? 'N': ' ', 179);
        }
       
        printf("\n");
        
        if(i< taille-1){
            printf("  %c",195);
            for(int k = 0; k<taille-1;k++){
                printf("%c%c%c%c%c",196,196,196,196,197);
            }
            printf("%c%c%c%c%c",196,196,196,196,180);
            printf("\n");
        }
    }


     printf("  %c",192);
    for(int i = 0; i<taille-1;i++){
        printf("%c%c%c%c%c",196,196,196,196,193);
    }
    printf("%c%c%c%c%c\n",196,196,196,196,217);
   
    printf("    %c", 65);

    for (int k = 0; k < taille - 1; k++) {
        printf("    %c", k + 66); // Affichage des coordonnées en absisses
    }
}
/***********************************************************************************************************************************************************************/

/**
 * @brief Affiche le menu du jeu Very Bad Chess
 *
 */
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

    for (int i = 0; i < 2; i++) {

        printf("%c", 186);
        asciiboucle(longueur, 219);

        printf("%c", 186);
        printf("\n");
    }

    ecritureaffichage(ecriture, 186);
    ecritureaffichage(ecriture1, 186);
    ecritureaffichage(ecriture2, 186);

    for (int i = 0; i < 2; i++) {

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

/***********************************************************************************************************************************************************************/

/**
 * @brief
 *
 * @param taille -> taille de l'échiquier
 * @param CoordonneeInit--> Coordonnée de départ entrée par l'utilisateur
 * @param CoordonneeFinit--> Coordonnée d'arriver entrée par l'utilisateur
 * @param Joue --> couleur entrain de jouer 
 */
void Coup(int taille, Coord *CoordonneeInit, Coord *CoordonneeFinit, Couleur Joue)
{
    if(Joue == BLANC){
        printf("\nC'est au tour des BLANC de jouer\n");
    }
    else{
        printf("\nC'est au tour des NOIR de jouer\n");
    }
    printf("\nChoisis une pi%cce %c d%cplacer...\n", 138, 133, 130);
    acquisitioncoordonnees(taille, CoordonneeInit);
    printf("\nSur quelle case veux-tu d%cplacer ta pi%cce...\n", 130, 138);
    acquisitioncoordonnees(taille, CoordonneeFinit);
}

/***********************************************************************************************************************************************************************/

/**
 * @brief Fonction booléenne servant dans partie. Sert  à savoir si un mouvement est légal sous trois conditions : la légalité du mouvement la couleur suivant le tour et l'echec à la découverte du Roi
 *
 * @param taille -> taille de l'échiquier
 * @param CoordonneeInit --> Coordonnée de départ entrée par l'utilisateur
 * @param CoordonneeFinit --> Coordonnée d'arriver entrée par l'utilisateur
 * @param MisenEchec --> Couleur du Roi mis en échec
 * @param MetEnEchec --> Couleur du Roi mis en échec
 * @param CoordonneRoi--> Coordonnées du Roi qui peut être en échec
 * @return Bool --> VRAI si le mouvement est légal
 */

Bool MouvementLegal(int taille, Coord CoordonneeInit, Coord CoordonneeFinit, Piece** echiquier, Couleur MiseEnEchec, Couleur MetEnEchec, Coord CoordonneRoi)
{

    Coord* TableauEchec;
    int TailleEchec = 0;

    Bool verif = VRAI;
    Piece tmp;
    tmp = echiquier[CoordonneeFinit.y][CoordonneeFinit.x];

    switch (echiquier[CoordonneeInit.y][CoordonneeInit.x].nom) {

    case (0):

        verif = FAUX;

        return verif;
        break;

    case (1):

        verif = PionVerification(CoordonneeInit, CoordonneeFinit, taille, echiquier);

        if (verif == FAUX) {
            printf("Attention ton coup ne marche pas pour un pion\n");
            return verif;
        }

        Mouvement(CoordonneeInit, CoordonneeFinit, echiquier);
        TableauEchec = EchecRoi(taille, CoordonneRoi, echiquier, MiseEnEchec, MetEnEchec, &TailleEchec);

        if (TableauEchec != NULL) {
            printf("Attention ton coup met en %cchec ton Roi\n", 130);
            verif = FAUX;
            freeTab(&TableauEchec, TailleEchec);
            Mouvement(CoordonneeFinit, CoordonneeInit, echiquier);
            echiquier[CoordonneeFinit.y][CoordonneeFinit.x] = tmp;

            return verif;
        }
        break;

    case (2):

        verif = CavalierVerification(CoordonneeInit, CoordonneeFinit, echiquier);

        if (verif == FAUX) {
            printf("Attention ton coup ne marche pas pour un cavalier\n");
            return verif;
        }
        Mouvement(CoordonneeInit, CoordonneeFinit, echiquier);
        TableauEchec = EchecRoi(taille, CoordonneRoi, echiquier, MiseEnEchec, MetEnEchec, &TailleEchec);

        if (TableauEchec != NULL) {
            printf("Attention ton coup met en %cchec ton Roi\n", 130);
            verif = FAUX;
            freeTab(&TableauEchec, TailleEchec);
            Mouvement(CoordonneeFinit, CoordonneeInit, echiquier);
            echiquier[CoordonneeFinit.y][CoordonneeFinit.x] = tmp;

            return verif;
        }
        break;
    case (3):
        verif = FouVerification(CoordonneeInit, CoordonneeFinit, echiquier);

        if (verif == FAUX) {
            printf("Attention ton coup ne marche pas pour un fou\n");
            return verif;
        }
        Mouvement(CoordonneeInit, CoordonneeFinit, echiquier);
        TableauEchec = EchecRoi(taille, CoordonneRoi, echiquier, MiseEnEchec, MetEnEchec, &TailleEchec);

        if (TableauEchec != NULL) {
            printf("Attention ton coup met en %cchec ton Roi\n", 130);
            verif = FAUX;
            freeTab(&TableauEchec, TailleEchec);
            Mouvement(CoordonneeFinit, CoordonneeInit, echiquier);
            echiquier[CoordonneeFinit.y][CoordonneeFinit.x] = tmp;
            return verif;
        }
        break;
    case (4):
        verif = TourVerification(CoordonneeInit, CoordonneeFinit, echiquier);

        if (verif == FAUX) {
            printf("Attention ton coup ne marche pas pour une tour\n");
            return verif;
        }
        Mouvement(CoordonneeInit, CoordonneeFinit, echiquier);
        TableauEchec = EchecRoi(taille, CoordonneRoi, echiquier, MiseEnEchec, MetEnEchec, &TailleEchec);

        if (TableauEchec != NULL) {
            printf("Attention ton coup met en %cchec ton Roi\n", 130);
            verif = FAUX;
            freeTab(&TableauEchec, TailleEchec);
            Mouvement(CoordonneeFinit, CoordonneeInit, echiquier);
            echiquier[CoordonneeFinit.y][CoordonneeFinit.x] = tmp;
            return verif;
        }
        break;

    case (5):
        verif = DameVerification(CoordonneeInit, CoordonneeFinit, echiquier);

        if (verif == FAUX) {
            printf("Attention ton coup ne marche pas pour une dame\n\n");
            return verif;
        }
        Mouvement(CoordonneeInit, CoordonneeFinit, echiquier);
        TableauEchec = EchecRoi(taille, CoordonneRoi, echiquier, MiseEnEchec, MetEnEchec, &TailleEchec);

        if (TableauEchec != NULL) {
            printf("Attention ton coup met en %cchec ton Roi\n", 130);
            verif = FAUX;
            freeTab(&TableauEchec, TailleEchec);
            Mouvement(CoordonneeFinit, CoordonneeInit, echiquier);
            echiquier[CoordonneeFinit.y][CoordonneeFinit.x] = tmp;
            return verif;
        }
        break;
    case (6):
        verif = RoiVerification(CoordonneeInit, CoordonneeFinit, echiquier);

        if (verif == FAUX) {
            printf("Attention ton coup ne marche pas pour un roi\n");
            return verif;
        }
        Mouvement(CoordonneeInit, CoordonneeFinit, echiquier);
        PositionRoi(CoordonneRoi, MiseEnEchec, taille, echiquier);
        TableauEchec = EchecRoi(taille, CoordonneRoi, echiquier, MiseEnEchec, MetEnEchec, &TailleEchec);

        if (TableauEchec != NULL) {
            printf("Attention ton coup met en %cchec ton Roi\n", 130);
            verif = FAUX;
            freeTab(&TableauEchec, TailleEchec);
            Mouvement(CoordonneeFinit, CoordonneeInit, echiquier);
            echiquier[CoordonneeFinit.y][CoordonneeFinit.x] = tmp;
            PositionRoi(CoordonneRoi, MiseEnEchec, taille, echiquier);
            return verif;
        }
        
        break;
    }
    Mouvement(CoordonneeFinit, CoordonneeInit, echiquier);
    echiquier[CoordonneeFinit.y][CoordonneeFinit.x] = tmp;
    PositionRoi(CoordonneRoi, MiseEnEchec, taille, echiquier);
    freeTab(&TableauEchec, TailleEchec);
    return verif;
}

/***********************************************************************************************************************************************************************/

/**
 * @brief Assure le bon déroulement d'une partie de Very Bad CHess
 *
 */
void partie(int taille, Piece** echiquier, int tour)
{

    Coord CoordonneeRoiBlanc;
    Coord CoordonneeRoiNoir;
    Coord coordonneeDepart = (Coord){0, 0};
    Coord coordonneeArrive = (Coord){0, 0};
    int couptotalBlanc = 0;
    int couptotalNoir = 0;
    char rep;
    char rep1;

    PositionRoi(CoordonneeRoiBlanc, BLANC, taille, echiquier);         
    PositionRoi(CoordonneeRoiNoir, NOIR, taille, echiquier);
    
   

    while (EchecEtMat(taille, CoordonneeRoiBlanc, BLANC, NOIR, echiquier) == FAUX && EchecEtMat(taille, CoordonneeRoiNoir, NOIR, BLANC, echiquier) == FAUX) {
        
        printf("/***************************************************************************************/\n");
        
        
        affichage(taille, echiquier);
        
        printf("\nVeux tu sauvegarder (S), abandonner (X), continuer(autre)....\n");
        scanf("%c",&rep);
        fflush(stdin);

        if(rep == 'S'){
            Sauvegarde("save.txt",taille,tour,echiquier);
            printf("Voulez vous quitter (O/N) ?\n");
            scanf("%c", &rep1);
            fflush(stdin);

            while(rep1 != 'O' && rep1 != 'N'){
                printf(" 'O' ou 'N' \n");
                scanf("%c", &rep1);
                fflush(stdin);
            }
            if(rep1 == 'O'){
                break;
            }else{
                printf("/***************************************************************************************/\n");
                affichage(taille, echiquier);
            }
        }
        if(rep == 'X' ){
                
            if(tour%2 == 0){
                printf("\n Les NOIRS gagnent par abandon \n");
                break;
            }else{
                printf("\n Les BLANCS gagnent par abandon \n");
                break;      
            }

         }
            
        fflush(stdin);
        
        if(tour == 0){
            printf("\nA CHAQUE DEBUT DE TOUR  TU POURRAS ABANDONNER EN TAPANT (X) OU SAUVEGARDER EN TAPANT (S)...\nBonne partie...\n");
        }
        
        if (tour % 2 == 0) {
            PositionRoi(CoordonneeRoiBlanc, BLANC, taille, echiquier);
            Coup(taille, &coordonneeDepart, &coordonneeArrive, BLANC);
            while (MouvementLegal(taille, coordonneeDepart, coordonneeArrive, echiquier, BLANC, NOIR, CoordonneeRoiBlanc) == FAUX || echiquier[coordonneeDepart.y][coordonneeDepart.x].couleur != BLANC) {
                if (echiquier[coordonneeDepart.y][coordonneeDepart.x].couleur != BLANC) {
                    printf("Vous avez s%clectionn%c une pi%cce qui ne t'appartient pas ou une case vide...\n", 130, 130, 138);
                    printf("%d:%d", coordonneeDepart.y, coordonneeDepart.x);
                }
                Coup(taille, &coordonneeDepart, &coordonneeArrive, BLANC);
            }
            Mouvement(coordonneeDepart, coordonneeArrive, echiquier);
            echiquier[coordonneeArrive.y][coordonneeArrive.x].coup++;
            couptotalBlanc++;

        } else {
            PositionRoi(CoordonneeRoiNoir, NOIR, taille, echiquier);
            Coup(taille, &coordonneeDepart, &coordonneeArrive, NOIR);
            while (MouvementLegal(taille, coordonneeDepart, coordonneeArrive, echiquier, NOIR, BLANC, CoordonneeRoiNoir) == FAUX || echiquier[coordonneeDepart.y][coordonneeDepart.x].couleur != NOIR) {
                if (echiquier[coordonneeDepart.y][coordonneeDepart.x].couleur != NOIR) {
                    printf("Vous avez s%clectionn%c une pi%cce qui ne t'appartient pas ou une case vide...\n", 130, 130, 138);
                }
                Coup(taille, &coordonneeDepart, &coordonneeArrive, NOIR);
            }
            Mouvement(coordonneeDepart, coordonneeArrive, echiquier);
            echiquier[coordonneeArrive.y][coordonneeArrive.y].coup++;
            couptotalNoir++;
        }
        tour++;
       
       
    }

    if(rep1 != 'O'  &&  rep != 'X'){
        affichage(taille, echiquier);
        if (EchecEtMat(taille, CoordonneeRoiBlanc, BLANC, NOIR, echiquier) == VRAI) {
            printf("\n les Noirs gagnent par Echec Et Mat \n");
        } else {
            printf("\n les Blanc gagnent par Echec Et Mat \n");
        }
    }
}

/***********************************************************************************************************************************************************************/



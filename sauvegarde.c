#include <sauvegarde.h>

void Sauvegarde(const char* filepath, int taille, int tour, Piece** echiquier)
{
    FILE* fichier = fopen(filepath, "w");
    fprintf(fichier, "%d\n%d\n", taille, tour);

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            fprintf(fichier, "%d%d%d;", echiquier[i][j].nom, echiquier[i][j].couleur, echiquier[i][j].coup);
        }
        // fprintf(fichier,"\n");
    }
    fclose(fichier);
}


Piece** LectureSauvegarde(const char* filepath,int* taille,int* tour){
    
    FILE* fichier = fopen(filepath,"r");
    fscanf(fichier,"%d\n",taille);
    fscanf(fichier,"%d\n",tour);

    Piece** echiquier = InitializeEchiquierS(fichier,*taille);
    fclose(fichier);
    return echiquier;
}


Piece** InitializeEchiquierS(FILE* fichier,int taille)
{
    
    char affichagePiece[] = { ' ', 'P', 'C', 'F', 'T', 'D', 'R' };

    Piece** echiquier = (Piece**)malloc(sizeof(Piece*) * taille);


    if (echiquier != NULL) {

        for (int i = 0; i < taille; i++) {
            // char c;
            echiquier[i] = (Piece*)malloc(sizeof(Piece) * taille);

            if (echiquier[i] != NULL) {
                for (int j = 0; j < taille; j++) {
                    char nom, couleur, coup;
                    fscanf(fichier,"%c%c%c;", &nom, &couleur, &coup);
                    echiquier[i][j].nom = nom - '0';
                    echiquier[i][j].couleur = couleur -'0';
                    echiquier[i][j].coup = coup -'0';

                    echiquier[i][j].aff = affichagePiece[echiquier[i][j].nom];
                }
                printf("onéal\n");
            } else {
                fprintf(stderr, "Les pieces n'ont pas %ct%c attribu%ces\n ",130,130,130);
            }
        }

        } else {
           fprintf(stderr, "Echiquier non attribué\n");
        }
    
    return echiquier;
}    
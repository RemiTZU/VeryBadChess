#include <sauvegarde.h>

/*sauvegarde.c contient toutes les fonctions destiné à la sauvegarde de l'échiquier ainsi qu'à son initialisation lors de la reprise d'une partie précédemment enregistrée*/

/***********************************************************************************************************************/
/**
 * @brief Sert à  sauvegarder une partie au cours du jeu 
 * 
 * @param filepath --> Nom du ficher qui va être créé ou ouvert 
 * @param taille --> taille de l'echiquier
 * @param tour --> Le nombre de tour de la partie actuelle 
 * @param echiquier --> structure de pièce 
 */
void Sauvegarde(const char* filepath, int taille, int tour, Piece** echiquier)
{
    FILE* fichier = fopen(filepath, "w");
    fprintf(fichier, "%d\n%d\n",taille,tour);

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            fprintf(fichier, "%d%d%d;", echiquier[i][j].nom, echiquier[i][j].couleur, echiquier[i][j].coup);
        }
        
    }
    fclose(fichier);
}
/***********************************************************************************************************************/
/**
 * @brief Sert à lire un fichier .txt pour reprendre une partie sauvegarder 
 * 
 * @param filepath --> Nom du ficher 
 * @param taille  --> taille de l'echiquier
 * @param tour -->  Le nombre de tour de la partie actuelle
 * @param echiquier  --> structure de pièce 
 */
Piece** LectureSauvegarde(const char* filepath,int* taille,int* tour){
    
    Piece** echiquier;
    FILE* fichier = fopen(filepath,"r");
    if (fichier == NULL){
       
       echiquier = NULL;

    }else{

        fscanf(fichier,"%d\n",taille);
        fscanf(fichier,"%d\n",tour);
        echiquier = InitializeEchiquierS(fichier,*taille);
        
        fclose(fichier);
    }
    return echiquier;
}
/***********************************************************************************************************************/
/**
 * @brief Sert à initializer un echiquier à partir d'une sauvegarde (si fichier corrumpu le programme s'ârrete il sera utile de supprimer le .txt si vous voulez jouer)
 * 
 * @param fichier --> addresse du fichier 
 * @param taille --> taille de l'echiquier
 * @return Piece** --> echiquier initializer si bien allouer 
 */
Piece** InitializeEchiquierS(FILE* fichier,int taille)
{
    
    char affichagePiece[7] = {' ', 'P', 'C', 'F', 'T', 'D', 'R'};

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
                
            } else {
                fprintf(stderr, "Les pieces n'ont pas %ct%c attribu%ces\n ",130,130,130);
            }
        }

        } else {
           fprintf(stderr, "Echiquier non attribué\n");
        }
    
    return echiquier;
}    
/***********************************************************************************************************************/
#ifndef SAUVEGARDEHEADER
#define SAUVEGARDEHEADER



#include <echiquier.h>

/**
 * @brief Sert à  sauvegarder une partie au cours du jeu 
 * 
 * @param filepath --> Nom du ficher qui va être créé ou ouvert 
 * @param taille --> taille de l'echiquier
 * @param tour --> Le nombre de tour de la partie actuelle 
 * @param echiquier --> structure de pièce 
 */
void Sauvegarde(const char* filepath, int taille, int tour, Piece** echiquier);
/**
 * @brief Sert à lire un fichier .txt pour reprendre une partie sauvegarder 
 * 
 * @param filepath --> Nom du ficher 
 * @param taille  --> taille de l'echiquier
 * @param tour -->  Le nombre de tour de la partie actuelle
 * @param echiquier  --> structure de pièce 
 */
Piece** LectureSauvegarde(const char* filepath,int* taille,int* tour);
/**
 * @brief Sert à initializer un echiquier à partir d'une sauvegarde (si fichier corrumpu le programme s'ârrete il sera utile de supprimer le .txt si vous voulez jouer)
 * 
 * @param fichier --> addresse du fichier 
 * @param taille --> taille de l'echiquier
 * @return Piece** --> echiquier initializer si bien allouer 
 */
Piece** InitializeEchiquierS(FILE* fichier,int taille);

#endif
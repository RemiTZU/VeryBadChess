#ifndef SAUVEGARDEHEADER
#define SAUVEGARDEHEADER



#include <echiquier.h>

/**
 * @brief 
 * 
 * @param filepath 
 * @param taille 
 * @param tour 
 * @param echiquier 
 */
void Sauvegarde(const char* filepath, int taille, int tour, Piece** echiquier);
/**
 * @brief 
 * 
 * @param filepath 
 * @param taille 
 * @param tour 
 * @param echiquier 
 */
Piece** LectureSauvegarde(const char* filepath,int* taille,int* tour);
/**
 * @brief 
 * 
 * @param taille 
 * @return Piece** 
 */
Piece** InitializeEchiquierS(FILE* fichier,int taille);

#endif
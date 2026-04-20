#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Structure.h"

#define TAILLE 7

void init_admin(int plateau[TAILLE][TAILLE]);
void afficher_admin(int plateau[TAILLE][TAILLE]);
void init_revele(char plateau_joueur[TAILLE][TAILLE]);
void afficher_revele(char plateau_joueur[TAILLE][TAILLE], int taille);
#endif

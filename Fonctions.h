#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Structure.h"

#define TAILLE 7

void init(Case plateau[TAILLE][TAILLE], int nb_joueurs);
void afficher(Case plateau[TAILLE][TAILLE]);
void init_joueur(Joueur* j);
int est_gagnant(Joueur j);
void tour(Joueur* j, Case plateau[TAILLE][TAILLE]);
#endif

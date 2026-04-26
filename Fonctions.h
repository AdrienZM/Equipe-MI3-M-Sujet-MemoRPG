#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "structure.h"
#define TAILLE 7

void init(Case plateau[TAILLE][TAILLE], int nb_joueurs);
void afficher(Case plateau[TAILLE][TAILLE]);
int est_gagnant(Joueur j);
void init_joueur(Joueur* j);
void tour(Joueur *j, Case plateau[TAILLE][TAILLE]);
void retourner(Case plateau[TAILLE][TAILLE]);

#endif

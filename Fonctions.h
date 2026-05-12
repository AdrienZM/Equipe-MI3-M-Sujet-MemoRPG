#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "structure.h"
#define TAILLE 7

void init(Case plateau[TAILLE][TAILLE], int nb_joueurs);
void afficher(Case plateau[TAILLE][TAILLE], Joueur *joueurs, int nb_joueurs);
int est_gagnant(Joueur j);
void init_joueur(Joueur* j);
int peut_jouer(Joueur *j, Case plateau[TAILLE][TAILLE]);
void tour(Joueur *j, Case plateau[TAILLE][TAILLE], Joueur *joueurs, int nb_joueurs);
void retourner(Case plateau[TAILLE][TAILLE]);
void sauvegarder(Joueur* joueur_partie, int nb_joueur, char* nom_gagnant);

#endif

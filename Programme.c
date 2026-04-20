#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "structure.h"

#define TAILLE 7

int main(){
	srand(time(NULL));
	int plateau_admin[TAILLE][TAILLE], plateau_joueur[TAILLE][TAILLE];
	printf("----------Plateau Admin----------");
	init_admin(plateau_admin);
	afficher_admin(plateau_admin);
	printf("----------Plateau Révélé----------");
	init_revele(plateau_joueur);
	afficher_revele(plateau_joueur);
	return 0;
}

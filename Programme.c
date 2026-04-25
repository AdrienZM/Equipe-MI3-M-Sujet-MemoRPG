#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "structure.h"

#define TAILLE 7

int main(){
	srand(time(NULL));
	Case plateau[TAILLE][TAILLE];
	//demande du nombre de joueurs puis initialisation du plateau de jeu
	int nb_joueur;
	do{printf("Saisir le nombre de joueur : \n");
	   scanf("%d", &nb_joueur);
	   if(nb_joueur < 1 || nb_joueur > 4)
		   printf("Nombre de joueur impossible. Réessayer.\n");
	  }while(nb_joueur < 1 || nb_joueur > 4); 
    init(plateau, nb_joueur);

    //initialisation des joueurs et de leur position
	Joueur joueurs[nb_joueur];
	for(int i=0;i<nb_joueur;i++){
		printf("--- Joueur %d ---\n", i + 1);
        init_joueur(&joueurs[i]);
		if (i == 0){
			joueurs[i].pos.x = 0;
			joueurs[i].pos.y = 4;
            joueurs[i].type = 1;
		}
		else if(i == 1){
			joueurs[i].pos.x = 2;
			joueurs[i].pos.y = 0;
            joueurs[i].type = 2;
		}
		else if(i == 2){
			joueurs[i].pos.x = 6;
			joueurs[i].pos.y = 2;
            joueurs[i].type = 3;
		}
		else{
			joueurs[i].pos.x = 4;
			joueurs[i].pos.y = 6;
            joueurs[i].type = 4;
		}
	}
    int i = 0, gagnant = 0;
    while(gagnant == 0){
        if(i >= nb_joueur)
            i = 0;
        tour(&joueurs[i], plateau);
        gagnant = est_gagnant(joueurs[i]);
        i++;
    }
    printf("fin");
	return 0;
}

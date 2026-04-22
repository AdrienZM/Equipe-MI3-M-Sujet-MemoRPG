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
		}
		else if(i == 1){
			joueurs[i].pos.x = 2;
			joueurs[i].pos.y = 0;
		}
		else if(i == 2){
			joueurs[i].pos.x = 6;
			joueurs[i].pos.y = 2;
		}
		else{
			joueurs[i].pos.x = 4;
			joueurs[i].pos.y = 6;
		}
	}
    printf("---------- Plateau ----------\n");
	afficher(plateau);
	return 0;
}

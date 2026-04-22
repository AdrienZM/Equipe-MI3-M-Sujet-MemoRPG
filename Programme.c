#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "structure.h"

#define TAILLE 7

int main(){
	srand(time(NULL));
	int plateau_admin[TAILLE][TAILLE];
	Case plateau_joueur[TAILLE][TAILLE];
	/*on changera ça après*/
	init_admin(plateau_admin);
	/*demande du nombre de joueurs puis initialisation des joueurs dans un tableau*/
	int nb_joueur;
	do{printf("Saisir le nombre de joueur : \n");
	   scanf("%d", &nb_joueur);
	   if(nb_joueur < 1 || nb_joueur > 4)
		   printf("Nombre de joueur impossible. Réessayer.\n");
	  }while(nb_joueur < 1 || nb_joueur > 4); 
    init_revele(plateau_joueur, nb_joueur);
	Joueur joueurs[nb_joueur];
	for(int i=0;i<nb_joueur;i++){
		printf("--- Joueur %d ---\n", i + 1);
        init_joueur(&joueurs[i]);
		if (i == 0){
			joueurs[i].pos.x = 0;
			joueurs[i].pos.y = 4;
			plateau_admin[0][4] = 1;
			plateau_joueur[0][4].correspond = '1';
		}
		else if(i == 1){
			joueurs[i].pos.x = 2;
			joueurs[i].pos.y = 0;
			plateau_admin[2][0] = 2;
			plateau_joueur[2][0].correspond = '2';
		}
		else if(i == 2){
			joueurs[i].pos.x = 6;
			joueurs[i].pos.y = 2;
			plateau_admin[6][2] = 3;
			plateau_joueur[6][2].correspond = '3';
		}
		else{
			joueurs[i].pos.x = 4;
			joueurs[i].pos.y = 6;
			plateau_admin[4][6] = 4;
			plateau_joueur[4][6].correspond = '4';
		}
	}
    printf("----------Plateau Admin----------\n");
	afficher_admin(plateau_admin);
	printf("----------Plateau Révélé----------\n");
	afficher_revele(plateau_joueur);
	return 0;
}

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
	printf("----------Plateau Admin----------\n");
	init_admin(plateau_admin);
	afficher_admin(plateau_admin);
	printf("----------Plateau Révélé----------\n");
	init_revele(plateau_joueur);
	afficher_revele(plateau_joueur);
	/*demande du nombre de joueurs puis initialisation des joueurs dans un tableau*/
	int nb_joueur;
	do{printf("Saisir le nombre de joueur : ");
	   scanf("%d", &nb_joueur);
	   if(nb_joueur < 1 || nb_joueur > 4)
		   printf("Nombre de joueur impossible. Réessayer.\n");
	  }while(nb_joueur < 1 || nb_joueur > 4);
	Joueur joueurs[nb_joueur];
	for(int i=0;i<nb_joueur;i++){
		Joueur j;
		init_joueur(&j);
		if(plateau_admin[0][4] == -1){
			j.pos.x = 0;
			j.pos.y = 4;
			plateau_admin[0][4] == 1;
			plateau_joueur[0][4].correspond == '1';
		}
		else if(plateau_admin[2][0] == -1){
			j.pos.x = 2;
			j.pos.y = 0;
			plateau_admin[0][4] == 2;
			plateau_joueur[0][4].correspond == '2';
		}
		else if(plateau_admin[6][2] == -1){
			j.pos.x = 6;
			j.pos.y = 2;
			plateau_admin[0][4] == 3;
			plateau_joueur[0][4].correspond == '3';
		}
		else{
			j.pos.x = 4;
			j.pos.y = 6;
			plateau_admin[0][4] == 4;
			plateau_joueur[0][4].correspond == '4';
		}
		joueurs[i] = j;
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

#define TAILLE 7

void init_admin(int tab[TAILLE][TAILLE]){
/*fonction qui initialise le plateau de jeu de 7 x 7 (pas le droit d'être sur la 1ere ligne, 1ere colonne et dernière ligne et dernière colonne) en placant aléatoirement les monstres (avec un type aléatoire : 
5 -> basilics ; 6 -> zombies ; 7 -> trolls ; 8 -> harpies), les totems (9), les coffres au trésors (10), le portail de téléportation (11) et les 4 armes antiques (12, 13, 14, 15)*/
	if(tab == NULL){
		printf("Tableau de départ = NULL(init_admin)");
		return;
	}
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			tab[i][j] = 0;
		}
	}
	for(int i=0;i<TAILLE;i++){
		tab[0][i] = -1;
		tab[6][i] = -1;
		tab[i][0] = -1;
		tab[i][6] = -1; 
	}	
	int j = 0, k = 0, nb_monstres = 0, nb_tresors = 0, nb_totems = 0, nb_arme_antique = 0;
	while(nb_monstres < 16){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(tab[j][k] == 0){
			tab[j][k] = rand() % 4 + 5;
			nb_monstres++;
		}
	}
	while(nb_totems < 2){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(tab[j][k] == 0){
			tab[j][k] = 9;
			nb_totems++;
		}
	}
	while(nb_tresors < 2){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(tab[j][k] == 0){
			tab[j][k] = 10;
			nb_tresors++;
		}
	}
	while(nb_arme_antique < 4){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(tab[j][k] == 0){
			tab[j][k] = 12 + nb_arme_antique;
			nb_arme_antique++;
		}
	}
	for(int i=1;i<TAILLE-1;i++){
		for(int j=1;j<TAILLE-1;j++){
			if(tab[i][j] == 0)
				tab[i][j] = 11;
		}
	}
}

void afficher_admin(int tab[TAILLE][TAILLE]){
	if(tab == NULL){
		printf("Tableau de départ = NULL(affiche_admin)");
		return;
	}
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}

void init_revele(Case plateau[TAILLE][TAILLE], int nb_joueurs){
	if(plateau == NULL){
		printf("Tableau de départ = NULL(init_revele)");
		return;
	}
    int c = 0;
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			plateau[i][j].contenu="[ ]";
			plateau[i][j].correspond = '0';
			if(i==0 || i==TAILLE-1 || j==0 || j==TAILLE-1){
				plateau[i][j].contenu = "   ";
			}
			if(i==0 && j==TAILLE-3 && c < nb_joueurs){
				plateau[i][j].contenu = "[ ]";
				plateau[i][j].correspond = '1';
                c++;
			}	
			else if(i==2 && j==0 && c < nb_joueurs){
				plateau[i][j].contenu = "[ ]";
				plateau[i][j].correspond = '2';
                c++;
			}
			else if(i==TAILLE-3 && j==TAILLE-1 && c < nb_joueurs){
				plateau[i][j].contenu = "[ ]";
				plateau[i][j].correspond = '3';
                c++;
			}
			else if(i==TAILLE-1 && j==2 && c < nb_joueurs){
				plateau[i][j].contenu = "[ ]";
				plateau[i][j].correspond = '4';
                c++;
			}
			
		}
	}
}
void afficher_revele(Case tab[TAILLE][TAILLE]){
	if(tab == NULL){
		printf("Tableau de départ = NULL(affiche_revele)");
		return;
	}
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			if(tab[i][j].correspond =='0'){
				printf("\033[37m%s\033[0m",tab[i][j].contenu);}
			else if(tab[i][j].correspond =='1'){
				printf("\033[31m%s\033[0m",tab[i][j].contenu);}
			else if(tab[i][j].correspond =='2'){
				printf("\033[32m%s\033[0m",tab[i][j].contenu);}
			else if(tab[i][j].correspond =='3'){
				printf("\033[33m%s\033[0m",tab[i][j].contenu);}
			else if(tab[i][j].correspond =='4'){
				printf("\033[34m%s\033[0m",tab[i][j].contenu);}
		}
		printf("\n");
	}
}

int est_gagnant(Joueur j){
	if(j.coffre >= 1 && j.arme_antique == 1)
		return 1;
	else
		return 0;
}
void init_joueur(Joueur* j){
	printf("Saisir le nom du joueur : ");
	scanf("%49s", j->nom);
    printf("\n");
	j->arme = 0;
	j->arme_antique = 0;
	j->coffre = 0;
}














































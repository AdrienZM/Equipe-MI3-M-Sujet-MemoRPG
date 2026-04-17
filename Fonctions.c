#include <stdio.h>
#include <stdlib.h>
#define TAILLE 7

void init_admin(int tab[TAILLE][TAILLE]){
/*fonction qui initialise le plateau de jeu de 7 x 7 (pas le droit d'être sur la première ligne / colonne et dernière ligne / colonne) en placant aléatoirement les monstres (avec un type aléatoire : 
1 -> basilics ; 2 -> zombies ; 3 -> trolls ; 4 -> harpies), les totems (5), les coffres au trésors (6), les 4 armes antiques (7, 8, 9, 10) et le portail de téléportation (11)*/
	//changer les num pour la procgaine fois
	if(tab == NULL){
		printf("Tableau de départ = NULL(init)");
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
	int j = 0, k = 0, nb_monstres = 0, nb_tresors = 0, nb_totems = 0;
	while(nb_monstres < 16){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(tab[j][k] == 0){
			tab[j][k] = rand() % 4 + 1;
			nb_monstres++;
		}
	}
	while(nb_totems < 2){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(tab[j][k] == 0){
			tab[j][k] = 5;
			nb_totems++;
		}
	}
	while(nb_tresors < 2){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(tab[j][k] == 0){
			tab[j][k] = 6;
			nb_tresors++;
		}
	}
	while(nb_arme_antique < 4){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(tab[j][k] == 0){
			tab[j][k] = 7;
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

void afficher_admin(int tab[7][7]){
	if(tab == NULL){
		printf("Tableau de départ = NULL(affiche)");
		return;
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}

void init_revele(Case plateau[][TAILLE]){
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			plateau[i][j].contenu="[ ]";
			plateau[i][j].correspond = '0';
			if(i==0 || i==TAILLE-1 || j==0 || j==TAILLE-1){
				plateau[i][j].contenu = "   ";
			}
			if(i==0 && j==TAILLE-3){
				plateau[i][j].contenu = "[ ]";
				plateau[i][j].correspond = '1';
			}	
			else if(i==2 && j==0){
				plateau[i][j].contenu = "[ ]";
				plateau[i][j].correspond = '2';
			}
			else if(i==TAILLE-3 && j==TAILLE-1){
				plateau[i][j].contenu = "[ ]";
				plateau[i][j].correspond = '3';
			}
			else if(i==TAILLE-1 && j==2){
				plateau[i][j].contenu = "[ ]";
				plateau[i][j].correspond = '4';
			}
			
		}
	}
}
void afficher_revele(Case tab[][TAILLE], int taille){
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			if(tab[i][j].correspond=='0'){
				printf("\033[37m%s\033[0m",tab[i][j]);}
			if(tab[i][j].correspond=='1'){
				printf("\033[31m%s\033[0m",tab[i][j]);}
			if(tab[i][j].correspond=='2'){
				printf("\033[32m%s\033[0m",tab[i][j]);}
			if(tab[i][j].correspond=='3'){
				printf("\033[33m%s\033[0m",tab[i][j]);}
			if(tab[i][j].correspond=='4'){
				printf("\033[34m%s\033[0m",tab[i][j]);}
		}
		printf("\n");
	}
}

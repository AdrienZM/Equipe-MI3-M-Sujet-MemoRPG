#include <stdio.h>
#include <stdlib.h>

void init(int tab[7][7]){
/*fonction qui initialise le plateau de jeu de 7 x 7 (pas le droit d'être sur la première ligne / colonne et dernière 
ligne / colonne) en placant aléatoirement les monstres (avec un type aléatoire : 1 -> basilics ; 2 -> zombies ;
3 -> trolls ; 4 -> harpies), les totems (5), les coffres au trésors (6) et le portail de téléportation (7)*/
	if(tab == NULL){
		printf("Tableau de départ = NULL(init)");
		return;
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			tab[i][j] = 0;
		}
	}
	for(int i=0;i<7;i++){
		tab[0][i] = -1;
		tab[6][i] = -1;
		tab[i][0] = -1;
		tab[i][6] = -1; 
	}
	/*for(int i=0;i<7;i++){
		tab[6][i] = -1; //dernière ligne
	}
	for(int i=1;i<6;i++){
		tab[i][0] = -1; //première colonne
	}
	for(int i=1;i<6;i++){
		tab[i][6] = -1; //dernière colonne
	}*/
	
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
	for(int i=1;i<6;i++){
		for(int j=1;j<6;j++){
			if(tab[i][j] == 0)
				tab[i][j] = 7;
		}
	}
}

void afficher(int tab[7][7]){
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

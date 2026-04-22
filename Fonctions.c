#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

#define TAILLE 7

void init(Case plateau[TAILLE][TAILLE], int nb_joueurs){
    /*fonction qui initialise le plateau de jeu de 7 x 7 (pas le droit d'être sur la 1ere ligne, 1ere colonne et dernière ligne et dernière colonne) en placant aléatoirement les monstres (avec un type aléatoire : 5 -> basilics ; 6 -> zombies ; 7 -> trolls ; 8 -> harpies), les totems (9), les coffres au trésors (10), le portail de téléportation (11) et les 4 armes antiques (12, 13, 14, 15)*/
    //initialisation des monstres et objets
	if(plateau == NULL){
		printf("Tableau de départ = NULL(init)");
		return;
	}
    for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			plateau[i][j].correspond = 0;
            plateau[i][j].revele = 0;
			plateau[i][j].contenu = "[ ]";
			if(i==0 || i==TAILLE-1 || j==0 || j==TAILLE-1)
				plateau[i][j].contenu = "   ";
		}
	}
	for(int i=0;i<TAILLE;i++){
		plateau[0][i].correspond = -1;
		plateau[6][i].correspond = -1;
		plateau[i][0].correspond = -1;
		plateau[i][6].correspond = -1; 
	}	
	int j = 0, k = 0, n = 0;
	while(n < 16){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(plateau[j][k].correspond == 0){
			plateau[j][k].correspond = rand() % 4 + 5;
			n++;
		}
	}
	n = 0;
	while(n < 2){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(plateau[j][k].correspond == 0){
			plateau[j][k].correspond = 9;
			n++;
		}
	}
	n = 0;
	while(n < 2){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(plateau[j][k].correspond == 0){
			plateau[j][k].correspond = 10;
			n++;
		}
	}
	n = 0;
	while(n < 4){
		j = rand()%5 + 1;
		k = rand()%5 + 1;
		if(plateau[j][k].correspond == 0){
			plateau[j][k].correspond = 12 + n;
			n++;
		}
	}
	for(int i=1;i<TAILLE-1;i++){
		for(int j=1;j<TAILLE-1;j++){
			if(plateau[i][j].correspond == 0)
				plateau[i][j].correspond = 11;
		}
    }
    //initialisation pour l'affichage et pour les joueurs
    if(nb_joueurs >= 1) plateau[0][4].correspond = 1;
    if(nb_joueurs >= 2) plateau[2][0].correspond = 2;
    if(nb_joueurs >= 3) plateau[6][2].correspond = 3;
    if(nb_joueurs >= 4) plateau[4][6].correspond = 4;
}

void afficher(Case plateau[TAILLE][TAILLE]){
	if(plateau == NULL){
		printf("Tableau de départ = NULL(affiche_revele)");
		return;
	}
    printf("Plateau Admin \n");
    for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
            printf("%d ", plateau[i][j].correspond);
        }
        printf("\n");
    }
    printf("Plateau Joueur\n");
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			if (plateau[i][j].correspond >= 1 && plateau[i][j].correspond <= 4) {
                switch(plateau[i][j].correspond) {
                    case 1: printf("\033[1;31m[1]\033[0m"); break; 
                    case 2: printf("\033[1;32m[2]\033[0m"); break; 
                    case 3: printf("\033[1;33m[3]\033[0m"); break; 
                    case 4: printf("\033[1;34m[4]\033[0m"); break; 
                }
            } 
            else if (plateau[i][j].revele == 1) {
                printf("\033[0;36m[X]\033[0m"); 
            }
            else if (plateau[i][j].contenu[0] == ' ') {
                printf("   ");
            }
            else {
                printf("\033[0;37m[ ]\033[0m");
            }
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

void tour(Joueur *j, Case plateau[TAILLE][TAILLE]){
    printf("\nC'est au tour de %s !\n", j->nom);
    //choix de l'arme
    do{printf("Choisir une arme : Bouclier (1) ; Hache (2) ; Torche (3) ; Arc(4)\n");
       scanf("%d", &j->arme);
       if(j->arme < 1 || j->arme > 4)
           printf("Mauvaise saisie. Réessayer.\n");
    }while(j->arme < 1 || j->arme > 4);

    //choix de la case
    char case_choisie;
    do{printf("Choisir la case où aller : 'h' --> haut ; 'g' --> gauche ; 'b' --> bas ; 'd' --> droite\n");
       scanf("%c", &case_choisie);
       if(case_choisie != 'h' && case_choisie != 'g' && case_choisie != 'b' && case_choisie != 'd')
           printf("Mauvaise saisie. Réessayer.\n");
    }while(case_choisie != 'h' && case_choisie != 'g' && case_choisie != 'b' && case_choisie != 'd');

    //déplacement à faire
    if(case_choisie == 'h'){
        if(j->pos.x + 1 > 0){
            
        }
        else
            printf("Déplacement impossible : sortie du plateau.");
    }
    else if(case_choisie == 'b'){
        if(j->pos.x - 1 < 6){
            
        }
        else
            printf("Déplacement impossible : sortie du plateau.");
    }
    if(case_choisie == 'g'){
        if(j->pos.y - 1 > 0){
            
        }
        else
            printf("Déplacement impossible : sortie du plateau.");
    }
    if(case_choisie == 'd'){
        if(j->pos.y + 1 < 6){
            
        }
        else
            printf("Déplacement impossible : sortie du plateau.");
    }
}

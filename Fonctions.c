#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

#define TAILLE 7
void init(Case plateau[TAILLE][TAILLE], int nb_joueurs) {
    /*fonction qui initialise le plateau de jeu de 7 x 7 (pas le droit d'être sur la 1ere ligne, 1ere colonne et dernière ligne et dernière colonne) en placant aléatoirement les monstres : basilics (5) ; zombies (6) ; trolls (7) ; harpies (8), les totems (9), les coffres au trésors (10), le portail de téléportation (11) et les 4 armes antiques (12, 13, 14, 15)*/
    
    //Initialisation des monstres et objets
    if (plateau == NULL) {
        printf("Tableau de départ = NULL (init)\n");
        return;
    }
    
    //Initialisation du plateau à 0 et du contenu à afficher
    for (int i = 0 ; i < TAILLE ; i++) {
        for (int j = 0 ; j < TAILLE ; j++) {
            plateau[i][j].correspond = 0;
            plateau[i][j].revele = 0;
            plateau[i][j].contenu = "[ ]";
            if (i == 0 || i == TAILLE - 1 || j == 0 || j == TAILLE - 1)
                plateau[i][j].contenu = "    ";
        }
    }
    
    //Initialisation des bordures
    for (int i = 0 ; i < TAILLE ; i++) {
        plateau[0][i].correspond = - 1;
        plateau[6][i].correspond = - 1;
        plateau[i][0].correspond = - 1;
        plateau[i][6].correspond = - 1; 
    }
    
    //Initialisation des monstres : basilics (5) ; zombies (6) ; trolls (7) ; harpies (8)
    int j = 0, k = 0, n = 0;
    while (n < 16) {
        j = rand() % 5 + 1;
        k = rand() % 5 + 1;
        if (plateau[j][k].correspond == 0) {
            plateau[j][k].correspond = rand() % 4 + 5;
            n++;
        }
    }
    
    //Initialisation des Totems : 9
    n = 0;
    while (n < 2) {
        j = rand() % 5 + 1;
        k = rand() % 5 + 1;
        if (plateau[j][k].correspond == 0) {
            plateau[j][k].correspond = 9;
            n++;
        }
    }
    
    //Initialisation des Coffres au Trésors : 10
    n = 0;
    while (n < 2) {
        j = rand() % 5 + 1;
        k = rand() % 5 + 1;
        if (plateau[j][k].correspond == 0) {
            plateau[j][k].correspond = 10;
            n++;
        }
    }
    
    //Initialisation des Armes Antiques : 12, 13, 14, 15
    n = 0;
    while (n < 4) {
        j = rand() % 5 + 1;
        k = rand() % 5 + 1;
        if (plateau[j][k].correspond == 0) {
            plateau[j][k].correspond = 12 + n;
            n++;
        }
    }
    
    //Initialisation du Portail de Téléportation : 11
    for (int i = 1 ; i < TAILLE - 1 ; i++) {
        for (int j = 1 ; j < TAILLE - 1 ; j++) {
            if (plateau[i][j].correspond == 0)
                plateau[i][j].correspond = 11;
        }
    }
    
    //Initialisation pour l'affichage et pour les joueurs
    if (nb_joueurs >= 1) 
        plateau[0][4].correspond = 1;
    if (nb_joueurs >= 2) 
        plateau[2][0].correspond = 2;
    if (nb_joueurs >= 3) 
        plateau[6][2].correspond = 3;
    if (nb_joueurs >= 4) 
        plateau[4][6].correspond = 4;
}

void afficher(Case plateau[TAILLE][TAILLE]) {
    /*Cette fonction permet d'afficher le plateau en prenant en compte si la case à un joueur (pas encore fait : le joueur reste statique sur la case de départ) et si elle est révélée ou non (met différentes couleurs selon les cas)*/
    
    if (plateau == NULL) {
        printf("Tableau de départ = NULL (affiche)\n");
        return;
    }

    //on enlèvera ça plus tard (c'est beaucoup plus simple de tester le programme avec le plateau des réponses)
    printf("----------Plateau Admin----------\n");
    for (int i = 0 ; i < TAILLE ; i++) {
        for (int j = 0 ; j < TAILLE ; j++) {
            printf("%3d ", plateau[i][j].correspond);
        }
        printf("\n");
    }
    
    printf("----------Plateau----------\n");
    for (int i = 0 ; i < TAILLE ; i++) {
        for (int j = 0 ; j < TAILLE ; j++) {
            if (plateau[i][j].correspond >= 1 && plateau[i][j].correspond <= 4) {
                switch(plateau[i][j].correspond) {
                    case 1: printf("\033[1;31m[%2d]\033[0m", plateau[i][j].correspond) ; break; 
                    case 2: printf("\033[1;32m[%2d]\033[0m", plateau[i][j].correspond) ; break; 
                    case 3: printf("\033[1;33m[%2d]\033[0m", plateau[i][j].correspond) ; break; 
                    case 4: printf("\033[1;34m[%2d]\033[0m", plateau[i][j].correspond) ; break; 
                }
            } 
            else if (plateau[i][j].revele == 1) {
                printf("\033[0;36m[%2d]\033[0m", plateau[i][j].correspond); 
            }
            else if (plateau[i][j].contenu[0] == ' ') {
                printf("    ");
            }
            else {
                printf("\033[0;37m[  ]\033[0m");
            }
        }
        printf("\n");
    }
}

int est_gagnant(Joueur j){
    /*Fonction qui vérifie si un joueur j est gagnant*/
    
	if(j.coffre >= 1 && j.arme_antique == 1)
		return 1;
	else
		return 0;
}

void init_joueur(Joueur* j){
    /*Fonction qui initialise le nom, l'arme actuelle, l'arme antique et le nombre de coffre du joueur à 0*/
    
    if(j == NULL){
		printf("Joueur inexistant (init_joueur)\n");
		return;
    }
    
	printf("Saisir le nom du joueur : ");
	scanf("%49s", j->nom);
    printf("\n");
	j->arme = 0;
	j->arme_antique = 0;
	j->coffre = 0;
}

void tour(Joueur *j, Case plateau[TAILLE][TAILLE]){
    /*Fonction qui fait le tour d'un joueur : affiche le plateau, demande l'arme à choisir, demande la case où aller et en fonction de la valeur de l'élément correspond de la case, vérifie et exécute les différentes options*/

    if (j == NULL || plateau == NULL) {
        printf("Joueur inexistant ou plateau = NULL (tour)\n");
        return;
    }
    
    char case_choisie;
    int ligne, colonne, recommencer, teleportation = 0, x, y;
    Coordonnees depart = j->pos;
    printf("\nC'est au tour de %s !\n", j->nom);
    afficher(plateau);
    
    do {
        recommencer = 0;
        //Demande l'arme à choisir
        do {
            printf("Arme : Bouclier(1), Torche(2), Hache(3), Arc(4) : ");
            if (scanf("%d", &j->arme) != 1) {
                printf("Mauvaise saisie. Réessayer.\n");
                while (getchar() != '\n');
            }
        } while (j->arme < 1 || j->arme > 4);

        /*Demande, s'il n'y a pas eu de téléportation, la prochaine case où aller ; S'il y a eu une téléportation, la case où le joueur s'est téléporté est la case qui va être révélée*/
        x = j->pos.x;
        y = j->pos.y;
        if (teleportation == 0) {
            do {
                printf("Choisir la case où aller : 'h' --> haut ; 'g' --> gauche ; 'b' --> bas ; 'd' --> droite ");
                scanf(" %c", &case_choisie);
                printf("\n");
                if (case_choisie == 'h' && j->pos.x - 1 > 0)
                    x--;
                else if (case_choisie == 'b' && j->pos.x + 1 < 6)
                    x++;
                else if (case_choisie == 'g' && j->pos.y - 1 > 0)
                    y--;
                else if (case_choisie == 'd' && j->pos.y + 1 < 6)
                    y++;
                else
                    printf("Mauvaise saisie. Réessayer.\n");
                
                if (x < 1 || x > 5 || y < 1 || y > 5)
                    printf("Déplacement impossible : sortie du plateau.\n");
            } while ((case_choisie != 'h' && case_choisie != 'g' && case_choisie != 'b' && case_choisie != 'd') || x < 1 || x > 5 || y < 1 || y > 5);
        }
        teleportation = 0;
        j->pos.x = x;
        j->pos.y = y;

        //Vérifie que la case choisie n'est pas déjà révélée
        if (plateau[j->pos.x][j->pos.y].revele == 1) {
            printf("Case déjà révélée. Réessayer.\n");
            recommencer = 1;
            j->pos = depart;
        }
            
        else {
            //Révélation de la case
            plateau[j->pos.x][j->pos.y].revele = 1;
            afficher(plateau);
            if (plateau[j->pos.x][j->pos.y].correspond <= 8 && plateau[j->pos.x][j->pos.y].correspond >= 5) { //Monstres
                if (j->arme == plateau[j->pos.x][j->pos.y].correspond - 4) { //Bonne arme
                    printf("Bravo ! Vous avez battu le monstre ! Vous pouvez continuer votre chemin.\n");
                    recommencer = 1;
                }
                else { //Mauvaise arme
                    printf("Vous êtes mort ! Vous réapparaisser à votre position initiale.");
                    j->pos = depart;
                }
            }
            else if (plateau[j->pos.x][j->pos.y].correspond == 9) { //Totem
                printf("Vous avez découvert un Totem de Transmutation !\n");
                do {
                    printf("Quelle case cachée voulez-vous échanger ? (ligne (1 à 5) colonne (1 à 5)\n");
                    scanf("%d %d", &ligne, &colonne);
                    if (ligne < 1 || ligne > 5 || (colonne < 1) || colonne > 5)
                        printf("Mauvaise saisie : sortie du plateau.\n");
                    else if (plateau[ligne][colonne].revele == 1)
                        printf("Case déjà révélée. Mauvaise saisie.\n");
                } while (ligne < 1 || ligne > 5 || (colonne < 1) || colonne > 5 || plateau[ligne][colonne].revele == 1);
                //échange des deux cases
                Case t = plateau[j->pos.x][j->pos.y];
                plateau[j->pos.x][j->pos.y] = plateau[ligne][colonne];
                plateau[ligne][colonne] = t;
                j->pos = depart;
            }
            else if (plateau[j->pos.x][j->pos.y].correspond == 10) { //Coffre au Trésor
                printf("Bravo ! Vous avez découvert un Coffre au Trésor !\n");
                j->coffre++;
                recommencer = 1;
                if (est_gagnant(*j) == 1) {
                    printf("Bravo ! %s est gagnant !\n", j->nom);
                    break;
                }
            }        
            else if (plateau[j->pos.x][j->pos.y].correspond == 11) { //Portail de Téléportation
                printf("Bravo ! Vous avez découvert un Portail de Téléportation !\n");
                do {
                    printf("Sur quelle case cachée voulez-vous vous téléporter ? (ligne (1 à 5) colonne (1 à 5)\n");
                    scanf("%d %d", &ligne, &colonne);
                    if (ligne < 1 || ligne > 5 || (colonne < 1) || colonne > 5)
                        printf("Mauvaise saisie : sortie du plateau.\n");
                    else if (plateau[ligne][colonne].revele == 1)
                        printf("Case déjà révélée. Mauvaise saisie.\n");
                } while (ligne < 1 || ligne > 5 || (colonne < 1) || colonne > 5 || plateau[ligne][colonne].revele == 1);
                
                printf("Vous vous téléporter sur la case %d %d !\n", ligne, colonne);
                j->pos.x = ligne;
                j->pos.y = colonne;
                recommencer = 1;
                teleportation = 1;
            }
            else if (plateau[j->pos.x][j->pos.y].correspond <= 15 && plateau[j->pos.x][j->pos.y].correspond >= 12) { //Arme Antique
                printf("Bravo ! Vous avez découvert une Arme Antique !\n");
                if (j->type == plateau[j->pos.x][j->pos.y].correspond - 11) {
                    printf("Bravo ! Vous avez découvert votre Arme Antique !\n");
                    j->arme_antique++;
                    if (est_gagnant(*j) == 1) {
                        printf("Bravo ! %s est gagnant !\n", j->nom);
                        break;
                    }
                }
                else
                    printf("Dommage ! Vous n'avez pas découvert votre Arme Antique !\n");
                recommencer = 1;
            }
        }
    } while (recommencer == 1);
}

void retourner(Case plateau[TAILLE][TAILLE]) {
    /*Fonction qui retourne toutes les cases après le tour d'un joueur*/
    for (int i = 1 ; i < TAILLE - 1 ; i++) {
        for (int j = 1 ; j < TAILLE - 1 ; j++) {
            plateau[i][j].revele = 0;
        }
    }
}

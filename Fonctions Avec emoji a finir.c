#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

#define TAILLE 7

void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void init(Case plateau[TAILLE][TAILLE], int nb_joueurs) {
	/*fonction qui initialise le plateau de jeu de 7 x 7 (pas le droit d'être sur la 1ere ligne, 1ere colonne et dernière ligne et dernière colonne) en placant aléatoirement les monstres : basilics (5) ; zombies (6) ; trolls (7) ; harpies (8), les totems (9), les coffres au trésors (10), le portail de téléportation (11) et les 4 armes antiques (12, 13, 14, 15)*/

	//Initialisation des monstres et objets
	if (plateau == NULL) {
		printf("Tableau de départ = NULL (init).\n");
		return;
	}

	if (nb_joueurs < 1 || nb_joueurs > 4) {
		printf("Nombre de joueurs impossible (init).\n");
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
}

char* correspondance_affichage(int numero) {
	/*Fonction qui renvoie un emoji en fonction du numéro passer en entrée*/
	if (numero < 1 || numero > 15) {
		printf("Nombre impossible (correspondance).\n");
		return "???";
	}

	switch (numero) {
	
		case -1 : 
			return "VIDE";
		case 1 :
			return "🧙" ;
		case 2 :
			return "🧝" ;
		case 3 :
			return "🫅" ;
		case 4 :
			return "🧞" ;
		case 5 :
			return "🦎" ;
		case 6 :
			return "🧟" ;
		case 7 :
			return "🧌" ;
		case 8 :
			return "🐦" ;
		case 9 :
			return "🪄" ;
		case 10 :
			return "💰" ;
		case 11 :
			return "🌀" ;
		case 12 :
			return "🪄" ;
		case 13 :
			return "🏹" ;
		case 14 :
			return "⚔" ;
		case 15 :
			return "🪔" ;
		default : {
			printf("Erreur, non affichable");
			return "???";
			}
		}
}
char* correspondance_Nom(int numero) {
	/*Fonction qui renvoie un emoji en fonction du numéro passer en entrée*/
	if (numero < 1 || numero > 15) {
		printf("Nombre impossible (correspondance).\n");
		return "???";
	}

	switch (numero) {
	
		case -1 : 
			return "VIDE";
		case 1 :
			return "Mage" ;
		case 2 :
			return "Elfe" ;
		case 3 :
			return "Roi" ;
		case 4 :
			return "Génie" ;
		case 5 :
			return "Basilick" ;
		case 6 :
			return "Zombie" ;
		case 7 :
			return "Troll" ;
		case 8 :
			return "Harpi" ;
		case 9 :
			return "Totem" ;
		case 10 :
			return "Trésor" ;
		case 11 :
			return "Portail" ;
		case 12 :
			return "Arme ultime mage" ;
		case 13 :
			return "Arme ultime Elef" ;
		case 14 :
			return "Arme ultime Roi" ;
		case 15 :
			return "Arme ultime Génie" ;
		default : {
			printf("Erreur, non affichable");
			return "???";
			}
		}
}

void afficher(Case plateau[TAILLE][TAILLE], Joueur *joueurs, int nb_joueurs) {
	if (plateau == NULL) {
		printf("Tableau de départ = NULL (afficher).\n");
		return;
	}

	if (joueurs == NULL) {
		printf("Tableau des joueurs = NULL (afficher).\n");
		return;
	}

	if (nb_joueurs < 1 || nb_joueurs > 4) {
		printf("Nombre de joueurs impossible (afficher).\n");
		return;
	}

	printf("----------Plateau Admin----------\n");
	for (int i = 0 ; i < TAILLE ; i++) {
		for (int j = 0 ; j < TAILLE ; j++) {
			printf("%3d ", plateau[i][j].correspond);
		}
		printf("\n");
	}

	for(int i = 0 ; i < nb_joueurs ; i++) {
		printf("Joueur %d : %s \n", i+1, joueurs[i].nom);
	}

	printf("\n----------Plateau----------\n");
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {

			//on vérifie si un joueur est sur la case i, j
			int id_joueur = -1;
			for (int k = 0; k < nb_joueurs; k++) {
				if (joueurs[k].pos.x == i && joueurs[k].pos.y == j) {
					id_joueur = k + 1; // on récupère le numéro (1 à 4)
					break;
				}
			}

			//si oui, on affiche le joueur
			if (id_joueur != -1) {
				switch(id_joueur) {
				case 1:
					printf("\033[1;31m[🧙]\033[0m");
					break; // Rouge
				case 2:
					printf("\033[1;32m[🧝]\033[0m");
					break; // Vert
				case 3:
					printf("\033[1;33m[🫅]\033[0m");
					break; // Jaune
				case 4:
					printf("\033[1;34m[🧞]\033[0m");
					break; // Bleu
				}
			
			}

			//sinon, on affiche le contenu de la case
			else if (plateau[i][j].revele == 1)
				printf("\033[0;36m[%s]\033[0m", correspondance_affichage(plateau[i][j].correspond));
			else if (i == 0 || i == TAILLE - 1 || j == 0 || j == TAILLE - 1)
				printf("    ");
			else
				printf("\033[0;37m[  ]\033[0m");
		}
		printf("\n");
		
	}
}

int est_gagnant(Joueur j) {
	/*Fonction qui vérifie si un joueur j est gagnant*/
	if(j.coffre >= 1 && j.arme_antique == 1)
		return 1;
	else
		return 0;
}

void init_joueur(Joueur* j) {
	/*Fonction qui initialise le nom, l'arme actuelle, l'arme antique et le nombre de coffre du joueur à 0*/
	if(j == NULL) {
		printf("Joueur inexistant (init_joueur).\n");
		return;
	}

	printf("Saisir le nom du joueur (pas d'espaces) : ");
	scanf("%49s", j->nom);
	viderBuffer();
	printf("\n");
	j->arme = 0;
	j->arme_antique = 0;
	j->coffre = 0;
}

int peut_jouer(Joueur *j, Case plateau[TAILLE][TAILLE]) {
	/*Fonction qui vérifie si le joueur peut jouer son tour : s'il n'est pas entouré de case révélées et de bordures*/
	if (plateau == NULL) {
		printf("Tableau de départ = NULL (peut_jouer).\n");
		return 0;
	}

	if (j == NULL) {
		printf("Joueur inexistant (peut_jouer).\n");
		return 0;
	}

	int x = j->pos.x;
	int y = j->pos.y;
	if (x > 1 && plateau[x - 1][y].revele == 0 && plateau[x - 1][y].correspond > 4)
		return 1;

	if (x < 5 && plateau[x + 1][y].revele == 0 && plateau[x + 1][y].correspond > 4)
		return 1;

	if (y > 1 && plateau[x][y - 1].revele == 0 && plateau[x][y - 1].correspond > 4)
		return 1;

	if (y < 5 && plateau[x][y + 1].revele == 0 && plateau[x][y + 1].correspond > 4)
		return 1;
	return 0;
}

void tour(Joueur *j, Case plateau[TAILLE][TAILLE], Joueur *joueurs, int nb_joueurs) {
	/*Fonction qui fait le tour d'un joueur : affiche le plateau, demande l'arme à choisir, demande la case où aller et en fonction de la valeur de l'élément correspond de la case, vérifie et exécute les différentes options*/

	if (j == NULL) {
		printf("Joueur inexistant (tour).\n");
		return;
	}

	if (plateau == NULL) {
		printf("Tableau de départ = NULL (tour).\n");
		return;
	}

	if (joueurs == NULL) {
		printf("Tableau des joueurs = NULL (tour).\n");
		return;
	}

	if (nb_joueurs < 1 || nb_joueurs > 4) {
		printf("Nombre de joueurs impossible (tour).\n");
		return;
	}

	char case_choisie;
	int ligne, colonne, recommencer, teleportation = 0, x, y;
	Coordonnees depart = j->pos;
	afficher(plateau, joueurs, nb_joueurs);
	printf("\nC'est au tour de %s !\n", j->nom);

	do {
		recommencer = 0;
		//Demande l'arme à choisir
		do {
			printf("Arme : Bouclier🛡(1), Torche🔥(2), Hache🪓(3), Arc🏹(4) : ");
			if (scanf("%d", &j->arme) != 1 || j->arme < 1 || j->arme > 4) {
				viderBuffer();
				printf("Mauvaise saisie arme. Réessayer.\n");
				while (getchar() != '\n');
				j->arme = 0;
			}
		} while (j->arme < 1 || j->arme > 4);

		if(peut_jouer(j, plateau) == 0) {
			printf("%s ne peut plus jouer ! Il est bloqué.\n", j->nom);
			break;
		}

		/*Demande, s'il n'y a pas eu de téléportation, la prochaine case où aller ; S'il y a eu une téléportation, la case où le joueur s'est téléporté est la case qui va être révélée*/
		x = j->pos.x;
		y = j->pos.y;
		if (teleportation == 0) {
			do {
				x = j->pos.x;
				y = j->pos.y; //si on le fait pas ils peuvent garder les valeurs d'un scanf précédent
				printf("Choisir la case où aller : 'h' --> haut ; 'g' --> gauche ; 'b' --> bas ; 'd' --> droite ; '!' --> sortie forcée : ");
				if (scanf(" %c", &case_choisie) != 1) {
					viderBuffer();
					printf("Mauvaise saisie case. Réessayer.\n");
				}
				while (getchar() != '\n');

				if (case_choisie == 'h' && plateau[j->pos.x - 1][j->pos.y].correspond > 4)
					x--;
				else if (case_choisie == 'b' && plateau[j->pos.x + 1][j->pos.y].correspond > 4)
					x++;
				else if (case_choisie == 'g' && plateau[j->pos.x][j->pos.y - 1].correspond > 4)
					y--;
				else if (case_choisie == 'd' && plateau[j->pos.x][j->pos.y + 1].correspond > 4)
					y++;
				else if(case_choisie == '!')
					exit(0);
				else
					printf("Mauvaise saisie de direction. Réessayer.\n");

				if (x < 1 || x > 5 || y < 1 || y > 5) {
					printf("Déplacement impossible : sortie du plateau.\n");
					case_choisie = 'e';
				}
				//Vérifie que la case choisie n'est pas déjà révélée
				if (plateau[x][y].revele == 1) {
					printf("Case déjà révélée. Réessayer.\n");
					case_choisie = 'e';
				}
			} while (case_choisie != 'h' && case_choisie != 'g' && case_choisie != 'b' && case_choisie != 'd');
		}

		teleportation = 0;
		j->pos.x = x;
		j->pos.y = y;
		//Révélation de la case
		plateau[j->pos.x][j->pos.y].revele = 1;
		int posJx, posJy;
		afficher(plateau, joueurs, nb_joueurs );
		printf("Le Joueurs est actuellement sur : %s", correspondance_Nom(plateau[j->pos.x][j->pos.y].correspond));
		printf("\n");

		if (plateau[j->pos.x][j->pos.y].correspond <= 8 && plateau[j->pos.x][j->pos.y].correspond >= 5) { //Monstres
			if (j->arme == plateau[j->pos.x][j->pos.y].correspond - 4) { //Bonne arme
				printf("Bravo ! %s a battu le monstre ! Vous pouvez continuer votre chemin.\n", j->nom);
				recommencer = 1;
			}
			else { //Mauvaise arme
				printf("%s es mort ! Il réapparait à sa position initiale.\n", j->nom);
				j->pos = depart;
			}
		}
		else if (plateau[j->pos.x][j->pos.y].correspond == 9) { //Totem
			printf("%s a découvert un Totem de Transmutation !\n", j->nom);
			do {
				printf("Quelle case cachée veux-tu échanger ? (ligne (1 à 5) colonne (1 à 5)\n");
				scanf("%d %d", &ligne, &colonne);
				viderBuffer();
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
			printf("Bravo ! %s a découvert un Coffre au Trésor !\n", j->nom);
			j->coffre++;
			recommencer = 1;
			if (est_gagnant(*j) == 1) {
				printf("Bravo ! %s est gagnant !\n", j->nom);
				break;
			}
		}
		else if (plateau[j->pos.x][j->pos.y].correspond == 11) { //Portail de Téléportation
			printf("Bravo ! %s a découvert un Portail de Téléportation !\n", j->nom);
			do {
				printf("Sur quelle case cachée veux-tu te téléporter ? (ligne (1 à 5) colonne (1 à 5)\n");
				scanf("%d %d", &ligne, &colonne);
				viderBuffer();
				if (ligne < 1 || ligne > 5 || (colonne < 1) || colonne > 5)
					printf("Mauvaise saisie : sortie du plateau.\n");
				else if (plateau[ligne][colonne].revele == 1)
					printf("Case déjà révélée. Mauvaise saisie.\n");
			} while (ligne < 1 || ligne > 5 || (colonne < 1) || colonne > 5 || plateau[ligne][colonne].revele == 1);

			printf("%s se téléporter sur la case %d %d !\n", j->nom, ligne, colonne);
			j->pos.x = ligne;
			j->pos.y = colonne;
			recommencer = 1;
			teleportation = 1;
		}
		else if (plateau[j->pos.x][j->pos.y].correspond <= 15 && plateau[j->pos.x][j->pos.y].correspond >= 12) { //Arme Antique
			printf("Bravo ! %s a découvert une Arme Antique !\n", j->nom);
			if (j->type == plateau[j->pos.x][j->pos.y].correspond - 11) {
				printf("%s a découvert son Arme Antique !\n", j->nom);
				j->arme_antique++;
				if (est_gagnant(*j) == 1) {
					printf("Bravo ! %s est gagnant !\n", j->nom);
					break;
				}
			}
			else
				printf("Dommage ! %s n'a pas découvert son Arme Antique !\n", j->nom);
			recommencer = 1;
		}
	} while (recommencer == 1);
}

void reinitialiser(Case plateau[TAILLE][TAILLE], Joueur *j) {
	/*Fonction qui retourne toutes les cases après le tour d'un joueur*/
	if (plateau == NULL) {
		printf("Tableau de départ = NULL (reinitialiser).\n");
		return;
	}

	if (j == NULL) {
		printf("Joueur inexistant (reinitialiser).\n");
		return;
	}

	for (int i = 1 ; i < TAILLE - 1 ; i++) {
		for (int j = 1 ; j < TAILLE - 1 ; j++) {
			plateau[i][j].revele = 0;
		}
	}
	j->coffre = 0;
	j->arme_antique = 0;
}

void sauvegarder(Joueur* joueurs_partie, int nb_joueurs, char* nom_gagnant) {
	/*Fonction qui sauvegarde dans un fichier texte le nombre de victoires et de parties jouées de chaque joueurs. Elle stocke toutes les données des parties précédentes dans un tableau temporaire puis vérifie si le gagnant est un nouveau joueur ou non et lui ajoute un victoire*/
	/*Faite par Gemini*/
	if (joueurs_partie == NULL) {
		printf("Tableau des joueurs = NULL (sauvegarder).\n");
		return;
	}

	if (nb_joueurs < 1 || nb_joueurs > 4) {
		printf("Nombre de joueurs impossible (sauvegarder).\n");
		return;
	}

	if (nom_gagnant == NULL) {
		printf("Nom du gagnant = NULL (sauvegarder).\n");
		return;
	}

	FILE* f = fopen("Game_History.txt", "r");
	Statistique historique[200]; //200 joueurs différents max
	int total_historique = 0;

	//on stocke toutes les données des parties précédentes dans un tableau temporaire (historique)
	if (f != NULL) {
		while (fscanf(f, "%s %d %d", historique[total_historique].nom, &historique[total_historique].parties, &historique[total_historique].victoires) != EOF) {
			viderBuffer();
			total_historique++;
		}
		fclose(f);
	}

	//mise à jour avec les joueurs de la partie actuelle
	for (int i = 0; i < nb_joueurs; i++) {
		//joueur gagnant déjà dans le fichier
		int trouve = 0;
		for (int j = 0; j < total_historique; j++) {
			if (strcmp(joueurs_partie[i].nom, historique[j].nom) == 0) {
				historique[j].parties++;
				if (strcmp(joueurs_partie[i].nom, nom_gagnant) == 0)
					historique[j].victoires++;
				trouve = 1;
				break;
			}
		}

		//nouveau joueur gagnant
		if (trouve == 0 && total_historique < 200) {
			strcpy(historique[total_historique].nom, joueurs_partie[i].nom);
			historique[total_historique].parties = 1;
			historique[total_historique].victoires = (strcmp(joueurs_partie[i].nom, nom_gagnant) == 0) ? 1 : 0;
			total_historique++;
		}
	}

	f = fopen("Game_History.txt", "w");
	if (f == NULL) {
		printf("Erreur lors de l'enregistrement du fichier !\n");
		return;
	}

	//réécriture du fichier
	for (int i = 0; i < total_historique; i++) {
		fprintf(f, "%s %d %d\n", historique[i].nom, historique[i].parties, historique[i].victoires);
	}
	fclose(f);
	printf("\nHistorique mis à jour dans 'Game_History.txt'.\n");
}


#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct{
	int x, y;
}Coordonnees;

typedef struct{
	Coordonnees pos;
	int type_monstre;
}Monstre;

typedef struct{
	int type_arme;
}Arme;

typedef struct{
	int type_objet;
}Objet;

typedef struct{
	Coordonnees pos;
	Arme arme;
	int arme_antique, coffre;
	Objet objet;
	char nom[50];
}Joueur;

typedef struct{
/* Ici on crée un struct qui représente chaque case du tableaux, dedans on met ce que contient la case et si elle a été révélé par un joueur (donc il faut la retourner)*/

	char* contenu;
	char correspond;//0: caché; 1,2,3,4: les joueurs;
	int revele;
}Case;
#endif

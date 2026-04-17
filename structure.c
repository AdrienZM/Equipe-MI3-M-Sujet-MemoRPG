#include <stdio.h>

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
	int arme_antique;
	Objet objet;
	char nom[50];
}Joueur;

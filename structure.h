#ifndef STRUCTURE_H
#define STRUCTURE_H

 typedef struct{
    int x, y;
}Coordonnees;

typedef struct{
    Coordonnees pos; 
    int arme, arme_antique, coffre, type;
    char nom[50];
}Joueur;

typedef struct{
/* Ici on crée un struct qui représente chaque case du tableaux, dedans on met ce que contient la case et si elle a été révélé par un joueur (donc il faut la retourner)*/
    char* contenu;
    int correspond, revele;
    /*caché (0) ; joueurs (1, 2, 3, 4) ; basilics (5) ; zombies (6) ; trolls (7) ; harpies (8) ; totems (9) ; coffres au trésors (10) ; portail de téléportation (11) ; armes antiques (12, 13, 14, 15)*/
}Case; 
#endif

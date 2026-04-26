#ifndef STRUCTURE_H
#define STRUCTURE_H

 typedef struct {
    int x, y;
} Coordonnees;

typedef struct {
    Coordonnees pos;
    int arme, arme_antique, coffre, type;
    char nom[50];
} Joueur;

typedef struct {  
    char* contenu;
    int correspond, revele;
    /*joueurs (1, 2, 3, 4) ; basilics (5) ; zombies (6) ; trolls (7) ; harpies (8) ; totems (9) ; coffres au trésors (10) ; portail de téléportation (11) ; armes antiques (12, 13, 14, 15) ; revele = 0 si cachée, 1 si révélée*/
} Case;
#endif

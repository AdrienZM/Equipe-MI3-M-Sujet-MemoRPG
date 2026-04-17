#include<stdio.h>
#define TAILLE 7

typedef struct{
/* Ici on crée un struct qui représente chaque case du tableaux, dedans on met ce que contient la case et si elle a été révélé par un joueur (donc il faut la retourner)*/

	char* contenu;
	char correspond;//0: caché; 1,2,3,4: les joueurs;
	int révélé;
}Case;

void init(Case plateau[][TAILLE]){
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
void afficher(Case tab[][TAILLE], int taille){
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
int main(){
	
	Case grille[TAILLE][TAILLE];
	init(grille);
	afficher(grille,TAILLE);

	return 0;
	
}

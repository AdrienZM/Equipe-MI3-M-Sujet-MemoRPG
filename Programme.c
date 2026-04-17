#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "structure.h"

int main(){
	int plateau_admin[7][7], plateau_joueur[7][7];
	init(plateau_admin);
	afficher(plateau_admin);
	
	return 0;
}

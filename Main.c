#include "Header.h"

int main() {
	//tab contenant toutes les tuiles mobiles
	Tuile tabTuilesMobiles[TUILEMOBILE];

	//Matrice de toutes les tuiles
	Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU];

	creationPlateau(plateau); //pose des tuiles fixes
	initPlateau(tabTuilesMobiles, plateau); //remplissage aléatoire avec les tuiles dispo
	afficherPlateau(plateau); //affichage du plateau de jeu après les opérations logiques

	return 0;
}
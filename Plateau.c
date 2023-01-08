#include "Header.h"

void creationPlateau(Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU])
{
	//Plateau des tuiles fixes
	const char plateauTuilesBase[TAILLEPLATEAU][TAILLEPLATEAU] = {
   {'L', ' ', 'T', ' ', 'T', ' ', 'L'},
   {' ', ' ', ' ', ' ', ' ', ' ', ' '},
   {'T', ' ', 'T', ' ', 'T', ' ', 'T'},
   {' ', ' ', ' ', ' ', ' ', ' ', ' '},
   {'T', ' ', 'T', ' ', 'T', ' ', 'T'},
   {' ', ' ', ' ', ' ', ' ', ' ', ' '},
   {'L', ' ', 'T', ' ', 'T', ' ', 'L'}
	};

	//Plateau des rotations fixes
	const int plateauRotations[TAILLEPLATEAU][TAILLEPLATEAU] = {
   { 90, 000, 000, 000, 000, 000, 180},
   {000, 000, 000, 000, 000, 000, 000},
   {270, 000, 270, 000, 000, 000,  90},
   {000, 000, 000, 000, 000, 000, 000},
   {270, 000, 180, 000,  90, 000,  90},
   {000, 000, 000, 000, 000, 000, 000},
   {000, 000, 180, 000, 180, 000, 270}
	};

	//boucles imbriquées qui remplissent le plateau de jeu
	for (int i = 0; i < TAILLEPLATEAU; i++) {
		for (int j = 0; j < TAILLEPLATEAU; j++) {
			plateau[i][j].type = plateauTuilesBase[i][j];
			plateau[i][j].angle = plateauRotations[i][j];
			



		}
	}
}

void pivoterTuile90(char tuile[3][3])
{
	int temp[3][3];
	int i, j;

	// Copie les données de la matrice dans un tableau temporaire
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			temp[i][j] = tuile[i][j];
		}
	}

	// Effectue une rotation de 90 degrés en utilisant la formule de rotation suivante:
	// mat[i][j] = temp[n-1-j][i]
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			tuile[i][j] = temp[3 - 1 - j][i];
		}
	}
}

void pivoterTuile270(char tuile[3][3])
{
	int temp[3][3];
	int i, j;

	// Copie les données de la matrice dans un tableau temporaire
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			temp[i][j] = tuile[i][j];
		}
	}

	// Effectue une rotation de 270 degrés en utilisant la formule de rotation suivante:
	// mat[i][j] = temp[j][n-1-i]
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			tuile[i][j] = temp[j][3 - 1 - i];
		}
	}
}

void pivoterTuile180(char tuile[3][3])
{
	int temp[3][3];
	int i, j;

	// Copie les données de la matrice dans un tableau temporaire
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			temp[i][j] = tuile[i][j];
		}
	}

	// Effectue une rotation de 180 degrés en utilisant la formule de rotation suivante:
	// mat[i][j] = temp[n-1-i][n-1-j]
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			tuile[i][j] = temp[3 - 1 - i][3 - 1 - j];
		}
	}
}

void initPlateau(Tuile tabTuilesMobiles[TUILEMOBILE], Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU], Tuile tuileRestante) {
    srand(time(0));
    int i;

    for (i = 0; i <= 5; i++) {
        tabTuilesMobiles[i].type = 'T';
        tabTuilesMobiles[i].angle = rand() % 4 * 90;
    }
    for (i = 6; i <= 11; i++) {
        tabTuilesMobiles[i].type = 'L';
        tabTuilesMobiles[i].angle = rand() % 4 * 90;
    }
    for (i = 12; i <= 21; i++) {
        tabTuilesMobiles[i].type = 'l';
        tabTuilesMobiles[i].angle = rand() % 4 * 90;
    }
    for (i = 22; i <= 33; i++) {
        tabTuilesMobiles[i].type = 'i';
        tabTuilesMobiles[i].angle = rand() % 4 * 90;
    }

    int a, b;
    Tuile temp;

    // Mélange les tuiles du tableau
    for (a = 0; a < TUILEMOBILE; a++) {
        b = rand() % TUILEMOBILE;
        temp = tabTuilesMobiles[a];
        tabTuilesMobiles[a] = tabTuilesMobiles[b];
        tabTuilesMobiles[b] = temp;
    }


        int compteur = 0;

        for (int i = 0; i < TAILLEPLATEAU; i++) {
            for (int j = 0; j < TAILLEPLATEAU; j++) {
                if (plateau[i][j].type == ' ') {
                    plateau[i][j] = tabTuilesMobiles[compteur];
                    compteur++;

                }
            }
        }
        tuileRestante = tabTuilesMobiles[TUILEMOBILE-1]; //on stocke la tuile restante
    }

void afficherPlateau(Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU]) {
        //tuile en forme de t sans trésor
        const char tuilet[3][3] = {
                {219, 219, 219},
                {' ', ' ', ' '},
                {219, ' ', 219}
        };

        //tuile en forme de l sans trésor
        const char tuilel[3][3] = {
                {219, ' ', 219},
                {219, ' ', ' '},
                {219, 219, 219}
        };

        //tuile en forme de i sans trésor
        const char tuilei[3][3] = {
                {219, ' ', 219},
                {219, ' ', 219},
                {219, ' ', 219}
        };

        //tuile en forme de T avec trésor
        const char tuileT[3][3] = {
                {219, 219, 219},
                {' ', 'T', ' '},
                {219, ' ', 219}
        };

        //tuile en forme de L avec trésor
        const char tuileL[3][3] = {
                {219, ' ', 219},
                {219, 'T', ' '},
                {219, 219, 219}
        };

        char plateauAffichage[
                TAILLEPLATEAU * 3][
                TAILLEPLATEAU * 3]; //tableau d'afficahge des tuiles (21 * 21 char car chaque tuile fait 3 * 3 char)
        char tuileAPoser[3][3];

        for (int i = 0; i < TAILLEPLATEAU; i++) {
            for (int j = 0; j < TAILLEPLATEAU; j++) {


                //On associe la tuile à poser au modèle de tuile prédéfini sélectionné dans la matrice plateauTuiles
                switch (plateau[i][j].type) {
                    case 't':
                        for (int k = 0; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {
                                tuileAPoser[k][l] = tuilet[k][l];
                            }
                        }
                        break;
                    case 'l':
                        for (int k = 0; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {
                                tuileAPoser[k][l] = tuilel[k][l];
                            }
                        }
                        break;
                    case 'i':
                        for (int k = 0; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {
                                tuileAPoser[k][l] = tuilei[k][l];
                            }
                        }
                        break;
                    case 'T':
                        for (int k = 0; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {
                                tuileAPoser[k][l] = tuileT[k][l];
                            }
                        }
                        break;
                    case 'L':
                        for (int k = 0; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {
                                tuileAPoser[k][l] = tuileL[k][l];
                            }
                        }
                        break;
                    case ' ':
                        for (int k = 0; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {
                                tuileAPoser[k][l] = ' ';
                            }
                        }
                        break;
                }

                //On effectue la rotation des tuiles à poser en fonction de l'angle défini dans la matrice plateauRotations
                switch (plateau[i][j].angle) {
                    case 90:
                        pivoterTuile90(tuileAPoser);
                        break;
                    case 180:
                        pivoterTuile180(tuileAPoser);
                        break;
                    case 270:
                        pivoterTuile270(tuileAPoser);
                        break;
                    default:
                        break;
                }

                //on remplie le plateau de jeu avec toutes les tuiles à poser
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        plateauAffichage[i * 3 + k][j * 3 + l] = tuileAPoser[k][l];
                    }
                }
            }
        }

        ///AFFICHAGE DU PLATEAU DE JEU///
        //affichage des flèches du haut :
        printf("   ");
        for (int i = 0; i < TAILLEPLATEAU; i++) {
            if (i % 2 == 1) {
                printf(" %c ", 31);
            } else {
                printf("   ");
            }
        }
        printf("\n\n");

        //affichage des tuiles + flèches du coté :
        for (int i = 0; i < TAILLEPLATEAU * 3; i++) {
            if (i % 6 == 4) {
                printf(" %c ", 16);
            } else {
                printf("   ");
            }
            for (int j = 0; j < TAILLEPLATEAU * 3; j++) {
                printf("%c", plateauAffichage[i][j]);
            }
            printf("\n");
        }

        //affichage des flèches du bas :
        printf("\n");
        printf("   ");
        for (int i = 0; i < TAILLEPLATEAU; i++) {
            if (i % 2 == 1) {
                printf(" %c ", 30);
            } else {
                printf("   ");
            }
        }
    }

void translationColonne (int choixIndex, int choixSens, Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU], Tuile tuileRestante)
{
    int i;
    Tuile temp[TAILLEPLATEAU];

    if(choixSens == 0){ //le sens de deplacement devient -1 ou 1 (haut ou bas)
        choixSens = -1;
    }

    for(i=0; i<TAILLEPLATEAU; i++){
        temp[i] = plateau[i][choixIndex*2+1];
    }
    if(choixSens == -1){ //vers le haut
        for(i=0; i<TAILLEPLATEAU - 1; i++){
            plateau[i][choixIndex*2+1] = temp[i+1];
        }
        plateau[TAILLEPLATEAU-1][choixIndex*2+1] = tuileRestante;
    }else{ //vers le bas
        plateau[0][choixIndex*2+1] = tuileRestante;
        for(i=1; i<TAILLEPLATEAU ; i++){
            plateau[i][choixIndex*2+1] = temp[i-1];
        }
    }
}

void translationLigne (int choixIndex, int choixSens, Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU], Tuile tuileRestante)
{
    int i;
    Tuile temp[TAILLEPLATEAU];

    if(choixSens == 0){ //le sens de deplacement devient -1 ou 1 (gauche ou droite)
        choixSens = -1;
    }

    for(i=0; i<TAILLEPLATEAU; i++){
        temp[i] = plateau[choixIndex*2+1][i];
    }
    if(choixSens == -1){ //vers le haut
        for(i=0; i<TAILLEPLATEAU - 1; i++){
            plateau[choixIndex*2+1][i] = temp[i+1];
        }
        plateau[choixIndex*2+1][TAILLEPLATEAU-1] = tuileRestante;
    }else{ //vers le bas
        plateau[choixIndex*2+1][0] = tuileRestante;
        for(i=1; i<TAILLEPLATEAU ; i++){
            plateau[choixIndex*2+1][i] = temp[i-1];
        }
    }
}
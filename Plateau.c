#include "Header.h"

void menu(void) {
    int choix;

    do {
        printf("--- Menu ---\n");
        printf("1. Lancer une nouvelle partie\n");
        printf("2. Reprendre une partie enregistrée\n");
        printf("3. Quitter le jeu\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
    } while (choix != 1 && choix != 2 && choix != 3);

    if (choix == 1) {
        printf("Lancement d'une nouvelle partie...\n");
        nbjoeur();
        //tab contenant toutes les tuiles mobiles
        Tuile tabTuilesMobiles[TUILEMOBILE];

        //Matrice de toutes les tuiles
        Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU];

        creationPlateau(plateau); //pose des tuiles fixes
        initPlateau(tabTuilesMobiles, plateau); //remplissage aléatoire avec les tuiles dispo
        afficherPlateau(plateau); //affichage du plateau de jeu après les opérations logiques

        // Code pour lancer une nouvelle partie ici
    } else if (choix == 2) {
        printf("Reprise d'une partie enregistrée...\n");
        // Code pour reprendre une partie enregistrée ici
    } else {
        printf("Au revoir !\n");
    }

}


void nbjoeur() {
    int nb_joueurs;

    do {
        printf("Combien de joueurs pour cette partie (1-4) ? ");
        scanf("%d", &nb_joueurs);
    } while (nb_joueurs < 1 || nb_joueurs > 4);

    printf("La partie sera donc jouée par %d joueurs.\n", nb_joueurs);

}

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

void initPlateau(Tuile tabTuilesMobiles[TUILEMOBILE], Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU]) {
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
    }




        //mélange aléatoire du sac de tuile à poser

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


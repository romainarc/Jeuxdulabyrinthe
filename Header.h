#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//constantes 
#define TAILLEPLATEAU 7
#define TUILEFIXE 16
#define TUILEMOBILE 34

//structure tuile
typedef struct Tuile Tuile;
struct Tuile {
	//les coordonn�es de chaque tuile sur le plateau de jeu sont donn�es par son indice dans le tableau
	//ex : la premiere tuile du tableau sera celle plac�e en haut a gauche
	//la 34eme tuile (indice 33 dans le tab) correspond � la tuile disponible � poser

	char type; // type de la tuile (t, l, i, T, L)
	int angle; // orientation de la tuile (0, 90, 180, 270)
    //todo: creer un attribut tresor (char)
};

//prototypes de Plateau.c
void menu();
void nbjoeur();
void creationPlateau(Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU]);
void afficherPlateau(Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU]);
void pivoterTuile90(char tuile[3][3]);
void pivoterTuile180(char tuile[3][3]);
void pivoterTuile270(char tuile[3][3]);
void initPlateau(Tuile tabTuilesMobiles[TUILEMOBILE], Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU]);
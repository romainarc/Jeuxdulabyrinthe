#include "Header.h"

void menuPrincipal(void) {
    int choix;
    //tab contenant toutes les tuiles mobiles
    Tuile tabTuilesMobiles[TUILEMOBILE];

    //Matrice de toutes les tuiles
    Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU];

    //Tuile disponible a chaque debut de tour
    Tuile tuileRestante;

    do {
        system("cls");
        printf("--- Menu ---\n");
        printf("1. Lancer une nouvelle partie\n");
        printf("2. Reprendre une partie enregistree\n");
        printf("3. Afficher les regles du jeu\n");
        printf("4. Quitter le jeu\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
    } while (choix != 1 && choix != 2 && choix != 3 && choix != 4);

    if (choix == 1) { //lancer une nouvelle partie
        printf("Lancement d'une nouvelle partie...\n");
        initialisation(tabTuilesMobiles, plateau, tuileRestante);

        while (0==0){
            system("cls");
            menuIntermediaire(plateau, tuileRestante);
        }



    } else if (choix == 2) { //reprendre une partie enregistrée
        printf("Reprise d'une partie enregistree...\n");

    } else if(choix == 3) { //règles
        printf("le but du jeu est de recolter tous les tresors\n");

    } else { //quitter
        printf("Au revoir !\n");
    }

}

int choixNbJoueur() {
    int nbJoueurs;

    do {
        system("cls");
        printf("Combien de joueurs pour cette partie (1-4) ? ");
        scanf("%d", &nbJoueurs);
    } while (nbJoueurs < 1 || nbJoueurs > 4);
    return nbJoueurs;
}

void menuIntermediaire(Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU], Tuile tuileRestante) {
    int choixMenu;
    int choixIndex;
    int choixSens;

    do {
        system("cls");
        afficherPlateau(plateau);
        printf("\n\n\n\n\n\n");
        printf("--- Action ---\n");
        printf("1. Deplacer une colonne\n");
        printf("2. Deplacer une ligne\n");
        printf("Votre choix ? ");
        scanf("%d", &choixMenu);
    } while (choixMenu != 1 && choixMenu != 2);

    if(choixMenu == 1){
        do {
            system("cls");
            afficherPlateau(plateau);
            printf("\n\n\n\n\n\n");
            printf("--- Action ---\n");
            printf("Quelle colonne souhaitez vous deplacer ? (1 - 3)\n");
            printf("Votre choix ? ");
            scanf("%d", &choixIndex);
        } while (choixIndex != 1 && choixIndex != 2 && choixIndex != 3);

        do {
            system("cls");
            afficherPlateau(plateau);
            printf("\n\n\n\n\n\n");
            printf("--- Action ---\n");
            printf("Dans quelle sens voulez vous deplacer la colonne ?\n");
            printf("1. Vers le haut\n");
            printf("2. Vers le bas\n");
            scanf("%d", &choixSens);
        } while (choixSens != 1 && choixSens != 2);

        translationColonne(choixIndex - 1, choixSens - 1, plateau, tuileRestante);

    }else{
        do {
            system("cls");
            afficherPlateau(plateau);
            printf("\n\n\n\n\n\n");
            printf("--- Action ---\n");
            printf("Quelle ligne souhaitez vous deplacer ? (1 - 3)\n");
            printf("Votre choix ? ");
            scanf("%d", &choixIndex);
        } while (choixIndex != 1 && choixIndex != 2 && choixIndex != 3);

        do {
            system("cls");
            afficherPlateau(plateau);
            printf("\n\n\n\n\n\n");
            printf("--- Action ---\n");
            printf("Dans quelle sens voulez vous deplacer la ligne ?\n");
            printf("1. Vers la gauche\n");
            printf("2. Vers la droite\n");
            scanf("%d", &choixSens);
        } while (choixSens != 1 && choixSens != 2);

        translationLigne(choixIndex - 1, choixSens - 1, plateau, tuileRestante);
    }
}

void initialisation(Tuile tabTuilesMobiles[TUILEMOBILE], Tuile plateau[TAILLEPLATEAU][TAILLEPLATEAU], Tuile tuileRestante){
    system("cls");
    //choix du nombre de joueurs :
    choixNbJoueur();

    creationPlateau(plateau); //pose des tuiles fixes
    initPlateau(tabTuilesMobiles, plateau, tuileRestante); //remplissage aléatoire avec les tuiles dispo
    afficherPlateau(plateau); //affichage du plateau de jeu après les opérations logiques
}

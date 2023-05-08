/*
main.c

Rôle : Permet de centraliser toute les fonctions du programme

Date de création : 16/05/2020
Date de dérnière modification : 18/05/2020
*/

#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "affichage.h"
#include "deplacement.h"

// Fonction générale du programe qui permet de bien centraliser toute les fonction du programme
int main(int argc, char *argv[])
{
    // Déclarations des variables utile au jeu
    int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU] = {0}; // Tableau qui va prendre les valeurs de chaques cases
    int compteurTour = 1; // Variable qui compte le nombre de tours dans la partie
    int continuer = 1; // Bouleen qui sert a sortir de la boucle quand le joueur veut quitter la partie

    // Donne les valeurs de base au tableau et l'affiche, c'est l'initialisation du jeu
    initialisation_jeu(plateau);

    // Boucle du jeu
    while (continuer)
    {
        printf ("    Tour numero %d\n\n", compteurTour);

        // Chaque tour on affiche le jeu puis on effectue le déplacement
        affichage_jeu(plateau);
        deplacement_general(plateau);

        compteurTour++; // Chaque tour, le nombre de tour augmente de 1 (logique)
    }


    return 0;
}

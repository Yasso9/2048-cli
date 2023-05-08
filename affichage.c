/*
affichage.c

Rôle : Permet d'initialiser le jeu et d'afficher le jeu en fonction des valeurs du tableau

Date de création : 16/05/2020
Date de dérnière modification : 17/05/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "affichage.h"

// Procédure qui initialise les valeurs du plateau au départ
void initialisation_jeu(int plateau[][TAILLE_PLATEAU])
{
    // Déclaration des variables
    int ligne = 0, colonne = 0;
    int i = 0;
    // Pour les nombres aleatoires
    srand(time(NULL)); //Initialisation à faire une seule fois pour les nombre aléatoire
    const int MAX = TAILLE_PLATEAU-1, MIN = 0; //


    // Double boucle qui sert à donner des valeurs vide au tableau
    for(ligne=0 ; ligne<TAILLE_PLATEAU ; ligne++)
    {
        for(colonne=0 ; colonne<TAILLE_PLATEAU ; colonne++)
        {
            plateau[colonne][ligne] = 0; // On met tout les valeurs du plateau à 0
        }
    }

    // Boucle pour mettre en place deux coordonnées aléatoire ou on va mettre les 2 valeurs de départs (2 est la valeur de départ)
    for(i=0 ; i<2 ; i++)
    {
        // On donne des valeurs aléotoire d'une coordonnées pour pouvoir placer les deux 2 à des endroits aléatoires
        ligne = ( rand() % (MAX - MIN + 1) ) + MIN;
        colonne = ( rand() % (MAX - MIN + 1) ) + MIN;

        plateau[colonne][ligne] = 2;
    }
}

// Procédure qui affiche en version console le jeu, la plupart des instructions ne sont pas interressantes, sachant que c'est purement esthetic
void affichage_jeu(int plateau[][TAILLE_PLATEAU])
{
    // Déclaration des variables
    int ligne = 0, colonne = 0;
    int i = 0; // Pour avoir encore une autre variables alternatif

    // Pour l'esthetique de l'affichage
    printf("  ");
    for(colonne=0 ; colonne<TAILLE_PLATEAU ; colonne++)
        printf("  %d ", colonne);

    printf("\n  ");
    for(i=0 ; i<TAILLE_PLATEAU ; i++)
            printf(" ___");

    printf("\n");

    // Double boucle esthetique qui sert à afficher les valeurs du plateau 1 à 1
    for(ligne=0 ; ligne<TAILLE_PLATEAU ; ligne++)
    {
        printf("  ");
        for(i=0 ; i<TAILLE_PLATEAU ; i++)
            printf("|   ");

        printf("|\n%d |", ligne);

        for(colonne=0 ; colonne<TAILLE_PLATEAU ; colonne++)
        {
            printf(" %d |", plateau[colonne][ligne]);  // Affchage de la valeur
        }

        printf("\n  ");
        for(i=0 ; i<TAILLE_PLATEAU ; i++)
            printf("|___");
        printf("|\n");
    }
}





/* UTILITAIRE

    ligne = 3;
    colonne = 1;
    plateau[colonne][ligne] = 2;

    ligne = 3;
    colonne = 2;
    plateau[colonne][ligne] = 2;


*/

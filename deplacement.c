/*
deplacement.c

R�le : Permet de deplacer les nombres du plateau tout en prenant en compte tout les r�gles du jeu

Date de cr�ation : 16/05/2020
Date de d�rni�re modification : 18/05/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "deplacement.h"


// Proc�dure g�n�ral qui demande au joueur sa direction et produit le d�placement en fonction de celle ci
void deplacement_general(int plateau[][TAILLE_PLATEAU])
{
    // D�claration des variables
    char direction = 0; // peut valoir D (droite) , Q (gauche), Z (haut), S (bas) pour savoir la direction des pions
    int valide = 1; // Pour savoir si la direction prise par le joueur est valide (elle est au d�part initialiser comme non valide)

    // Tant que le joueur n'a pas pris une direction valide (valide = 1)
    while (valide)
    {
        printf("\nQuelle direction voulez vous prendre ?  ");
        scanf("%c", &direction); // On lit la direction que veux prendre le joueur
        getchar(); // Pour lire le \n et donc on ne vas pas avoir d'erreur li� � �a

        // Si la direction prise n'est droite, gauche, haut, bas on reste dans la boucle, sinon on quitte
        if (direction != 'd' && direction != 'q' && direction != 'z' && direction != 's' &&
            direction != 'D' && direction != 'Q' && direction != 'Z' && direction != 'S')

            printf("Vous avez choisis une mauvaise direction\n\n");

        else // Si la direction est bonne
        {
            printf("Vous avez choisis une bonne direction\n\n");
            valide = 0;
        }
    }

    // Maintenant que la v�rification a �t� faite on va d'abord d�caler au maximum tout les chiffres dans la direction demand�e
    deplacement_direction(plateau, direction);

    // Ensuite on rassemble les chiffres qu'on peut rassembler toujours en fonction de la direction (cette fonction d�cale automatiquement les nombre rassembl�)
    rassemblement(plateau, direction);

    // On met finalement un nombre 2 ou 4 sur une coordonnee al�atoire d'une case vide du plateau
    random_number(plateau);

}


// Proc�dure qui d�cale les chiffre en fonction de la direction qu'a prise le joueur
void deplacement_direction(int plateau[][TAILLE_PLATEAU] , char direction)
{
    // D�claration des variables
    int colonne = 0, ligne = 0, i = 0;
    int colonneDepart = 0, ligneDepart = 0;
    int horizontale = 0, verticale = 0; // Pour les d�calages horizontales et verticales dans la boucle colonne
    int right = 0, left = 0, up = 0, down = 0; // Pour les whiles, pour savoir quand et o� ils vont s'arreter, ils peuvent �tre �gale � 1 ou a 0 (en quelque sorte �a sert � bidouiller les whiles en fonction de la direction)

    // Serie de if pour savoir quelle direction a �t� choisis et faire les changements de variables dont on aura besoin dans les boucles d'apr�s
    // On prend en compte les majuscules et minuscule, donc on fait des if pour pouvoir mettre des ou

    if (direction == 'd' || direction == 'D') // Droite
    {
        // On se d�cale de fa�on inverse sur la droite par rapport au coordonnees du plan
        horizontale = -1; // verticale = 0 et ligne = 0 d'apr�s l'initialisation
        colonne = TAILLE_PLATEAU-1; // Dans la boucle d'apr�s on va commencer � cette valeur car on part de droite � gauche
        right = 1; // Pour mettre de bonne condition dans la boucle, on a aussi left = 0, up = 0 et down = 0 d'apr�s l'initialisation
    }

    else if (direction == 'q' || direction == 'Q') // Gauche
    {
        // On se d�cale de fa�on inverse sur la gauche par rapport au coordonnees du plan
        horizontale = +1; // verticale = 0, colonne = 0 et ligne = 0 d'apr�s l'initialisation
        left = 1; // Pour mettre de bonne condition dans la boucle, on a aussi right = 0, up = 0 et down = 0 d'apr�s l'initialisation
    }

    else if (direction == 'z' || direction == 'Z') // Haut
    {
        // On se d�cale de fa�on inverse sur le bas par rapport au coordonnees du plan
        verticale = +1; // horizontale = 0, colonne = 0 et ligne = 0 d'apr�s l'initialisation
        up = 1; // Pour mettre de bonne condition dans la boucle, on a aussi right = 0, left = 0 et down = 0 d'apr�s l'initialisation
    }

    else if (direction == 's' || direction == 'S') // Bas
    {
        // On se d�cale de fa�on inverse sur le haut par rapport au coordonnees du plan
        verticale = -1; // horizontale = 0 et colonne = 0 d'apr�s l'initialisation
        ligne = TAILLE_PLATEAU-1; // Dans la boucle d'apr�s on va commencer � cette valeur car on part de haut en bas
        down = 1; // Pour mettre de bonne condition dans la boucle, on a aussi right = 0, left = 0 et up = 0 d'apr�s l'initialisation
    }

    else // Si ce else est utiliser c'est tr�s bizarre
        printf("ERREUR : else de deplacement_direction utilise\n");

    // Je dis de fa�on inverser dans les commentaires plus haut car c'est la fa�on utilis� pour les variables ces variable dans la triple boucle

    // On sauvegarde les valeurs de d�part en colonne et en ligne car on va en avoir besoin en d�but de boucle principale
    colonneDepart = colonne;
    ligneDepart = ligne;

    for (i = 0 ; i<TAILLE_PLATEAU-1 ; i++) // Boucle qui va repeter toute l'operation un certains nombre de fois pour �tre sur de ne rien manquer, notament les vides entre les nombres
    {
        // On reinitialise la valeur de ligne avant chaque recommencement de la boucle qui suit
        ligne = ligneDepart;

        // Double boucle pour ligne et colonne
        while (ligne<TAILLE_PLATEAU-up && ligne>=down) /* Si on part en haut c'est un tant que ligne < TAILLE_PLATEAU-1, si on part en bas c'est un tant que ligne > =1,
        sinon c'est un tant que ligne < TAILLE_PLATEAU*/
        {
            // On reinitialise la valeur de colonne avant chaque recommencement de la boucle qui suit
            colonne = colonneDepart;

            while (colonne<TAILLE_PLATEAU-left && colonne>=right) /* Si on part � droite c'est un tant que colonne >=1, si on part � gauche, c'est un tant que colonne < TAILLE_PLATEAU-1,
            sinon c'est un tant que colonne < TAILLE_PLATEAU*/
            {
                // Si la valeurs actuelle est vide et que la valeurs � droite, � gauche, en haut ou en bas est un chiffre (�a depend de ce qu'a choisis l'utilisateur)
                if ( (plateau[colonne][ligne] == 0)  &&  (plateau[colonne+horizontale][ligne+verticale] != 0) )
                {
                    // Alors la valeurs actuelle vaut ce chiffre et la valeurs d'apres deviens vide
                    plateau[colonne][ligne] = plateau[colonne+horizontale][ligne+verticale];
                    plateau[colonne+horizontale][ligne+verticale] = 0;
                }

                // On fait maintenant l'incr�mentation de la colonne en fonction de la direction
                if (horizontale != 0) // Si la direction choisis est � gauche ou � droite
                    colonne = colonne + horizontale; // Equivalent � colonne++ si direction � gauche ou colonne-- si direction � droite
                else // horizontale = 0, si la direction choisis est en bas ou en haut
                    colonne++;
            }

            // On fait encore une incr�mentation pour la direction, mais cette fois c'est la ligne
            if (verticale != 0) // Si la direction choisis est en haut ou en bas
                ligne = ligne + verticale; // Equivalent � verticale++ si direction en haut ou verticale-- si direction en bas
            else // verticale = 0, si la direction choisis est en bas ou en haut
                ligne++;
        }
    }
}

// IL FAUT GERER LA PRIORITER LORS DES RASSEMBLEMENT !!!
// Proc�dure qui rassemble les chiffres identiques de suite si il y'en a. Elle s'occupe aussi de redecaler les lignes et colonnes suite � ce rassemblement
void rassemblement(int plateau[][TAILLE_PLATEAU] , char direction)
{
    // D�claration des variables
    int colonne = 0, ligne = 0, i = 0;

    // Double boucle pour rassembler les nombres qui sont pareil
    for(ligne=0 ; ligne<TAILLE_PLATEAU ; ligne++)
    {
        for(colonne=0 ; colonne<TAILLE_PLATEAU ; colonne++)
        {
            // Si la direction est � droite
            if(direction == 'd' || direction == 'D')
            {
                if (colonne == TAILLE_PLATEAU-1) // Si on est a la derni�re colonne du plateau
                {
                    // On ne fait rien car dans ce cas la, colonne + 1 n'existe pas
                }
                else if (plateau[colonne][ligne] == plateau[colonne+1][ligne]) // Si le nombre en position actuel est egale au nombre d'apr�s suivant l'axe horizontale
                {
                    plateau[colonne+1][ligne] *= 2; // On additionne les deux nombres en les mettant � droite (ce sont les m�mes donc on peut multiplier par deux)

                    // On effectue un d�calage de tout les termes prochains suite � ce rassemblement
                    for(i=colonne; i>0; i--)
                        plateau[i][ligne] = plateau[i-1][ligne];

                    // Le terme final vaut 0
                    plateau[0][ligne] = 0;
                }
                // Sinon on fait rien
            }

            // Si la direction est � gauche
            else if(direction == 'q' || direction == 'Q')
            {
                if (colonne == TAILLE_PLATEAU-1) // Si on est a la derni�re colonne du plateau
                {
                    // On ne fait rien car dans ce cas la, colonne + 1 n'existe pas
                }
                else if (plateau[colonne][ligne] == plateau[colonne+1][ligne]) // Si le nombre en position actuel est egale au nombre d'apr�s suivant l'axe horizontale
                {
                    plateau[colonne][ligne] *= 2; // On additionne les deux nombres en les mettant � gauche (ce sont les m�mes donc on peut multiplier par deux)

                    // On effectue un d�calage de tout les termes prochains suite � ce rassemblement
                    for(i=colonne+1; i<TAILLE_PLATEAU-1; i++)
                        plateau[i][ligne] = plateau[i+1][ligne];

                    // Le terme final vaut 0
                    plateau[TAILLE_PLATEAU-1][ligne] = 0;
                }
                // Sinon on fait rien
            }

            // Si la direction est vers le haut
            else if(direction == 'z' || direction == 'Z')
            {
                if (ligne == TAILLE_PLATEAU-1) // Si on est a la derni�re ligne du plateau
                {
                    // On ne fait rien car dans ce cas la, ligne + 1 n'existe pas
                }
                if (plateau[colonne][ligne] == plateau[colonne][ligne+1]) // Si le nombre en position actuel est egale au nombre d'apr�s suivant l'axe verticale
                {
                    plateau[colonne][ligne] *= 2; // On additionne les deux nombres en les mettant en haut (ce sont les m�mes donc on peut multiplier par deux)

                    // On effectue un d�calage de tout les termes prochains suite � ce rassemblement
                    for(i=ligne+1; i<TAILLE_PLATEAU-1; i++)
                        plateau[colonne][i] = plateau[colonne][i+1];

                    // Le terme final vaut 0
                    plateau[colonne][TAILLE_PLATEAU-1] = 0;
                }
            }

            // Si la direction est vers le bas
            else if(direction == 's' || direction == 'S')
            {
                if (ligne == TAILLE_PLATEAU-1) // Si on est a la derni�re ligne du plateau
                {
                    // On ne fait rien car dans ce cas la, ligne + 1 n'existe pas
                }
                if (plateau[colonne][ligne] == plateau[colonne][ligne+1]) // Si le nombre en position actuel est egale au nombre d'apr�s suivant l'axe verticale
                {
                    plateau[colonne][ligne+1] *= 2; // On additionne les deux nombres en les mettant en bas (ce sont les m�mes donc on peut multiplier par deux)

                    // On effectue un d�calage de tout les termes prochains suite � ce rassemblement
                    for(i=ligne; i>0; i--)
                        plateau[colonne][i] = plateau[colonne][i-1];

                    // Le terme final vaut 0
                    plateau[colonne][0] = 0;
                }
            }

            else // Normalement �a ne devrait jamais arriver
                printf("ERREUR : Dernier else de rassemblement utiliser\n");
        }
    }
}

// A AMELIORER EN FAISANT 1 CHANCE SUR 10 POUR LE 4 D APPARAITRE !!!
// Proc�dure qui place aleatoirement un deux ou un quatre dans une case vide du jeu
void random_number(int plateau[][TAILLE_PLATEAU])
{
    // D�claration des variables
    int ligne = 0, colonne = 0;
    int vide = 1;
    // Pour les nombres aleatoires
    srand(time(NULL)); //Initialisation � faire une seule fois pour les nombre al�atoire
    const int MAX = TAILLE_PLATEAU-1, MIN = 0; //

    while(vide) // Tant que la positition aleatoire pointe vers une position ou il y'a d�j� un nombre
    {
        // On donne des valeurs al�atoire d'une coordonn�e
        ligne = ( rand() % (MAX - MIN + 1) ) + MIN;
        colonne = ( rand() % (MAX - MIN + 1) ) + MIN;

        if (plateau[colonne][ligne] == 0) // Si les coordonnees aleatoire du plateau sont vide
        {
            plateau[colonne][ligne] = 2; // On donne notre nouvelle valeurs de 2 � cette endroite la
            vide = 0; // Et on sort de la boucle
        }
    }
}

/* UTILITAIRE
printf("1er while %d\t%d\n", colonne, ligne);
printf("2em while %d\t%d\n", colonne, ligne);
printf("\t\t%d\t%d\t%d\t%d", plateau[colonne][ligne], plateau[colonne+1][ligne] , colonne, ligne);
printf("On est bien\n");
*/

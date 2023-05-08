/*
deplacement.h

R�le : Prototype des fonction de  deplacement.c

Date de cr�ation : 16/05/2020
Date de d�rni�re modification : 18/05/2020
*/

#ifndef DEPLACEMENT
#define DEPLACEMENT

    #include "constantes.h"

    void deplacement_general(int plateau[][TAILLE_PLATEAU]);

    void deplacement_direction(int plateau[][TAILLE_PLATEAU] , char direction);

    void rassemblement(int plateau[][TAILLE_PLATEAU] , char direction);

    void random_number(int plateau[][TAILLE_PLATEAU]);

#endif


/*
deplacement.h

Rôle : Prototype des fonction de  deplacement.c

Date de création : 16/05/2020
Date de dérnière modification : 18/05/2020
*/

#ifndef DEPLACEMENT
#define DEPLACEMENT

    #include "constantes.h"

    void deplacement_general(int plateau[][TAILLE_PLATEAU]);

    void deplacement_direction(int plateau[][TAILLE_PLATEAU] , char direction);

    void rassemblement(int plateau[][TAILLE_PLATEAU] , char direction);

    void random_number(int plateau[][TAILLE_PLATEAU]);

#endif


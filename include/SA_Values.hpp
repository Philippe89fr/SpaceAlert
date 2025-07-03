
#pragma once

//carte_action
#define ACT_A 1
#define ACT_B 2
#define ACT_C 3
#define ACT_R 4

//carte_action_hero
#define ACT_AH 5
#define ACT_BH 6
#define ACT_RH 7

//carte_deplacement
#define DIR_R 8
#define DIR_B 9
#define DIR_A 10       //ascenseur

//carte_etat
#define ASSOME 11
#define INACTIF 0
#define TODO 12

//carte_deplacement_hero
#define DIR_RB 12// Red Bas
#define DIR_RH 13// Red Haut
#define DIR_WB 14// White Bas
#define DIR_WH 15// White Haut
#define DIR_BB 16// Blue Bas
#define DIR_BH 17// Blue Haut

// //carte_zone
#define ZONE_BAS_RED 1// Red Bas
#define ZONE_HAUT_RED 4// Red Haut
#define ZONE_BAS_WHITE 2// White Bas
#define ZONE_HAUT_WHITE 5// White Haut
#define ZONE_BAS_BLUE 3// Blue Bas
#define ZONE_HAUT_BLUE 6// Blue Haut

//carte_zone
#define ZONE_RED 1// Red Bas
#define ZONE_WHITE 2// Red Haut
#define ZONE_BLUE 3// White Bas

//State_bots
#define NO_BOTS 0
#define BOTS_EVEILLE 1
#define BOTS_INACTIF 2

//State_joueur
#define KO 0
#define ACTIF 1

//Difficulte_menace
#define MENACE_COMMUNE 1
#define MENACE_COMMUNE_AVANCEE 2
#define MENACE_SERIEUSE 3
#define MENACE_SERIEUSE_AVANCEE 4

//Type Cannon
#define CANON_LOURD 1
#define CANON_LATERAUX 2
#define CANON_IMPULSION 3

const std::string CANON_IMPULSION_STR = "le canon à impulsion";
const std::string CANON_LATERAUX_STR = "un cannon lateral";
const std::string CANON_LOURD_STR = "un cannon lourd";

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()

//////////////////////////////// VOIX //////////////////////////

// espeak : le programme de synthèse vocale
// -v en+f3 : voix (voice) = anglais, femme, variant 3
// -s 150 : vitesse (speed) = mots par minute
// -p 50 : pitch = hauteur de la voix (grave/aigu)
// "texte" : ce qui sera lu

// Les paramètres expliqués
// Speed (vitesse) :

// 80 = très lent (robot mourant)
// 150 = normal (conversation)
// 200 = rapide (urgence)
// 300 = très rapide (panique totale !)

// Pitch (hauteur) :

// 10 = très grave (Darth Vader)
// 50 = normal
// 80 = aigu (R2D2)
// 99 = très aigu (souris)


// fr+f1, fr+f2, fr+f3, fr+f4 : voix féminines françaises
// fr+m1, fr+m2, fr+m3 : voix masculines françaises

#define VOIX_TRES_LENT 80
#define VOIX_LENT 115
#define VOIX_NORMAL 150
#define VOIX_RAPIDE 200
#define VOIX_TRES_RAPIDE 300

#define TIMBRE_GRAVE 10
#define TIMBRE_NORMAL 55
#define TIMBRE_AIGU 80
#define TIMBRE_TRES_AIGU 99

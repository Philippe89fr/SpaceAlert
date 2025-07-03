#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "space_alerte.hpp"

/*
//carte_action
#define INACTIF 0
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
#define DIR_A 10//ascenseur
*/

class carte;

class carte
{
    int c_action;

    public:
        carte();
        carte(int action);
        void setc_action(int input);
        int getc_action() const;
        ~carte();
};

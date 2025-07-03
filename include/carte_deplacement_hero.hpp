#pragma once

#include <string>    // pour std::string
#include <map>
#include "carte.hpp"
#include "carte_deplacement.hpp"

class carte;

class carte_deplacement_hero: public carte_deplacement
{
    private:

    public:
        carte_deplacement_hero();
        ~carte_deplacement_hero();
};

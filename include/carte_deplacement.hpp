#pragma once

#include <string>    // pour std::string
#include <map>
#include "carte.hpp"

class carte;

class carte_deplacement: public carte
{
    protected:
        int c_direction;
    public:
        carte_deplacement();
        ~carte_deplacement();
};

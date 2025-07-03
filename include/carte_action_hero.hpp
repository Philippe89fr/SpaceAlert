#pragma once

#include <string>    // pour std::string
#include <map>
#include "carte.hpp"
#include "carte_action.hpp"

class carte;

class carte_action_hero: public carte_action
{
    private:

    public:
        carte_action_hero();
        ~carte_action_hero();
};

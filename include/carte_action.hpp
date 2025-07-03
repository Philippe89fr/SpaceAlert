#pragma once

#include <string>    // pour std::string
#include <map>
#include "carte.hpp"

class carte;

class carte_action: public carte
{
    protected:
        int c_action;
    public:
        carte_action();
        ~carte_action();
};

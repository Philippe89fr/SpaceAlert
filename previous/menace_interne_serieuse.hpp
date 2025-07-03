#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "menace_interne.hpp"

class menace_interne_serieuse: public menace_interne
{
    public:
        menace_interne_serieuse();
        ~menace_interne_serieuse();
};

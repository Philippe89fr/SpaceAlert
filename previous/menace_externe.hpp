#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "menace.hpp"

class menace_externe: public menace
{
    public:
        menace_externe();
        ~menace_externe();
};

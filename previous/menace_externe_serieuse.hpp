#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "menace.hpp"
#include "menace_externe.hpp"

class menace_externe_serieuse: public menace_externe
{
    public:
        menace_externe_serieuse();
        ~menace_externe_serieuse();
};

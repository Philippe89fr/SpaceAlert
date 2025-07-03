#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "zone.hpp"
#include "zone_bas_red.hpp"
#include "chemin_menace.hpp"

class zone_bas_red;
class zone_haut_white;

class zone_haut_red: public zone
{
    private:
        int z_bouclier_dispo;
        int z_max_size_bouclier;
        zone_bas_red *zone_bas;
        chemin_menace z_chemin;

    public:
        zone_haut_red();
        ~zone_haut_red();
        void setzone_bas(zone* zone);
        zone* getzone_bas() const;

        bool actionA();
        bool actionAHeros();
        void actionB();
        void actionBHeros();
        void actionC();
        bool ascenseur();
};

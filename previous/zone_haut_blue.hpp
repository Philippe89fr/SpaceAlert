#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "zone.hpp"
#include "zone_bas_blue.hpp"
#include "chemin_menace.hpp"

class zone_bas_blue;
class zone_haut_white;

class zone_haut_blue: public zone
{
    private:
        int z_bouclier_dispo;
        int z_max_size_bouclier;
        bool z_bots;
        zone_bas_blue *zone_bas;
        chemin_menace z_chemin;

    public:
        zone_haut_blue();
        ~zone_haut_blue();
        void setzone_bas(zone* zone);
        zone* getzone_bas() const;
        bool actionA();
        bool actionAHeros();
        void actionB();
        void actionBHeros();
        void actionC();
        bool ascenseur();
};

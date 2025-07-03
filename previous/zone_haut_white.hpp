#pragma once

#include "zone.hpp"
#include "zone_bas_white.hpp"
#include "chemin_menace.hpp"

class zone_bas_white;
class zone_haut_red;
class zone_haut_blue;

class zone_haut_white: public zone
{
    private:
        int z_bouclier_dispo;
        int z_max_size_bouclier;
        std::vector<int> z_maintenance_ordinateur;
        zone_bas_white *zone_bas;
        zone_haut_red *zone_red;
        zone_haut_blue *zone_blue;
        chemin_menace z_chemin;

    public:
        zone_haut_white();
        ~zone_haut_white();
        bool actionA();
        bool actionAHeros();
        void actionB();
        void actionBHeros();
        void actionC();
        bool ascenseur();
        void setzone_bas(zone* zone);
        zone* getzone_bas() const;
        void setzone_red(zone_haut_red *zone);
        void setzone_blue(zone_haut_blue *zone);
};

#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "zone.hpp"

class zone_haut_white;
class zone_bas_red;
class zone_bas_blue;

class zone_bas_white: public zone
{
    private:
        int z_reserve_capsule_carburant;
        int z_energie_dispo;
        std::vector<int> z_maintenance_ordinateur;
        //zone *zone_haut;

    public:
        zone_bas_white();
        ~zone_bas_white();

        //setters
        void setz_energie_dispo(int input);

        //getters
        int getz_energie_dispo() const;
        virtual zone* getzone_bas() const;
        virtual void setzone_bas(zone* zone);
        bool actionA();
        bool actionAHeros();
        void actionB();
        void actionBHeros();
        void actionC();
        bool ascenseur();
};

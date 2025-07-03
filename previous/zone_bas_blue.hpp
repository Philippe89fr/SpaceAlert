#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "zone.hpp"
#include "zone_bas_white.hpp"

class zone_haut_blue;
class zone_bas_white;

class zone_bas_blue: public zone
{
    private:
        int z_energie_dispo;
        int z_max_energie;
        std::map<int, int> roquete_position;
        zone *zone_haut;
        zone_bas_white *zone_white;

    public:
        //constr & destr
        zone_bas_blue();
        ~zone_bas_blue();

        //setters
        void setz_energie_dispo(int input);

        //getters
        int getz_energie_dispo() const;

        //others
        virtual void setzone_bas(zone* zone);
        virtual zone* getzone_bas() const;
        bool roquete_damage();
        bool actionA();
        bool actionAHeros();
        void actionB();
        void actionBHeros();
        void actionC();
        bool ascenseur();
        bool deplacement_red();
        bool deplacement_blue();
};

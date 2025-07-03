#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "zone.hpp"
#include "zone_bas_white.hpp"

class zone_haut_blue;
class zone_bas_white;

class zone_bas_red: public zone
{
    private:
        bool z_bots;
        int z_energie_dispo;
        int z_max_energie;
        //zone *zone_haut;
        zone_bas_white *zone_white;

    public:
        //constr & destr
        zone_bas_red();
        ~zone_bas_red();

        //setters
        void setz_energie_dispo(int input);
        void setz_bots(bool input);

        //getters
        int getz_energie_dispo() const;
        bool getz_bots() const;

        //autre
        virtual void setzone_bas(zone* zone);
        virtual zone* getzone_bas() const;
        bool actionA();
        bool actionAHeros();
        void actionB();
        void actionBHeros();
        void actionC();
        bool ascenseur();
};

#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "SA_Values.hpp"

/*
//cannon_action
#define INACTIF 0
#define ACT_A 1
#define ACT_B 2
#define ACT_C 3
#define ACT_R 4

//cannon_action_hero
#define ACT_AH 5
#define ACT_BH 6
#define ACT_RH 7

//cannon_deplacement
#define DIR_R 8
#define DIR_B 9
#define DIR_A 10//ascenseur
*/

class cannon;
class menace_externe;
class zone; // Forward declaration pour éviter les dépendances circulaires

class cannon
{
    protected:
    std::string nom_cannon;
    int puissance_cannon;
    int portee_cannon;
    int type_cannon;
    bool actionHeroique;
    bool canon_used;
    std::string tireur;
    zone *zone_cannon;  // zone dans laquelle le canon est utilisé

    public:
        cannon();
        cannon(std::string nom_cannon, int puissance_cannon, int portee_cannon, int type);
        void setpuissance_cannon(int input);
        void setzone_cannon(zone *input) {
            zone_cannon = input;
        }
        void setactionHeroique(bool input) {
            actionHeroique = input;
        }
        bool getactionHeroique() const {
            return (actionHeroique);
        }
        void settireur(std::string input) {
            tireur = input;
        }
        std::string gettireur() const {
            return (tireur);
        }
        void setportee_cannon(int input);
        void setnom_cannon(std::string input);
        void setcanon_used(bool input);
        bool getcanon_used();
        std::vector<menace_externe*> getmenace_Exte_vulnerables(zone* zone);
        int getpuissance_cannon() const;
        int getportee_cannon() const;
        int gettype_cannon() const;
        std::string getnom_cannon () const;
        void debuf_puissance_cannon(int debuf);
        void debuf_portee_cannon(int debuf);
        virtual void attaque_canon(zone *zone);
        void infligeDegats(menace_externe *menace); // inflige des dégâts à la menace
        void cumuleDegats(menace_externe *menace);
        bool MenaceIsinCannonRange(menace_externe *menace) const;
        ~cannon();
};

class canon_lourd: public cannon
{
    private:

    public:
        canon_lourd() {};
        canon_lourd(std::string nom, int puissance_cannon, zone *zone)
        {
            setzone_cannon(zone);
            setpuissance_cannon(puissance_cannon);
            setportee_cannon(16);
            setnom_cannon(nom);
            type_cannon = CANON_LOURD;
            canon_used = false;
        };
        ~canon_lourd() {};
};

class canon_lateral: public cannon
{
    private:

    public:
        canon_lateral(zone *zone)
        {
            setzone_cannon(zone);
            setpuissance_cannon(2);
            setportee_cannon(16);
            nom_cannon = "Canon Lateral";
            type_cannon = CANON_LATERAUX;
            canon_used = false;
        };
        ~canon_lateral() {};
};

class canon_impulsion: public cannon
{
    private:

    public:
        canon_impulsion(zone *zone)
        {
            setzone_cannon(zone);
            setpuissance_cannon(1);
            setportee_cannon(10);
            nom_cannon = "Canon a impulsion";
            type_cannon = CANON_IMPULSION;
            canon_used = false;
        };
        virtual void attaque_canon(zone *zone);
        ~canon_impulsion() {};
};

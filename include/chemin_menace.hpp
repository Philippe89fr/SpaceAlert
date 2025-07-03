#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "space_alerte.hpp"

class menace;
class menace_interne;
class menace_externe;
class menace_se1_01; // Forward declaration pour éviter les dépendances circulaires

class chemin_menace
{
    private:
        std::string          ch_nom;
        std::map<int,char> ch_chemin;
        int                 ch_chemin_size;
        std::vector<menace_externe*> ch_menacesExte;
        std::vector<menace_interne*> ch_menacesInte;

    public:
        chemin_menace();
        chemin_menace(std::string input);
        std::vector<menace_externe*> targeted_intercepteur_menace();
        void add_menaceExte(menace_externe *input);
        void add_menaceInt(menace_interne *input);
        menace_externe* get_menace_that_attracts_rocket();
        menace* get_closest_menace();
        menace_externe* get_closest_menace_rocket_vulnerable();
        void remove_menace(menace *input);
        std::string get_ch_nom() const {
            return ch_nom;
        };
        int  get_ch_chemin_size() const {
            return ch_chemin_size;
        };
        std::map<int,char> get_ch_chemin() const {
            return ch_chemin;
        };
        std::vector<menace_externe*> get_menacesExte() const {
            return ch_menacesExte;
        };
        std::vector<menace_interne*> get_menacesInte() const {
            return ch_menacesInte;
        };
        ~chemin_menace();
};

#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "space_alerte.hpp"
#include "carte.hpp"
#include "SA_Struct.hpp"


class carte;

class joueur {
private:
    std::string j_nom;
    t_data *j_data;
    bool j_state;//eveille / KO
    int j_bots;//
    int j_jump_tour;
    int j_number;//numero du joueur
    bool j_capitaine;
    int j_zone;//un joueur est dans une zone
    std::map<int, carte> cartes;//un joueur pose des cartes, associe au tour ou il pose ses cartes

public:
    joueur();
    joueur(std::string nom);

    //setters
    void setj_number(int input);
    void setj_jump_tour(int input);
    void setj_state(bool input);
    void setj_bots(int input);
    void setj_capitaine(bool input);
    void setj_zone(int input);
    void setj_nom(std::string nom);
    void setj_data(t_data *data);

    //autre
    void attaqueIntercepteur(t_data &data);
    void attaqueIntercepteurHero(t_data &data);
    void addcartes(int input, carte carte);
    void passerTour(int input);
    void setcarteInactif(int input);
    void setcarteAssome(int input);
    void print();
    void getcarteTour(int tour);

    //getters
    int getj_number() const;
    t_data * getj_data() const;
    int getj_jump_tour() const;
    bool getj_state()const;
    bool getj_capitaine()const;
    std::string getj_nom() const;
    int getj_bots() const;
    int getj_zone() const;
    std::map<int, carte> getcartes() const;

    //destructeur
    ~joueur();
};

#pragma once


#include <stdexcept>
#include "joueur.hpp"
#include "SA_Values.hpp"
#include "chemin_menace.hpp"
#include "cannon.hpp"
#include <random>
#include "SA_Struct.hpp"

class joueur;
class menace_interne;
class chemin_menace;

class zone
{
    private:
        cannon *z_cannon_haut;
        cannon *z_cannon_bas;
        std::string z_nom_zone;
        chemin_menace *z_chemin_menace;
        chemin_menace *z_chemin_menace_intern;
        bool z_bots;
        bool z_bots_englues;
        int z_zone;//NUMERO DE La ZONE
        int z_temps;//chelou ici
        int z_capsule_energie;
        bool z_ascenseur;
        bool z_degats_doubles;
        int z_reacteur;
        int z_max_reacteur;
        bool z_jump_tour_upon_entry_haut;
        bool z_jump_tour_upon_entry_bas;
        int z_bouclier;
        int z_max_energie_bouclier;
        int z_degats_recu;
        std::map<int, int> z_ordre_degats; // 0 = degats recu, 1 = degats infliges, 2 = degats infliges aux menaces, 3 = degats infliges aux canons, 4 = degats infliges aux joueurs, 5 = degats infliges aux robots
        std::vector<cannon*> z_cannon_used;  // degats[3] += 4 // degats[3] += 2
        std::vector<int> z_maintenance_ordinateur;
        std::vector<int> z_observations;
        std::map<int, int> z_roquete_position;
        zone *zone_blue;
        zone *zone_red;
        zone *zone_white;
        zone *zone_right;
        zone *zone_left;
        t_data *z_data;
        std::string z_joueur_playing;//chelou ici
        std::vector<joueur*> z_joueurs_haut;
        std::vector<joueur*> z_joueurs_bas;
        joueur *z_joueur_intercepteurs;
        std::vector<int>    z_actions_bas;
        std::vector<int>    z_actions_haut;
        std::vector<int>    z_actions_used_ce_tour_bas;
        std::vector<int>    z_actions_used_ce_tour_haut;

    public:
        //constr & destr
        zone();
        zone(int nb_zone);
        virtual ~zone();

        //setters
        void setz_data(t_data &data);
        void setz_zone(int input);
        void setz_joueur_playing(std::string input);
        void setzone_white(zone* zone);
        void setzone_red(zone* zone);
        void setzone_blue(zone* zone);
        void setz_degats_recu(int input);
        void setzone_right(zone* zone);
        void setzone_left(zone* zone);
        void setz_cannon_haut(cannon *input);
        void setz_cannon_bas(cannon *input);
        void setz_nom_zone(std::string input);
        void setz_chemin(chemin_menace *input);
        void setz_chemin_intern(chemin_menace *input);
        void setz_bots(bool input);
        void setz_bots_englues(bool input);
        void setz_temps(int input);
        void setz_capsule_energie(int input);
        void setz_ascenseur(bool input);
        void setz_degats_doubles(bool input);
        void setz_reacteur(int input);
        void setz_max_energie_reservoir(int input);
        void setz_bouclier(int input);
        void setz_max_energie_bouclier(int input);
        void setz_roquete_position(int, int);
        void setz_jump_tour_upon_entry_bas(bool input);
        void setz_jump_tour_upon_entry_haut(bool input);
        void setz_ordre_degats();
        void setz_joueur_intercepteurs(joueur *input);

        //getters
        std::map<int, int> getz_roquete_position();
        bool getz_jump_tour_upon_entry_bas() const;
        bool getz_degats_doubles() const;
        bool getz_jump_tour_upon_entry_haut() const;
        int getz_reacteur() const;
        int getz_degats_recu() const;
        int getz_max_energie_reacteur() const;
        int getz_capsule_energie() const;
        bool getz_bots() const;
        joueur *getz_joueur_intercepteurs() const;
        bool getz_bots_englues() const;
        int getz_bouclier() const;
        int getz_max_energie_bouclier() const;
        int getz_zone() const;
        t_data *getz_data();
        std::string getz_nom_zone() const;
        bool getz_ascenseur() const;
        chemin_menace *getz_chemin_menace() const;
        chemin_menace* getz_chemin_menace_Int() const;
        cannon *getz_cannon_haut() const;
        cannon *getz_cannon_bas() const;
        std::string getz_joueur_playing() const;
        int getz_temps() const;
        std::vector<joueur*> getz_joueurs_bas_vec() const;
        std::vector<joueur*> getz_joueurs_haut_vec() const;
        std::vector<cannon*> getz_cannon_used() const;
        std::vector<int>    getz_actions_bas() const;
        std::vector<int>    getz_actions_haut() const;
        std::vector<int>    getz_actions_used_ce_tour_bas() const;
        std::vector<int>    getz_actions_used_ce_tour_haut() const;
        std::vector<int>    getz_maintenance_ordinateur() const;
        std::vector<int>    getz_observations() const;
        zone* getzone_white() const;
        zone* getzone_red() const;
        zone* getzone_blue() const;
        zone* getzone_right() const;
        zone* getzone_left() const;

        //degats
        void calculateDegatsCanons();
        void etatdesdegats();
        void getdegats(int input);
        void getdegatsIgnoreBouclier(int input);

        //autre
        void wrongActionInSpace();
        menace_interne* is_menace_fissure();
        menace_interne* checkIfMenaceInternAttrackAction(int joueurAction, int Zone, bool haut);
        joueur* getz_joueur_haut(std::string nom);
        joueur* getz_joueur_bas(std::string nom);
        void removez_joueur_intercepteurs();
        void addz_maintenance_ordinateur(int input);
        void addz_observations(int input);
        void print();
        void printz_action_ce_tour_haut();
        void printz_action_ce_tour_bas();
        void printZone();
        void addtemps();
        void addz_joueurs_bas(joueur* input);
        void removez_joueurs_bas(std::string input);
        void addz_actions_bas(int input);
        void removez_actions_bas(int input);
        void addz_actions_used_ce_tour_bas(int input);
        void clearz_actions_used_ce_tour_bas();
        void clearz_cannon_used();
        void addz_cannon_used(cannon* input);
        void addz_joueurs_haut(joueur* input);
        void removez_joueurs_haut(std::string input);
        void addz_actions_haut(int input);
        void removez_actions_haut(int input);
        void addz_actions_used_ce_tour_haut(int input);
        void clearz_actions_used_ce_tour_haut();
        void actionA();
        void actionB();
        void actionR();
        void actionAHeros();
        void actionBHeros();
        void actionRHeros();
        void actionC();
        void dirHeroique(int action_heroique);
        void moveplayerzone(zone *zone_to_move, bool direction_haut);
        void ascenseur();
        void inactif();
        void retarderactionZoneHaut();
        void retarderactionZoneBas();
        void assomerjoueursZoneHaut_IfNoActifRobot();
        void assomerjoueursZoneBas_IfNoActifRobot();
        int countPlayerInStation(bool m_position_haut);
        std::string stationWithMostPlayer(bool m_position_haut, int zone);
        void assomerjoueursZoneHaut();
        void assomerjoueursZoneBas();
        void assomerjoueursZoneHautRobotsActifs();
        void assomerjoueursZoneBasRobotsActifs();
        void assomerjoueursZoneRobotsActifs();
        void assomerjoueursZone();
        void retarderactionZone();
        bool action_used_ce_tour_haut(int input);
        bool action_possible_haut(int input);
        bool action_used_ce_tour_bas(int input);
        bool action_possible_bas(int input);

        //Deplacement
        void flechesRouge();
        void flechesBleue();
};

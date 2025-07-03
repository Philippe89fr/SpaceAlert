#include "zone.hpp"

zone::zone()
{
	z_degats_recu = 0;
}

zone::zone(int nb_zone)
{
	z_degats_recu = 0;
	z_temps = 1;
	z_zone = nb_zone;
	z_ascenseur = true;
}

void zone::setzone_white(zone* zone)
{
	zone_white = zone;
}
void zone::setzone_red(zone* zone)
{
	zone_red = zone;
}

void zone::setzone_blue(zone* zone)
{
	zone_blue = zone;
}

void zone::setzone_right(zone* zone)
{
	zone_right = zone;
}

void zone::setzone_left(zone* zone)
{
	zone_left = zone;
}

void zone::setz_cannon_haut(cannon *input)
{
	z_cannon_haut = input;
}

void zone::setz_cannon_bas(cannon *input)
{
	z_cannon_bas = input;
}

void zone::setz_nom_zone(std::string input)
{
	z_nom_zone = input;
}

void zone::setz_chemin(chemin_menace *input)
{
	z_chemin_menace = input;
}

void zone::setz_chemin_intern(chemin_menace *input)
{
	z_chemin_menace_intern = input;
}

void zone::setz_bots(bool input)
{
	z_bots = input;
}

void zone::setz_zone(int input)
{
	z_zone = input;
}

void zone::setz_temps(int input)
{
	z_temps = input;
}

void zone::setz_capsule_energie(int input)
{
	z_capsule_energie = input;
}

void zone::setz_ordre_degats()
{
	std::vector<int> valeurs = {1, 2, 3, 4, 5, 6};
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(valeurs.begin(), valeurs.end(), g);

	for (int i = 1; i <= 6; ++i)
		z_ordre_degats[i] = valeurs[i - 1];
}

void zone::setz_degats_recu(int input)
{
	z_degats_recu = input;
}

int zone::getz_degats_recu() const
{
	return (z_degats_recu);
}

void zone::setz_reacteur(int input)
{
	z_reacteur = input;
}

void zone::setz_max_energie_reservoir(int input)
{
	z_max_reacteur = input;
}

void zone::setz_bouclier(int input)
{
	z_bouclier = input;
}

void zone::setz_max_energie_bouclier(int input)
{
	z_max_energie_bouclier = input;
}

void zone::setz_ascenseur(bool input)
{
	z_ascenseur = input;
}

void zone::setz_degats_doubles(bool input)
{
	z_degats_doubles = input;
}

void zone::setz_joueur_playing(std::string input)
{
	z_joueur_playing = input;
}

void zone::setz_roquete_position(int key, int value)
{
	z_roquete_position[key] = value;
}

void zone::setz_jump_tour_upon_entry_bas(bool input)
{
	z_jump_tour_upon_entry_bas = input;
}

void zone::setz_jump_tour_upon_entry_haut(bool input)
{
	z_jump_tour_upon_entry_haut = input;
}

void zone::setz_bots_englues(bool input)
{
	z_bots_englues = input;
}

void zone::setz_joueur_intercepteurs(joueur *input)
{
	z_joueur_intercepteurs = input;
}

joueur *zone::getz_joueur_intercepteurs() const
{
	return (z_joueur_intercepteurs);
}

int zone::getz_temps() const
{
	return (z_temps);
}

void zone::setz_data(t_data &data)
{
	z_data = &data;
}

t_data *zone::getz_data()
{
	return (z_data);
}

bool zone::getz_degats_doubles() const
{
	return (z_degats_doubles);
}

bool zone::getz_bots_englues() const
{
	return (z_bots_englues);
}

bool zone::getz_jump_tour_upon_entry_bas() const
{
	return (z_jump_tour_upon_entry_bas);
}

bool zone::getz_jump_tour_upon_entry_haut() const
{
	return (z_jump_tour_upon_entry_haut);
}

int zone::getz_reacteur() const
{
	return (z_reacteur);
}

int zone::getz_max_energie_reacteur() const
{
	return (z_max_reacteur);
}

int zone::getz_capsule_energie() const
{
	return (z_capsule_energie);
}

bool zone::getz_bots() const
{
	return (z_bots);
}

int zone::getz_bouclier() const
{
	return (z_bouclier);
}

int zone::getz_max_energie_bouclier() const
{
	return (z_max_energie_bouclier);
}

std::vector<cannon*> zone::getz_cannon_used() const
{
	return (z_cannon_used);
}

std::string zone::getz_joueur_playing() const
{
	return (z_joueur_playing);
}

std::vector<joueur*> zone::getz_joueurs_bas_vec() const
{
	return (z_joueurs_bas);
}

std::vector<int>    zone::getz_actions_bas() const
{
	return (z_actions_bas);
}

std::vector<int>    zone::getz_actions_used_ce_tour_bas() const
{
	return (z_actions_used_ce_tour_bas);
}

std::vector<joueur*> zone::getz_joueurs_haut_vec() const
{
	return (z_joueurs_haut);
}

std::vector<int>    zone::getz_actions_haut() const
{
	return (z_actions_haut);
}

std::vector<int>    zone::getz_actions_used_ce_tour_haut() const
{
	return (z_actions_used_ce_tour_haut);
}

chemin_menace* zone::getz_chemin_menace() const {
	return (z_chemin_menace);
}

chemin_menace* zone::getz_chemin_menace_Int() const {
	return (z_chemin_menace_intern);
}

bool zone::getz_ascenseur() const
{
	return (z_ascenseur);
}

cannon *zone::getz_cannon_haut() const
{
	return (z_cannon_haut);
}
cannon *zone::getz_cannon_bas() const
{
	return (z_cannon_bas);
}

int zone::getz_zone() const
{
	return (z_zone);
}

std::string zone::getz_nom_zone() const
{
	return (z_nom_zone);
}

std::map<int, int> zone::getz_roquete_position()
{
	return (z_roquete_position);
}

zone* zone::getzone_white() const
{
	return zone_white;
}
zone* zone::getzone_red() const
{
	return zone_red;
}
zone* zone::getzone_blue() const
{
	return zone_blue;
}
zone* zone::getzone_right() const
{
	return zone_right;
}
zone* zone::getzone_left() const
{
	return zone_left;
}

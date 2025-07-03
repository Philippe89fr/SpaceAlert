
#include "space_alerte.hpp"
#include "SA_Values.hpp"
#include "GameNarrator.hpp"

void init_carte_joueur_test(t_data& data)
{
	int i(1);
	carte carte_ACT_A(ACT_A);
	carte carte_ACT_B(ACT_B);
	carte carte_ACT_C(ACT_C);
	carte carte_DIR_A(DIR_A);
	carte carte_DIR_B(DIR_B);
	carte carte_DIR_R(DIR_R);
	carte carte_ACT_R(ACT_R);
	carte carte_ACT_AH(ACT_AH);
	carte carte_ACT_BH(ACT_BH);
	carte carte_INACTIF(INACTIF);
	data.joueurs[i]->addcartes(1, carte_ACT_C);
	data.joueurs[i]->addcartes(2, carte_ACT_C);
	data.joueurs[i]->addcartes(3, carte_INACTIF);
	data.joueurs[i]->addcartes(4, carte_ACT_C);
	data.joueurs[i]->addcartes(5, carte_DIR_B);
	data.joueurs[i]->addcartes(6, carte_ACT_R);
	data.joueurs[i]->addcartes(7, carte_ACT_A);
	data.joueurs[i]->addcartes(8, carte_DIR_A);
	data.joueurs[i]->addcartes(9, carte_DIR_A);
	data.joueurs[i]->addcartes(10, carte_ACT_B);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_INACTIF);
	i++;
	data.joueurs[i]->addcartes(1, carte_DIR_R);
	data.joueurs[i]->addcartes(2, carte_ACT_B);
	data.joueurs[i]->addcartes(3, carte_DIR_A);
	data.joueurs[i]->addcartes(4, carte_ACT_B);
	data.joueurs[i]->addcartes(5, carte_ACT_AH);
	data.joueurs[i]->addcartes(6, carte_ACT_R);
	data.joueurs[i]->addcartes(7, carte_DIR_A);
	data.joueurs[i]->addcartes(8, carte_DIR_B);
	data.joueurs[i]->addcartes(9, carte_ACT_C);
	data.joueurs[i]->addcartes(10, carte_ACT_B);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_ACT_A);
	i++;
	data.joueurs[i]->addcartes(1, carte_DIR_A);
	data.joueurs[i]->addcartes(2, carte_ACT_A);
	data.joueurs[i]->addcartes(3, carte_ACT_B);
	data.joueurs[i]->addcartes(4, carte_ACT_C);
	data.joueurs[i]->addcartes(5, carte_ACT_B);
	data.joueurs[i]->addcartes(6, carte_DIR_B);
	data.joueurs[i]->addcartes(7, carte_ACT_B);
	data.joueurs[i]->addcartes(8, carte_DIR_R);
	data.joueurs[i]->addcartes(9, carte_ACT_B);
	data.joueurs[i]->addcartes(10, carte_ACT_A);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_ACT_A);
	i++;
	data.joueurs[i]->addcartes(1, carte_DIR_B);
	data.joueurs[i]->addcartes(2, carte_DIR_A);
	data.joueurs[i]->addcartes(3, carte_ACT_B);
	data.joueurs[i]->addcartes(4, carte_ACT_A);
	data.joueurs[i]->addcartes(5, carte_DIR_A);
	data.joueurs[i]->addcartes(6, carte_DIR_A);
	data.joueurs[i]->addcartes(7, carte_DIR_A);
	data.joueurs[i]->addcartes(8, carte_ACT_B);
	data.joueurs[i]->addcartes(9, carte_DIR_A);
	data.joueurs[i]->addcartes(10, carte_DIR_A);
	data.joueurs[i]->addcartes(11, carte_ACT_B);
	data.joueurs[i]->addcartes(12, carte_DIR_A);
}

void init_zone_white(t_data& data)
{
	cannon *cannon_zone_white = new canon_lourd("Cannon laser lourd Central", 5, data.zones[ZONE_WHITE]);
	cannon *cannon_impulsion_zone_white = new canon_impulsion(data.zones[ZONE_WHITE]);
    data.zones[ZONE_WHITE]->setzone_white(data.zones[ZONE_WHITE]);
    data.zones[ZONE_WHITE]->setzone_red(data.zones[ZONE_RED]);
    data.zones[ZONE_WHITE]->setzone_blue(data.zones[ZONE_BLUE]);
    data.zones[ZONE_WHITE]->setzone_right(data.zones[ZONE_BLUE]);
    data.zones[ZONE_WHITE]->setzone_left(data.zones[ZONE_RED]);
    data.zones[ZONE_WHITE]->setz_nom_zone("zone blanche");
    data.zones[ZONE_WHITE]->setz_bots(true);
    data.zones[ZONE_WHITE]->setz_temps(1);
    data.zones[ZONE_WHITE]->setz_capsule_energie(3);
    data.zones[ZONE_WHITE]->setz_ascenseur(true);
    data.zones[ZONE_WHITE]->setz_reacteur(3);
    data.zones[ZONE_WHITE]->setz_max_energie_reservoir(5);
    data.zones[ZONE_WHITE]->setz_bouclier(1);
    data.zones[ZONE_WHITE]->setz_max_energie_bouclier(3);
    data.zones[ZONE_WHITE]->setz_cannon_haut(cannon_zone_white);
    data.zones[ZONE_WHITE]->setz_cannon_bas(cannon_impulsion_zone_white);
    data.zones[ZONE_WHITE]->setz_chemin(new chemin_menace());
    data.zones[ZONE_WHITE]->setz_joueur_intercepteurs(nullptr);
    data.zones[ZONE_WHITE]->addz_actions_bas(ACT_A);
    data.zones[ZONE_WHITE]->addz_actions_bas(ACT_B);
    data.zones[ZONE_WHITE]->addz_actions_bas(ACT_C);
    data.zones[ZONE_WHITE]->addz_actions_bas(DIR_R);
    data.zones[ZONE_WHITE]->addz_actions_bas(DIR_B);
    data.zones[ZONE_WHITE]->addz_actions_bas(DIR_A);
    data.zones[ZONE_WHITE]->addz_actions_bas(ACT_AH);
    data.zones[ZONE_WHITE]->addz_actions_bas(ACT_BH);
    data.zones[ZONE_WHITE]->addz_actions_bas(ACT_R);
    data.zones[ZONE_WHITE]->addz_actions_haut(ACT_A);
    data.zones[ZONE_WHITE]->addz_actions_haut(ACT_B);
    data.zones[ZONE_WHITE]->addz_actions_haut(ACT_C);
    data.zones[ZONE_WHITE]->addz_actions_haut(DIR_R);
    data.zones[ZONE_WHITE]->addz_actions_haut(DIR_A);
    data.zones[ZONE_WHITE]->addz_actions_haut(DIR_B);
    data.zones[ZONE_WHITE]->addz_actions_haut(ACT_AH);
    data.zones[ZONE_WHITE]->addz_actions_haut(ACT_BH);
    data.zones[ZONE_WHITE]->addz_actions_haut(ACT_R);
    data.zones[ZONE_WHITE]->setz_degats_doubles(false);
    data.zones[ZONE_WHITE]->setz_data(data);
    data.zones[ZONE_WHITE]->setz_ordre_degats();
    data.zones[ZONE_WHITE]->setz_jump_tour_upon_entry_haut(false);
    data.zones[ZONE_WHITE]->setz_jump_tour_upon_entry_bas(false);
}

void init_zone_blue(t_data& data)
{
    cannon *cannon_zone_blue = new canon_lourd("Cannon laser lourd lateral", 4, data.zones[ZONE_BLUE]);
	cannon *cannon_leger_zone_blue = new canon_lateral(data.zones[ZONE_BLUE]);
    data.zones[ZONE_BLUE]->setzone_white(data.zones[ZONE_WHITE]);
    data.zones[ZONE_BLUE]->setzone_red(data.zones[ZONE_RED]);
    data.zones[ZONE_BLUE]->setzone_blue(data.zones[ZONE_BLUE]);
    data.zones[ZONE_BLUE]->setzone_right(data.zones[ZONE_RED]);
    data.zones[ZONE_BLUE]->setzone_left(data.zones[ZONE_WHITE]);
    data.zones[ZONE_BLUE]->setz_nom_zone("zone bleue");
    data.zones[ZONE_BLUE]->setz_bots(true);
    data.zones[ZONE_BLUE]->setz_temps(1);
    data.zones[ZONE_BLUE]->setz_capsule_energie(0);
    data.zones[ZONE_BLUE]->setz_ascenseur(true);
    data.zones[ZONE_BLUE]->setz_reacteur(2);
    data.zones[ZONE_BLUE]->setz_degats_doubles(false);
    data.zones[ZONE_BLUE]->setz_max_energie_reservoir(3);
    data.zones[ZONE_BLUE]->setz_bouclier(1);
    data.zones[ZONE_BLUE]->setz_max_energie_bouclier(2);
    data.zones[ZONE_BLUE]->setz_cannon_haut(cannon_zone_blue);
    data.zones[ZONE_BLUE]->setz_cannon_bas(cannon_leger_zone_blue);
    data.zones[ZONE_BLUE]->setz_chemin(new chemin_menace());
    data.zones[ZONE_BLUE]->setz_joueur_intercepteurs(nullptr);
    data.zones[ZONE_BLUE]->addz_actions_bas(ACT_A);
    data.zones[ZONE_BLUE]->addz_actions_bas(ACT_B);
    data.zones[ZONE_BLUE]->addz_actions_bas(ACT_C);
    data.zones[ZONE_BLUE]->addz_actions_bas(DIR_R);
    data.zones[ZONE_BLUE]->addz_actions_bas(DIR_A);
    data.zones[ZONE_BLUE]->addz_actions_bas(ACT_AH);
    data.zones[ZONE_BLUE]->addz_actions_bas(ACT_BH);
    data.zones[ZONE_BLUE]->addz_actions_bas(ACT_R);
    data.zones[ZONE_BLUE]->addz_actions_haut(ACT_A);
    data.zones[ZONE_BLUE]->addz_actions_haut(ACT_B);
    data.zones[ZONE_BLUE]->addz_actions_haut(ACT_C);
    data.zones[ZONE_BLUE]->addz_actions_haut(DIR_R);
    data.zones[ZONE_BLUE]->addz_actions_haut(DIR_A);
    data.zones[ZONE_BLUE]->addz_actions_haut(ACT_AH);
    data.zones[ZONE_BLUE]->addz_actions_haut(ACT_BH);
    data.zones[ZONE_BLUE]->addz_actions_haut(ACT_R);
    data.zones[ZONE_BLUE]->setz_data(data);
    data.zones[ZONE_BLUE]->setz_ordre_degats();
    data.zones[ZONE_BLUE]->setz_jump_tour_upon_entry_haut(false);
    data.zones[ZONE_BLUE]->setz_jump_tour_upon_entry_bas(false);
    data.zones[ZONE_BLUE]->setz_roquete_position(1, 0);
    data.zones[ZONE_BLUE]->setz_roquete_position(2, 0);
    data.zones[ZONE_BLUE]->setz_roquete_position(3, 0);
}

void init_zone_red(t_data& data)
{
    data.zones[ZONE_RED]->setz_data(data);
	cannon *cannon_zone_red = new canon_lourd("Cannon laser lourd lateral", 4, data.zones[ZONE_RED]);
	cannon *cannon_leger_zone_red = new canon_lateral(data.zones[ZONE_RED]);
    data.zones[ZONE_RED]->setzone_white(data.zones[ZONE_WHITE]);
    data.zones[ZONE_RED]->setzone_red(data.zones[ZONE_RED]);
    data.zones[ZONE_RED]->setzone_blue(data.zones[ZONE_BLUE]);
    data.zones[ZONE_RED]->setzone_right(data.zones[ZONE_WHITE]);
    data.zones[ZONE_RED]->setzone_left(data.zones[ZONE_BLUE]);
    data.zones[ZONE_RED]->setz_degats_doubles(false);
    data.zones[ZONE_RED]->setz_nom_zone("zone rouge");
    data.zones[ZONE_RED]->setz_bots_englues(false);
    data.zones[ZONE_RED]->setz_bots(true);
    data.zones[ZONE_RED]->setz_temps(1);
    data.zones[ZONE_RED]->setz_capsule_energie(0);
    data.zones[ZONE_RED]->setz_ascenseur(true);
    data.zones[ZONE_RED]->setz_reacteur(2);
    data.zones[ZONE_RED]->setz_max_energie_reservoir(3);
    data.zones[ZONE_RED]->setz_bouclier(1);
    data.zones[ZONE_RED]->setz_max_energie_bouclier(2);
    data.zones[ZONE_RED]->setz_cannon_haut(cannon_zone_red);
    data.zones[ZONE_RED]->setz_cannon_bas(cannon_leger_zone_red);
    data.zones[ZONE_RED]->setz_chemin(new chemin_menace());
    data.zones[ZONE_RED]->setz_joueur_intercepteurs(nullptr);
    data.zones[ZONE_RED]->addz_actions_bas(ACT_A);
    data.zones[ZONE_RED]->addz_actions_bas(ACT_B);
    data.zones[ZONE_RED]->addz_actions_bas(ACT_C);
    data.zones[ZONE_RED]->addz_actions_bas(DIR_B);
    data.zones[ZONE_RED]->addz_actions_bas(DIR_A);
    data.zones[ZONE_RED]->addz_actions_bas(ACT_AH);
    data.zones[ZONE_RED]->addz_actions_bas(ACT_BH);
    data.zones[ZONE_RED]->addz_actions_bas(ACT_R);
    data.zones[ZONE_RED]->addz_actions_haut(ACT_A);
    data.zones[ZONE_RED]->addz_actions_haut(ACT_B);
    data.zones[ZONE_RED]->addz_actions_haut(ACT_C);
    data.zones[ZONE_RED]->addz_actions_haut(DIR_B);
    data.zones[ZONE_RED]->addz_actions_haut(DIR_A);
    data.zones[ZONE_RED]->addz_actions_haut(ACT_AH);
    data.zones[ZONE_RED]->addz_actions_haut(ACT_BH);
    data.zones[ZONE_RED]->addz_actions_haut(ACT_R);
    data.zones[ZONE_RED]->setz_ordre_degats();
    data.zones[ZONE_RED]->setz_jump_tour_upon_entry_haut(false);
    data.zones[ZONE_RED]->setz_jump_tour_upon_entry_bas(false);
}

void init_data(t_data& data)
{
	data.nb_joueur = 0;
	data.tour = 1;
    data.chemin_menace_interne = new chemin_menace;
	data.zones[ZONE_WHITE] = new zone(ZONE_WHITE);
	data.zones[ZONE_BLUE] = new zone(ZONE_BLUE);
	data.zones[ZONE_RED] = new zone(ZONE_RED);
    data.VoixAlert = new GameNarrator(true, "fr+f2", 110, 60);
    data.VoixRobot1 = new GameNarrator(true, "fr+m2", 100, 28);
    data.VoixRobot2 = new GameNarrator(true, "fr+m6", 100, 30);
    init_zone_white(data);
    init_zone_blue(data);
    init_zone_red(data);
}

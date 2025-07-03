#include "zone.hpp"
#include "chemin_menace.hpp"
#include "menace.hpp"
#include "menace_externe.hpp"
#include "menace_interne.hpp"

void zone::addtemps()
{
	z_temps++;
}

void zone::addz_joueurs_bas(joueur* input)
{
	if (z_jump_tour_upon_entry_bas)
	{
		input->setj_jump_tour(true);
		z_joueurs_bas.push_back(input);
	}
	else
		z_joueurs_bas.push_back(input);
}

void zone::addz_joueurs_haut(joueur* input)
{
	if (z_jump_tour_upon_entry_haut)
	{
		input->setj_jump_tour(true);
		z_joueurs_haut.push_back(input);
	}
	else
		z_joueurs_haut.push_back(input);
}

void zone::assomerjoueursZoneHaut_IfNoActifRobot()
{
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_haut.begin(); it != z_joueurs_haut.end(); it++)
	{
		if((*it)->getj_bots() != BOTS_EVEILLE)
			(*it)->setcarteAssome(z_temps);
	}
}

void zone::assomerjoueursZoneBas_IfNoActifRobot()
{
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_bas.begin(); it != z_joueurs_bas.end(); it++)
	{
		if((*it)->getj_bots() != BOTS_EVEILLE)
			(*it)->setcarteAssome(z_temps);
	}
}

void zone::assomerjoueursZoneHaut()
{
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_haut.begin(); it != z_joueurs_haut.end(); it++)
	{
		(*it)->setcarteAssome(z_temps);
	}
}

void zone::assomerjoueursZoneHautRobotsActifs()
{
	std::string msg;
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_haut.begin(); it != z_joueurs_haut.end(); it++)
	{
		if ((*it)->getj_bots() == 1)
		{
			(*it)->setcarteAssome(z_temps);
			printSlowly(msg, *z_data);
		}
	}
	if (z_zone == ZONE_RED)
	{
		if (z_joueur_intercepteurs)
		{
			z_joueur_intercepteurs->setcarteAssome(z_temps);
			printSlowly(msg, *z_data);
		}
	}
}

void zone::assomerjoueursZoneBas()
{
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_bas.begin(); it != z_joueurs_bas.end(); it++)
	{
		(*it)->setcarteAssome(z_temps);
	}
}

void zone::assomerjoueursZoneBasRobotsActifs()
{
	std::string msg;
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_bas.begin(); it != z_joueurs_bas.end(); it++)
	{
		if ((*it)->getj_bots() == 1)
		{
			(*it)->setcarteAssome(z_temps);
			printSlowly(msg, *z_data);
		}
	}
}

void zone::retarderactionZoneHaut()
{
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_haut.begin(); it != z_joueurs_haut.end(); it++)
	{
		(*it)->setj_jump_tour(true);
	}
}

void zone::retarderactionZoneBas()
{
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_bas.begin(); it != z_joueurs_bas.end(); it++)
	{
		(*it)->setj_jump_tour(true);
	}
}

void zone::removez_joueur_intercepteurs()
{
	this->addz_joueurs_haut(z_joueur_intercepteurs);
	z_joueur_intercepteurs = nullptr;
}

void zone::assomerjoueursZone()
{
	assomerjoueursZoneHaut();
	assomerjoueursZoneBas();
}

void zone::assomerjoueursZoneRobotsActifs()
{
	assomerjoueursZoneHautRobotsActifs();
	assomerjoueursZoneBasRobotsActifs();
}

void zone::retarderactionZone()
{
	retarderactionZoneHaut();
	retarderactionZoneBas();
}

void zone::etatdesdegats()
{
	std::string msg;
	z_degats_recu++;
	if(z_degats_recu > 6)
	{
		msg = "[Le vaisseau a recu trop de degats, il est detruit !]\n";
		mission_failed(msg, *z_data);
		return ;
	}
	int degat = z_ordre_degats[z_degats_recu];
	if (degat == 1)
	{
		msg = "[Le vaisseau a recu des degats mais ils sont negligeables!]\n";
		printSlowly(msg, *z_data);
	}
	else if (degat == 2)
	{
		msg = "[Le vaisseau a recu des degats et l'ascenseur de la " + z_nom_zone + " est endommage !]\n";
		printSlowly(msg, *z_data);
		this->removez_actions_bas(DIR_A);
		this->removez_actions_haut(DIR_A);
	}
	else if (degat == 3)
	{
		msg = "[Le vaisseau a recu des degats et le canon lazer lourd de la " + z_nom_zone + " est endommage !]\n";
		printSlowly(msg, *z_data);
		z_cannon_haut->setpuissance_cannon(z_cannon_haut->getpuissance_cannon() - 1);
		msg = "------> [Ce canon lourd a desormais une puissance de " + std::to_string(z_cannon_haut->getpuissance_cannon()) + " !]\n";
		printSlowly(msg, *z_data);
	}
	else if (degat == 4)
	{
		msg = "[Le vaisseau a recu des degats et le reacteur de la " + z_nom_zone + " est endommage !]\n";
		printSlowly(msg, *z_data);
		z_max_reacteur--;
		if (z_reacteur > z_max_reacteur)
		{
			z_reacteur = z_max_reacteur;
		}
		msg = "------> [Ce reacteur a desormais une capacite de " + std::to_string(z_max_reacteur) + " !]\n";
		printSlowly(msg, *z_data);
	}
	else if (degat == 5)
	{
		msg = "[Le vaisseau a recu des degats et le bouclier de la " + z_nom_zone + " est endommage !]\n";
		printSlowly(msg, *z_data);
		z_max_energie_bouclier--;
		if (z_bouclier > z_max_energie_bouclier)
		{
			z_bouclier = z_max_energie_bouclier;
		}
		msg = "------> [Ce bouclier a desormais une capacite de " + std::to_string(z_max_energie_bouclier) + " !]\n";
		printSlowly(msg, *z_data);
	}
	else if (degat == 6)
	{
		if (z_zone == ZONE_WHITE)
		{
			msg = "[Le vaisseau a recu des degats et le canon a impulsion de la " + z_nom_zone + " est endommage !]\n";
			printSlowly(msg, *z_data);
			z_cannon_bas->setportee_cannon(z_cannon_bas->getportee_cannon() - 5);
			msg = "------> [Ce canon leger a desormais une portee de " + std::to_string(z_cannon_bas->getportee_cannon()) + " !]\n";
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[Le vaisseau a recu des degats et le canon laser leger de la " + z_nom_zone + " est endommage !]\n";
			printSlowly(msg, *z_data);
			z_cannon_bas->setpuissance_cannon(z_cannon_bas->getpuissance_cannon() - 1);
			msg = "------> [Ce canon leger a desormais une puissance de " + std::to_string(z_cannon_bas->getpuissance_cannon()) + " !]\n";
			printSlowly(msg, *z_data);
		}
	}
}

void zone::getdegats(int input)
{
	if (input == 0)
		return;
	int degats_absorbes(0);
	if (z_zone == 1)
        std::cout << "\033[1;31m[DEGATS ZONE ROUGE]\n";
    else if (z_zone == 2)
        std::cout << "\033[1;37m[DEGATS ZONE BLANCHE]\n";
    else if (z_zone == 3)
	{
        std::cout << "\033[1;36m[DEGATS ZONE BLEUE]\n";
	}
	while (z_bouclier > 0 && input > 0)
	{
		degats_absorbes++;
		z_bouclier--;
		input--;
	}
	if (z_degats_doubles && input)
	{
		std::string msg = "[Attention, les degats recus sont doubles!]\n";
		printSlowly(msg, *z_data);
		input = input * 2;
	}
	else if (!input)
	{
		std::string msg = "[Le bouclier de la zone rouge absorbe tous les degats!]\n";
		msg += "[Bouclier restant : " + std::to_string(z_bouclier) + "]\n";
		printSlowly(msg, *z_data);
	}
	else if (input && degats_absorbes)
	{
		std::string msg = "[Le bouclier de la zone rouge absorbe" + std::to_string(degats_absorbes) + " degat(s)!]\n";
		printSlowly(msg, *z_data);
	}
	while (input > 0)
	{
		etatdesdegats();
		input--;
	}
	end_color();
}

void zone::getdegatsIgnoreBouclier(int input)
{
	if (input == 0)
		return;
	if (z_zone == 1)
        std::cout << "\033[1;31m[DEGATS ZONE ROUGE]\n";
    else if (z_zone == 2)
        std::cout << "\033[1;37m[DEGATS ZONE BLANCHE]\n";
    else if (z_zone == 3)
	{
        std::cout << "\033[1;36m[DEGATS ZONE BLEUE]\n";
	}
	while (input > 0)
	{
		etatdesdegats();
		input--;
	}
	end_color();
}

menace_interne* zone::is_menace_fissure()
{
	std::vector<menace_interne *> menaces_interne = this->getz_chemin_menace_Int()->get_menacesInte();

	std::vector<menace_interne *>::iterator it;
	for (it = menaces_interne.begin(); it != menaces_interne.end(); it++)
	{
		if ((*it)->get_m_name() == "Fissure")
			return ((*it));
	}
	return (nullptr);
}

void zone::removez_joueurs_haut(std::string input)
{
	for (std::vector<joueur*>::iterator it = z_joueurs_haut.begin(); it != z_joueurs_haut.end();)
	{
		if (!*it)
		{
			it = z_joueurs_haut.erase(it);
			continue;
		}
		if (z_joueurs_haut.size() == 0)
		{
			return;
		}
        if ((*it)->getj_nom() == input)
		{
            it = z_joueurs_haut.erase(it);
		}
        else
            ++it;
    }
}

void zone::removez_joueurs_bas(std::string input)
{
	for (std::vector<joueur*>::iterator it = z_joueurs_bas.begin(); it != z_joueurs_bas.end();)
	{
		if (!*it)
		{
			it = z_joueurs_bas.erase(it);
			continue;
		}
		if (z_joueurs_bas.size() == 0)
		{
			return;
		}
        if ((*it)->getj_nom() == input)
            it = z_joueurs_bas.erase(it);
        else
            ++it;
    }
}

joueur* zone::getz_joueur_bas(std::string nom)
{
	std::vector<joueur*>::iterator it;

	for (it = z_joueurs_bas.begin(); it != z_joueurs_bas.end();)
	{
        if ((*it)->getj_nom() == nom)
            return *it;
        else
            ++it;
    }
	return (NULL);
}

joueur* zone::getz_joueur_haut(std::string nom)
{
	std::vector<joueur*>::iterator it;
	for (it = z_joueurs_haut.begin(); it != z_joueurs_haut.end();)
	{
        if ((*it)->getj_nom() == nom)
		{
			return *it;
		}
        else
            ++it;
    }
	return (NULL);
}

void zone::addz_actions_haut(int input)
{
	z_actions_haut.push_back(input);
}

void zone::removez_actions_haut(int input)
{
	z_actions_haut.erase(std::remove(z_actions_haut.begin(), z_actions_haut.end(), input), z_actions_haut.end());
}

void zone::removez_actions_bas(int input)
{
	z_actions_bas.erase(std::remove(z_actions_bas.begin(), z_actions_bas.end(), input), z_actions_bas.end());
}

void zone::addz_actions_used_ce_tour_haut(int input)
{
	z_actions_used_ce_tour_haut.push_back(input);
}

void zone::clearz_actions_used_ce_tour_haut()
{
	z_actions_used_ce_tour_haut.clear();
}

std::vector<int> zone::getz_maintenance_ordinateur() const
{
	return z_maintenance_ordinateur;
}

std::vector<int> zone::getz_observations() const
{
	return z_observations;
}

void zone::addz_maintenance_ordinateur(int input)
{
	z_maintenance_ordinateur.push_back(input);
}

void zone::addz_observations(int input)
{
	z_observations.push_back(input);
}

void zone::clearz_cannon_used()
{
	z_cannon_used.clear();
}

void zone::addz_cannon_used(cannon* input)
{
	z_cannon_used.push_back(input);
}

void zone::addz_actions_bas(int input)
{
	z_actions_bas.push_back(input);
}

void zone::addz_actions_used_ce_tour_bas(int input)
{
	z_actions_used_ce_tour_bas.push_back(input);
}

void zone::clearz_actions_used_ce_tour_bas()
{
	z_actions_used_ce_tour_bas.clear();
}

void zone::printZone()
{
	wr("--------- ZONE START---------");
	wr("Zone : " + z_nom_zone);
	std::cout << "Temps : " << z_temps << std::endl;
	std::cout << "Bouclier : " << z_bouclier << std::endl;
	std::cout << "Reacteur : " << z_reacteur << "/ " << std::to_string(z_max_reacteur) << std::endl;
	std::cout << "Capsule d'energie : " << z_capsule_energie << std::endl;
	wr("Joueur en jeu : " + z_joueur_playing);
	wr("chemin_menace : " + z_chemin_menace->get_ch_nom());
	wr("--------- ZONE END---------");
}

int zone::countPlayerInStation(bool m_position_haut) // count nbr joueur dans station de la zone
{
	std::vector<joueur*>::iterator it;
	int count(0);
	if(m_position_haut)
	{
		for (it = z_joueurs_haut.begin(); it != z_joueurs_haut.end();it++)
		{
			count++;
		}
	}
	else
	{
		for (it = z_joueurs_bas.begin(); it != z_joueurs_bas.end();it++)
		{
			count++;
		}
	}
	return(count);
}

// en fonction d ou tu es regarde vers ou il y a le plus de joueur
std::string zone::stationWithMostPlayer(bool m_position_haut, int zone)
{
	int upDownCount(0);
	upDownCount = countPlayerInStation(!m_position_haut);
	int leftCount = getzone_left()->countPlayerInStation(m_position_haut);
	int rightCount = getzone_right()->countPlayerInStation(m_position_haut);
	if(zone == ZONE_BLUE)
	{
		if(upDownCount == leftCount)
			return("No movement");
		else if(leftCount > upDownCount)
			return("Left");
		else
			return("Up/Down");
	}
	else if(zone == ZONE_RED)
	{
		if(upDownCount == rightCount)
			return("No movement");
		else if(rightCount > upDownCount)
			return("Right");
		else
			return("Up/Down");
	}
	else if(zone == ZONE_WHITE)
	{
		if(upDownCount == rightCount && rightCount == leftCount)
			return("No movement");
		else if(rightCount > upDownCount && rightCount > leftCount)
			return("Right");
		else if(leftCount > upDownCount && leftCount > rightCount)
			return("Left");
		else if(upDownCount > leftCount && upDownCount > rightCount)
			return("Up/Down");
		else
			return("No mouvement");
	}
	return("FUCK");
}

// le joueur est dans les vaisseaux et une autre action que Robot est faite
void zone::wrongActionInSpace()
{
	if(z_zone == ZONE_RED)
	{
		std::string msg = "[Vous revenez dans le vaisseau et vos attaques sont decalees!!]\n";
		printSlowly(msg, *z_data);
		this->addz_joueurs_haut(z_joueur_intercepteurs);
		this->removez_joueur_intercepteurs();
		this->getz_joueur_haut(z_joueur_playing)->passerTour(this->getz_temps() - 1);
	}
}

void zone::printz_action_ce_tour_haut()
{
	std::vector<int>::iterator it;
	std::cout << "z_action_USED_haut : \n";
	for (it = z_actions_used_ce_tour_haut.begin(); it != z_actions_used_ce_tour_haut.end(); it++)
	{
		std::cout << " / " << (*it);
	}
	std::cout << "\n fin z_action_USED_haut : \n";
}

bool zone::action_used_ce_tour_haut(int input)
{
	std::vector<int>::iterator it;
	for (it = z_actions_used_ce_tour_haut.begin(); it != z_actions_used_ce_tour_haut.end(); it++)
	{
		if (*it == input)
			return (true);
	}
	return (false);
}

bool zone::action_used_ce_tour_bas(int input)
{
	std::vector<int>::iterator it;
	for (it = z_actions_used_ce_tour_bas.begin(); it != z_actions_used_ce_tour_bas.end(); it++)
	{
		if (*it == input)
			return (true);
	}
	return (false);
}

bool zone::action_possible_haut(int input)
{
	std::vector<int>::iterator it;
	for (it = z_actions_haut.begin(); it != z_actions_haut.end(); it++)
	{
		if (*it == input)
			return (true);
	}
	return (false);
}

bool zone::action_possible_bas(int input)
{
	std::vector<int>::iterator it;
	for (it = z_actions_bas.begin(); it != z_actions_bas.end(); it++)
	{
		if (*it == input)
			return (true);
	}
	return (false);
}

void zone::printz_action_ce_tour_bas()
{
	std::vector<int>::iterator it;
	std::cout << "z_action_USED_bas : \n";
	for (it = z_actions_used_ce_tour_bas.begin(); it != z_actions_used_ce_tour_bas.end(); it++)
	{
		std::cout << " / " << (*it);
	}
	std::cout << "\n fin z_action_USED_bas : \n";
}

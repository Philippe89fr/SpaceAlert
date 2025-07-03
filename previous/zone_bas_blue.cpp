#include "zone_bas_blue.hpp"

zone_bas_blue::zone_bas_blue(): zone(ZONE_BAS_RED, 2, CANON_LATERAUX, "canon lateral droit")
{
	this->addz_deplacements_lateraux(ZONE_BAS_WHITE);
	roquete_position[1] = 0;
	roquete_position[2] = 0;
	roquete_position[3] = 0;
    z_energie_dispo = 2;
	z_max_energie = 3;
}

int zone_bas_blue::getz_energie_dispo() const
{
	return (z_energie_dispo);
}

bool zone_bas_blue::roquete_damage()
{
	if (roquete_position[1] == 2 || roquete_position[2] == 2 || roquete_position[3] == 2)
		return (true);
	return (false);
}

void zone_bas_blue::setz_energie_dispo(int input)
{
	z_energie_dispo = input;
}

/* ------------------------- ACTION ATTACK -------------------------*/
bool zone_bas_blue::actionA()
{
	const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour().begin(), this->getz_actions_used_ce_tour().end(), ACT_A);
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_A);

    if (action_ce_tour == this->getz_actions_used_ce_tour().end() && action_possible != this->getz_actions().end())
	{
		if (z_energie_dispo)
		{
			wr("[ATTACK avec le " + this->getz_nom_canon() + " !]");
			z_energie_dispo -= 1;
			std::cout << "[Carburant disponible : " << z_energie_dispo << "]\n";
			this->addz_actions(ACT_A);
			return (true);
		}
		else
		{
			wr("[Tentative d'attack avec " + this->getz_nom_canon() + " ... Echec par manque d'energie! Dommage...]");
			this->addz_actions(ACT_A);
			return (false);
		}
	}
	else
	{
		wr("[Tentative d'attack avec " + this->getz_nom_canon() + " Echec, coordonnez vous bordel]");
		return (false);
	}
}

/* ------------------------- ACTION ATTACK -------------------------*/
bool zone_bas_blue::actionAHeros()
{
	const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour().begin(), this->getz_actions_used_ce_tour().end(), ACT_A);
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_A);

    if (action_ce_tour == this->getz_actions_used_ce_tour().end() && action_possible != this->getz_actions().end())
	{
		if (z_energie_dispo)
		{
			wr("[HERO MODE - ATTACK avec le " + this->getz_nom_canon() + " !]");
			z_energie_dispo -= 1;
			std::cout << "[Carburant disponible : " << z_energie_dispo << "]\n";
			this->addz_actions(ACT_A);
			return (true);
		}
		else
		{
			wr("[HERO MODE - Tentative d'attack avec le " + this->getz_nom_canon() + "... Echec par manque d'energie! Dommage...]");
			this->addz_actions(ACT_A);
			return (false);
		}
	}
	else
	{
		wr("[HERO MODE - Tentative d'attack avec le " + this->getz_nom_canon() + "... Echec, coordonnez vous bordel]");
		return (false);
	}
}

/* ------------------------- ACTION ENERGIE -------------------------*/
void zone_bas_blue::actionB()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_B);

	if (action_possible != this->getz_actions().end())
	{
		if (zone_white->getz_energie_dispo())
		{
			wr("[Recuperation de l'energie du reacteur central pour alimenter le reacteur gauche]");
			while (zone_white->getz_energie_dispo() || z_energie_dispo < z_max_energie)
			{
				zone_white->setz_energie_dispo(zone_white->getz_energie_dispo() - 1);
				z_energie_dispo++;
			}
			std::cout << "[Energie disponible dans le reacteur gauche : " << z_energie_dispo << "]\n";
			std::cout << "[Energie disponible dans le reacteur central : " << zone_white->getz_energie_dispo() << "]\n";
		}
		else
		{
			wr("[Tentative de recuperation de l'energie du reacteur central pour alimenter le reacteur.. Echec... c'est la merde, et en plus ton tour sert a rien...]");
		}
	}
	else
	{
		wr("[Tentative de rechargement du reacteur gauche... Vous ne pouvez pas.");
	}
}

/* ------------------------- ACTION ENERGIE -------------------------*/
void zone_bas_blue::actionBHeros()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_B);

	if (action_possible != this->getz_actions().end())
	{
		if (zone_white->getz_energie_dispo())
		{
			wr("[HERO MODE - Recuperation de l'energie du reacteur central pour alimenter le reacteur gauche]");
			while (zone_white->getz_energie_dispo() || z_energie_dispo < z_max_energie + 1)
			{
				zone_white->setz_energie_dispo(zone_white->getz_energie_dispo() - 1);
				z_energie_dispo++;
			}
			std::cout << "[Energie disponible dans le reacteur gauche : " << z_energie_dispo << "]\n";
			std::cout << "[Energie disponible dans le reacteur central : " << zone_white->getz_energie_dispo() << "]\n";
		}
		else
		{
			wr("[HERO MODE - Tentative de recuperation de l'energie du reacteur central pour alimenter le reacteur.. Echec... c'est la merde, et en plus ton tour sert a rien...]");
		}
	}
	else
	{
		wr("[HERO MODE - Tentative de rechargement du reacteur gauche... Vous ne pouvez pas.");
	}
}

void zone_bas_blue::actionC()
{
	const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour().begin(), this->getz_actions_used_ce_tour().end(), ACT_C);
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_C);

	if (action_ce_tour == this->getz_actions_used_ce_tour().end() && action_possible != this->getz_actions().end())
	{
		if (roquete_position[1] == 0)
		{
			wr("[Lancement de la premiere rocket !]");
			roquete_position[1] = 1;
			this->addz_actions_used_ce_tour(ACT_C);
		}
		else if (roquete_position[2] == 0)
		{
			wr("[Lancement de la premiere rocket !]");
			roquete_position[2] = 1;
			this->addz_actions_used_ce_tour(ACT_C);
		}
		else if (roquete_position[3] == 0)
		{
			wr("[Lancement de la premiere rocket !]");
			roquete_position[3] = 1;
			this->addz_actions_used_ce_tour(ACT_C);
		}
		else
		{
			wr("[Toutes les roquetes ont deja ete lancees... pas la peine de s'exciter frere]");
		}
	}
	else if (action_ce_tour != this->getz_actions_used_ce_tour().end())
	{
		wr("[Mais coordonnez vous bordel, rocket deja lancee]");
	}
	else if (action_possible == this->getz_actions().end())
	{
		wr("[Impossible de lancer les roquettes]");
	}
}

/* ------------------------- ACTION ASCENSEUR -------------------------*/
bool zone_bas_blue::ascenseur()
{
	if (this->getz_ascenseur())
	{
		wr("[Vous prenez l'ascenseur pour monter d'un etage.]");
		this->setz_ascenseur(false);
		this->getz_joueur(this->getz_joueur_playing())->setj_zone(ZONE_HAUT_BLUE);
		return (true);
	}
	else
	{
		wr("[Vous ne pouvez pas prendre l'ascenseur....]");
		return (false);
	}
}

void zone_bas_blue::setzone_bas(zone* zone) {
	zone->setz_ascenseur(true);
}

zone* zone_bas_blue::getzone_bas() const {
	zone *zone = NULL;
	return (zone);
}

zone_bas_blue::~zone_bas_blue() {}

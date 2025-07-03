#include "zone_bas_red.hpp"

zone_bas_red::zone_bas_red(): zone(ZONE_BAS_RED, 2, CANON_LATERAUX, "canon lateral gauche")
{
	this->addz_deplacements_lateraux(ZONE_BAS_WHITE);
	z_bots = true;
    z_energie_dispo = 2;
	z_max_energie = 3;
}

int zone_bas_red::getz_energie_dispo() const
{
	return (z_energie_dispo);
}

bool zone_bas_red::getz_bots() const
{
	return (z_bots);
}

void zone_bas_red::setz_energie_dispo(int input)
{
	z_energie_dispo = input;
}

void zone_bas_red::setz_bots(bool input)
{
	z_bots = input;
}

/* ------------------------- ACTION ATTACK -------------------------*/
bool zone_bas_red::actionA()
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
			this->addz_actions_used_ce_tour(ACT_A);
			return (true);
		}
		else
		{
			wr("[Tentative d'attack avec " + this->getz_nom_canon() + " ... Echec par manque d'energie! Dommage...]");
			this->addz_actions_used_ce_tour(ACT_A);
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
bool zone_bas_red::actionAHeros()
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
			this->addz_actions_used_ce_tour(ACT_A);
			return (true);
		}
		else
		{
			wr("[HERO MODE - Tentative d'attack avec le " + this->getz_nom_canon() + "... Echec par manque d'energie! Dommage...]");
			this->addz_actions_used_ce_tour(ACT_A);
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
void zone_bas_red::actionB()
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
void zone_bas_red::actionBHeros()
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
		wr("[HERO MODE - Tentative de rechargement du reacteur gauche... Vous ne pouvez pas.]");
	}
}

/* ------------------------- ACTION PRENDRE ROBOT -------------------------*/
void zone_bas_red::actionC()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_C);

	if (action_possible != this->getz_actions().end())
	{
		if (z_bots)
		{
			wr("[Vous prenez les robots avec vous! C'est parti pour la baston!]");
			z_bots = false;
		}
		else
		{
			wr("[Faites un effort, la vous allez tous mourir... Les robots accompagnent deja un autre joueur.]");
		}
	}
	else
	{
		wr("[Impossible de prendre les robots a ce tour, dommage!]");
	}
}

/* ------------------------- ACTION ASCENSEUR -------------------------*/
bool zone_bas_red::ascenseur()
{
	if (this->getz_ascenseur())
	{
		wr("[Vous prenez l'ascenseur pour monter d'un etage.]");
		this->setz_ascenseur(false);
		this->getz_joueur(this->getz_joueur_playing())->setj_zone(ZONE_HAUT_RED);
		return (true);
	}
	else
	{
		wr("[Vous ne pouvez pas prendre l'ascenseur....]");
		return (false);
	}
}
void zone_bas_red::setzone_bas(zone* zone) {
	zone->setz_ascenseur(true);
}

zone* zone_bas_red::getzone_bas() const {
	zone *zone = NULL;
	return (zone);
}

zone_bas_red::~zone_bas_red() {}

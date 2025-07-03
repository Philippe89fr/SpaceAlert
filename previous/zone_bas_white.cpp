#include "zone_bas_white.hpp"

zone_bas_white::zone_bas_white(): zone(ZONE_BAS_WHITE, 1, CANON_IMPULSION, "canon a impulsion central")
{
	this->addz_deplacements_lateraux(ZONE_BAS_RED);
	this->addz_deplacements_lateraux(ZONE_BAS_BLUE);
	z_reserve_capsule_carburant = 3;
    z_energie_dispo = 3;
}

int zone_bas_white::getz_energie_dispo() const
{
	return (z_energie_dispo);
}

void zone_bas_white::setz_energie_dispo(int input)
{
	z_energie_dispo = input;
}

bool zone_bas_white::actionA()
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

bool zone_bas_white::actionAHeros()
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
void zone_bas_white::actionB()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_B);

	if (action_possible != this->getz_actions().end())
	{
		if (z_reserve_capsule_carburant)
		{
			wr("[Activation capsule de carburant - Carburant disponible : 5]");
			z_energie_dispo = 5;
			z_reserve_capsule_carburant -= 1;
			std::cout << "[Capsule de carburant disponible : " << z_reserve_capsule_carburant << "]\n";
		}
		else
		{
			wr("[Tentative d'activation d'une capsule de carburant... echouee... plus de carburant disponible]");
		}
	}
	else
	{
		wr("[Tentative d'activation d'une capsule de carburant... echouee... Impossible dans l'etat du vaisseaux...]");
	}
}

/* ------------------------- ACTION ENERGIE -------------------------*/
void zone_bas_white::actionBHeros()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_B);

	if (action_possible != this->getz_actions().end())
	{
		if (z_reserve_capsule_carburant)
		{
			wr("[HERO MODE - Activation capsule de carburant - HERO MODE - Carburant disponible : 6]");
			z_energie_dispo = 6;
			z_reserve_capsule_carburant -= 1;
			std::cout << "[Capsule de carburant disponible : " << z_reserve_capsule_carburant << "]\n";
		}
		else
		{
			wr("[HERO MODE - Tentative d'activation d'une capsule de carburant... echouee... plus de carburant disponible]");
		}
	}
	else
	{
		wr("[HERO MODE - Tentative d'activation d'une capsule de carburant... echouee... Impossible dans l'etat du vaisseaux...]");
	}
}

/* ------------------------- ACTION ASCENSEUR -------------------------*/
bool zone_bas_white::ascenseur()
{
	if (this->getz_ascenseur())
	{
		wr("[Vous prenez l'ascenseur pour monter d'un etage.]");
		this->setz_ascenseur(false);
		this->getz_joueur(this->getz_joueur_playing())->setj_zone(ZONE_HAUT_WHITE);
		return (true);
	}
	else
	{
		wr("[Vous ne pouvez pas prendre l'ascenseur....]");
		return (false);
	}
}

void zone_bas_white::actionC()
{
	wr("[Ta mere la tchoin, t'as cru que vous alliez survivre avec ce genre de move ?!]");
}

void zone_bas_white::setzone_bas(zone* zone) {
	zone->setz_ascenseur(true);
}

zone* zone_bas_white::getzone_bas() const {
	zone *zone = NULL;
	return (zone);
}

zone_bas_white::~zone_bas_white() {}

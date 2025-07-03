#include "zone_haut_white.hpp"

zone_haut_white::zone_haut_white(): zone(ZONE_HAUT_WHITE, 3, CANON_LOURD, "canon lourd central")
{
	this->addz_deplacements_lateraux(ZONE_HAUT_RED);
	this->addz_deplacements_lateraux(ZONE_HAUT_BLUE);
	z_bouclier_dispo = 1;
    z_max_size_bouclier = 3;
}

zone_haut_white::~zone_haut_white() {}

/* ------------------------- ACTION ATTACK -------------------------*/
bool zone_haut_white::actionA()
{
	const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour().begin(), this->getz_actions_used_ce_tour().end(), ACT_A);
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_A);

    if (action_ce_tour == this->getz_actions_used_ce_tour().end() && action_possible != this->getz_actions().end())
	{
		if (zone_bas->getz_energie_dispo())
		{
			wr("[ATTACK avec le " + this->getz_nom_canon() + " !]");
			zone_bas->setz_energie_dispo(zone_bas->getz_energie_dispo() - 1);
			std::cout << "[Carburant disponible : " << zone_bas->getz_energie_dispo() << "]\n";
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
bool zone_haut_white::actionAHeros()
{
	const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour().begin(), this->getz_actions_used_ce_tour().end(), ACT_A);
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_A);

    if (action_ce_tour == this->getz_actions_used_ce_tour().end() && action_possible != this->getz_actions().end())
	{
		if (zone_bas->getz_energie_dispo())
		{
			wr("[HERO MODE - ATTACK avec le " + this->getz_nom_canon() + " !]");
			zone_bas->setz_energie_dispo(zone_bas->getz_energie_dispo() - 1);
			std::cout << "[Carburant disponible : " << zone_bas->getz_energie_dispo() << "]\n";
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
void zone_haut_white::actionB()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_B);

	if (action_possible != this->getz_actions().end())
	{
		if (zone_bas->getz_energie_dispo())
		{
			wr("[Recuperation de l'energie du reacteur central pour alimenter le bouclier central]");
			while (zone_bas->getz_energie_dispo() || z_bouclier_dispo < z_max_size_bouclier)
			{
				zone_bas->setz_energie_dispo(zone_bas->getz_energie_dispo() - 1);
				z_bouclier_dispo++;
			}
			std::cout << "[Energie disponible dans le bouclier central : " << z_bouclier_dispo << "]\n";
			std::cout << "[Energie disponible dans le reacteur central : " << zone_bas->getz_energie_dispo() << "]\n";
		}
		else
		{
			wr("[Tentative de recuperation de l'energie du reacteur central pour alimenter le bouclier.. Echec... c'est la merde, et en plus ton tour sert a rien...]");
		}
	}
	else
	{
		wr("[Tentative de rechargement du bouclier central... Vous ne pouvez pas.");
	}
}

/* ------------------------- ACTION ENERGIE -------------------------*/
void zone_haut_white::actionBHeros()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_B);

	if (action_possible != this->getz_actions().end())
	{
		if (zone_bas->getz_energie_dispo())
		{
			wr("[HERO MODE - Recuperation de l'energie du reacteur central pour alimenter le bouclier central]");
			while (zone_bas->getz_energie_dispo() || z_bouclier_dispo < z_max_size_bouclier + 1)
			{
				zone_bas->setz_energie_dispo(zone_bas->getz_energie_dispo() - 1);
				z_bouclier_dispo++;
			}
			std::cout << "[Energie disponible dans le bouclier central : " << z_bouclier_dispo << "]\n";
			std::cout << "[Energie disponible dans le reacteur central : " << zone_bas->getz_energie_dispo() << "]\n";
		}
		else
		{
			wr("[HERO MODE - Tentative de recuperation de l'energie du reacteur central pour alimenter le reacteur.. Echec... c'est la merde, et en plus ton tour sert a rien...]");
		}
	}
	else
	{
		wr("[HERO MODE - Tentative de rechargement du reacteur central... Vous ne pouvez pas.");
	}
}

/* ------------------------- ACTION MAINTENANCE -------------------------*/
void zone_haut_white::actionC()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_C);
	const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour().begin(), this->getz_actions_used_ce_tour().end(), ACT_C);

    if (action_ce_tour == this->getz_actions_used_ce_tour().end() && action_possible != this->getz_actions().end())
	{
		z_maintenance_ordinateur.push_back(this->gettemps());
		wr("[Bravo! Vous avez fait la maintenance! (elle genere toujours autant d'enthousiasme celle la)]");
		this->addz_actions_used_ce_tour(ACT_C);
	}
	else if (action_possible == this->getz_actions_used_ce_tour().end())
		wr("[Impossible de faire la maintenance maintenant!]");
	else
		wr("[Vous etes deux a faire la maintenance.......]");
}

/* ------------------------- ACTION ASCENSEUR -------------------------*/
bool zone_haut_white::ascenseur()
{
	if (this->getz_ascenseur())
	{
		wr("[Vous pprenez l'ascenseur pour descendre d'un etage.]");
		this->setz_ascenseur(false);
		this->getz_joueur(this->getz_joueur_playing())->setj_zone(ZONE_BAS_WHITE);
		return (true);
	}
	else
	{
		wr("[Vous ne pouvez pas prendre l'ascenseur....]");
		return (false);
	}
}

void zone_haut_white::setzone_bas(zone* zone)
{
    zone_bas_white* zone_bas = dynamic_cast<zone_bas_white*>(zone);
    if (zone_bas)
    {
        this->zone_bas = zone_bas;
    }
    else
    {
        // gestion d'erreur si le cast échoue
        std::cerr << "Erreur : setzone_bas - zone invalide" << std::endl;
    }
}

zone* zone_haut_white::getzone_bas() const
{
	return (zone_bas);
}

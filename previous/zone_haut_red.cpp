#include "zone_haut_red.hpp"

zone_haut_red::zone_haut_red(): zone(ZONE_HAUT_RED, 4, CANON_LOURD, "canon lourd gauche")
{
	this->addz_deplacements_lateraux(ZONE_HAUT_WHITE);
	z_bouclier_dispo = 1;
    z_max_size_bouclier = 2;
}

/* ------------------------- ACTION ATTACK -------------------------*/
bool zone_haut_red::actionA()
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
bool zone_haut_red::actionAHeros()
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
void zone_haut_red::actionB()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_B);

	if (action_possible != this->getz_actions().end())
	{
		if (zone_bas->getz_energie_dispo())
		{
			wr("[Recuperation de l'energie du reacteur gauche pour alimenter le bouclier gauche]");
			while (zone_bas->getz_energie_dispo() || z_bouclier_dispo < z_max_size_bouclier)
			{
				zone_bas->setz_energie_dispo(zone_bas->getz_energie_dispo() - 1);
				z_bouclier_dispo++;
			}
			std::cout << "[Energie disponible dans le bouclier gauche : " << z_bouclier_dispo << "]\n";
			std::cout << "[Energie disponible dans le reacteur gauche : " << zone_bas->getz_energie_dispo() << "]\n";
		}
		else
		{
			wr("[Tentative de recuperation de l'energie du reacteur gauche pour alimenter le bouclier.. Echec... c'est la merde, et en plus ton tour sert a rien...]");
		}
	}
	else
	{
		wr("[Tentative de rechargement du bouclier gauche... Vous ne pouvez pas.");
	}
}

/* ------------------------- ACTION ENERGIE -------------------------*/
void zone_haut_red::actionBHeros()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_B);

	if (action_possible != this->getz_actions().end())
	{
		if (zone_bas->getz_energie_dispo())
		{
			wr("[HERO MODE - Recuperation de l'energie du reacteur gauche pour alimenter le bouclier gauche]");
			while (zone_bas->getz_energie_dispo() || z_bouclier_dispo < z_max_size_bouclier + 1)
			{
				zone_bas->setz_energie_dispo(zone_bas->getz_energie_dispo() - 1);
				z_bouclier_dispo++;
			}
			std::cout << "[Energie disponible dans le bouclier gauche : " << z_bouclier_dispo << "]\n";
			std::cout << "[Energie disponible dans le reacteur gauche : " << zone_bas->getz_energie_dispo() << "]\n";
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

/* ------------------------- ACTION VAISSEAU -------------------------*///on rentre la dedans que si le joueur a les vaisseaux.
void zone_haut_red::actionC()
{
	const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions().begin(), this->getz_actions().end(), ACT_C);

	if (action_possible != this->getz_actions().end())
	{
		wr("[Vous vous envolez avec les robots dans l'espace!!]");
	}
	else
	{
		wr("[Impossible de prendre les vaisseaux a ce tour, dommage!]");
	}
}

/* ------------------------- ACTION ASCENSEUR -------------------------*/
bool zone_haut_red::ascenseur()
{
	if (this->getz_ascenseur())
	{
		wr("[Vous prrenez l'ascenseur pour descendre d'un etage.]");
		this->setz_ascenseur(false);
		this->getz_joueur(this->getz_joueur_playing())->setj_zone(ZONE_BAS_RED);
		return (true);
	}
	else
	{
		wr("[Vous ne pouvez pas prendre l'ascenseur....]");
		return (false);
	}
}

void zone_haut_red::setzone_bas(zone* zone)
{
    zone_bas_red* zone_bas = dynamic_cast<zone_bas_red*>(zone);
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

zone* zone_haut_red::getzone_bas() const
{
	return (zone_bas);
}

zone_haut_red::~zone_haut_red() {}

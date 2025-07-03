#include "space_alerte.hpp"

void check_maintenance(t_data &data)
{
	std::string msg;
	if (data.tour == 3 || data.tour == 6 || data.tour == 9)
	{
		print_tour("MAINTENANCE TOUR " + std::to_string(data.tour));
		std::vector<int> maintenance = data.zones[ZONE_WHITE]->getz_maintenance_ordinateur();
		for (std::vector<int>::iterator it = maintenance.begin(); it != maintenance.end(); it++)
		{
			if (data.tour == 3 && (*it == 1 || *it == 2 || *it == 3))
			{
				msg = "[Maintenance de l'ordinateur effectuée pour le tour " + std::to_string(data.tour) + ".]\n";
				printSlowly(msg, data);
				return;
			}
			else if (data.tour == 6 && (*it == 4 || *it == 5 || *it == 6))
			{
				msg = "[Maintenance de l'ordinateur effectuée pour le tour " + std::to_string(data.tour) + ".]\n";
				printSlowly(msg, data);
				return;
			}
			else if (data.tour == 9 && (*it == 7 || *it == 8 || *it == 9))
			{
				msg = "[Maintenance de l'ordinateur effectuée pour le tour " + std::to_string(data.tour) + ".]\n";
				printSlowly(msg, data);
				return;
			}
		}
		msg = "[La maintenance de l'ordinateur n'a pas ete effectuée...]\n";
		msg += "[Tous les joueurs voient leurs actions decalees d'un tour.]\n";
		printSlowly(msg, data);
		for (int i = 1; i <= data.nb_joueur; i++)
		{
			if (!data.zones[ZONE_RED]->getz_joueur_intercepteurs())
				data.joueurs[i]->setj_jump_tour(true);
			else if ((data.joueurs[i]->getj_nom() != data.zones[ZONE_RED]->getz_joueur_intercepteurs()->getj_nom()))
				data.joueurs[i]->setj_jump_tour(true);
		}
	}
}

void retarder_joueurs(t_data &data)
{
	for (int i = 1; i <= data.nb_joueur; i++)
	{
		if (data.joueurs[i]->getj_jump_tour())
		{
			data.joueurs[i]->passerTour(data.tour);
			data.joueurs[i]->setj_jump_tour(false);
		}
	}
}

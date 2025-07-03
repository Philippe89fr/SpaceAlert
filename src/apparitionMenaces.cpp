#include "space_alerte.hpp"
#include "menace.hpp"
#include "menace_externe.hpp"
#include "menace_interne.hpp"

void remove_dead_or_outdated_menaces(t_data &data)
{
    int i = 1;
    while (i < 4)
    {
        chemin_menace *chemin = data.zones[i]->getz_chemin_menace();
        std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end();)
        {
            if ((*it)->get_m_position() <= 1 || (*it)->get_m_vie() <= 0)
            {
                chemin->remove_menace(*it); // Suppression de la menace du chemin
                it = tmp.erase(it);
            }
            else
                ++it; // Avance l'itérateur si l'élément n'est pas supprimé
        }
        i++;
    }
    chemin_menace *chemin_interne = data.chemin_menace_interne;
    std::vector<menace_interne*> tmp = data.chemin_menace_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it2 = tmp.begin(); it2 != tmp.end(); ++it2)
	{
		if ((*it2)->get_m_position() <= 1 || (*it2)->get_m_vie() <= 0)
        {
            chemin_interne->remove_menace(*it2); // Suppression de la menace du chemin
        }
	}
}

void revelerMenace(menace_externe* menace)
{
    if (menace->get_m_name().find("Satellite") != std::string::npos && menace->get_m_position() <= 10) // SURCHARGE
        menace->set_m_revele(true);
}


void mouvement_menaces(t_data &data)
{
    int j = 0;
    int i = 1;
    print_title("ACTIONS MENACES");
    while (i < 4)
    {
        std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        {
            if ((*it)->get_m_presence())
            {
                wait();
                start_color((*it)->get_m_zone());
                int positionBefore = (*it)->get_m_position();
                int positionAfter = (*it)->get_m_position() - (*it)->get_m_vitesse();
                std::string msg;
                msg = "[La menace " + (*it)->get_m_name() + " avance de " + std::to_string((*it)->get_m_vitesse()) + " cases et se trouve desormais en position " + std::to_string(positionAfter) + ".]\n";
                printSlowly(msg, data);
                (*it)->checkIfCrossActionZone(positionBefore, positionAfter);
                (*it)->setm_position(positionAfter); // update position
                std::cout << std::endl;
                end_color();
                j = 1;
            }
            if (!(*it)->get_m_revele())
                revelerMenace(*it);
        }
        i++;
    }
    chemin_menace *chemin_interne = data.chemin_menace_interne;
    std::vector<menace_interne*> tmp = chemin_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if ((*it)->get_m_presence())
        {
            wait();
            start_color_interne();
            int positionBefore = (*it)->get_m_position();
            int positionAfter = (*it)->get_m_position() - (*it)->get_m_vitesse();
            std::string msg;
            msg = "[La menace interne " + (*it)->get_m_name() + " avance de " + std::to_string((*it)->get_m_vitesse()) + " cases et se trouve desormais en position " + std::to_string(positionAfter) + ".]\n";
            printSlowly(msg, data);
            (*it)->checkIfCrossActionZone(positionBefore, positionAfter);
            (*it)->setm_position(positionAfter); // update position
            std::cout << std::endl;
            end_color();
            j = 1;
        }
	}
    start_color_titre();
    if (!j)
    {
        std::string msg_mouvement_menace = "[Aucune menace n'est presente a proximite!]\n";
        printSlowly(msg_mouvement_menace, data);
    }
    std::cout << std::endl;
    end_color();

}

void apparitionMenaces(t_data &data)
{
    print_title("APPARITION DES MENACES");
    int i = 1;
    while (i < 4)
    {
        std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        {
            if ((*it)->get_m_tourDarrivee() == data.tour)
            {
                wait();
                start_color((*it)->get_m_zone());
                (*it)->set_m_presence(true);
                (*it)->send_announcement_message();
                end_color();
            }
        }
        i++;
    }
    std::vector<menace_interne*> tmp = data.chemin_menace_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if ((*it)->get_m_tourDarrivee() == data.tour)
        {
            wait();
            start_color_interne();
            (*it)->set_m_presence(true);
            (*it)->send_announcement_message();
            end_color();
        }
	}
}

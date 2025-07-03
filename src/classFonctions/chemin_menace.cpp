#include "chemin_menace.hpp"
#include "menace.hpp"
#include "menace_externe.hpp"
#include "menace_interne.hpp"

chemin_menace::chemin_menace()
{
}

void chemin_menace::add_menaceInt(menace_interne *input)
{
    input->setm_position(get_ch_chemin_size()); // On place la menace a la fin du chemin
    ch_menacesInte.push_back(input);
}

// arrive a la fin du chemin
void chemin_menace::add_menaceExte(menace_externe *input) {
    input->setm_position(get_ch_chemin_size()); // On place la menace a la fin du chemin
    if (input->get_m_position() == 10 && input->get_m_name().find("Satellite") != std::string::npos)
        input->set_m_revele(true);
    ch_menacesExte.push_back(input);
}

menace_externe* chemin_menace::get_menace_that_attracts_rocket()
{
    if (ch_menacesExte.empty()) {
        return nullptr; // Si il n'y a pas de menace, on retourne nullptr
    }
    for (auto it = ch_menacesExte.begin(); it != ch_menacesExte.end(); it++)
    {
        if ((*it)->get_m_presence() == false || (*it)->get_m_revele() == false) // Si la menace n'est pas presente, on passe a la suivante
        {
            continue;
        }
        if ((*it)->get_m_attraction_roquette() && (*it)->get_m_vulnerable_roquette()) // Si la menace est une menace qui attire les roquettes et qu'elle est vulnérable aux roquettes (il y en a qu'une seule, c'est le juggernaut, et peu importe sa position)
        {
            (*it)->set_m_bouclier((*it)->get_m_bouclier() + 1);
            return (*it); // On retourne la menace qui attire les roquettes
        }
        else if ((*it)->get_m_attraction_roquette() && (*it)->get_m_position() <= 10) // Si la menace est une menace qui attire les roquettes mais qu'elle n'est pas vulnérable aux roquettes (il y en a qu'une seule, c'est le juggernaut)
            return (*it); // On retourne la menace qui attire les roquettes
    }
    return (nullptr);
}

menace_externe* chemin_menace::get_closest_menace_rocket_vulnerable()
{
    if (ch_menacesExte.empty()) {
        return nullptr; // Si il n'y a pas de menace, on retourne nullptr
    }
    int positionPlusProche = 0;
    menace_externe *menaceProche = nullptr;
    for (auto it = ch_menacesExte.begin(); it != ch_menacesExte.end(); it++)
    {
        if ((*it)->get_m_presence() == false || !(*it)->get_m_vulnerable_roquette() || (*it)->get_m_revele() == false) // Si la menace n'est pas presente, on passe a la suivante
        {
            continue;
        }
        if (positionPlusProche == 0)
        {
            positionPlusProche = (*it)->get_m_position(); // La position la plus prochde de la ou les menaces
            menaceProche = (*it); // La menace la plus proche
        }
        else if ((*it)->get_m_position() < positionPlusProche || ((*it)->get_m_position() == positionPlusProche && (*it)->get_m_tourDarrivee() < menaceProche->get_m_tourDarrivee())) // Si la menace est plus proche que la menace la plus proche
        {
            positionPlusProche = (*it)->get_m_position(); // On change la position de la menace la plus proche
            menaceProche = (*it); // On change la menace la plus proche
        }
    }
    return menaceProche; // On retourne la menace la plus proche
}

std::vector<menace_externe*> chemin_menace::targeted_intercepteur_menace()
{
    std::vector<menace_externe*> menace_incepteur_vulnerable;
    for (auto it = ch_menacesExte.begin(); it != ch_menacesExte.end(); it++)
    {
        if ((*it)->get_m_position() <= 5)
        {
            menace_incepteur_vulnerable.push_back(*it);
        }
    }
    return (menace_incepteur_vulnerable);
}

menace* chemin_menace::get_closest_menace()
{
    if (ch_menacesExte.empty()) {
        return nullptr; // Si il n'y a pas de menace, on retourne nullptr
    }
    int positionPlusProche = 0;
    menace *menaceProche = nullptr;
    for (auto it = ch_menacesExte.begin(); it != ch_menacesExte.end(); it++)
    {
        if ((*it)->get_m_presence() == false || (*it)->get_m_revele() == false) // Si la menace n'est pas presente, on passe a la suivante
        {
            continue;
        }
        if (positionPlusProche == 0)
        {
            positionPlusProche = (*it)->get_m_position(); // La position la plus prochde de la ou les menaces
            menaceProche = (*it); // La menace la plus proche
        }
        else if ((*it)->get_m_position() < positionPlusProche || ((*it)->get_m_position() == positionPlusProche && (*it)->get_m_tourDarrivee() < menaceProche->get_m_tourDarrivee())) // Si la menace est plus proche que la menace la plus proche
        {
            positionPlusProche = (*it)->get_m_position(); // On change la position de la menace la plus proche
            menaceProche = (*it); // On change la menace la plus proche
        }
    }
    return menaceProche; // On retourne la menace la plus proche
}

void chemin_menace::remove_menace(menace *input) {
    for (auto it = ch_menacesExte.begin(); it != ch_menacesExte.end(); ++it) {
        if (*it == input) {
            delete (*it); // Libération de la mémoire
            ch_menacesExte.erase(it); // Suppression de l'élément du vecteur
            return;
        }
    }
    for (auto it = ch_menacesInte.begin(); it != ch_menacesInte.end(); ++it) {
        if (*it == input) {
            delete (*it); // Libération de la mémoire
            ch_menacesInte.erase(it); // Suppression de l'élément du vecteur
            return;
        }
    }
}

chemin_menace::chemin_menace(std::string input)
{
    if(input == "t1")
    {
        ch_nom = "t1";
        ch_chemin_size = 10;
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'R';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'X';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
    if(input == "t2")
    {
        ch_nom = "t2";
        ch_chemin_size = 11;
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'X';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'R';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
    if(input == "t3")
    {
        ch_nom = "t3";
        ch_chemin_size = 12;
        ch_chemin[12] = 'R';
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'X';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'R';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'Y';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
        if(input == "t4")
    {
        ch_nom = "t4";
        ch_chemin_size = 13;
        ch_chemin[13] = 'R';
        ch_chemin[12] = 'R';
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'X';
        ch_chemin[8] = 'R';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'Y';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
        if(input == "t5")
    {
        ch_nom = "t5";
        ch_chemin_size = 14;
        ch_chemin[14] = 'R';
        ch_chemin[13] = 'R';
        ch_chemin[12] = 'R';
        ch_chemin[11] = 'X';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'R';
        ch_chemin[7] = 'Y';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'R';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
        if(input == "t6")
    {
        ch_nom = "t6";
        ch_chemin_size = 15;
        ch_chemin[15] = 'R';
        ch_chemin[14] = 'R';
        ch_chemin[13] = 'X';
        ch_chemin[12] = 'R';
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'X';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'R';
        ch_chemin[7] = 'Y';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'R';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'Y';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
        if(input == "t7")
    {
        ch_nom = "t7";
        ch_chemin_size = 16;
        ch_chemin[16] = 'R';
        ch_chemin[15] = 'R';
        ch_chemin[14] = 'R';
        ch_chemin[13] = 'R';
        ch_chemin[12] = 'X';
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'Y';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'Y';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
}

chemin_menace::~chemin_menace() {}

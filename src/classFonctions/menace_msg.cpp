#include "menace.hpp"
#include "menace_externe.hpp"

// void messageAttaque(std::string nom)
// {
//     std::cout << "\033[1;35m[ACTION MENACE " << nom << "!]\033[0m" << std::endl;
// }

void menace::messageMenaceZone(int degats, zone *zone)
{
    //messageAttaque(m_name);
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    std::string msg = "[La menace " + m_name + " lance une attaque de puissance " + std::to_string(degats + m_buff_attack) + "\n";
    printSlowly(msg, *m_zone->getz_data());
    if (zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    msg = " sur la " + zone->getz_nom_zone() + "!]\n";
    printSlowly(msg, *m_zone->getz_data());
    end_color();
}

void menace::messageAttaqueMenace(int degats)
{
    //messageAttaque(m_name);
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    std::string msg = "[La menace " + m_name + " lance une attaque de puissance " + std::to_string(degats + m_buff_attack) + "\n";
    printSlowly(msg, *m_zone->getz_data());
    end_color();
}

void menace::messageBufferMenace(std::string &string, int degats)
{
    //messageAttaque(m_name);
    std::string msg;
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    if (degats < 0)
        msg = string + "\n";
    else
        msg = string + std::to_string(degats) + "\n";
    printSlowly(msg, *m_zone->getz_data());
    end_color();
}

void menace::messageRecapCapitaine()
{
    std::cout << "\33[1;35m";
    printSlowly("\nCapitaine, la menace " + m_name + " a ete elimine, souhaitez vous un recap ?", *m_zone->getz_data());
    std::string input;
    std::getline(std::cin, input);  // attend que l'utilisateur appuie sur Entrée
    if (input == "Y" || input == "y" || input == "oui" || input == "yes" || input == "OUI" || input == "YES")
        printSlowly(m_degats_totaux_str, *m_zone->getz_data());
    end_color();
    std::cout << std::endl;
}

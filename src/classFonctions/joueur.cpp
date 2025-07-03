#include "joueur.hpp"
#include "SA_Values.hpp"
#include "menace_externe.hpp"
#include "menace_interne.hpp"

joueur::joueur()
{
    j_nom = generateRandomString(5);
	j_state = ACTIF;
    j_bots = NO_BOTS;
    j_zone = ZONE_WHITE;
    j_jump_tour = false;
    j_capitaine = false;
}

joueur::joueur(std::string nom)
{
    j_nom = nom;
	j_state = ACTIF;
    j_jump_tour = false;
    j_bots = NO_BOTS;
    j_zone = ZONE_WHITE;
}
void joueur::print()
{
    std::cout  << "                     ----- JOUEUR ------" << std::endl;
    std::cout << "Je suis " << j_nom << " et je me trouve en ";
    if (j_zone == ZONE_BLUE)
        std::cout << "zone bleue.\n";
    else if (j_zone == ZONE_WHITE)
        std::cout << "zone blanche.\n";
    else if (j_zone == ZONE_RED)
        std::cout << "zone rouge.\n";
    if (j_state == INACTIF)
        std::cout << "Je suis inactif" << std::endl;
    if (j_bots == NO_BOTS)
        std::cout << "Je n'ai pas de robots" << std::endl;
    else if (j_bots == BOTS_EVEILLE)
        std::cout << "J'ai des robots actifs avec moi" << std::endl;
    else if (j_bots == BOTS_INACTIF)
        std::cout << "J'ai des robots inactif avec moi" << std::endl;
}

void joueur::setj_number(int input)
{
    j_number = input;
}

void joueur::setj_data(t_data *input)
{
    j_data = input;
}

t_data *joueur::getj_data() const
{
    return (j_data);
}

int joueur::getj_number() const
{
    return (j_number);
}

void joueur::setj_state(bool input)
{
    j_state = input;
}

void joueur::setj_capitaine(bool input)
{
    j_capitaine = input;
}
void joueur::setj_bots(int input)
{
    j_bots = input;
}

void joueur::setj_zone(int input)
{
    j_zone = input;
}

void joueur::setj_nom(std::string input)
{
    j_nom = input;
}

//autre
void joueur::addcartes(int input, carte carte)
{
    cartes[input] = carte;
}
void joueur::passerTour(int input)
{
    int i = 12;
    while (i > input + 1)
    {
        cartes[i] = cartes[i - 1];
        i--;
    }
    cartes[i].setc_action(INACTIF);
}

void joueur::setcarteInactif(int input)
{
    int i = 12;
    while (i > input + 1)
    {
        cartes[i].setc_action(INACTIF);
        i--;
    }
    cartes[i].setc_action(INACTIF);
}

void joueur::setcarteAssome(int input)
{
    std::string msg = "[" + j_nom + " est assome jusqu'a la fin du voyage...]\n";
    printSlowly(msg, *j_data);
    int i = 12;
    while (i > input + 1)
    {
        cartes[i].setc_action(ASSOME);
        i--;
    }
    cartes[i].setc_action(ASSOME);
}

void joueur::setj_jump_tour(int input)
{
    j_jump_tour = input;
}

int joueur::getj_jump_tour() const
{
    return (j_jump_tour);
}

//getters
bool joueur::getj_state()const
{
    return (j_state);
}

int joueur::getj_bots() const
{
    return (j_bots);
}

bool joueur::getj_capitaine() const
{
    return (j_bots);
}

int joueur::getj_zone() const
{
    return (j_zone);
}

std::string joueur::getj_nom() const
{
    return (j_nom);
}

std::map<int, carte> joueur::getcartes() const
{
    return (cartes);
}

void joueur::attaqueIntercepteur(t_data &data)
{
    menace_interne *menace_fissure = data.zones[ZONE_RED]->is_menace_fissure();
    if (menace_fissure)
    {
        std::string degats_str = "[Les intercepteurs attaquent la menace interne " + menace_fissure->get_m_name() + " .]\n";
        printSlowly(degats_str, *j_data);
        menace_fissure->getDamage(this);
        return ;
    }
    std::vector<menace_externe *> menace_intercepteur_blue = data.zones[ZONE_BLUE]->getz_chemin_menace()->targeted_intercepteur_menace();
    std::vector<menace_externe *> menace_intercepteur_red = data.zones[ZONE_RED]->getz_chemin_menace()->targeted_intercepteur_menace();
    std::vector<menace_externe *> menace_intercepteur_white = data.zones[ZONE_WHITE]->getz_chemin_menace()->targeted_intercepteur_menace();
    std::vector<menace_externe *> menace_intercepteur = menace_intercepteur_blue;
    menace_intercepteur.insert(menace_intercepteur.end(), menace_intercepteur_red.begin(), menace_intercepteur_red.end());
    menace_intercepteur.insert(menace_intercepteur.end(), menace_intercepteur_white.begin(), menace_intercepteur_white.end());
    int nb_menace = menace_intercepteur.size();
    int degats = 3;
    if (nb_menace > 1)
        degats = 1;
    std::string degats_str;
    if (!nb_menace)
    {
        degats_str = "[Les intercepteurs font pas de degats, il n'y a pas de menaces a distance.]\n";
        printSlowly(degats_str, *j_data);
        return ;
    }
    if (degats == 3 && menace_intercepteur[0]->get_m_name() == "Behemoth")
    {
        menace_intercepteur[0]->add_m_degats(9);
		degats_str = "[Les intercepteurs font 9 degat(s) a la menace " + menace_intercepteur[0]->get_m_name() + " .]\n";
	    menace_intercepteur[0]->add_m_degats_str(degats_str);
        degats_str = "[Les intercepteurs attaquent uniquement la menace " + menace_intercepteur[0]->get_m_name() + " qui assome le pilote et desactive ses robots.]\n";
        this->setcarteAssome(data.tour);
        printSlowly(degats_str, *j_data);
        return ;
    }
    std::vector<menace_externe *>::iterator it;
    for (it = menace_intercepteur.begin(); it != menace_intercepteur.end(); it++)
    {
        (*it)->add_m_degats(degats);
		degats_str = "[Les intercepteurs font " + std::to_string(degats) + " degat(s) a la menace " + (*it)->get_m_name() + " .]\n";
	    (*it)->add_m_degats_str(degats_str);
    }
}

void joueur::getcarteTour(int tour)
{
    int i = -1;
    if (cartes[tour].getc_action() == ASSOME || cartes[tour].getc_action() == INACTIF)
    {
        printSlowly("Vous ne pouvez pas jouer ce tour...", *j_data);
        std::string input;
        std::getline(std::cin, input);  // attend que l'utilisateur appuie sur Entrée
    }
    else if (cartes[tour].getc_action() != TODO)
    {
        printSlowly("Votre carte a deja ete joue pour ce tour...", *j_data);
        std::string input;
        std::getline(std::cin, input);  // attend que l'utilisateur appuie sur Entrée
    }
    else
    {
        printSlowly("Quelle carte avez vous joue ce tour ?\n", *j_data);
        std::string input;
        std::getline(std::cin, input);
        i = get_nb_actions(input);
        while (i == -1)
        {
            std::cout << "Je n'ai pas compris...\n";
            std::getline(std::cin, input);  // attend que l'utilisateur appuie sur Entrée
            i = get_nb_actions(input);
        }
        cartes[tour].setc_action(i);
    }
}

void joueur::attaqueIntercepteurHero(t_data &data)
{
    menace_interne *menace_fissure = data.zones[ZONE_RED]->is_menace_fissure();
    if (menace_fissure)
    {
        std::string degats_str = "[Les intercepteurs attaquent la menace interne " + menace_fissure->get_m_name() + " .]\n";
        printSlowly(degats_str, *j_data);
        menace_fissure->getDamageHero(this);
        return ;
    }
    std::vector<menace_externe *> menace_intercepteur_blue = data.zones[ZONE_BLUE]->getz_chemin_menace()->targeted_intercepteur_menace();
    std::vector<menace_externe *> menace_intercepteur_red = data.zones[ZONE_RED]->getz_chemin_menace()->targeted_intercepteur_menace();
    std::vector<menace_externe *> menace_intercepteur_white = data.zones[ZONE_WHITE]->getz_chemin_menace()->targeted_intercepteur_menace();
    std::vector<menace_externe *> menace_intercepteur = menace_intercepteur_blue;
    menace_intercepteur.insert(menace_intercepteur.end(), menace_intercepteur_red.begin(), menace_intercepteur_red.end());
    menace_intercepteur.insert(menace_intercepteur.end(), menace_intercepteur_white.begin(), menace_intercepteur_white.end());
    int nb_menace = menace_intercepteur.size();
    int degats = 4;
    if (nb_menace > 1)
        degats = 2;
    std::string degats_str;
    if (!nb_menace)
    {
        degats_str = "[Les intercepteurs font pas de degats, il n'y a pas de menaces a distance.]\n";
        printSlowly(degats_str, *j_data);
        return ;
    }
    if (degats == 4 && menace_intercepteur[0]->get_m_name() == "Behemoth")
    {
        menace_intercepteur[0]->add_m_degats(10);
		degats_str = "[Les intercepteurs font 10 degat(s) a la menace " + menace_intercepteur[0]->get_m_name() + " .]\n";
	    menace_intercepteur[0]->add_m_degats_str(degats_str);
        degats_str = "[Les intercepteurs attaquent uniquement la menace " + menace_intercepteur[0]->get_m_name() + " qui assome le pilote et desactive ses robots.]\n";
        this->setcarteAssome(data.tour);
        printSlowly(degats_str, *j_data);
        return ;
    }
    std::vector<menace_externe *>::iterator it;
    for (it = menace_intercepteur.begin(); it != menace_intercepteur.end(); it++)
    {
        (*it)->add_m_degats(degats);
		degats_str = "[Les intercepteurs font " + std::to_string(degats) + " degat(s) a la menace " + (*it)->get_m_name() + " .]\n";
	    (*it)->add_m_degats_str(degats_str);
    }
}

joueur::~joueur() {}

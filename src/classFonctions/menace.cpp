#include "menace.hpp"

menace::menace()
{
}

// Surcharge de l'opérateur d'affectation
menace &menace::operator=(const menace &other) {
            if (this != &other) {
                m_name = other.m_name;
                m_tourDarrivee = other.m_tourDarrivee;
                m_presence = other.m_presence;
                m_vitesse = other.m_vitesse;
                m_vie = other.m_vie;
                m_difficulte = other.m_difficulte;
            }
            return *this;
}

menace::menace(std::string input, int tourDarrivee)
{
    input += "";
    m_presence = false;
    m_immunity = false;
    m_tourDarrivee = tourDarrivee;
    m_max_vie = m_vie; // Initialiser la vie maximale à la vie actuelle
    m_buff_attack = 0;
}

void menace::send_announcement_message()
{
    std::string msg = "[Attention, la menace " + m_name + " vient d'arriver et est presente en " + m_zone->getz_nom_zone() + "!]\n";
    msg += "[Difficulté : " + std::to_string(m_difficulte) + ", Vitesse : " + std::to_string(m_vitesse) + ", Vie : " + std::to_string(m_vie) + "]\n\n";
    printSlowly(msg, *m_zone->getz_data());
}

void menace::print_menace() const
{
    start_color(m_zone);
    std::cout << "Menace : " << m_name << std::endl;
    std::cout << "Tour d'arrivée : " << m_tourDarrivee << std::endl;
    std::cout << "Position : " << m_position << std::endl;
    std::cout << "Vitesse : " << m_vitesse << std::endl;
    std::cout << "Vie : " << m_vie << std::endl;
    std::cout << "Difficulté : " << m_difficulte << std::endl;
    // std::cout << "DegatsRecus : " << m_degatsRecus << std::endl;
    std::cout << "Zone : " << m_zone->getz_nom_zone() << std::endl;
    std::cout << "Chemin : " << m_chemin->get_ch_nom() << std::endl;
    std::cout << "Buff Attack : " << m_buff_attack << std::endl;
    end_color();
}

void menace::actionMenace(char input)
{
    input += 0;
}

void menace::actionQuandDetruit() {
    std::cout << "\033[1;32m[ELIMINATION DE LA MENACE !]\033[0m\n";
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    std::string msg = "[La menace " + m_name + " en " + m_zone->getz_nom_zone() + " a été détruite.]\033[0m\n";
    printSlowly(msg, *m_zone->getz_data());
    messageRecapCapitaine();
}

void menace::checkIfCrossActionZone(int positionBefore, int positionAfter)
{
    int i = 0;
    while(positionBefore != positionAfter)
    {
        positionBefore--;
        if(m_chemin->get_ch_chemin()[positionBefore] == 'X')
        {
            std::string msg;
            msg = "[La menace " + m_name + " effectue son action X.]\n";
            printSlowly(msg, *m_zone->getz_data());
            actionMenace('X');
            i = 1;
        }
        else if (m_chemin->get_ch_chemin()[positionBefore] == 'Y')
        {
            std::string msg;
            msg = "[La menace " + m_name + " effectue son action Y.]\n";
            printSlowly(msg, *m_zone->getz_data());
            actionMenace('Y');
            i = 1;
        }
        else if (m_chemin->get_ch_chemin()[positionBefore] == 'Z')
        {
            std::string msg;
            msg = "[La menace " + m_name + " effectue son action Z.]\n";
            printSlowly(msg, *m_zone->getz_data());
            actionMenace('Z');
            i = 1;
        }
    }
    if (!i)
    {
        std::string msg;
        msg = "[Elle n'effectue pas d'action ce tour.]\n";
        printSlowly(msg, *m_zone->getz_data());
    }
}


menace::~menace() {}


/// Action des menaces

// draine l'energie du bouclier de toutes les zones
void menace::draineEnergieBouclier(int input)
{
    m_zone->setz_bouclier(m_zone->getz_bouclier() - input);
    if (m_zone->getz_bouclier() < 0) {
        m_zone->setz_bouclier(0);
    }
    m_zone->getzone_left()->setz_bouclier(m_zone->getzone_left()->getz_bouclier() - input);
    if (m_zone->getzone_left()->getz_bouclier() < 0) {
        m_zone->getzone_left()->setz_bouclier(0);
    }
    m_zone->getzone_right()->setz_bouclier(m_zone->getzone_right()->getz_bouclier() - input);
    if (m_zone->getzone_right()->getz_bouclier() < 0) {
        m_zone->getzone_right()->setz_bouclier(0);
    }
    if( m_zone->getz_bouclier() == 0 && m_zone->getzone_left()->getz_bouclier() == 0 && m_zone->getzone_right()->getz_bouclier() == 0) {
        std::string msg = "[Toutes les zones ont perdu leur bouclier !]\n";
        printSlowly(msg, *m_zone->getz_data());
    } else {
        std::string msg =  "[Le bouclier de la zone " + m_zone->getz_nom_zone() + " est maintenant de " + std::to_string(m_zone->getz_bouclier()) + ".]\n";
        printSlowly(msg, *m_zone->getz_data());
        msg = "[Le bouclier de la zone " + m_zone->getzone_left()->getz_nom_zone() + " est maintenant de " + std::to_string(m_zone->getzone_left()->getz_bouclier()) + ".]\n";
        printSlowly(msg, *m_zone->getz_data());
        msg = "[Le bouclier de la zone " + m_zone->getzone_right()->getz_nom_zone() + " est maintenant de " + std::to_string(m_zone->getzone_right()->getz_bouclier()) + ".]\n";
        printSlowly(msg, *m_zone->getz_data());
    }
};

void menace::makedegatsInZone(int input)
{
    m_zone->getdegats(input + m_buff_attack);
}

void menace::makedegatsInZoneIgnoreBouclier(int input)
{
    m_zone->getdegatsIgnoreBouclier(input);//on ne rajoute pas buff_attack car c'est la menace qui fait augmenter ce buffer qui fait cette attaque (ne se buff pas elle meme).
}

void menace::makedegatsLeft(int input)
{
    m_zone->getzone_left()->getdegats(input + m_buff_attack);
}

void menace::makedegatsRight(int input)
{
    m_zone->getzone_right()->getdegats(input + m_buff_attack);
}

void menace::regeneration(int input)
{
    m_vie += input;
    if (m_vie > m_max_vie) {
        m_vie = m_max_vie; // Ne pas dépasser la vie maximale
    }
    std::string msg = "[La menace " + m_name + " se régénère de " + std::to_string(input) + " points de vie. Vie actuelle : " + std::to_string(m_vie) + "!]";
    messageBufferMenace(msg, -1);
}

// combien de X, Y, Z ont été jusqu'à présent traversés par la menace
int menace::checkNombreInputCrossed(char input) const
{
    int count = 0;
    for (int i = m_chemin->get_ch_chemin_size(); i >= m_position; i--) {
        if (m_chemin->get_ch_chemin()[i] == input) {
            count++;
        }
    }
    return count;
}

// enleve les PV correspondant au degats (apres bouclier)
void menace::recoitDegats(int input)
{
    if (m_vie == 0)
    {
        start_color(m_zone);
        std::string msg = "[La menace " + m_name + " est deja detruite.]\n";
        printSlowly(msg, *m_zone->getz_data());
        end_color();
        return ;
    }
    m_vie -= input;
    if (m_vie < 0) {
        m_vie = 0;
    }
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    printSlowly("[La menace " + m_name + " a reçu " + std::to_string(input) + " points de dégâts. Vie restante : " + std::to_string(m_vie) + "]\033[0m\n", *m_zone->getz_data());
    if (m_vie == 0) {
        actionQuandDetruit();
        // m_presence = false; // la presence n'est pas enleve car elle doit tjs etre cible si c est la plus proche
    }
}



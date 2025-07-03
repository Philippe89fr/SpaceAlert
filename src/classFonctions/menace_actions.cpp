#include "menace.hpp"
#include "menace_externe.hpp"

//Actions des menaces externes serieuses


void menace_se1_01::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Y') {
        messageAttaqueMenace(3);
        makedegatsInZone(3);
    } else if (input == 'Z') {
        messageAttaqueMenace(4);
        makedegatsInZone(4);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_02::actionMenace(char input)
{
    if (input == 'X') {
        std::string msg = "[La menace " + m_name + " augmente sa vitesse de 1!]";
        messageAttaqueMenace(1);
        messageBufferMenace(msg, -1);
        makedegatsInZone(1);
        m_vitesse++;
    } else if (input == 'Y') {
        std::string msg = "[La menace " + m_name + " augmente son blindage de 1!]";
        messageAttaqueMenace(3);
        messageBufferMenace(msg, -1);
        makedegatsInZone(3);
        m_bouclier++;
    } else if (input == 'Z') {
        messageAttaqueMenace(5);
        makedegatsInZone(5);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_03::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Y') {
        messageAttaqueMenace(2);
        regeneration(2);
        makedegatsInZone(2);
    } else if (input == 'Z') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_03::actionQuandDetruit()
{
    std::vector<menace_externe *> menaces = m_zone->getzone_left()->getz_chemin_menace()->get_menacesExte();
    std::string msg = "\033[1;32m[ELIMINATION DE LA MENACE !]\033[0m\n";
    printSlowly(msg, *m_zone->getz_data());
    msg = "[La menace " + m_name + " a été détruite. Elle inflige 1 point de dégâts aux menaces presentes.]";
    messageBufferMenace(msg, -1);
    std::vector<menace_externe *>::iterator it;
    for (it = menaces.begin(); it != menaces.end(); ++it)
    {
        if ((*it) != this)
        {
            (*it)->recoitDegats(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0)
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }
    menaces = m_zone->getzone_right()->getz_chemin_menace()->get_menacesExte();
    for (it = menaces.begin(); it != menaces.end(); ++it)
    {
        if ((*it) != this)
        {
            (*it)->recoitDegats(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0)
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }
    menaces = m_zone->getz_chemin_menace()->get_menacesExte();
    for (it = menaces.begin(); it != menaces.end(); ++it)
    {
        if ((*it) != this)
        {
            (*it)->recoitDegats(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0)
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }
}

void menace_se1_04::actionMenace(char input)
{
    if (input == 'X') {
        messageMenaceZone(1, m_zone);
        makedegatsInZone(1);
        messageMenaceZone(1, m_zone->getzone_left());
        makedegatsLeft(1);
        messageMenaceZone(1, m_zone->getzone_right());
        makedegatsRight(1);
    } else if (input == 'Y') {
        messageMenaceZone(2, m_zone);
        makedegatsInZone(2);
        messageMenaceZone(2, m_zone->getzone_left());
        makedegatsLeft(2);
        messageMenaceZone(2, m_zone->getzone_right());
        makedegatsRight(2);
    } else if (input == 'Z') {
        messageMenaceZone(3, m_zone);
        makedegatsInZone(3);
        messageMenaceZone(3, m_zone->getzone_left());
        makedegatsLeft(3);
        messageMenaceZone(3, m_zone->getzone_right());
        makedegatsRight(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

bool menace_se1_04::vulnerability_check(cannon* input)
{
    input->getcanon_used(); // pour pas avoir de prob de compilation
    if (m_revele)
        return (true);
    return (false);
}

void menace_se1_05::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Y') {
        messageAttaqueMenace(3);
        makedegatsInZone(3);
    } else if (input == 'Z') {
        messageAttaqueMenace(4);
        makedegatsInZone(4);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_05::effetDebutTour()
{
    if(!m_immunity)
    {
        m_immunity2 = false;
    }
}

void menace_se1_05::recoitDegats(int input)
{
    if (m_immunity || m_immunity2)
    {
        m_immunity = false;
        std::string msg = "[La menace " + m_name + " ne prend pas de degat lorsqu'elle est touchee pour la premiere fois.]";
        messageBufferMenace(msg, -1);
    }
    else if (!m_immunity2)
        menace::recoitDegats(input);
}

void menace_se1_06::actionMenace(char input)
{
    if (input == 'X') {
        if (m_vie < m_max_vie)
        {
            messageMenaceZone(1, m_zone);
            makedegatsInZone(1);
            messageMenaceZone(1, m_zone->getzone_left());
            makedegatsLeft(1);
            messageMenaceZone(1, m_zone->getzone_right());
            makedegatsRight(1);
        }
        else
        {
            std::string msg = "[La menace " + m_name + " n'a pas perdu de vie, elle ne fait donc aucune attaque!]";
            messageBufferMenace(msg, -1);
        }
    } else if (input == 'Y') {
        if (m_vie < m_max_vie)
        {
            messageMenaceZone(2, m_zone);
            makedegatsInZone(2);
            messageMenaceZone(2, m_zone->getzone_left());
            makedegatsLeft(2);
            messageMenaceZone(2, m_zone->getzone_right());
            makedegatsRight(2);
        }
        else
        {
            std::string msg = "[La menace " + m_name + " n'a pas perdu de vie, elle ne fait donc aucune attaque!]";
            messageBufferMenace(msg, -1);
        }
    } else if (input == 'Z') {
        messageAttaqueMenace(m_vie * 2);
        makedegatsInZone(m_vie * 2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}


void menace_se1_08::actionMenace(char input)
{
    if (input == 'Z') {
        int degats = get_m_vie();
        messageAttaqueMenace(degats);
        makedegatsInZone(degats);
    }
    else if (input != 'X' && input != 'Y') {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_08::actionQuandDetruit()
{
    std::string msg = "\033[1;32m[ELIMINATION DE LA MENACE !]\033[0m\n";
    printSlowly(msg, *m_zone->getz_data());
    int itemCrossed = (checkNombreInputCrossed('X') + checkNombreInputCrossed('Y')) * 2; // Dégâts infligés en fonction des actions croisées
    msg = "[La menace " + m_name + " a été détruite. Elle inflige " + std::to_string(itemCrossed) + " points de dégâts!]";
    messageBufferMenace(msg, -1);
    makedegatsInZone(itemCrossed);
    messageRecapCapitaine();
}



void menace_se1_07::actionMenace(char input)
{
    if (input == 'X') {
        std::string msg = "[La menace " + m_name + " draine toutes l'energie de chaque bouclier!]";
        messageBufferMenace(msg, -1);
        draineEnergieBouclier(200);
    } else if (input == 'Y') {
        messageMenaceZone(2, m_zone->getzone_left());
        makedegatsLeft(2);
        messageMenaceZone(2, m_zone->getzone_right());
        makedegatsRight(2);
    } else if (input == 'Z') {
        messageMenaceZone(3, m_zone->getzone_left());
        makedegatsLeft(3);
        messageMenaceZone(3, m_zone->getzone_right());
        makedegatsRight(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}


//Actions des menaces externes serieuses avancees

void menace_se2_01::actionMenace(char input)
{
    if (input == 'X') {
        if (m_vie > m_max_vie - 2)
        {
            messageAttaqueMenace(2);
            makedegatsInZone(2);
        }
        else {
            std::string msg = "[La menace " + m_name + " a subit 2 degats ou plus, elle ne fait donc rien!]";
            messageBufferMenace(msg, -1);
        }
    } else if (input == 'Y') {
        if (m_vie > m_max_vie - 3)
        {
            messageAttaqueMenace(3);
            makedegatsInZone(3);
        }
        else {
            std::string msg = "[La menace " + m_name + " a subit 3 degats ou plus, elle ne fait donc rien!]";
            messageBufferMenace(msg, -1);
        }
    } else if (input == 'Z') {
        if (m_vie > m_max_vie - 6)
        {
            messageAttaqueMenace(6);
            makedegatsInZone(6);
        }
        else {
            std::string msg = "[La menace " + m_name + " a subit 6 degats ou plus, elle ne fait donc rien!]";
            messageBufferMenace(msg, -1);
        }
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se2_02::actionMenace(char input)
{
    if (input == 'X') {
        std::string msg = "[La menace " + m_name + " augmente sa vitesse de 2!]";
        messageAttaqueMenace(2);
        messageBufferMenace(msg, -1);
        makedegatsInZone(2);
        m_vitesse += 2;
    } else if (input == 'Y') {
        std::string msg = "[La menace " + m_name + " augmente sa vitesse de 2!]";
        messageAttaqueMenace(3);
        messageBufferMenace(msg, -1);
        makedegatsInZone(3);
        m_vitesse += 2;
    } else if (input == 'Z') {
        messageAttaqueMenace(7);
        makedegatsInZone(7);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se2_03::actionMenace(char input)
{
    if (input == 'X') {
        std::string msg = "[La menace " + m_name + " attaque et retarde tous les joueurs de la " + m_zone->getz_nom_zone();
        messageBufferMenace(msg, -1);
        m_zone->retarderactionZone();
    } else if (input == 'Y') {
        m_zone->retarderactionZone();
        m_zone->getzone_right()->retarderactionZone();
        m_zone->getzone_left()->retarderactionZone();
        std::string msg = "[La menace " + m_name + " attaque et retarde tous les joueurs du vaisseau";
        messageBufferMenace(msg, -1);
    } else if (input == 'Z') {
        m_zone->assomerjoueursZone();
        m_zone->getzone_right()->assomerjoueursZone();
        m_zone->getzone_left()->assomerjoueursZone();
        std::string msg = "[La menace " + m_name + " attaque et assome tous les joueurs du vaisseau";
        messageBufferMenace(msg, -1);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

bool menace_se2_03::vulnerability_check(cannon* input)
{
    input->getcanon_used(); // pour pas avoir de prob de compilation
    if (m_revele)
        return (true);
    return (false);
}

void menace_se2_04::actionMenace(char input)
{
    std::string msg;
    if (input == 'X') {
        msg = "[La menace " + m_name + " augmente son blindage a 4!]";
        messageBufferMenace(msg, -1);
        m_bouclier = 4;
    } else if (input == 'Y') {
        m_bouclier = 2;
        msg = "[La menace " + m_name + " diminue son blindage a 2!]";
        messageBufferMenace(msg, -1);
        m_vitesse += 2;
        msg = "[La menace " + m_name + " augmente sa vitesse de 2!]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Z') {
        messageMenaceZone(5, m_zone->getzone_red());
        messageMenaceZone(5, m_zone->getzone_blue());
        if (m_zone->getz_zone() == ZONE_WHITE)
        {
            makedegatsLeft(5);
            makedegatsRight(5);
        }
        else if (m_zone->getz_zone() == ZONE_BLUE)
        {
            makedegatsInZone(5);
            makedegatsRight(5);
        }
        else
        {
            makedegatsInZone(5);
            makedegatsLeft(5);
        }
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se2_05::recoitDegats(int input)
{
    menace::recoitDegats(input);
    if (m_degats != 0 && m_vie > 0)
    {
        messageMenaceZone(1, m_zone);
        makedegatsInZone(1);
        messageMenaceZone(1, m_zone->getzone_left());
        makedegatsLeft(1);
        messageMenaceZone(1, m_zone->getzone_right());
        makedegatsRight(1);
    }
}

void menace_se2_05::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(1);
        makedegatsInZone(1);
        std::string msg = "[La menace " + m_name + " s'inflige 1 point de dégâts!]";
        messageBufferMenace(msg, -1);
        menace::recoitDegats(1);
    } else if (input == 'Y') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
        std::string msg = "[La menace " + m_name + " s'inflige 2 point de dégâts!]";
        messageBufferMenace(msg, -1);
        menace::recoitDegats(2);
    } else if (input == 'Z') {
        std::string msg = "[GAME OVER: " + m_name + " vient de detruire le vaisseau!//////!!!!\\\\\\\\\\\\]\n";
        mission_failed(msg, *m_zone->getz_data());
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}



void menace_se2_06::actionMenace(char input)
{
    if (input == 'Z') {
        int degats = get_m_vie();
        messageAttaqueMenace(degats);
        makedegatsInZone(degats);
    }
    else if (input != 'X' && input != 'Y') {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se2_06::actionQuandDetruit()
{
    std::string msg = "\033[1;32m[ELIMINATION DE LA MENACE !]\033[0m\n";
    printSlowly(msg, *m_zone->getz_data());
    int itemCrossed = (checkNombreInputCrossed('X') + checkNombreInputCrossed('Y')) * 3; // Dégâts infligés en fonction des actions croisées
    msg = "[La menace " + m_name + " a été détruite. Elle inflige " + std::to_string(itemCrossed) + " points de dégâts!]";
    messageBufferMenace(msg, -1);
    makedegatsInZone(itemCrossed);
    messageRecapCapitaine();
}



//Actions des menaces externes communes

void menace_e1_01::actionMenace(char input)
{
    if (input == 'X') {
        messageMenaceZone(1, m_zone);
        makedegatsInZone(1);
        messageMenaceZone(1, m_zone->getzone_left());
        makedegatsLeft(1);
        messageMenaceZone(1, m_zone->getzone_right());
        makedegatsRight(1);
    } else if (input == 'Y') {
        messageMenaceZone(1, m_zone);
        makedegatsInZone(1);
        messageMenaceZone(1, m_zone->getzone_left());
        makedegatsLeft(1);
        messageMenaceZone(1, m_zone->getzone_right());
        makedegatsRight(1);
    } else if (input == 'Z') {
        messageMenaceZone(2, m_zone);
        makedegatsInZone(2);
        messageMenaceZone(2, m_zone->getzone_left());
        makedegatsLeft(2);
        messageMenaceZone(2, m_zone->getzone_right());
        makedegatsRight(2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_02::actionMenace(char input)
{
    if (input == 'X') {
        if (m_zone->getz_bouclier() == 0) {
            std::string msg = "[La menace " + m_name + " lance une attaque de puissance 1 (pas de bouclier, attaque x2)!]";
            messageBufferMenace(msg, -1);
            makedegatsInZone(2);
        }
        else {
            messageAttaqueMenace(1);
            makedegatsInZone(1);
        }
    }
    else if (input == 'Y') {
        messageAttaqueMenace(2);
        if (m_zone->getz_bouclier() == 1) {
            std::string msg = "[Le bouclier part un degat, l'autre degat est multiplie par deux!]";
            messageBufferMenace(msg, -1);
            makedegatsInZone(3);
        }
        else if (m_zone->getz_bouclier() == 0) {
            std::string msg = "[Il n'y a pas de bouclier, les degats sont multiplies par deux!]";
            messageBufferMenace(msg, -1);
            makedegatsInZone(4);
        }
        else {
            makedegatsInZone(2);
        }
    }
    else if (input == 'Z') {
        messageAttaqueMenace(2);
        if (m_zone->getz_bouclier() == 1) {
            std::string msg = "[Le bouclier part un degat, l'autre degat est multiplie par deux!]";
            messageBufferMenace(msg, -1);
            makedegatsInZone(3);
        }
        else if (m_zone->getz_bouclier() == 0) {
            std::string msg = "[Il n'y a pas de bouclier, les degats sont multiplies par deux!]";
            messageBufferMenace(msg, -1);
            makedegatsInZone(4);
        }
        else {
            makedegatsInZone(2);
        }
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_09::actionMenace(char input)
{
    if (input == 'X') {
        regeneration(2);
        std::string msg = "[La menace " + m_name + " regagne 2 points de vie!]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Y') {
        regeneration(2);
        std::string msg = "[La menace " + m_name + " regagne 2 points de vie!]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Z') {
        messageAttaqueMenace(5);
        makedegatsInZone(5);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_03::actionMenace(char input)
{
    if (input == 'X') {
        set_m_revele(true);
        std::string msg = "[La menace " + m_name + " se revele.]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Y') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Z') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_04::actionMenace(char input)
{
    if (input == 'X') {
        std::string msg = "[La menace " + m_name + " draine toutes l'energie de chaque bouclier!]";
        messageBufferMenace(msg, -1);
        draineEnergieBouclier(200);
    } else if (input == 'Y') {
        messageMenaceZone(1, m_zone->getzone_left());
        messageMenaceZone(1, m_zone->getzone_right());
        makedegatsLeft(1);
        makedegatsRight(1);
    } else if (input == 'Z') {
        messageMenaceZone(2, m_zone->getzone_left());
        messageMenaceZone(2, m_zone->getzone_right());
        makedegatsLeft(2);
        makedegatsRight(2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_05::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Y') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Z') {
        messageAttaqueMenace(3);
        makedegatsInZone(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_06::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(1);
        makedegatsInZone(1);
    } else if (input == 'Y') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Z') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_06::recoitDegats(int input)
{
    if (m_immunity)
    {
        m_immunity = false;
        std::string msg = "[La menace " + m_name + " ne prend pas de degat lorsqu'elle est touchee pour la premiere fois.]";
        messageBufferMenace(msg, -1);
    }
    else
        menace::recoitDegats(input);
}

void menace_e1_07::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(1);
        makedegatsInZone(1);
    } else if (input == 'Y') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Z') {
        messageAttaqueMenace(3);
        makedegatsInZone(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_08::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(1);
        makedegatsInZone(1);
    }
    else if (input == 'Y') {
        regeneration(1);
        std::string msg = "[La menace " + m_name + " regagne 1 points de vie!]";
        messageBufferMenace(msg, -1);
    }
    else if (input == 'Z') {
        messageAttaqueMenace(4);
        makedegatsInZone(4);
    }
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_10::actionMenace(char input)
{
    if (input == 'X') {

    } else if (input == 'Y') {

    } else if (input == 'Z') {
        messageAttaqueMenace(m_vie);
        makedegatsInZone(m_vie);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

//Actions des menaces externes communes avancees

void menace_e2_01::actionMenace(char input)
{
    std::string msg;
    if (input == 'X') {
        m_bouclier = 1;
        msg = "[La menace " + m_name + " set son blindage a 1!]";
        messageBufferMenace(msg, -1);
        m_vitesse += 1;
        msg = "[La menace " + m_name + " augmente sa vitesse de 1!]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Y') {
        m_bouclier = 0;
        msg = "[La menace " + m_name + " set son blindage a 0!]";
        messageBufferMenace(msg, -1);
        m_vitesse += 1;
        msg = "[La menace " + m_name + " augmente sa vitesse de 1!]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Z') {
        messageAttaqueMenace(6);
        makedegatsInZone(6);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e2_02::augmenteAttackInZone(zone *zone)
{
    std::vector<menace_externe*> tmp = zone->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        if ((*it)->get_m_presence())
        {
            (*it)->increase_m_buff_attack(1); // update position
        }
    }
}


void menace_e2_02::effetDebutTour()
{
    if(m_effetDebutTourOn)
    {
        std::string msg = "[BUFFER : " + m_name + " augmente la puissance d'attaque de toutes le autres menace ! (attaque +1)]\n";
        printSlowly(msg, *m_zone->getz_data());
        augmenteAttackInZone(m_zone);
        augmenteAttackInZone(m_zone->getzone_left());
        augmenteAttackInZone(m_zone->getzone_right());
    }
}

void menace_e2_02::menaceAvanceUneCaseInZone(zone *zone)
{
    std::vector<menace_externe*> tmp = zone->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        if ((*it)->get_m_presence())
        {
            int positionBefore = (*it)->get_m_position();
            int positionAfter = (*it)->get_m_position() - 1;
            (*it)->checkIfCrossActionZone(positionBefore, positionAfter);
            (*it)->setm_position(positionAfter); // update position
        }
        if (!(*it)->get_m_revele())
            revelerMenace(*it);
    }
}

void menace_e2_02::actionMenace(char input)
{
    if (input == 'X') {
        m_effetDebutTourOn = true;
        std::string msg = "[La menace " + m_name + " active son effet, les autres menaces externes ont +1 dattaque tant qu il est pas mort!]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Y') {
        menaceAvanceUneCaseInZone(m_zone);
        menaceAvanceUneCaseInZone(m_zone->getzone_left());
        menaceAvanceUneCaseInZone(m_zone->getzone_right());
        std::string msg = "[La menace " + m_name + " fait avancer toutes les menaces de un!]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " lance une attaque de puissance 3 qui ignore le bouclier!]";
        messageBufferMenace(msg, -1);
        makedegatsInZoneIgnoreBouclier(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

bool menace_e2_02::vulnerability_check(cannon* input)
{
    if (input->gettype_cannon() == m_imunity_canon)
        return (false);
    return (true);
}

void menace_e2_02::actionQuandDetruit()
{
    std::string msg = "\033[1;32m[ELIMINATION DE LA MENACE !]\033[0m\n";
    printSlowly(msg, *m_zone->getz_data());
    std::vector<menace_externe*> tmp = m_zone->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->setm_buff_attack(0);
    }
    tmp = m_zone->getzone_left()->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->setm_buff_attack(0);
    }
    tmp = m_zone->getzone_right()->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->setm_buff_attack(0);
    }
    msg = "[La menace " + m_name + " a été détruite. Le buffer (+1 attaque) n'est plus!]";
    messageBufferMenace(msg, -1);
    messageRecapCapitaine();
}

void menace_e2_03::actionMenace(char input)
{
    if (input == 'X') {
        set_m_revele(true);
        std::string msg = "[La menace " + m_name + " se revele.]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Y') {
        messageAttaqueMenace(2);
        makedegatsInZone(2);
    } else if (input == 'Z') {
        messageAttaqueMenace(3);
        makedegatsInZone(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e2_04::recoitDegats(int input)
{
    start_color(m_zone);
    if (input > 1)
    {
        std::string msg = "[La menace " + m_name + "ne peut prendre plus de 1 degat par tour.]\n";
        printSlowly(msg, *m_zone->getz_data());
    }
    menace::recoitDegats(1);
}

void menace_e2_04::actionMenace(char input)
{
    if (input == 'X') {
        messageAttaqueMenace(1);
        makedegatsInZone(1);
    } else if (input == 'Y') {
        messageMenaceZone(2, m_zone);
        messageMenaceZone(1, m_zone->getzone_left());
        messageMenaceZone(1, m_zone->getzone_right());
        makedegatsInZone(2);
        makedegatsLeft(1);
        makedegatsRight(1);
    } else if (input == 'Z') {
        messageMenaceZone(3, m_zone);
        messageMenaceZone(2, m_zone->getzone_left());
        messageMenaceZone(2, m_zone->getzone_right());
        makedegatsInZone(3);
        makedegatsLeft(2);
        makedegatsRight(2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e2_05::actionMenace(char input)
{
    if (input == 'X') {
        messageMenaceZone(1, m_zone);
        messageMenaceZone(1, m_zone->getzone_left());
        messageMenaceZone(1, m_zone->getzone_right());
        makedegatsInZone(1);
        makedegatsLeft(1);
        makedegatsRight(1);
        std::string msg = "[La menace " + m_name + " se regenere de la moitie de ses degats ! (" + std::to_string((m_max_vie - m_vie) / 2) + "points de vie recuperes)]";
        messageBufferMenace(msg, -1);
        regeneration((m_max_vie - m_vie) / 2);
    } else if (input == 'Y') {
        messageMenaceZone(1, m_zone);
        messageMenaceZone(1, m_zone->getzone_left());
        messageMenaceZone(1, m_zone->getzone_right());
        makedegatsInZone(1);
        makedegatsLeft(1);
        makedegatsRight(1);
        std::string msg = "[La menace " + m_name + " se regenere de la moitie de ses degats ! (" + std::to_string((m_max_vie - m_vie) / 2) + "points de vie recuperes)]";
        messageBufferMenace(msg, -1);
        regeneration((m_max_vie - m_vie) / 2);
    } else if (input == 'Z') {
        messageMenaceZone(2, m_zone);
        messageMenaceZone(2, m_zone->getzone_left());
        messageMenaceZone(2, m_zone->getzone_right());
        makedegatsInZone(2);
        makedegatsLeft(2);
        makedegatsRight(2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void putBufferToPermanent(zone *zoneactuel)
{
    zone *zone1 = zoneactuel->getzone_right();
    zone *zone2 = zoneactuel->getzone_left();
    std::vector<menace_externe*> tmp = zone1->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->set_m_bouclier((*it)->get_m_bouclier() + 1);
        (*it)->setm_buff_blindage(0);
    }
    tmp = zone2->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->set_m_bouclier((*it)->get_m_bouclier() + 1);
        (*it)->setm_buff_blindage(0);
    }
    tmp = zoneactuel->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->set_m_bouclier((*it)->get_m_bouclier() + 1);
        (*it)->setm_buff_blindage(0);
    }
}

void menace_e2_06::actionMenace(char input)
{
    if (input == 'X') {
        effetDebutTourOn = true;
        std::string msg = "[La menace " + m_name + " lance un buffer qui rajoute +1 de blindage aux autres menaces externes jusau'a sa mort!]";
        messageBufferMenace(msg, -1);
    } else if (input == 'Y') {
        std::string msg = "[La menace " + m_name + " draine 1 energie de chaque bouclier du vaisseau!]";
        messageBufferMenace(msg, -1);
        draineEnergieBouclier(1);
    } else if (input == 'Z') {
        messageAttaqueMenace(4);
        makedegatsInZone(4);
        std::string msg = "[La menace " + m_name + " a rempli sa mission. Les menaces externes ont +1 de blindage de maniere permanente!]";
        messageBufferMenace(msg, -1);
        putBufferToPermanent(m_zone);
        effetDebutTourOn = false;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e2_06::actionQuandDetruit()
{
    std::string msg = "\033[1;32m[ELIMINATION DE LA MENACE !]\033[0m\n";
    printSlowly(msg, *m_zone->getz_data());
    std::vector<menace_externe*> tmp = m_zone->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->set_m_etat_bouclier((*it)->get_m_etat_bouclier() - 1);
    }
    tmp = m_zone->getzone_left()->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->set_m_etat_bouclier((*it)->get_m_etat_bouclier() - 1);
    }
    tmp = m_zone->getzone_right()->getz_chemin_menace()->get_menacesExte();
    for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        (*it)->set_m_etat_bouclier((*it)->get_m_etat_bouclier() - 1);
    }
    msg = "[La menace " + m_name + " a été détruite. Le buffer (+1 blindage) n'est plus!]";
    messageBufferMenace(msg, -1);
    messageRecapCapitaine();
}

void menace_e2_06::effetDebutTour()
{
    if (effetDebutTourOn)
    {
        zone *zone1 = m_zone;
        zone *zone2 = m_zone->getzone_right();
        zone *zone3 = m_zone->getzone_left();
        std::vector<menace_externe*> tmp = zone1->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        {
            if ((*it)->getm_buff_blindage() != 1)
                (*it)->setm_buff_blindage(1);
        }
        tmp = zone2->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        {
            if ((*it)->getm_buff_blindage() != 1)
                (*it)->setm_buff_blindage(1);
        }
        tmp = zone3->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        {
            if ((*it)->getm_buff_blindage() != 1)
                (*it)->setm_buff_blindage(1);
        }
    }
}


void menace_e2_07::actionMenace(char input)
{
    if (input == 'Z') {
        int degats = get_m_vie();
        messageAttaqueMenace(degats);
        makedegatsInZone(degats);
    }
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e2_07::actionQuandDetruit()
{
    std::string msg = "\033[1;32m[ELIMINATION DE LA MENACE !]\033[0m\n";
    printSlowly(msg, *m_zone->getz_data());
    int itemCrossed = (checkNombreInputCrossed('X') + checkNombreInputCrossed('Y')); // Dégâts infligés en fonction des actions croisées
    msg = "[La menace " + m_name + " a été détruite. Elle inflige " + std::to_string(itemCrossed) + " points de dégâts!]";
    messageBufferMenace(msg, -1);
    makedegatsInZone(itemCrossed);
    messageRecapCapitaine();
}



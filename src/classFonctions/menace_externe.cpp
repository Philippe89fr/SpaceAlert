#include "menace.hpp"
#include "menace_externe.hpp"


menace_externe::menace_externe(std::string input, int tourDarrivee): menace(input, tourDarrivee)
{
    m_attraction_roquette = false;
    m_degats = 0;
    m_vulnerable_roquette = true;
    m_buff_blindage = 0;
    m_revele = true;
    m_etat_bouclier = m_bouclier; // L'état du bouclier est initialisé à la valeur de m_bouclier

    if(input == "se1-01")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Fregate";
        m_vie = 7;
        m_vitesse = 2;
    }
    else if(input == "se1-02")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Man of War";
        m_vie = 9;
        m_vitesse = 1;
    }
    else if(input == "se1-03")
    {
        m_bouclier = 3;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Ravitailleur Leviathan";
        m_vie = 8;
        m_vitesse = 2;
    }
    else if(input == "se1-04")
    {
        m_revele = false;
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Satellite a impulsion";
        m_vie = 4;
        m_vitesse = 3;
    }
    else if(input == "se1-05")
    {
        m_immunity = true;
        m_bouclier = 1;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Fregate a Cryoprotection";
        m_vie = 7;
        m_vitesse = 2;
    }
    else if(input == "se1-06")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 1;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Pieuvre Interstellaire";
        m_vie = 8;
        m_vitesse = 2;
    }
    else if(input == "se1-07")
    {
        m_bouclier = 3;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Maelstrom";
        m_vie = 8;
        m_vitesse = 2;
    }
    else if(input == "se1-08")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Asteroide";
        m_vie = 9;
        m_vitesse = 3;
    }
    else if(input == "se2-01")
    {
        m_bouclier = 4;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Behemoth";
        m_vie = 7;
        m_vitesse = 2;
    }
    else if(input == "se2-02")
    {
        m_attraction_roquette = true;
        m_bouclier = 3;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Juggernaut";
        m_vie = 10;
        m_vitesse = 1;
    }
    else if(input == "se2-03")
    {
        m_revele = false;
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Satellite Psionique";
        m_vie = 5;
        m_vitesse = 2;
    }
    else if(input == "se2-04")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Crabe nebula";
        m_vie = 7;
        m_vitesse = 2;
    }
    else if(input == "se2-05")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Nemesis";
        m_vie = 9;
        m_vitesse = 3;
    }
    else if(input == "se2-06")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Asteroide Majeur";
        m_vie = 11;
        m_vitesse = 2;
    }
    else if(input == "e1-01")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Pulsar";
        m_vie = 5;
        m_vitesse = 2;
    }
    else if(input == "e1-02")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Destroyer";
        m_vie = 5;
        m_vitesse = 2;
    }
    else if(input == "e1-03")
    {
        m_revele = false;
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Chasseur furtif";
        m_vie = 4;
        m_vitesse = 3;
    }
    else if(input == "e1-04")
    {
        m_bouclier = 3;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Nuage d'energie";
        m_vie = 5;
        m_vitesse = 2;
    }
    else if(input == "e1-05")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Vaisseau de combat";
        m_vie = 5;
        m_vitesse = 2;
    }
    else if(input == "e1-06")
    {
        m_immunity = true;
        m_bouclier = 1;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Chasseur a cryoprotection";
        m_vie = 4;
        m_vitesse = 3;
    }
    else if(input == "e1-07")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Chasseur";
        m_vie = 4;
        m_vitesse = 3;
    }
    else if(input == "e1-08")
    {
        m_bouclier = 3;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Constricteur Blinde";
        m_vie = 4;
        m_vitesse = 2;
    }
    else if(input == "e1-09")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Amibe";
        m_vie = 8;
        m_vitesse = 2;
    }
    else if(input == "e1-10")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Meteorite";
        m_vie = 5;
        m_vitesse = 5;
    }
    else if(input == "e2-01")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Kamikaze";
        m_vie = 5;
        m_vitesse = 4;
    }
    else if(input == "e2-02")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Eclaireur";
        m_vie = 3;
        m_vitesse = 2;
    }
    else if(input == "e2-03")
    {
        m_revele = false;
        m_vulnerable_roquette = false;
        m_attraction_roquette = true;
        m_bouclier = 3;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Chasseur fantome";
        m_vie = 3;
        m_vitesse = 3;
    }
    else if(input == "e2-04")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Nuee Insectoide";
        m_vie = 3;
        m_vitesse = 2;
    }
    else if(input == "e2-05")
    {
        m_vulnerable_roquette = false;
        m_bouclier = -2;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Meduse";
        m_vie = 13;
        m_vitesse = 2;
    }
    else if(input == "e2-06")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Maraudeur";
        m_vie = 6;
        m_vitesse = 3;
    }
    else if(input == "e2-07")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Asteroide mineur";
        m_vie = 7;
        m_vitesse = 4;
    }
    m_max_vie = m_vie;
};

void menace_externe::print_menace() const
{
    menace::print_menace();
    start_color(m_zone);
    std::cout << "Bouclier : " << m_bouclier << std::endl;
    std::cout << "Etat Bouclier : " << m_etat_bouclier << std::endl;
    std::cout << "Buff Bouclier : " << m_buff_blindage << std::endl;
    std::cout << "Chemin : " << m_chemin->get_ch_nom() << std::endl;
    for (std::vector<cannon *>::const_iterator it = m_canon_used.begin(); it != m_canon_used.end(); ++it)
    {
        std::cout << "Canon utilisé contre elle : " << (*it)->getnom_cannon() << std::endl;
    }
    std::cout << "Zone : " << m_zone->getz_nom_zone() << std::endl;
    std::cout << "Chemin : " << m_chemin->get_ch_nom() << std::endl;
    end_color();
};

void menace_externe::send_announcement_message_externe()
{
    start_color(m_zone);
    std::string msg = "[Attention, la menace " + m_name + " vient d'arriver !]\n";
    printSlowly(msg, *m_zone->getz_data());
    msg = "[Difficulté : " + std::to_string(m_difficulte) + ", Vitesse : " + std::to_string(m_vitesse) + ", Vie : " + std::to_string(m_vie) + ", Bouclier : " + std::to_string(m_bouclier) + "]\n";
    printSlowly(msg, *m_zone->getz_data());
    end_color();
};

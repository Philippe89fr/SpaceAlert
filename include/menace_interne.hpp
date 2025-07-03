#pragma once

#include "menace.hpp"

class zone;

class menace_interne :public menace
{
    protected:
    bool    m_position_haut;
    int     m_killAction;
    bool m_ripost;

    public:
        menace_interne();
        menace_interne(zone *zone_input, std::string input, int tourDarrivee);
        void set_m_Positionhaut(bool position)
        { m_position_haut = position;};
        bool get_m_Positionhaut()
        { return m_position_haut;};
        void set_m_Ripost(bool ripost)
        { m_ripost = ripost;};
        bool get_m_Ripost()
        { return m_ripost;};
        virtual void print_menace() const;
        virtual bool AttractAction(int joueurAction, int Zone, bool haut) const;
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        void manaceMoveInZone(std::string string);
        void printfaitdegats(int degats);
        virtual ~menace_interne();
        virtual void send_announcement_message();
        void getDamaged();
};

//MENACES COMMUNES

class menace_interne_i1_01 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_01() {};
        menace_interne_i1_01(zone *zone, std::string input, int tourDarrivee): menace_interne(zone, input, tourDarrivee) {};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_01() {};
};

class menace_interne_i1_02 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_02() {};
        menace_interne_i1_02(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_02() {};
};

class menace_interne_i1_03 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_03() {};
        menace_interne_i1_03(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_03() {};
};

class menace_interne_i1_04 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_04() {};
        menace_interne_i1_04(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_04() {};
};

class menace_interne_i1_05 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_05() {};
        menace_interne_i1_05(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_05() {};
};

class menace_interne_i1_06 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_06() {};
        menace_interne_i1_06(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_06() {};
};

class menace_interne_i1_07 :public menace_interne
{
    protected:
    bool m_life_set;

    public:
        menace_interne_i1_07() {};
        menace_interne_i1_07(bool life_set, zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee)
        {m_life_set = life_set;};
        virtual void actionMenace(char input);
        virtual void send_announcement_message();
        virtual ~menace_interne_i1_07() {};
};

//MENACES COMMUNES AVANCEES

class menace_interne_i2_01 :public menace_interne
{
    protected:
    bool m_zone_delay_set;

    public:
        menace_interne_i2_01() {};
        menace_interne_i2_01(bool zone_delay_set, zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee)
        {m_zone_delay_set = zone_delay_set;};
        //virtual void getDamage(joueur *joueur);
        virtual void effetDebutTour();
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_01() {};
};

class menace_interne_i2_015 :public menace_interne
{
    protected:
    bool m_zone_delay_set;

    public:
        menace_interne_i2_015() {};
        menace_interne_i2_015(bool zone_delay_set, zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee)
        {m_zone_delay_set = zone_delay_set;};
        //virtual void getDamage(joueur *joueur);
        virtual void effetDebutTour();
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_015() {};
};

class menace_interne_i2_02 :public menace_interne
{
    protected:
    bool m_zone_delay_set;

    public:
        menace_interne_i2_02() {};
        menace_interne_i2_02(bool zone_delay_set, zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee)
        {m_zone_delay_set = zone_delay_set;};
        //virtual void getDamage(joueur *joueur);
        virtual void effetDebutTour();
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_02() {};
};

class menace_interne_i2_03 :public menace_interne
{
    protected:

    public:
        menace_interne_i2_03() {};
        menace_interne_i2_03(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_03() {};
};

class menace_interne_i2_04 :public menace_interne
{
    protected:

    public:
        menace_interne_i2_04() {};
        menace_interne_i2_04(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_04() {};
};

class menace_interne_i2_05 :public menace_interne
{
    protected:

    public:
        menace_interne_i2_05() {};
        menace_interne_i2_05(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_05() {};
};

class menace_interne_i2_06 :public menace_interne
{
    protected:

    public:
        menace_interne_i2_06() {};
        menace_interne_i2_06(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input , input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual void actionQuandDetruit();
        virtual ~menace_interne_i2_06() {};
};


//MENACES SERIEUSE

class menace_interne_si1_01 :public menace_interne
{
    protected:

    public:
        menace_interne_si1_01() {};
        menace_interne_si1_01(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input , input, tourDarrivee) {};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_si1_01() {};
};

class menace_interne_si1_02 :public menace_interne
{
    protected:

    public:
        menace_interne_si1_02() {};
        menace_interne_si1_02(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input , input, tourDarrivee) {};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_si1_02() {};
};

class menace_interne_si1_03 :public menace_interne
{
    protected:
    bool m_grandit;

    public:
        menace_interne_si1_03() {};
        menace_interne_si1_03(bool grandit, zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee)
        {m_grandit = grandit;};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_si1_03() {};
};

class menace_interne_si1_04 :public menace_interne
{
    protected:

    public:
        menace_interne_si1_04() {};
        menace_interne_si1_04(zone *zone, std::string input, int tourDarrivee): menace_interne(zone , input, tourDarrivee) {};
        virtual bool AttractAction(int joueurAction, int Zone, bool haut) const;
        virtual void actionMenace(char input);
        virtual void actionQuandDetruit();
        virtual ~menace_interne_si1_04() {};
};


class menace_interne_si1_05 :public menace_interne
{
    protected:

    public:
        menace_interne_si1_05() {};
        menace_interne_si1_05(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input , input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_si1_05() {};
};

class menace_interne_si1_06 :public menace_interne
{
    protected:
    int m_degats_tour_zone;
    int m_zoneInt_bis;
    bool m_position_haut_bis;
    zone *m_zone_bis;

    public:
        menace_interne_si1_06() {};
        menace_interne_si1_06(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input, input, tourDarrivee)
        {m_degats_tour_zone = 0; m_zoneInt_bis = ZONE_BLUE; m_position_haut_bis = true; m_zone_bis = zone_input->getzone_blue();};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual void effetDebutTour();
        virtual bool AttractAction(int joueurAction, int Zone, bool haut) const;
        virtual ~menace_interne_si1_06() {};
};

class menace_interne_si2_01 :public menace_interne
{
    protected:

    public:
        menace_interne_si2_01() {};
        menace_interne_si2_01(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input, input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual ~menace_interne_si2_01() {};
};

class menace_interne_si2_02 :public menace_interne
{
    protected:

    public:
        menace_interne_si2_02() {};
        menace_interne_si2_02(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input, input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual ~menace_interne_si2_02() {};
};

class menace_interne_si2_03 :public menace_interne
{
    protected:
    int m_degats_zone_red;
    int m_degats_zone_blue;
    int m_degats_zone_white;
    int m_zoneInt_bis1;
    bool m_position_haut_bis1;
    int m_zoneInt_bis2;
    bool m_position_haut_bis2;

    public:
        menace_interne_si2_03() {};
        menace_interne_si2_03(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input, input, tourDarrivee)
        {m_degats_zone_red = 0; m_degats_zone_blue = 0; m_degats_zone_white = 0; m_zoneInt_bis1 = ZONE_WHITE; m_position_haut_bis1 = false; m_zoneInt_bis2 = ZONE_BLUE; m_position_haut_bis2 = false;};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual void effetDebutTour();
        virtual bool AttractAction(int joueurAction, int Zone, bool haut) const;
        virtual ~menace_interne_si2_03() {};
};

class menace_interne_si2_04 :public menace_interne
{
    protected:
    bool m_contamination_blue_bas;
    bool m_contamination_blue_haut;
    bool m_contamination_red_bas;
    bool m_contamination_red_haut;
    int m_zoneInt_bis1;
    bool m_position_haut_bis1;
    int m_zoneInt_bis2;
    bool m_position_haut_bis2;
    int m_zoneInt_bis3;
    bool m_position_haut_bis3;

    public:
        menace_interne_si2_04() {};
        menace_interne_si2_04(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input, input, tourDarrivee)
        {m_contamination_blue_bas = true; m_contamination_blue_haut = true; m_contamination_red_bas = true; m_contamination_red_haut = true ; m_zoneInt_bis1 = ZONE_RED; m_position_haut_bis1 = true; m_zoneInt_bis2 = ZONE_BLUE; m_position_haut_bis2 = false; m_zoneInt_bis3 = ZONE_BLUE; m_position_haut_bis3 = true;};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual bool AttractAction(int joueurAction, int Zone, bool haut) const;
        virtual ~menace_interne_si2_04() {};
};

class menace_interne_si2_05 :public menace_interne
{
    protected:
    int m_degats_par_tour;

    public:
        menace_interne_si2_05() {};
        menace_interne_si2_05(zone *zone_input, std::string input, int tourDarrivee): menace_interne(zone_input, input, tourDarrivee)
        {m_degats_par_tour = 0;};
        virtual void getDamage(joueur *joueur);
        virtual void getDamageHero(joueur *joueur);
        virtual void actionMenace(char input);
        virtual void effetDebutTour();
        virtual ~menace_interne_si2_05() {};
};

// class menace_interne_si2_05 :public menace_interne
// {
//     protected:

//     public:
//         menace_interne_si2_05() {};
//         menace_interne_si2_05(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
//         virtual void actionMenace(char input);
//         virtual ~menace_interne_si2_05() {};
// };





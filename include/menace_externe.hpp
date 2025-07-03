#pragma once

#include "space_alerte.hpp"

#include "menace.hpp"

class menace_externe : public menace
{
    protected:
    int m_bouclier;
    int m_etat_bouclier;
    int m_buff_blindage;
    bool m_vulnerable_roquette;
    bool m_attraction_roquette;
    bool m_revele;

    std::vector<cannon *> m_canon_used; // pour les menaces qui utilisent des canons
    std::vector<int>    m_canon_immunity; // pour les menaces qui sont immunisées contre certains canons


    public:
        menace_externe();
        menace_externe(std::string input, int tourDarrivee);
        virtual void print_menace() const;
        //Set & Get
        void set_m_attraction_roquette(bool input) {
            m_attraction_roquette = input;
        };
        bool get_m_revele() const {
            return m_revele;
        };
        void set_m_revele(bool input) {
            m_revele = input;
        };
        bool get_m_attraction_roquette() const {
            return m_attraction_roquette;
        };
        void setm_vulnerable_roquette(bool input) {
            m_vulnerable_roquette = input;
        };
        bool get_m_vulnerable_roquette() const {
            return m_vulnerable_roquette;
        };
        void set_m_bouclier(int input) {
            m_bouclier = input;
        }
        void setm_buff_blindage(int input) {
            m_buff_blindage = input;
        };
        int getm_buff_blindage() const {
            return m_buff_blindage;
        };
        int get_m_etat_bouclier() const {
            return m_etat_bouclier;
        };
        int get_m_bouclier() const {
            return m_bouclier;
        };
        void set_m_etat_bouclier(int input) {
            m_etat_bouclier = input;
        };
        std::vector<int> get_m_canon_immunity() const {
            return m_canon_immunity;
        };
        std::vector<cannon *> get_m_canon_used() const {
            return m_canon_used;
        };

        //Autres fonctions
        void add_m_canon_immunity(int input) {
            m_canon_immunity.push_back(input);
        };

        void add_m_canon_used(cannon *input) {
            m_canon_used.push_back(input);
        };
        void clear_m_canon_used() {
            m_canon_used.clear();
        };
        void augmenteBouclier(int input) {
            m_bouclier += input;
        };

        void send_announcement_message_externe();
        virtual ~menace_externe() {};
};

class menace_se1_01: public menace_externe
{
    private:

    public:
        menace_se1_01() : menace_externe() {};
        menace_se1_01(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se1_01() {};
};

class menace_se1_02: public menace_externe
{
    private:

    public:
        menace_se1_02() : menace_externe() {};
        menace_se1_02(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se1_02() {};
};

class menace_se1_03: public menace_externe
{
    private:

    public:
        menace_se1_03() : menace_externe() {};
        menace_se1_03(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se1_03() {};
};

class menace_se1_04: public menace_externe
{
    private:

    public:
        menace_se1_04() : menace_externe() {};
        menace_se1_04(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual bool vulnerability_check(cannon* input);
        ~menace_se1_04() {};
};

class menace_se1_05: public menace_externe
{
    private:
        int m_immunity2;

    public:
        menace_se1_05() : menace_externe() {};
        menace_se1_05(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {
            m_immunity2 = true;
        };
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void recoitDegats(int input);
        virtual void effetDebutTour();
        ~menace_se1_05() {};
};

class menace_se1_06: public menace_externe
{
    private:

    public:
        menace_se1_06() : menace_externe() {};
        menace_se1_06(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se1_06() {};
};

class menace_se1_07: public menace_externe
{
    private:

    public:
        menace_se1_07() : menace_externe() {};
        menace_se1_07(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se1_07() {};
};

class menace_se1_08: public menace_externe
{
    private:

    public:
        menace_se1_08() : menace_externe() {};
        menace_se1_08(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se1_08() {};
};

class menace_se2_01: public menace_externe
{
    private:

    public:
        menace_se2_01() : menace_externe() {};
        menace_se2_01(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se2_01() {};
};

class menace_se2_02: public menace_externe
{
    private:

    public:
        menace_se2_02() : menace_externe() {};
        menace_se2_02(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se2_02() {};
};

class menace_se2_03: public menace_externe
{
    private:

    public:
        menace_se2_03() : menace_externe() {};
        menace_se2_03(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual bool vulnerability_check(cannon* input);
        ~menace_se2_03() {};
};

class menace_se2_04: public menace_externe
{
    private:

    public:
        menace_se2_04() : menace_externe() {};
        menace_se2_04(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se2_04() {};
};

class menace_se2_05: public menace_externe
{
    private:

    public:
        menace_se2_05() : menace_externe() {};
        menace_se2_05(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void recoitDegats(int input);
        virtual ~menace_se2_05() {};
};

class menace_se2_06: public menace_externe
{
    private:

    public:
        menace_se2_06() : menace_externe() {};
        menace_se2_06(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se2_06() {};
};

class menace_e1_01: public menace_externe
{
    private:

    public:
        menace_e1_01() : menace_externe() {};
        menace_e1_01(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_01() {};
};

class menace_e1_02: public menace_externe
{
    private:

    public:
        menace_e1_02() : menace_externe() {};
        menace_e1_02(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_02() {};
};

class menace_e1_03: public menace_externe
{
    private:

    public:
        menace_e1_03() : menace_externe() {};
        menace_e1_03(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_03() {};
};

class menace_e1_04: public menace_externe
{
    private:

    public:
        menace_e1_04() : menace_externe() {};
        menace_e1_04(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_04() {};
};

class menace_e1_05: public menace_externe
{
    private:

    public:
        menace_e1_05() : menace_externe() {};
        menace_e1_05(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_05() {};
};

class menace_e1_06: public menace_externe
{
    private:

    public:
        menace_e1_06() : menace_externe() {};
        menace_e1_06(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void recoitDegats(int input);
        ~menace_e1_06() {};
};

class menace_e1_07: public menace_externe
{
    private:

    public:
        menace_e1_07() : menace_externe() {};
        menace_e1_07(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_07() {};
};

class menace_e1_08: public menace_externe
{
    private:

    public:
        menace_e1_08() : menace_externe() {};
        menace_e1_08(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_08() {};
};

class menace_e1_09: public menace_externe
{
    private:

    public:
        menace_e1_09() : menace_externe() {};
        menace_e1_09(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_09() {};
};

class menace_e1_10: public menace_externe
{
    private:

    public:
        menace_e1_10() : menace_externe() {};
        menace_e1_10(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_10() {};
};

class menace_e2_01: public menace_externe
{
    private:

    public:
        menace_e2_01() : menace_externe() {};
        menace_e2_01(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e2_01() {};
};

class menace_e2_02: public menace_externe
{
    private:
        bool m_effetDebutTourOn;
        int m_imunity_canon;

    public:
        menace_e2_02() : menace_externe() {};
        menace_e2_02(int imunity_canon, bool effetDebutTourOn, std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee)
        {m_imunity_canon = imunity_canon;
        m_effetDebutTourOn = effetDebutTourOn;};
        virtual void effetDebutTour();
        void menaceAvanceUneCaseInZone(zone *zone);
        virtual bool vulnerability_check(cannon* input);
        void augmenteAttackInZone(zone *zone);
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void actionQuandDetruit();
        ~menace_e2_02() {};
};

class menace_e2_03: public menace_externe
{
    private:

    public:
        menace_e2_03() : menace_externe() {};
        menace_e2_03(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e2_03() {};
};

class menace_e2_04: public menace_externe
{
    private:

    public:
        menace_e2_04() : menace_externe() {};
        menace_e2_04(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void recoitDegats(int input);
        ~menace_e2_04() {};
};

class menace_e2_05: public menace_externe
{
    private:

    public:
        menace_e2_05() : menace_externe() {};
        menace_e2_05(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e2_05() {};
};

class menace_e2_06: public menace_externe
{
    private:
        bool effetDebutTourOn;

    public:
        menace_e2_06() : menace_externe() {};
        menace_e2_06(bool effet, std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {
            effetDebutTourOn = effet;
        };
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void effetDebutTour();
        void actionQuandDetruit();
        ~menace_e2_06() {};
};

class menace_e2_07: public menace_externe
{
    private:

    public:
        menace_e2_07() : menace_externe() {};
        menace_e2_07(std::string input, int tourDarrivee) : menace_externe(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void actionQuandDetruit();
        ~menace_e2_07() {};
};

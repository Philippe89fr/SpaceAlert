#include "space_alerte.hpp"
#include "GameNarrator.hpp"

void wr(std::string str)
{
    //printSlowly(str);
	std::cout << str << std::endl;
}

std::string generateRandomString(int length) {
    std::string result = "";
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int charsetSize = sizeof(charset) - 1; // -1 pour ne pas inclure le '\0'

    for (int i = 0; i < length; ++i) {
        int index = rand() % charsetSize;
        result += charset[index];
    }
    return result;
}

void printSlowly(const std::string& text, t_data &data, int delayMs) {
    for (char c : text) {
        std::cout << c << std::flush;  // afficher sans attendre le buffer
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        //data.VoixRobot1->announce(text);
        data.nb_joueur += 0;
    }
}

void start_color(zone *zone)
{
    if (zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
}

void start_color_interne()
{
    std::cout << "\033[32m";
}

void print_title(std::string msg)
{
    std::string msg_tour_joueur = "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "                  ****            ****            ****          [" + msg + "]          ****            ****            **** \n";
    msg_tour_joueur += "-----------------------------------------------------------------------------------------------------------------------------------------------\n\n";

	start_color_titre();
	std::cout << msg_tour_joueur;
    end_color();
}

void start_color_tour()
{
    std::cout << "\033[1;35m";
}

void mission_failed(std::string msg, t_data &data)
{
    start_color_tour();
    std::string msg_tour_joueur = "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\" + msg;
    msg_tour_joueur += "-----------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	std::cout << msg_tour_joueur;
    printSlowly("[Souhaitez-vous continuez a voir votre catastrophe ou preferez vous en finir rapidement ? (continuer : Y/y)]\n", data);
    std::string input;
    std::getline(std::cin, input);  // attend que l'utilisateur appuie sur Entrée
    end_color();
    if (input == "Y" || input == "y" || input == "oui" || input == "yes" || input == "OUI" || input == "YES")
        return;
    exit(1);
}

void print_tour(std::string msg)
{
    std::string msg_tour_joueur = "\n\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "                  ****            ****            ****              [" + msg + "]             ****            ****            ****  \n";
    msg_tour_joueur += "-----------------------------------------------------------------------------------------------------------------------------------------------\n\n";

	start_color_tour();
	std::cout << msg_tour_joueur;
    end_color();
}

void start_color_titre()
{
    std::cout << "\033[1;33m";
}

void end_color()
{
    std::cout << "\033[0m";
}

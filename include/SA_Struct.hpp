
#pragma once

#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()

class joueur;
class zone;
class chemin_menace;
class GameNarrator;

typedef struct s_data
{
	int nb_joueur;
	std::map<int, joueur*> joueurs;
	std::map<int, zone*> zones;
	int tour;
	chemin_menace *chemin_menace_interne;
	GameNarrator *VoixRobot1;
	GameNarrator *VoixRobot2;
	GameNarrator *VoixAlert;
} t_data;

void wr(std::string str);
std::string generateRandomString(int length);



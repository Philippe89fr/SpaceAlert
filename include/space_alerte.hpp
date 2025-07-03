
#pragma once

#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()
#include <chrono>
#include <thread>

#include "SA_Struct.hpp"
#include "SA_Class.hpp"
class menace;
class menace_externe;


void wr(std::string str);
std::string generateRandomString(int length);
void init_carte_joueur_test(t_data& data);
void init_data(t_data& data);
void apparitionMenaces(t_data &data);
void parsing_config(t_data &data, char* av);
void	action_joueur(t_data &data, int joueur);
void assignationCannons(t_data &data);
void mouvement_menaces(t_data &data);
void remove_dead_or_outdated_menaces(t_data &data);
void analyseDesDegatsCanons(t_data &data);
void rocketActions(t_data &data);
void impactDegatsTotaux(t_data &data);
void check_maintenance(t_data &data);
void attaqueDesCanons(t_data &data);
menace* get_closest_menace_in_vector(std::vector<menace*> menaces);
void revelerMenace(menace* menace);
void end_color();
void start_color(zone *zone);
menace_externe* get_closest_menace_in_vector(std::vector<menace_externe*> menaces);
void revelerMenace(menace_externe* menace);
void retarder_joueurs(t_data &data);
int get_nb_actions(std::string nomAction);
void printSlowly(const std::string& text, t_data &data, int delayMs = 5);
void start_color_interne();
void start_color_titre();
void print_title(std::string msg);
void print_tour(std::string msg);
void wait();
void mission_failed(std::string msg, t_data &data);

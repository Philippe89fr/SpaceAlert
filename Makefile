# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 14:46:31 by prambaud          #+#    #+#              #
#    Updated: 2025/05/30 18:19:21 by lbenatar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	spaceAlert

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++11 -g3

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
UP			=	\033[A
CUT			=	\033[K

SRC_FILES	=	classFonctions/cannon.cpp \
				classFonctions/carte_action.cpp \
				classFonctions/carte_action_hero.cpp \
				classFonctions/carte.cpp \
				classFonctions/carte_deplacement.cpp \
				classFonctions/carte_deplacement_hero.cpp \
				classFonctions/carte_heros.cpp \
				classFonctions/chemin_menace.cpp \
				classFonctions/jeux.cpp \
				classFonctions/joueur.cpp \
				classFonctions/menace.cpp \
				classFonctions/menace_msg.cpp \
				classFonctions/menace_actions.cpp \
				classFonctions/menace_interne.cpp \
				classFonctions/menace_externe.cpp \
				classFonctions/zoneGetSet.cpp \
				classFonctions/zoneActDir.cpp \
				classFonctions/zoneActAct.cpp \
				classFonctions/zoneUtils.cpp \
				initialisation.cpp \
				calculDegatsCanons.cpp \
				calculDegatsRockets.cpp \
				apparitionMenaces.cpp \
				parsingConfig.cpp \
				actionsDesJoueurs.cpp \
				checkMaintenance.cpp \
				main.cpp \
				utils.cpp

OBJ			=	$(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRC_FILES))
DEPS		=	$(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

-include $(DEPS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CXX) $(CXXFLAGS) -MMD -MP -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(BLUE)Deleting all objects from $(OBJ_DIR)...$(RESET)"; \
	else \
		echo "No objects to remove from $(OBJ_DIR)."; \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME)...$(RESET)"; \
	else \
		echo "No executable to remove."; \
	fi;

re: fclean all

.PHONY: all clean fclean re



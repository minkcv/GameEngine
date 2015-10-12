/*
 * interactivemanager.h
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */


#ifndef INTERACTIVEMANAGER_H_
#define INTERACTIVEMANAGER_H_

#include "pausemenu.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include "interactive.h"
#include "../gengine/gamestack.h"

using namespace gengine;

class MainMenu; // forward declaration because of circular dependency
class Game; // forward declaration because of circular dependency

/**
 * handles switching between different interactive components
 * and serves as a central source for the game stack and window pointer
 */
class InteractiveManager
{
private:
	Interactive* currentInteractive;
	Game* game;
	MainMenu* mainMenu;
	PauseMenu* pauseMenu;
	sf::RenderWindow* window;
	GameStack* gStack;
public:
	InteractiveManager(sf::RenderWindow* window);
	void update(double deltaT);
	void render();
	void startGame();
	void pauseGame();
	void resumeGame();
	sf::RenderWindow* getWindow();
	GameStack* getGameStack();
	~InteractiveManager();
};

#endif /* INTERACTIVEMANAGER_H_ */

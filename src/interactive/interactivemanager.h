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
#include "../gengine/windowmanager.h"
#include "../gengine/physicsmanager.h"

using namespace gengine;

class MainMenu; // forward declaration
class Game; // forward declaration

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
	WindowManager* wManager;
	GameStack* gStack;
public:
	InteractiveManager(WindowManager* wManager, PhysicsManager* pManager);
	void update(double deltaT);
	void render();
	void startGame();
	void pauseGame();
	void resumeGame();
	GameStack* getGameStack();
	~InteractiveManager();
};

#endif /* INTERACTIVEMANAGER_H_ */

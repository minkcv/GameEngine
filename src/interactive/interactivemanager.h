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
#include <SFML/Window.hpp>
#include "mainmenu.h"
#include "interactive.h"

namespace interactive
{
	class MainMenu; // forward declaration because of circular dependency

	class InteractiveManager
	{
	private:
		Interactive* currentInteractive;
		Game* game;
		MainMenu* mainMenu;
		PauseMenu* pauseMenu;
		sf::Window* window;
	public:
		InteractiveManager(sf::Window* window);
		void update(double deltaT);
		void render();
		void startGame();
		void pauseGame();
		void resumeGame();
	};
}

#endif /* INTERACTIVEMANAGER_H_ */

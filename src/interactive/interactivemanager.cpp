/*
 * interactivemanager.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */

#include "interactivemanager.h"
#include <SFML/Window.hpp>

namespace interactive
{
	InteractiveManager::InteractiveManager(sf::Window* window)
	{
		//mainMenu = new MainMenu(this);
		mainMenu = new MainMenu(this);
		pauseMenu = new PauseMenu();
		game = new Game(window);
		currentInteractive = mainMenu;
		this->window = window;
	}

	void InteractiveManager::update(double deltaT)
	{
		currentInteractive->update(deltaT);
	}

	void InteractiveManager::render()
	{
		currentInteractive->render();
	}

	void InteractiveManager::startGame()
	{
		currentInteractive = game;
		window->setMouseCursorVisible(false);
	}
	void InteractiveManager::pauseGame()
	{
		currentInteractive = pauseMenu;
		window->setMouseCursorVisible(true);
	}
	void InteractiveManager::resumeGame()
	{
		currentInteractive = game;
		window->setMouseCursorVisible(false);
	}
}

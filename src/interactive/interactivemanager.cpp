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
	InteractiveManager::InteractiveManager(sf::RenderWindow* window)
	{
		this->window = window;
		gStack = new GameStack();
		mainMenu = new MainMenu(this);
		pauseMenu = new PauseMenu();
		currentInteractive = mainMenu;
		game = new Game(this);
//		void* a = gStack->push(sizeof(int));
//		int* b = new(a) int;
//		*b = 10;
//		printf("%d\n",*b);
//		gStack->pop();
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

	sf::RenderWindow* InteractiveManager::getWindow()
	{
		return window;
	}

	GameStack* InteractiveManager::getGameStack()
	{
		return gStack;
	}
	InteractiveManager::~InteractiveManager()
	{
		delete gStack;
	}
}

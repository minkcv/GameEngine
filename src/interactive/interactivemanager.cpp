/*
 * interactivemanager.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */

#include "interactivemanager.h"
#include <SFML/Window.hpp>

InteractiveManager::InteractiveManager(WindowManager* wManager)
{
	this->wManager = wManager;
	gStack = new GameStack();
	mainMenu = new MainMenu(this, wManager);
	pauseMenu = new PauseMenu();
	currentInteractive = mainMenu;
	game = new Game(this, wManager);
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
	wManager->setShowMouse(false);
}
void InteractiveManager::pauseGame()
{
	currentInteractive = pauseMenu;
	wManager->setShowMouse(true);
}
void InteractiveManager::resumeGame()
{
	currentInteractive = game;
	wManager->setShowMouse(false);
}

GameStack* InteractiveManager::getGameStack()
{
	return gStack;
}
InteractiveManager::~InteractiveManager()
{
	game = nullptr;
	gStack = nullptr;
}

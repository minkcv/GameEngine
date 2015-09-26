/*
 * menu.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */

#include "mainmenu.h"

namespace interactive
{
	MainMenu::MainMenu(InteractiveManager* iManager)
	{
		this->iManager = iManager;
	}

	void MainMenu::update(double deltaT)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			iManager->startGame();
	}

	void MainMenu::render()
	{

	}

	MainMenu::~MainMenu()
	{

	}
}

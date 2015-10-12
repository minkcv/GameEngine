/*
 * windowmanager.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: wsmith
 */

#include <SFML/Graphics.hpp>
#include "windowmanager.h"

namespace gengine
{
WindowManager::WindowManager(InteractiveManager* iManager, GameConfig& gConfig) : window(nullptr), iManager(iManager), gConfig(gConfig)
{
}
void WindowManager::createWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(gConfig.getWindowWidth(), gConfig.getWindowHeight()), gConfig.getWindowTitle(), sf::Style::Default, gConfig.getContextSettings());
}

void WindowManager::manageEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		else if(event.type == sf::Event::Resized){
			//glViewport(0, 0, event.size.width, event.size.height);
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window->close();
}

void WindowManager::changeStyle(sf::Uint32 style)
{
	window->create(sf::VideoMode(gConfig.getWindowWidth(), gConfig.getWindowHeight()), gConfig.getWindowTitle(), style);
}

bool WindowManager::windowIsOpen()
{
	return window->isOpen();
}

void WindowManager::displayWindow()
{
	window->display();
}

sf::RenderWindow* WindowManager::getWindow()
{
	return window;
}
}

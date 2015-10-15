/*
 * windowmanager.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: wsmith
 */

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <string>
#include "windowmanager.h"

namespace gengine
{
WindowManager::WindowManager(InteractiveManager* iManager, GameConfig& gConfig) : window(nullptr), iManager(iManager), gConfig(gConfig)
{
	if (!font.loadFromFile("resources/DejaVuSansMono.ttf"))
	{
		printf("error loading font\n");
	}
	fpsText.setFont(font);
	fpsText.setCharacterSize(24);
	fpsText.setColor(sf::Color::White);
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

void WindowManager::setShowMouse(bool showMouse)
{
	window->setMouseCursorVisible(showMouse);
}

void WindowManager::displayFPS(int fps)
{
	fpsText.setColor(sf::Color::White);
	fpsText.setPosition(0, 0);
	std::string fpsString = "FPS: ";
	fpsString += std::to_string(fps);
	fpsText.setString(fpsString);
	window->pushGLStates();
	window->draw(fpsText);
	window->popGLStates();
}

sf::RenderWindow* WindowManager::getWindow()
{
	return window;
}
}

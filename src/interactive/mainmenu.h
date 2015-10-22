/*
 * menu.h
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */


#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "../gengine/gamestack.h"
#include "../gengine/windowmanager.h"
#include "interactive.h"
#include "interactivemanager.h"
#include <SFML/Graphics.hpp>

using namespace gengine;

class InteractiveManager; // forward declaration because of circular dependency

class MainMenu : public Interactive
{
private:
	InteractiveManager* iManager;
	WindowManager* wManager;
	GameStack* gStack;
	sf::Font font;
	sf::Text text;
	sf::Image image;
	sf::Texture texture;
public:
	MainMenu(InteractiveManager* iManager, WindowManager* wManager);
	void update(double deltaT);
	void render();
	~MainMenu();
};


#endif /* MENU_H_ */

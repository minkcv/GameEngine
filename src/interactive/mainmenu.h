/*
 * menu.h
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */


#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "../gengine/gamestack.h"
#include "interactive.h"
#include "interactivemanager.h"
#include <SFML/Graphics.hpp>

using namespace gengine;

namespace interactive
{
	class InteractiveManager; // forward declaration because of circular dependency

	class MainMenu : public Interactive
	{
	private:
		InteractiveManager* iManager;
		GameStack* gStack;
		sf::Font font;
		sf::Text text;
	public:
		MainMenu(InteractiveManager* iManager);
		void update(double deltaT);
		void render();
		~MainMenu();
	};
}

#endif /* MENU_H_ */

/*
 * menu.h
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */


#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "interactive.h"
#include "interactivemanager.h"

namespace interactive
{
	class InteractiveManager; // forward declaration because of circular dependency

	class MainMenu : public Interactive
	{
	private:
		InteractiveManager* iManager;
	public:
		MainMenu(InteractiveManager* iManager);
		void update(double deltaT);
		void render();
		~MainMenu();
	};
}

#endif /* MENU_H_ */

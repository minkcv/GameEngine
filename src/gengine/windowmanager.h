/*
 * windowmanager.h
 *
 *  Created on: Oct 11, 2015
 *      Author: wsmith
 */

#include <SFML/Graphics.hpp>
#include "../interactive/interactivemanager.h"
#include "gameconfig.h"

#ifndef WINDOWMANAGER_H_
#define WINDOWMANAGER_H_

namespace gengine
{
class WindowManager
{
private:
	sf::RenderWindow* window;
	std::string window_title = "SFML works!";
	sf::Uint32 window_style = sf::Style::Default;
	InteractiveManager* iManager;
	GameConfig gConfig;
public:
	WindowManager(InteractiveManager* iManager, GameConfig& gConfig);
	void createWindow();
	void changeStyle(sf::Uint32 style);
	void manageEvents();
	bool windowIsOpen();
	void displayWindow();
	sf::RenderWindow* getWindow();
};
}



#endif /* WINDOWMANAGER_H_ */

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

class InteractiveManager; // forward declaration

namespace gengine
{
class WindowManager
{
private:
	sf::RenderWindow* window;
	std::string windowTitle;
	sf::Uint32 windowStyle;
	InteractiveManager* iManager;
	GameConfig gConfig;
	sf::Font font;
	sf::Text fpsText;
public:
	WindowManager(InteractiveManager* iManager, GameConfig& gConfig);
	void createWindow();
	void changeStyle(sf::Uint32 style);
	void manageEvents();
	bool windowIsOpen();
	void displayWindow();
	void setShowMouse(bool showMouse);
	void displayFPS(int fps);
	sf::RenderWindow* getWindow();
};
}



#endif /* WINDOWMANAGER_H_ */

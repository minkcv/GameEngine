/*
 * gameconfig.h
 *
 *  Created on: Oct 11, 2015
 *      Author: wsmith
 */

#include <SFML/Graphics.hpp>

#ifndef GAMECONFIG_H_
#define GAMECONFIG_H_

namespace gengine
{
class GameConfig
{
private:
	int windowWidth;
	int windowHeight;
	int maxFPS;
	int antiAliasLevel;
	float mouseSensitivity;
	std::string windowTitle;
	sf::ContextSettings glContextSettings;
public:
	GameConfig();
	GameConfig(int windowWidth, int windowHeight, int maxFPS, int antiAliasLevel, float mouseSensitivity, std::string windowTitle, sf::ContextSettings glContextSettings);
	int getWindowWidth();
	int getWindowHeight();
	int getMaxFPS();
	int getAntiAliasLevel();
	float getMouseSensitivity();
	std::string getWindowTitle();
	sf::ContextSettings getContextSettings();
};
}

#endif /* GAMECONFIG_H_ */

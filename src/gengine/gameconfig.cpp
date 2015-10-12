/*
 * gameconfig.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: wsmith
 */

#include "gameconfig.h"

namespace gengine
{
GameConfig::GameConfig()
	:windowWidth(800), windowHeight(600), maxFPS(60), antiAliasLevel(0), mouseSensitivity(1), windowTitle("Game Engine")
{
}
GameConfig::GameConfig(int windowWidth, int windowHeight, int maxFPS, int antiAliasLevel, float mouseSensitivity, std::string windowTitle, sf::ContextSettings glContextSettings)
	: windowWidth(windowWidth), windowHeight(windowHeight), maxFPS(maxFPS), antiAliasLevel(antiAliasLevel), mouseSensitivity(mouseSensitivity), windowTitle(windowTitle), glContextSettings(glContextSettings)
{
}

int GameConfig::getWindowWidth()
{
	return windowWidth;
}

int GameConfig::getWindowHeight()
{
	return windowHeight;
}

int GameConfig::getMaxFPS()
{
	return maxFPS;
}

int GameConfig::getAntiAliasLevel()
{
	return antiAliasLevel;
}

float GameConfig::getMouseSensitivity()
{
	return mouseSensitivity;
}

std::string GameConfig::getWindowTitle()
{
	return windowTitle;
}

sf::ContextSettings GameConfig::getContextSettings()
{
	return glContextSettings;
}
}


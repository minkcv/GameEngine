/*
 * configmanager.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: wsmith
 */

#include <iostream>
#include <fstream>
#include <string>
#include "configmanager.h"
#include "gameconfig.h"

using namespace std;

namespace gengine
{

// declare static GameConfig
GameConfig ConfigManager::gConfig = GameConfig();

void ConfigManager::loadConfig()
{
	int windowWidth;
	int windowHeight;
	int maxFPS;
	int antiAliasLevel;
	float mouseSensitivity;
	string windowTitle;

	ifstream configFile("resources/config.txt");
	string line;
	if(configFile.is_open()) {
		while(getline(configFile,line)) {
			int eqPosition = line.find('=');
			string valueName = line.substr(0, eqPosition);
			string value = line.substr(eqPosition + 1, line.length());
			if(valueName == "windowWidth") {
				windowWidth = atoi(value.c_str());
			}
			else if(valueName == "windowHeight") {
				windowHeight = atoi(value.c_str());
			}
			else if(valueName == "maxFPS") {
				maxFPS = atoi(value.c_str());
			}
			else if(valueName == "antiAliasLevel") {
				antiAliasLevel = atoi(value.c_str());
			}
			else if(valueName == "mouseSensitivity") {
				mouseSensitivity = atof(value.c_str());
			}
			else if(valueName == "windowTitle") {
				windowTitle = value;
			}
		}
		configFile.close();
	}

	sf::ContextSettings glContextSettings;
	glContextSettings.antialiasingLevel = antiAliasLevel;
	glContextSettings.depthBits = 24;

	gConfig = GameConfig(windowWidth, windowHeight, maxFPS, antiAliasLevel, mouseSensitivity, windowTitle, glContextSettings);
}

GameConfig ConfigManager::getConfig()
{
	return gConfig;
}

}


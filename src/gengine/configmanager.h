/*
 * configmanager.h
 *
 *  Created on: Oct 11, 2015
 *      Author: wsmith
 */

#include "gameconfig.h"

#ifndef CONFIGMANAGER_H_
#define CONFIGMANAGER_H_

namespace gengine
{
class ConfigManager
{
private:
	ConfigManager(); // class is static
	static GameConfig gConfig;
public:
	static void loadConfig();
	static GameConfig getConfig();
};
}


#endif /* CONFIGMANAGER_H_ */

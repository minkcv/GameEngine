/*
 * menu.h
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */


#ifndef PAUSEMENU_H_
#define PAUSEMENU_H_

#include "interactive.h"

namespace interactive
{
	class PauseMenu : public Interactive
	{
	public:
		PauseMenu();
		void update(double deltaT);
		void render();
		~PauseMenu();
	};
}

#endif /* MENU_H_ */

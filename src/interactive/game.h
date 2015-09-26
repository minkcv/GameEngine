/*
 * game.h
 *
 *  Created on: Aug 31, 2015
 *      Author: wsmith
 */

#include "../gelements/camera.h"
#include "../gelements/axes3d.h"

#ifndef GAME_H_
#define GAME_H_

#include "interactive.h"
#include <SFML/Window.hpp>

using namespace gelements;

namespace interactive
{
	class Game : public Interactive
	{
	private:
		Camera camera;
		Axes3D axes;
	public:
		Game(sf::Window* window);
		void update(double deltaT);
		void render();
		~Game();
	};
}

#endif /* GAME_H_ */

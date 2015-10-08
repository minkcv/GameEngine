/*
 * game.h
 *
 *  Created on: Aug 31, 2015
 *      Author: wsmith
 */

#include "../gelements/camera.h"
#include "../gelements/axes3d.h"
#include "../gengine/gamestack.h"

#ifndef GAME_H_
#define GAME_H_

#include "interactive.h"
#include "interactivemanager.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace gelements;
using namespace gengine;

namespace interactive
{
	class InteractiveManager; // forward declaration because of circular dependency

	class Game : public Interactive
	{
	private:
		InteractiveManager* iManager;
		GameStack* gStack;
		Camera camera;
		Axes3D axes;
		sf::Image image;
		sf::Image* image2;
		GLuint texture_handle;
	public:
		Game(InteractiveManager* iManager);
		void update(double deltaT);
		void render();
		~Game();
	};
}

#endif /* GAME_H_ */

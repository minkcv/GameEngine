/*
 * game.h
 *
 *  Created on: Aug 31, 2015
 *      Author: wsmith
 */

#include "../gelements/camera.h"
#include "../gelements/axes3d.h"
#include "../gelements/box.h"
#include "../gelements/pyramid.h"
#include "../gelements/sphere.h"
#include "../gelements/uvsphere.h"
#include "../gengine/gamestack.h"
#include "../gengine/gameconfig.h"
#include "../gengine/windowmanager.h"

#ifndef GAME_H_
#define GAME_H_

#include "interactive.h"
#include "interactivemanager.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace gelements;
using namespace gengine;


class InteractiveManager; // forward declaration because of circular dependency

class Game : public Interactive
{
private:
	InteractiveManager* iManager;
	WindowManager* wManager;
	GameConfig gConfig;
	GameStack* gStack;
	Camera camera;
	Axes3D axes;
	Box* box;
	Pyramid* pyramid;
	Sphere* sphere;
	UVSphere* uvSphere;
	sf::Image image;
	sf::Image* image2;
	GLuint texture_handle;
	float aspectRatio;
public:
	Game(InteractiveManager* iManager, WindowManager* wManager);
	void update(double deltaT);
	void render();
	~Game();
};


#endif /* GAME_H_ */

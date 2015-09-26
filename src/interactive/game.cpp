/*
 * game.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: wsmith
 */


#include "game.h"
#include <SFML/OpenGL.hpp>


namespace interactive
{

	Game::Game(sf::Window* window)
	{
		camera.setWindow(window);
	}


	void Game::update(double deltaT)
	{
		camera.update(deltaT);
	}

	void Game::render()
	{
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90.0 / 2, 800.0/600.0, 1.0, 50.0);
//		glOrtho(-10, 10, -10, 10, -10, 10);
		//glFrustum(-1, 1, -1, 1, 0.1, 5);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		camera.transform();

		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
		{
			glVertex3f(0.0f, 0.0f, 1.0f);
			glVertex3f(10.0f, 0.0f, 1.0f);
			glVertex3f(10.0f, 10.0f, 1.0f);
			glVertex3f(0.0f, 10.0f, 1.0f);
		}
		glEnd();
		axes.render();
	}

	Game::~Game()
	{

	}
}

/*
 * game.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: wsmith
 */


#include "game.h"
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

namespace interactive
{
Game::Game(InteractiveManager* iManager)
{
	this->iManager = iManager;
	gStack = iManager->getGameStack();
	camera.setWindow(iManager->getWindow());
	void* imagePtr = gStack->push(sizeof(sf::Image));
	image2 = new(imagePtr) sf::Image();
	if(!image2->loadFromFile("resources/image.png")){
		printf("error loading image\n");
	}
	if(!image.loadFromFile("resources/image.png")){
		printf("error loading image\n");
	}
	glGenTextures(1, &texture_handle);
	glBindTexture(GL_TEXTURE_2D, texture_handle);
	int width = image.getSize().x;
	int height = image.getSize().y;
	glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RGBA,
			width, height,
			0,
			GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr()
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	void* boxPtr = gStack->push(sizeof(Box));
	box = new(boxPtr) Box(10, 4, 3, 4, 5, 2);
	void* pyramidPtr = gStack->push(sizeof(Pyramid));
	pyramid = new(pyramidPtr) Pyramid(4, 0, 10, 4, 4);
	void* spherePtr = gStack->push(sizeof(Sphere));
	sphere = new(spherePtr) Sphere(-5, 0, 5, 5);
	void* uvSpherePtr = gStack->push(sizeof(UVSphere));
	uvSphere = new(uvSpherePtr) UVSphere(-50, 0, -5, 2, 20);
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
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0 / 2, 800.0/600.0, 1.0, 50.0);
	//glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera.transform();

	glColor3f(1.0f, 1.0f, 0.5f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_handle);

	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(10.0f, 0.0f, 1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(10.0f, 10.0f, 1.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.0f, 10.0f, 1.0f);
	}
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	axes.render();
	box->render();
	pyramid->render();
	sphere->render();
	uvSphere->render();
}

Game::~Game()
{
	box = nullptr;
	pyramid = nullptr;
	image2 = nullptr;
}
}

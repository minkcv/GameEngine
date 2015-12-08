/*
 * game.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: wsmith
 */


#include "game.h"
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "../gengine/configmanager.h"

Game::Game(InteractiveManager* iManager, WindowManager* wManager, PhysicsManager* pManager)
: objMesh(-5, 0, -13), pBox(10, 10, 10, 5, 5, 5), pBox2(10, 20, 18, 4, 4, 4), light0(0, 20, 0, GL_LIGHT0)
{
	this->iManager = iManager;
	this->wManager = wManager;
	this->pManager = pManager;
	gStack = iManager->getGameStack();
	gConfig = ConfigManager::getConfig();
	camera.setWindow(wManager->getWindow());
	aspectRatio = (float)(gConfig.getWindowWidth()) / (float)(gConfig.getWindowHeight());
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
	uvSphere = new(uvSpherePtr) UVSphere(0, 20, 0, 2, 20);

	//	objMesh.loadObj("resources/complex.obj");
	pManager->addPhysicsBox(&pBox);
	pManager->addPhysicsBox(&pBox2);
}

void Game::update(double deltaT)
{
	camera.update(deltaT);
	pManager->update();
	//TODO remove memory leak here
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
		PhysicsBox* pb = new PhysicsBox(camera.getX(), camera.getY(), camera.getZ(), 1.f, 1.f, 1.f);
		pBoxes.push_back(pb);
		pManager->addPhysicsBox(pb);
		float xRotation = camera.getXRotation();
		float xVelocity = 0;
		float zVelocity = 0;
		float xRotationRadians = xRotation * M_PI / 180.0f;
		xVelocity += 200 * sin(xRotationRadians);
		zVelocity -= 200 * cos(xRotationRadians);
		pb->applyCentralImpulse(xVelocity, 0, zVelocity);
	}
}

void Game::render()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0 / 2, aspectRatio, 1.0, 150.0);
	//glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// flashlight occurs before camera transform because flashlight always points forward
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
		float lightAmbient[4]   = {0.0f, 0.0f, 0.0f, 1.0f};
		float lightDiffuse[4]   = {1.0f, 1.0f, 1.0f, 1.0f};
		float lightSpecular[4]  = {1.0f, 1.0f, 1.0f, 1.0f};
		float lightPosition[4]  = {0.0f, 0.0f, 0.0, 1.0f};
		float lightDirection[4] = {0.0f, 0.0f, 1.0f, 0.0f};

		glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
		glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 15.f);

		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

		glShadeModel(GL_FLAT);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
	}
	else {
		glDisable(GL_LIGHT1);
	}

	camera.transform();

	//	glColor3f(1.0f, 1.0f, 0.5f);
	//	glEnable(GL_TEXTURE_2D);
	//	glBindTexture(GL_TEXTURE_2D, texture_handle);
	//
	//	glBegin(GL_QUADS);
	//	{
	//		glTexCoord2f(0.0f, 0.0f);
	//		glVertex3f(0.0f, 0.0f, 1.0f);
	//
	//		glTexCoord2f(1.0f, 0.0f);
	//		glVertex3f(10.0f, 0.0f, 1.0f);
	//
	//		glTexCoord2f(1.0f, 1.0f);
	//		glVertex3f(10.0f, 10.0f, 1.0f);
	//
	//		glTexCoord2f(0.0f, 1.0f);
	//		glVertex3f(0.0f, 10.0f, 1.0f);
	//	}
	//	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);



	axes.render();
	glColor3f(.5, .5, .5);
	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS);
	{
		glVertex3f(-50, -8, -50);
		glVertex3f(-50, -8, 50);
		glVertex3f(50, -8, 50);
		glVertex3f(50, -8, -50);
	}
	glEnd();
	//pManager->debugDrawWorld();
	//box->render();
	//sphere->render();
	//pyramid->render();
	uvSphere->render();
	//objMesh.render();
	pBox.render();
	pBox2.render();
	for (unsigned i = 0; i < pBoxes.size(); i++)
	{
		PhysicsBox* pb = pBoxes[i];
		pb->render();
	}
	light0.render();
}

Game::~Game()
{
	box = nullptr;
	pyramid = nullptr;
	for (unsigned i = 0; i < pBoxes.size(); i++)
	{
		delete pBoxes[i];
	}
}

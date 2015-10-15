/*
 * menu.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */

#include "mainmenu.h"
#include <SFML/OpenGL.hpp>

MainMenu::MainMenu(InteractiveManager* iManager, WindowManager* wManager)
{
	this->wManager = wManager;
	this->iManager = iManager;
	this->gStack = iManager->getGameStack();
	if (!font.loadFromFile("resources/DejaVuSansMono.ttf"))
	{
		printf("error loading font\n");
	}
	text.setFont(font);
	text.setString("Press Enter\n\n Move with WASD, Ctrl, Space");
	text.setCharacterSize(24);
	text.setColor(sf::Color::White);
	text.setPosition(40, 40);
}

void MainMenu::update(double deltaT)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		iManager->startGame();
}

void MainMenu::render()
{
	sf::Image image;
	image.loadFromFile("resources/image.png");
	sf::Texture texture;
	texture.loadFromImage(image);
	glClearColor(0, 0, 0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	sf::Texture::bind(&texture);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-5.0f, -5.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-5.0f, 5.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(5.0f, 5.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(5.0f, -5.0f, 0.0f);
	}
	glEnd();
	sf::Texture::bind(NULL);
	wManager->getWindow()->pushGLStates();
	wManager->getWindow()->draw(text);
	wManager->getWindow()->popGLStates();
}

MainMenu::~MainMenu()
{

}


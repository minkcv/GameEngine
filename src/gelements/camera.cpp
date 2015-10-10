/*
 * Camera.cpp
 *
 *  Created on: Sep 25, 2015
 *      Author: wsmith
 */

#include "camera.h"
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

namespace gelements
{
Camera::Camera()
{
	x = 0;
	y = 0;
	z = 0;
	xVelocity = 0;
	yVelocity = 0;
	zVelocity = 0;
	xRotation = 0;
	yRotation = 0;
	moveSpeed = baseMoveSpeed;
	oldMouseX = 0;
	oldMouseY = 0;
	mousedx = 0;
	mousedy = 0;
	window = nullptr;
}

void Camera::update(double deltaT)
{
	xVelocity = 0;
	yVelocity = 0;
	zVelocity = 0;

	sf::Vector2i windowPosition = sf::Mouse::getPosition(*window);
	mousedx = 400 - windowPosition.x;
	mousedy = 300 - windowPosition.y;

	oldMouseX = windowPosition.x;
	oldMouseY = windowPosition.y;
	sf::Vector2i zero(400, 300);
	sf::Mouse::setPosition(zero, *window);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		moveSpeed = fastMoveSpeed;
	else
		moveSpeed = baseMoveSpeed;

	//moveSpeed *= deltaT; // make movespeed independent of fps
	float xRotationRadians = xRotation * M_PI / 180.0f;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		xVelocity += moveSpeed * sin(xRotationRadians);
		zVelocity -= moveSpeed * cos(xRotationRadians);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		xVelocity -= moveSpeed * sin(xRotationRadians);
		zVelocity += moveSpeed * cos(xRotationRadians);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		xVelocity -= moveSpeed * cos(xRotationRadians);
		zVelocity -= moveSpeed * sin(xRotationRadians);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		xVelocity += moveSpeed * cos(xRotationRadians);
		zVelocity += moveSpeed * sin(xRotationRadians);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		yVelocity += moveSpeed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
		yVelocity -= moveSpeed;
	}

	x += xVelocity;
	y += yVelocity;
	z += zVelocity;

	xRotation += -mousedx * mouseSensitivity;
	yRotation += -mousedy * mouseSensitivity;

	//normalize x rotation to between 0 and 360
	if(xRotation > 360)
		xRotation -= 360;
	else if(xRotation < 0)
		xRotation += 360;

	//limit y rotation at top and bottom
	if(yRotation > 90)
		yRotation = 90;
	else if(yRotation < -90)
		yRotation = -90;

//			printf("xy rotation: %f %f\n", xRotation, yRotation);
//			printf("xyz pos: %f, %f, %f\n", x, y, z);
}

void Camera::transform()
{
	glRotatef(yRotation, 1, 0, 0);
	glRotatef(xRotation, 0, 1, 0);
	glTranslatef(-x, -y, -z);
}

void Camera::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}

Camera::~Camera()
{
	window = nullptr;
}
}

/*
 * pyramid.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#include "pyramid.h"
#include <SFML/OpenGL.hpp>
#include <stdio.h>

namespace gelements
{
Pyramid::Pyramid(float x, float y, float z,
		float l, float h)
		: GameObject(x, y, z), length(l), height(h)
{
	center = length / 2;
}

void Pyramid::update(double deltaT)
{

}

void Pyramid::render()
{
	glTranslatef(position.getX(), position.getY(), position.getZ());
	glBegin(GL_TRIANGLES);
	{
		//base
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, length);
		glVertex3f(length, 0, length);

		glVertex3f(0, 0, 0);
		glVertex3f(length, 0, 0);
		glVertex3f(length, 0, length);

		//sides
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, length);
		glVertex3f(center, height, center);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(length, 0, 0);
		glVertex3f(center, height, center);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, length);
		glVertex3f(length, 0, length);
		glVertex3f(center, height, center);

		glColor3f(1, 0, 0);
		glVertex3f(length, 0, 0);
		glVertex3f(length, 0, length);
		glVertex3f(center, height, center);
	}
	glEnd();
	glTranslatef(-position.getX(), -position.getY(), -position.getZ());
}

Pyramid::~Pyramid()
{
}
}


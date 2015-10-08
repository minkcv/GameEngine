/*
 * Box.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#include "box.h"
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

namespace gelements
{
Box::Box(float x, float y, float z,
		 float w, float h, float d)
		: x(x), y(y), z(z), width(w), height(h), depth(d)
{

}

void Box::update(double deltaT)
{

}
void Box::render()
{
	glTranslatef(x, y, z);
	glBegin(GL_QUADS);
	{
		glVertex3f(0, 0, 0);
		glVertex3f(0, depth, 0);
		glVertex3f(width, depth, 0);
		glVertex3f(width, 0, 0);

		glVertex3f(0, 0, 0);
		glVertex3f(width, 0, 0);
		glVertex3f(width, 0, height);
		glVertex3f(0, 0, height);

		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, height);
		glVertex3f(0, depth, height);
		glVertex3f(0, depth, 0);

		glVertex3f(width, depth, height);
		glVertex3f(0, depth, height);
		glVertex3f(0, 0, height);
		glVertex3f(width, 0, height);

		glVertex3f(width, depth, height);
		glVertex3f(width, depth, 0);
		glVertex3f(0, depth, 0);
		glVertex3f(0, depth, height);

		glVertex3f(width, depth, height);
		glVertex3f(width, 0, height);
		glVertex3f(width, 0, 0);
		glVertex3f(width, depth, 0);
	}
	glEnd();
	glTranslatef(-x, -y, -z);
}
}

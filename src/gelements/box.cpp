/*
 * box.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#include "box.h"
#include "../gmath/point3.h"
#include <SFML/OpenGL.hpp>

using namespace gmath;

namespace gelements
{
Box::Box(float x, float y, float z,
		 float w, float h, float d)
		: GameObject(x, y, z), width(w), height(h), depth(d)
{
}

void Box::update(double deltaT)
{

}
void Box::render()
{
	glTranslatef(position.getX(), position.getY(), position.getZ());
	glBegin(GL_QUADS);
	{
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, depth, 0);
		glVertex3f(width, depth, 0);
		glVertex3f(width, 0, 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(width, 0, 0);
		glVertex3f(width, 0, height);
		glVertex3f(0, 0, height);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, height);
		glVertex3f(0, depth, height);
		glVertex3f(0, depth, 0);

		glColor3f(1, 0, 0);
		glVertex3f(width, depth, height);
		glVertex3f(0, depth, height);
		glVertex3f(0, 0, height);
		glVertex3f(width, 0, height);

		glColor3f(0, 1, 0);
		glVertex3f(width, depth, height);
		glVertex3f(width, depth, 0);
		glVertex3f(0, depth, 0);
		glVertex3f(0, depth, height);

		glColor3f(0, 0, 1);
		glVertex3f(width, depth, height);
		glVertex3f(width, 0, height);
		glVertex3f(width, 0, 0);
		glVertex3f(width, depth, 0);
	}
	glEnd();
	glTranslatef(-position.getX(), -position.getY(), -position.getZ());
}
Box::~Box()
{
}
}

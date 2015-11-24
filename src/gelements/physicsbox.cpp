/*
 * physicsbox.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: wsmith
 */

#include "physicsbox.h"
#include "../gmath/point3.h"
#include <SFML/OpenGL.hpp>

using namespace gmath;

namespace gelements
{
PhysicsBox::PhysicsBox(float x, float y, float z, float w, float h, float d)
	: GameObject(x, y, z), width(w), height(h), depth(d), mass(1.0f)
{

}

void PhysicsBox::update(double deltaT)
{

}

void PhysicsBox::render()
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

float PhysicsBox::getWidth() { return width; }
float PhysicsBox::getHeight() { return height; }
float PhysicsBox::getDepth() { return depth; }
float PhysicsBox::getMass() { return mass; }

PhysicsBox::~PhysicsBox()
{

}
}


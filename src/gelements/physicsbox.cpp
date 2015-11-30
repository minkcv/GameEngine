/*
 * physicsbox.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: wsmith
 */

#include "physicsbox.h"
#include "../gmath/point3.h"
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace gmath;

namespace gelements
{
PhysicsBox::PhysicsBox(float x, float y, float z, float w, float h, float d)
: GameObject(x, y, z), width(w), height(h), depth(d), mass(10.0f), rigidBody(nullptr)
{

}

void PhysicsBox::update(double deltaT)
{

}

void PhysicsBox::render()
{
	glTranslatef(position.getX(), position.getY(), position.getZ());
	glMultMatrixf(glm::value_ptr(glm::mat4_cast(rotation)));
	glBegin(GL_QUADS);
	{
		glColor3f(1, 0, 0);
		glVertex3f(-width, -depth, -height);
		glVertex3f(-width, depth, -height);
		glVertex3f(width, depth, -height);
		glVertex3f(width, -depth, -height);

		glColor3f(0, 1, 0);
		glVertex3f(-width, -depth, -height);
		glVertex3f(width, -depth, -height);
		glVertex3f(width, -depth, height);
		glVertex3f(-width, -depth, height);

		glColor3f(0, 0, 1);
		glVertex3f(-width, -depth, -height);
		glVertex3f(-width, -depth, height);
		glVertex3f(-width, depth, height);
		glVertex3f(-width, depth, -height);

		glColor3f(1, 0, 0);
		glVertex3f(width, depth, height);
		glVertex3f(-width, depth, height);
		glVertex3f(-width, -depth, height);
		glVertex3f(width, -depth, height);

		glColor3f(0, 1, 0);
		glVertex3f(width, depth, height);
		glVertex3f(width, depth, -height);
		glVertex3f(-width, depth, -height);
		glVertex3f(-width, depth, height);

		glColor3f(0, 0, 1);
		glVertex3f(width, depth, height);
		glVertex3f(width, -depth, height);
		glVertex3f(width, -depth, -height);
		glVertex3f(width, depth, -height);
	}
	glEnd();
	glMultTransposeMatrixf(glm::value_ptr(glm::mat4_cast(rotation)));
	glTranslatef(-position.getX(), -position.getY(), -position.getZ());
}

void PhysicsBox::applyCentralImpulse(float x, float y, float z)
{
	rigidBody->applyCentralImpulse(btVector3(x, y, z));
}

void PhysicsBox::setRigidBody(btRigidBody* rb)
{
	rigidBody = rb;
}

float PhysicsBox::getWidth() { return width; }
float PhysicsBox::getHeight() { return height; }
float PhysicsBox::getDepth() { return depth; }
float PhysicsBox::getMass() { return mass; }

PhysicsBox::~PhysicsBox()
{

}
}


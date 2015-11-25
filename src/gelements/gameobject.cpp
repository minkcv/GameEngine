/*
 * gameobject.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: wsmith
 */

#include "gameobject.h"

namespace gelements
{
GameObject::GameObject(float x, float y, float z) : position(x, y, z), rotation(0, 0, 0, 1)
{
}

void GameObject::setPosition(float x, float y, float z)
{
	position = Point3<float>(x, y, z);
}

void GameObject::setRotation(glm::quat rotation)
{
	this->rotation = rotation;
}

float GameObject::getX()
{
	return position.getX();
}

float GameObject::getY()
{
	return position.getY();
}

float GameObject::getZ()
{
	return position.getZ();
}
}


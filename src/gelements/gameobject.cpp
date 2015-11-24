/*
 * gameobject.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: wsmith
 */

#include "gameobject.h"

namespace gelements
{
GameObject::GameObject(float x, float y, float z) : position(x, y, z)
{
}

void GameObject::setPosition(float x, float y, float z)
{
	position = Point3<float>(x, y, z);
}
}


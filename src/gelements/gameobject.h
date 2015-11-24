/*
 * gameobject.h
 *
 *  Created on: Oct 12, 2015
 *      Author: wsmith
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "../gmath/point3.h"
#include "updateable.h"
#include "renderable.h"

using namespace gmath;

namespace gelements
{
class GameObject : public Updateable, public Renderable
{
public:
	GameObject(float x, float y, float z);
	void setPosition(float x, float y, float z);
protected:
	Point3<float> position;
};
}

#endif /* GAMEOBJECT_H_ */

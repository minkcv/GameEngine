/*
 * physicsbox.h
 *
 *  Created on: Nov 23, 2015
 *      Author: wsmith
 */

#ifndef PHYSICSBOX_H_
#define PHYSICSBOX_H_

#include "gameobject.h"
#include "btBulletDynamicsCommon.h"

namespace gelements
{
class PhysicsBox : public GameObject
{
private:
	float width, height, depth;
	float mass;
	btRigidBody* rigidBody;
public:
	PhysicsBox(float x, float y, float z,
			   float w, float h, float d);
	void update(double deltaT);
	void render();
	void applyCentralImpulse(float x, float y, float z);
	void setRigidBody(btRigidBody* rb);
	float getWidth();
	float getHeight();
	float getDepth();
	float getMass();
	~PhysicsBox();
};
}



#endif /* PHYSICSBOX_H_ */

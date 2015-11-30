/*
 * physicsmanager.h
 *
 *  Created on: Oct 30, 2015
 *      Author: wsmith
 */

#ifndef PHYSICSMANAGER_H_
#define PHYSICSMANAGER_H_

#include "btBulletDynamicsCommon.h"
#include "../gelements/physicsbox.h"

using namespace gelements;

namespace gengine
{
class PhysicsManager
{
private:
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;
	btCollisionShape* groundShape;
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
public:
	PhysicsManager();
	void testPhysics();
	void addPhysicsBox(PhysicsBox* pb);
	void update();
	void debugDrawWorld();
	void cleanup();
};
}



#endif /* PHYSICSMANAGER_H_ */

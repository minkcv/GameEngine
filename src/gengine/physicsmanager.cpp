/*
 * physicsmanager.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: wsmith
 */

#include "physicsmanager.h"
#include "btBulletDynamicsCommon.h"
#include "gamemotionstate.hpp"
#include "physicsdebugdrawer.hpp"

namespace gengine
{
PhysicsManager::PhysicsManager()
{
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,
			overlappingPairCache, solver, collisionConfiguration);

	dynamicsWorld->setGravity(btVector3(0, -10, 0));

	PhysicsDebugDrawer* debugDrawer = new PhysicsDebugDrawer();
	dynamicsWorld->setDebugDrawer(debugDrawer);
	dynamicsWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawAabb);

	//create test shapes and rigid bodies
	groundShape = new btBoxShape(btVector3(50, 2, 50));
	collisionShapes.push_back(groundShape);
	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(0,-10,0));
	{
		btScalar mass(0.);

		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		bool isDynamic = (mass != 0.f);

		btVector3 localInertia(0,0,0);
		if (isDynamic)
			groundShape->calculateLocalInertia(mass,localInertia);

		//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
		//TODO keep a vector of motionstates and free them
		btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,groundShape,localInertia);
		btRigidBody* body = new btRigidBody(rbInfo);

		//add the body to the dynamics world
		dynamicsWorld->addRigidBody(body);
	}
}

//create a dynamic rigidbody
void PhysicsManager::addPhysicsBox(PhysicsBox* pb)
{
	btCollisionShape* colShape = new btBoxShape(btVector3(pb->getWidth(), pb->getHeight(), pb->getDepth()));
	collisionShapes.push_back(colShape);

	/// Create Dynamic Objects
	btTransform startTransform;
	startTransform.setIdentity();

	btScalar	mass(pb->getMass());

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0,0,0);
	if (isDynamic)
		colShape->calculateLocalInertia(mass,localInertia);

	startTransform.setOrigin(btVector3(pb->getX(), pb->getY(), pb->getZ()));

	//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	btMotionState* motionState = new GameMotionState(startTransform, pb);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,motionState,colShape,localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);

	dynamicsWorld->addRigidBody(body);
	pb->setRigidBody(body);
}

void PhysicsManager::update()
{
	dynamicsWorld->stepSimulation(1.f/30.f, 10);
}

void PhysicsManager::debugDrawWorld()
{
	dynamicsWorld->debugDrawWorld();
}

void PhysicsManager::cleanup()
{
	for(int i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--){
		btCollisionObject * obj = dynamicsWorld->getCollisionObjectArray () [i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if(body && body->getMotionState()){
			delete body->getMotionState();
		}
		dynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	delete dynamicsWorld;
	delete overlappingPairCache;
	delete dispatcher;
	delete collisionConfiguration;
	collisionShapes.clear();
}
}


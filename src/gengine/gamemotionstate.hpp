/*
 * gamemotionstate.hpp
 *
 *  Created on: Nov 23, 2015
 *      Author: wsmith
 */

#ifndef GAMEMOTIONSTATE_HPP_
#define GAMEMOTIONSTATE_HPP_

#include "btBulletDynamicsCommon.h"
#include "../gelements/gameobject.h"

using namespace gelements;

namespace gengine
{
class GameMotionState : public btMotionState
{
private:
	btTransform initialTransform;
	GameObject* gObject;
public:
	GameMotionState(const btTransform& initialTransform, GameObject* gObject)
: initialTransform(initialTransform), gObject(gObject)
{

}

	virtual void setWorldTransform(const btTransform& worldTransform)
	{
		if(gObject == nullptr)
			return;

		btVector3 position = worldTransform.getOrigin();
		gObject->setPosition(position.getX(), position.getY(), position.getZ());
	}

	virtual void getWorldTransform(btTransform& worldTransform) const
	{
		worldTransform = initialTransform;
	}

	virtual ~GameMotionState()
	{

	}
};
}

#endif /* GAMEMOTIONSTATE_HPP_ */

/*
 * physicsdebugdrawer.hpp
 *
 *  Created on: Nov 25, 2015
 *      Author: wsmith
 */

#ifndef PHYSICSDEBUGDRAWER_HPP_
#define PHYSICSDEBUGDRAWER_HPP_

#include "btBulletDynamicsCommon.h"
#include <SFML/OpenGL.hpp>

namespace gengine
{
class PhysicsDebugDrawer : public btIDebugDraw
{
private:
	int debugMode;
public:

	virtual void drawLine(const btVector3& from,const btVector3& to,const btVector3& color)
	{
		glColor3f(color.getX(), color.getY(), color.getZ());
		glBegin(GL_LINES);
		{
			glVertex3f(from.getX(), from.getY(), from.getZ());
			glVertex3f(to.getX(), to.getY(), to.getZ());
		}
		glEnd();
	}

	virtual void draw3dText(const btVector3& location, const char * textString)
	{

	}

	virtual void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifetTime, const btVector3& color)
	{

	}

	virtual void reportErrorWarning(const char* warningString)
	{
		printf("warning: %s\n", warningString);
	}

	virtual int getDebugMode() const
	{
		return debugMode;
	}

	virtual void setDebugMode(int debugMode)
	{
		this->debugMode = debugMode;
	}
};
}

#endif /* PHYSICSDEBUGDRAWER_HPP_ */

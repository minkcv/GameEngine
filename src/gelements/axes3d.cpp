/*
 * axes3d.cpp
 *
 *  Created on: Sep 25, 2015
 *      Author: wsmith
 */

#include "axes3d.h"
#include <SFML/OpenGL.hpp>

namespace gelements
{
	Axes3D::Axes3D()
	{

	}

	void Axes3D::render()
	{
		glColor3f(1, 0, 0);
		glBegin(GL_LINES);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(1, 0, 0);
		}
		glEnd();

		glColor3f(0, 1, 0);
		glBegin(GL_LINES);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(0, 1, 0);
		}
		glEnd();

		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 1);
		}
		glEnd();
	}
	Axes3D::~Axes3D()
	{

	}
}



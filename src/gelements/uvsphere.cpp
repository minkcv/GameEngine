/*
 * uvsphere.cpp
 *
 *  Created on: Oct 9, 2015
 *      Author: wsmith
 */

#include "uvsphere.h"
#include <math.h>
#include <SFML/OpenGL.hpp>
#include <stdio.h>

namespace gelements
{
UVSphere::UVSphere(float x, float y, float z, float radius, float angleDelta)
: x(x), y(y), z(z), radius(radius), angleDelta(angleDelta)
{
}

void UVSphere::update(double deltaT)
{

}

void UVSphere::render()
{
	glRotatef(90, 1, 0, 0);
	glTranslatef(x, y, z);
	double thetarplusdelta;
	double c=3.141592654/180.0;
	double x1,y1,z1,phi0;
	phi0=60;
	glColor3f(0, 0, 1);
	glBegin(GL_QUAD_STRIP);
	for (double phi=-phi0; phi<phi0; phi+=angleDelta) {
		double phir=c*phi; //Phi in radians
		double phirplusdelta=c*(phi+angleDelta);
		for (double theta=0; theta<=360; theta+=angleDelta) {
			double thetar=c*theta;
			x1=radius*sin(thetar)*cos(phir);
			y1=radius*cos(thetar)*cos(phir);
			z1=radius*sin(phir);
			glVertex3d(x1, y1, z1);
			//Complete quad
			x1=radius*sin(thetar)*cos(phirplusdelta);
			y1=radius*cos(thetar)*cos(phirplusdelta);
			z1=radius*sin(phirplusdelta);
			glVertex3d(x1, y1, z1);
		}
	}
	glEnd();

	//bottom
	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0,0,radius); //Initial point
	z1=radius * sin(c*phi0);
	for (double theta=-180; theta<=180; theta+=angleDelta){
		double thetar=c*theta;
		x1=radius * sin(thetar)*cos(c*phi0);
		y1=radius * cos(thetar)*cos(c*phi0);
		glVertex3d(x1,y1,z1);
	}
	glEnd();

	//top
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0,0,-radius); //Initial point
	z1=-radius * sin(c*phi0);
	for (double theta=-180; theta<=180; theta+=angleDelta){
		double thetar=c*theta;
		x1=radius * sin(thetar)*cos(c*phi0);
		y1=radius * cos(thetar)*cos(c*phi0);
		glVertex3d(x1,y1,z1);
	}
	glEnd();
	glTranslatef(-x, -y, -z);
	glRotatef(-90, 1, 0, 0);
}
}

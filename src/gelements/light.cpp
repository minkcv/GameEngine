/*
 * light.cpp
 *
 *  Created on: Dec 4, 2015
 *      Author: wsmith
 */


#include "light.h"
#include <stdio.h>

namespace gelements
{
Light::Light(float x, float y, float z, GLint lightId)
: lightId(lightId)
{
	lightPosition[0] = x;
	lightPosition[1] = y;
	lightPosition[2] = z;
	lightPosition[3] = 1; // 1 = positional light, 0 = infinite
}

void Light::render()
{
	glLightfv(lightId, GL_AMBIENT, lightAmbient);
	glLightfv(lightId, GL_DIFFUSE, lightDiffuse);
	glLightfv(lightId, GL_SPECULAR, lightSpecular);

	float mat_specular[4]   = {1.0f, 1.0f, 1.0f, 1.0f};
	float mat_diffuse[4]    = {1.0f, 0.0f, 0.0f, 1.0f};
	float mat_ambient[4]    = {1.0f, 0.0f, 0.0f, 1.0f};
	float mat_shininess[1]  = {64.0f};

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(lightId, GL_POSITION, lightPosition);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(lightId);
}

Light::~Light()
{

}

}

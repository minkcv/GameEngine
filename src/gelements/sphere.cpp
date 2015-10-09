/*
 * sphere.cpp
 *
 *  Created on: Oct 9, 2015
 *      Author: wsmith
 */

#include "sphere.h"
#include <math.h>
#include <SFML/OpenGL.hpp>

namespace gelements
{
Sphere::Sphere(float x, float y, float z, int recursions) : x(x), y(y), z(z), recursions(recursions)
{

}

void Sphere::divideTriangle(float a[3], float b[3], float c[3], int m)
{
	float v1[3];
	float v2[3];
	float v3[3];

	if (m > 0)
	{
		for(int j = 0; j < 3; j++) v1[j] = a[j] + b[j];
		normalize(v1);
		for(int j = 0; j < 3; j++) v2[j] = a[j] + c[j];
		normalize(v2);
		for(int j = 0; j < 3; j++) v3[j] = b[j] + c[j];
		normalize(v3);
		divideTriangle(a, v1, v2, m-1);
		divideTriangle(c, v2, v3, m-1);
		divideTriangle(b, v3, v1, m-1);
		divideTriangle(v1, v3, v2, m-1);
	}
	else{
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		{
			glVertex3f(a[0], a[1], a[2]);
			glVertex3f(b[0], b[1], b[2]);
			glVertex3f(c[0], c[1], c[2]);
		}
		glEnd();
		glColor3f(0, 0, 1);
		glBegin(GL_LINE_LOOP);
		{
			glVertex3f(a[0], a[1], a[2]);
			glVertex3f(b[0], b[1], b[2]);
			glVertex3f(c[0], c[1], c[2]);
		}
		glEnd();
	}
}

void Sphere::normalize(float p[3])
{
	float d = 0.0f;

	for (int i = 0; i < 3; i++) d += p[i] * p[i];
	d = (float) sqrt(d);
	if(d > 0.0f) for (int i = 0; i < 3; i++) p[i] /= d;
}

void Sphere::update(double deltaT)
{

}

void Sphere::render()
{
	glTranslatef(x, y, z);
	divideTriangle(baseTetrahedron[0], baseTetrahedron[1], baseTetrahedron[2], recursions);
	divideTriangle(baseTetrahedron[3], baseTetrahedron[2], baseTetrahedron[1], recursions);
	divideTriangle(baseTetrahedron[0], baseTetrahedron[3], baseTetrahedron[1], recursions);
	divideTriangle(baseTetrahedron[0], baseTetrahedron[2], baseTetrahedron[3], recursions);
	glTranslatef(-x, -y, -z);
}
}



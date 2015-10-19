/*
 * sphere.h
 *
 *  Created on: Oct 9, 2015
 *      Author: wsmith
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "gameobject.h"

namespace gelements
{
class Sphere : protected GameObject
{
private:
	int recursions;
	void divideTriangle(const float a[3], const float b[3], const float c[3], int m);
	void normalize(float p[3]);
public:
	static float const baseTetrahedron[4][3]; // initialized in source file
	Sphere(float x, float y, float z, int recursions);
	void update(double deltaT);
	void render();
};
}
#endif /* SPHERE_H_ */

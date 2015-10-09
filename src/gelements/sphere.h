/*
 * sphere.h
 *
 *  Created on: Oct 9, 2015
 *      Author: wsmith
 */

#ifndef SPHERE_H_
#define SPHERE_H_

namespace gelements
{
class Sphere
{
private:
	float x, y, z;
	int recursions;
	float baseTetrahedron[4][3] = {
			{0.0f, 0.0f, 1.0f},
			{0.0f, 0.942809f, -0.33333f},
			{-0.816497f, -0.471405f, -0.333333f},
			{0.816497f, -0.471405f, -0.333333f}
	};
	void divideTriangle(float a[3], float b[3], float c[3], int m);
	void normalize(float p[3]);
public:
	Sphere(float x, float y, float z, int recursions);
	void update(double deltaT);
	void render();
};
}



#endif /* SPHERE_H_ */

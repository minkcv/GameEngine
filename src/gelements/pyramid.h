/*
 * pyramid.h
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#ifndef PYRAMID_H_
#define PYRAMID_H_

namespace gelements
{
class Pyramid
{
private:
	float x, y, z;
	float center;
	float length;
	float height;
public:
	Pyramid(float x, float y, float z,
			float l, float h);
	void update(double deltaT);
	void render();
	~Pyramid();
};
}



#endif /* PYRAMID_H_ */

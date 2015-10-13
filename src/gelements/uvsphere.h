/*
 * uvsphere.h
 *
 *  Created on: Oct 9, 2015
 *      Author: wsmith
 */

#ifndef UVSPHERE_H_
#define UVSPHERE_H_

#include "gameobject.h"

namespace gelements
{
class UVSphere : protected GameObject
{
private:
	float radius;
	float angleDelta;
public:
	UVSphere(float x, float y, float z, float radius, float angleDelta);
	void update(double deltaT);
	void render();
	~UVSphere();
};
}

#endif /* UVSPHERE_H_ */

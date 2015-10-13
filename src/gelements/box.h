/*
 * box.h
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#ifndef BOX_H_
#define BOX_H_

#include "gameobject.h"

namespace gelements
{
class Box : protected GameObject
{
private:
	float width, height, depth;
public:
	Box(float x, float y, float z,
		float w, float h, float d);
	void update(double deltaT);
	void render();
	~Box();
};
}



#endif /* BOX_H_ */

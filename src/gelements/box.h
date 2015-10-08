/*
 * box.h
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#ifndef BOX_H_
#define BOX_H_

namespace gelements
{
class Box
{
private:
	float x, y, z;
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

/*
 * light.h
 *
 *  Created on: Dec 4, 2015
 *      Author: wsmith
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "gameobject.h"

namespace gelements
{
class Light
{
private:
	float lightAmbient[4]  = {0.0f, 0.0f, 0.0f, 1.0f};
	float lightDiffuse[4]  = {1.0f, 1.0f, 1.0f, 1.0f};
	float lightSpecular[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	float lightPosition[4];
	GLint lightId;
public:
	Light(float x, float y, float z, GLint lightId);
	void render();
	~Light();
};
}



#endif /* LIGHT_H_ */

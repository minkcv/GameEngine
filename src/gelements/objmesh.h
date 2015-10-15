/*
 * objmesh.h
 *
 *  Created on: Oct 13, 2015
 *      Author: wsmith
 */

#ifndef OBJMESH_H_
#define OBJMESH_H_

#include "gameobject.h"
#include <string>

namespace gelements
{
class ObjMesh : protected GameObject
{
private:
	float* triangleFaces;
	int totalConnectedTriangles;
public:
	ObjMesh(float x, float y, float z);
	void loadObj(std::string name);
	void update(double deltaT);
	void render();
	~ObjMesh();
};
}



#endif /* OBJMESH_H_ */

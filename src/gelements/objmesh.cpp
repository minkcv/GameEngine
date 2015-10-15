/*
 * objmesh.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: wsmith
 */

#include "objmesh.h"
#include <SFML/OpenGL.hpp>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

namespace gelements
{
ObjMesh::ObjMesh(float x, float y, float z) : GameObject(x, y, z)
{
	triangleFaces = nullptr;
	totalConnectedTriangles = 0;
}

void ObjMesh::loadObj(std::string name)
{
	float* vertexBuffer;
	long totalConnectedPoints = 0;
	string line;
	ifstream objFile(name);
	if(objFile.is_open()) {
		int numVerticies = 0;
		int numFaces = 0;
		string line;
		while(getline(objFile, line)) {
			if(line[0] == 'v')
				numVerticies+=3;
			else if(line[0] == 'f')
				numFaces++;
		}

		printf("verts %d faces %d\n", numVerticies, numFaces);

		objFile.clear();
		objFile.seekg(0);

		vertexBuffer = new float[numVerticies];
		triangleFaces = new float [numFaces * 3 * 3];

		for(int i = 0; i < numFaces * 3 * 3; i++) {
			triangleFaces[i] = 0;
		}
		for(int i = 0; i < numVerticies; i++) {
			vertexBuffer[i] = 0;
		}

		int triangleIndex = 0;

		while (getline(objFile, line)) {
			char lineType = line[0];
			// convert line to char[] so it is editable
			char lineData[line.size()];
			strcpy(lineData, line.c_str());
			lineData[0] = ' ';
			if(lineType == 'v') {
				sscanf(lineData, "%f %f %f",
				&vertexBuffer[totalConnectedPoints],
				&vertexBuffer[totalConnectedPoints + 1],
				&vertexBuffer[totalConnectedPoints + 2]);
				totalConnectedPoints += 3;
			}
			else if(lineType == 'f') {
				int vertexNumber[3] = {0, 0, 0};
				sscanf(lineData, "%i %i %i",
						&vertexNumber[0],
						&vertexNumber[1],
						&vertexNumber[2]);
				// obj indices starting at 1, c++ indices start at 0
				vertexNumber[0] -= 1;
				vertexNumber[1] -= 1;
				vertexNumber[2] -= 1;

				int tCount = 0;
				for(int i = 0; i < 3; i++) {
					triangleFaces[triangleIndex + tCount] = vertexBuffer[3 * vertexNumber[i]];
					triangleFaces[triangleIndex + tCount + 1] = vertexBuffer[3 * vertexNumber[i] + 1];
					triangleFaces[triangleIndex + tCount + 2] = vertexBuffer[3 * vertexNumber[i] + 2];
					tCount += 3;
				}

				triangleIndex += 9;
				totalConnectedTriangles += 9;
			}
		}
		objFile.close();
	}
	else {
		printf("error loading obj\n");
	}
	delete[] vertexBuffer;
	vertexBuffer = nullptr;
}

void ObjMesh::update(double deltaT)
{

}

void ObjMesh::render()
{
	glColor3f(1, 0, 0);
	glTranslatef(position.getX(), position.getY(), position.getZ());
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleFaces);
	glDrawArrays(GL_TRIANGLES, 0, totalConnectedTriangles);
	glDisableClientState(GL_VERTEX_ARRAY);
	glTranslatef(-position.getX(), -position.getY(), -position.getZ());
}

ObjMesh::~ObjMesh()
{
	delete[] triangleFaces;
	triangleFaces = nullptr;
}
}


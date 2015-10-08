/*
 * camera.h
 *
 *  Created on: Sep 25, 2015
 *      Author: wsmith
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <SFML/Graphics.hpp>

namespace gelements
{
	class Camera
	{
	public:
		Camera();
		void update(double deltaT);
		void transform();
		void setWindow(sf::RenderWindow* window);
		~Camera();
	private:
		sf::RenderWindow* window;
		float x, y, z;
		float xVelocity, yVelocity, zVelocity;
		float xRotation, yRotation;
		float moveSpeed;
		float baseMoveSpeed = 0.5f;
		float fastMoveSpeed = 1.0f;
		float mouseSensitivity = 0.05f;
		int oldMouseX;
		int oldMouseY;
		int mousedx;
		int mousedy;
	};
}

#endif /* CAMERA_H_ */

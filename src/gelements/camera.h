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
/**
 * a first person camera that supports rotation and movement
 * from mouse and keyboard input
 */
class Camera
{
private:
	sf::RenderWindow* window; // reference to window to get and set mouse position
	float x, y, z; // position of camera
	float xVelocity, yVelocity, zVelocity; // movement added to position each update
	float xRotation, yRotation; // rotation of camera, vertical, horizontal respectively
	float moveSpeed; // how much velocity currently is;
	float baseMoveSpeed = 0.5f; // what moveSpeed is normally
	float fastMoveSpeed = 1.0f; // when you want to go fast
	float mouseSensitivity = 0.05f; // how fast to rotate based on mouse movement
	int oldMouseX, oldMouseY; // mouse x and y from last update
	int mousedx, mousedy; // change in mouse position from last update
public:
	/**
	 * default constructor
	 * positions the camera at 0, 0, 0 with x and y rotation 0
	 */
	Camera();
	/**
	 * update the camera's position and rotation
	 * based on keyboard and mouse input
	 */
	void update(double deltaT);
	/**
	 * call this before rendering other objects in opengl to
	 * apply the camera's translation and rotation
	 */
	void transform();
	/**
	 * set the camera's reference to the window
	 */
	void setWindow(sf::RenderWindow* window);
	/**
	 * nulls all pointer variables
	 */
	~Camera();

};
}

#endif /* CAMERA_H_ */

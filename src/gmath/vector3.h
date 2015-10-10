/*
 * vector3.h
 *
 *  Created on: Aug 31, 2015
 *      Author: wsmith
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

namespace gmath
{
template<typename T>
class Vector3
{
private:
	T x;
	T y;
	T z;

public:
	/**
	 * default constructor
	 * default values are all 0
	 */
	Vector3();

	/**
	 * constructor with three values for x y z
	 */
	Vector3(T x, T y, T z);

	/**
	 * adds two vector's components and returns them in a new vector
	 */
	static Vector3<T> add(const Vector3<T>& v1, const Vector3<T>& v2);

	/**
	 * dot product of two vectors
	 */
	static T dot(const Vector3<T>& v1, const Vector3<T>& v2);

	/**
	 * cross product of two vectors
	 */
	static Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2);

	/**
	 * returns the vector divided by its own magnitude
	 */
	static Vector3<T> normalize(const Vector3<T>& v);

	/**
	 * returns the vector pointing in the opposite direction
	 * in all dimensions
	 */
	static Vector3<T> invert(const Vector3<T>& v);

	T getX();
	T getY();
	T getZ();
};
};
#include "vector3.cpp" // this is how I chose to deal with template implementation
#endif /* VECTOR3_H_ */

/*
 * vector3.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: wsmith
 */

#ifndef VECTOR3_CPP_
#define VECTOR3_CPP_
#include <cmath>
#include "vector3.h"

namespace gmath
{
template<typename T>
Vector3<T>::Vector3() : x(0), y(0), z(0)
{
}

template<typename T>
Vector3<T>::Vector3(T x, T y, T z) : x(x), y(y), z(z)
{
}

template<typename T>
Vector3<T> Vector3<T>::add(const Vector3<T>& v1, const Vector3<T>& v2)
{
	Vector3<T> v3(v1->getX() + v2->getX(),
			v1->getY() + v2->getY(),
			v1->getZ() + v2->getZ());
	return v3;
}

template<typename T>
T Vector3<T>::dot(const Vector3<T>& v1, const Vector3<T>& v2)
{
	return v1->getX() * v2->getX() + v1->getY() * v2->getY() + v1->getZ() * v2->getZ();
}

template<typename T>
Vector3<T> Vector3<T>::cross(const Vector3<T>& v1, const Vector3<T>& v2)
{
	Vector3<T> v3(v1->getY() * v2->getZ() - v1->getZ() * v2->getY(),
			v1->getZ() * v2->getX() - v1->getX() * v2->getZ(),
			v1->getX() * v2->getY() - v1->getY() * v2->getX());
	return v3;
}

template<typename T>
Vector3<T> Vector3<T>::normalize(const Vector3<T>& v)
{
	T length = sqrt((v->getX() * v->getX()) + (v->getY() * v->getY()) + (v->getZ() * v->getZ()));
	Vector3<T> n(v->getX() / length, v->getY() / length, v->getZ() / length);
	return n;
}

template<typename T>
Vector3<T> Vector3<T>::invert(const Vector3<T>& v)
{
	Vector3<T> vi(-v->getX(), -v->getY(), -v->getZ());
	return vi;
}

template<typename T>
T Vector3<T>::getX()
{
	return x;
}

template<typename T>
T Vector3<T>::getY()
{
	return y;
}

template<typename T>
T Vector3<T>::getZ()
{
	return z;
}
}
#endif

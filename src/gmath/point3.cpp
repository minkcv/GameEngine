/*
 * point3.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: wsmith
 */

#ifndef POINT3_CPP_
#define POINT3_CPP_
#include "point3.h"

namespace gmath
{
template<typename T>
Point3<T>::Point3()
{
	x = 0;
	y = 0;
	z = 0;
}

template<typename T>
Point3<T>::Point3(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<typename T>
T Point3<T>::dist(const Point3<T>& p1, const Point3<T>& p2)
{

}

template<typename T>
T Point3<T>::getX() { return x; }

template<typename T>
T Point3<T>::getY() { return y; }

template<typename T>
T Point3<T>::getZ() { return z; }

template<typename T>
void Point3<T>::setX(T x) { this->x = x; }

template<typename T>
void Point3<T>::setY(T y) { this->y = y; }

template<typename T>
void Point3<T>::setZ(T z) { this->z = z; }
}

#endif

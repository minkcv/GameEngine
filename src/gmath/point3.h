/*
 * point3.h
 *
 *  Created on: Sep 4, 2015
 *      Author: wsmith
 */

#ifndef POINT_H_
#define POINT_H_

namespace gmath
{
	template<typename T>
	class Point3
	{
	private:
		T x;
		T y;
		T z;

	public:
		Point3();

		Point3(T x, T y, T z);

		static T dist(const Point3<T>& p1, const Point3<T>& p2);

		T getX();

		T getY();

		T getZ();

		void setX(T x);

		void setY(T y);

		void setZ(T z);
	};
}

#include "point3.cpp"

#endif /* POINT_H_ */

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
        Vector3();

        Vector3(T x, T y, T z);

        static Vector3<T> add(const Vector3<T>& v1, const Vector3<T>& v2);

        static T dot(const Vector3<T>& v1, const Vector3<T>& v2);

        static Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2);

        static T normalize(const Vector3<T>& v);

        static Vector3<T> invert(const Vector3<T>& v);

        T getX();
        T getY();
        T getZ();
    };
};
#include "vector3.cpp"
#endif /* VECTOR3_H_ */

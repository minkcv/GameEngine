/*
 * matrix.h
 *
 *  Created on: Sep 4, 2015
 *      Author: wsmith
 */
#include <string.h>

#ifndef MATRIX4_H_
#define MATRIX4_H_

namespace gmath
{
	template<typename T>
	class Matrix4
	{
	private:
		T m [4][4]; // the internal matrix
		static bool iCreated; // has the identity matrix been setup?
		//static T i [4][4]; // the identity matrix
		static Matrix4<T> identity;
	public:
		/**
		 * default constructor
		 * default values in the matrix are all zero
		 */
		Matrix4();

		/**
		 * copy constructor
		 * internal matrix copies the values of the passed matrix
		 */
		Matrix4(const Matrix4<T>& m1);

		/**
		 * constructor that copies values from a 2d array
		 */
		Matrix4(const T (&values)[4][4]);

		/**
		 * returns the value of the matrix at
		 * @param row row of the matrix
		 * @param col column of the matrix
		 */
		T getValue(const int& row, const int& col) const;

		/**
		 * Pass in a 2d array to be filled with the data of the internal matrix.
		 * Passing in the array is necessary to avoid returning a pointer to the data
		 */
		void getMatrixData(T (&values)[4][4]) const;

		/**
		 * does the matrix product (aka multiplication or dot) of two matricies
		 */
		static Matrix4<T> mult(const Matrix4<T>& m1, const Matrix4<T>& m2);


		/**
		 * returns the identity matrix, creating it if necessary
		 */
		static Matrix4<T> getIdentity();

		/**
		 * transposes the matrix
		 * @param m1
		 */
		static Matrix4<T> transpose(const Matrix4<T>& m1);
	};
}

#include "matrix4.cpp" // this is how I chose to deal with template implementation
#endif /* MATRIX_H_ */

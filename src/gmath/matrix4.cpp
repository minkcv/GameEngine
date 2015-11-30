/*
 * matrix.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: wsmith
 */
#ifndef MATRIX4_CPP_
#define MATRIX4_CPP_
#include "matrix4.h"

namespace gmath
{

template<typename T>
bool Matrix4<T>::iCreated = false;

template<typename T>
Matrix4<T> Matrix4<T>::identity;

template<typename T>
Matrix4<T>::Matrix4()
{

}

template<typename T>
Matrix4<T>::Matrix4(const Matrix4<T>& m1)
{
	for(int itr = 0; itr < 4; itr++){
		for(int itr2 = 0; itr2 < 4; itr2++){
			m[itr][itr2] = m1.getValue(itr, itr2);
		}
	}
}

template<typename T>
Matrix4<T>::Matrix4(const T (&values)[4][4])
{
	for(int itr = 0; itr < 4; itr++){
		for(int itr2 = 0; itr2 < 4; itr2++){
			m[itr][itr2] = values[itr][itr2];
		}
	}
}

template<typename T>
T Matrix4<T>::getValue(const int& row, const int& col) const
{
	return m[row][col];
}

template<typename T>
void Matrix4<T>::getMatrixData(T (&values)[4][4]) const
{
	for(int itr = 0; itr < 4; itr++){
		for(int itr2 = 0; itr2 < 4; itr2++){
			values[itr][itr2] = m[itr][itr2];
		}
	}
	return;
}

template<typename T>
Matrix4<T> Matrix4<T>::mult(const Matrix4<T>& m1, const Matrix4<T>& m2)
{
	T result [4][4];
	for(int row = 0; row < 4; row++){
		for(int col = 0; col < 4; col++){
			result[row][col] = 0;
			for(int inner = 0; inner < 4; inner++){
				result[row][col] =result[row][col] +  m1.getValue(row, inner) * m2.getValue(inner, col);
			}
		}
	}
	Matrix4<T> resultM(result);
	return resultM;
};

template<typename T>
Matrix4<T> Matrix4<T>::getIdentity()
{
	if(! iCreated){
		iCreated = true;
		T i[4][4];
		for(int itr = 0; itr < 4; itr++){ // set diagonal to 1
			i[itr][itr] = 1;
		}
		identity = Matrix4<T>(i);
	}
	return identity;
}

template<typename T>
Matrix4<T> Matrix4<T>::transpose(const Matrix4<T>& m1)
{
	T t [4][4];
	for(int itr = 0; itr < 4; itr++){
		for(int itr2 = 0; itr2 < 4; itr2++){
			t[itr][itr2] = m1.getValue(itr2, itr);
		}
	}
	Matrix4<T> transposed(t);
	return transposed;
}
}
#endif


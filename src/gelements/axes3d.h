/*
 * axes.h
 *
 *  Created on: Sep 25, 2015
 *      Author: wsmith
 */

#ifndef AXES3D_H_
#define AXES3D_H_

#include "renderable.h"

namespace gelements
{
	class Axes3D : public Renderable
	{
	public:
		Axes3D();
		void render();
		~Axes3D();
	};
}

#endif /* AXES_H_ */

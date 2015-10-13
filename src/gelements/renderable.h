/*
 * renderable.h
 *
 *  Created on: Oct 12, 2015
 *      Author: wsmith
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

namespace gelements
{
class Renderable
{
public:
	virtual void render() = 0;
	virtual ~Renderable(){};
};
}


#endif /* RENDERABLE_H_ */

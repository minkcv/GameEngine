/*
 * updateable.h
 *
 *  Created on: Oct 12, 2015
 *      Author: wsmith
 */

#ifndef UPDATEABLE_H_
#define UPDATEABLE_H_

namespace gelements
{
class Updateable
{
public:
	virtual void update(double deltaT) = 0;
	virtual ~Updateable(){};
};
}



#endif /* UPDATEABLE_H_ */

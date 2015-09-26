/*
 * interactive.h
 *
 *  Created on: Sep 18, 2015
 *      Author: wsmith
 */

#ifndef INTERACTIVE_H_
#define INTERACTIVE_H_

namespace interactive
{
	class Interactive
	{
	public:
		virtual void update(double deltaT) = 0;
		virtual void render() = 0;
		virtual ~Interactive(){};
	};
}

#endif /* INTERACTIVE_H_ */

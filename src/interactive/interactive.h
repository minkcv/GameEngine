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
/**
 * extensions of this class are high level designs that
 * need to update and render their members and read keyboard / mouse input.
 * an example is a game or a main menu.
 */
class Interactive
{
public:
	virtual void update(double deltaT) = 0;
	virtual void render() = 0;
	virtual ~Interactive(){};
};
}

#endif /* INTERACTIVE_H_ */

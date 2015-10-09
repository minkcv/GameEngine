/*
 * gamestack.h
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#include "node.h"
#ifndef GAMESTACK_H_
#define GAMESTACK_H_
#include <stdlib.h>

namespace gengine
{
class GameStack
{
private:
	static const size_t STACK_SIZE = 256;
	const int MAX_NODES = 32;
	Node nodes[16];
	int topNode;
	void* top;
	void* buffer;
public:
	GameStack();
	bool isEmpty();
	void* push(size_t size);
	bool pop();
	void* peek();
	~GameStack();
};
};
#endif /* GAMESTACK_H_ */

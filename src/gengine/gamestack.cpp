/*
 * gamestack.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#include "gamestack.h"
#include <stdio.h>
namespace gengine
{
GameStack::GameStack() : topNode(-1)
{
	buffer = malloc(STACK_SIZE);
	printf("allocated %lu bytes for game stack\n", STACK_SIZE);
	top = buffer;
}

bool GameStack::isEmpty()
{
	return topNode < 0;
}

void* GameStack::push(size_t size)
{
	if(topNode >= MAX_NODES - 1){
		return 0;
	}
	topNode++;
	nodes[topNode] = Node(top, size);
	top += size;
	return top;
}

bool GameStack::pop()
{
	if(topNode < 0){
		return 1;
	}
	top -= nodes[topNode].getDataSize();
	topNode--;
	return 0;
}

void* GameStack::peek()
{
	return nodes[topNode].getData();
}
GameStack::~GameStack()
{
	while(! isEmpty())
		pop();

	free(buffer);
	buffer = nullptr;
	top = nullptr;
}
}

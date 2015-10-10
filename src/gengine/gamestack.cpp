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
	top = (size_t*)buffer;
}

bool GameStack::isEmpty()
{
	return topNode < 0;
}

void* GameStack::push(size_t size)
{
	if(top + size > (size_t*)buffer + STACK_SIZE){
		printf("stack overflow\n");
		return 0;
	}
	if(topNode >= MAX_NODES - 1){
		printf("out of nodes for stack\n");
		return 0;
	}
	topNode++;
	nodes[topNode] = Node(top, size);
	top += size;
	return top;
}

bool GameStack::pop()
{
	if(isEmpty()){
		printf("can't pop while stack empty\n");
		return 0;
	}
	top -= nodes[topNode].getDataSize();
	topNode--;
	return 1;
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

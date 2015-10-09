/*
 * node.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */


#include "node.h"

namespace gengine
{
Node::Node() : dataPtr(nullptr), dataSize(0)
{
}

Node::Node(void* data, size_t dataSize) : dataPtr(data), dataSize(dataSize)
{
}

void* Node::getData()
{
	return dataPtr;
}

size_t Node::getDataSize()
{
	return dataSize;
}

Node::~Node()
{
	dataPtr = nullptr;
}
}

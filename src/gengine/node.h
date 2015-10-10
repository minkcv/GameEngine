/*
 * node.h
 *
 *  Created on: Oct 7, 2015
 *      Author: wsmith
 */

#ifndef NODE_H_
#define NODE_H_
#include <stdlib.h>
namespace gengine
{
/**
 * a tuple for holding the start address for a buffer and the size of the buffer
 */
class Node
{
private:
	void* dataPtr; // pointer to start of data buffer
	size_t dataSize; // size of data buffer
public:
	/**
	 * initializes the data pointer with nullptr and size with 0
	 */
	Node();
	/**
	 * sets the data pointer to the address and sets the size to dataSize
	 * does not allocate any memory on the heap (free store)
	 */
	Node(void* data, size_t dataSize);
	/**
	 * returns a pointer to the data
	 */
	void* getData();
	/**
	 * returns the size of the data
	 */
	size_t getDataSize();
	/**
	 * nulls the data pointer.
	 * does not free any memory because none is allocated here
	 */
	~Node();
};
};
#endif /* NODE_H_ */

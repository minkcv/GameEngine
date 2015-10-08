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
class Node
{
private:
	void* dataPtr;
	size_t dataSize;
public:
	Node();
	Node(void* data, size_t dataSize);
	void* getData();
	size_t getDataSize();
};
};
#endif /* NODE_H_ */

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
/**
 * a stack for managing a pre-allocated buffer of memory.
 * this allows you to create objects on the heap (free store) without
 * calling new or malloc which can be slow and should be avoided during
 * the game's update/render loop
 */
class GameStack
{
private:
	static const size_t STACK_SIZE = 2048; // capacity of the stack
	static const int MAX_NODES = 32; // number of things that can be on the stack regardless of size
	Node nodes[MAX_NODES]; // nodes contain the address and size of an item on the stack
	int topNode; // an index of the nodes array that points to the top node;
	size_t* top; // a pointer to the top of the stack
	void* buffer; // a pointer to the beginning of the stack
public:
	/**
	 * default constructor, allocates STACK_SIZE bytes
	 * and points top to same address of buffer
	 */
	GameStack();
	/**
	 * returns true if there is no data on the stack
	 */
	bool isEmpty();
	/**
	 * returns an address where size bytes have been allocated
	 * returns 0 if the the stack is out of nodes or overflows
	 * @param size size of the object to be placed on the stack
	 *
	 * create your object with the placement new:
	 * void* myObjPtr = stack.push(sizeof(MyClass));
	 * MyClass* myObj = new(myObjPtr) MyClass();
	 */
	void* push(size_t size);
	/**
	 * removes the top item from the stack.
	 * you should null all pointers that pointed to the
	 * item that has been pop'ed.
	 * returns 1 if the stack is empty and can't be pop'ed
	 * returns 0 if the pop is successful
	 */
	bool pop();
	/**
	 * returns the address of the top node on the stack.
	 * this does not return the top pointer
	 */
	void* peek();
	/**
	 * pops all nodes and frees the allocated memory
	 */
	~GameStack();
};
};
#endif /* GAMESTACK_H_ */

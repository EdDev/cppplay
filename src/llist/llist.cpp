/*
 * llist.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: Svetah
 */

#include "llist.h"

#include <iostream>

template<typename DataType>
LList<DataType>::LList()
{
	this->head = new Node;
	this->head->next = this->head;
}

template<typename DataType>
LList<DataType>::~LList()
{
	clean();
	delete this->head;
}

template<typename DataType>
bool LList<DataType>::insert(DataType data)
{
	// Fastest add is to HEAD
	Node *node = new Node;
	node->data = data;

	node->next 		 = this->head->next;
	this->head->next = node;

	return true;
}

template<typename DataType>
void LList<DataType>::print()
{
	for(Node *node = this->head->next; (this->head != node); node = node->next)
	{
		std::cout << "#" << node->data << "->";
	}
	std::cout << "||" << std::endl;
}

template<typename DataType>
bool LList<DataType>::clean()
{
	for(Node *node = this->head->next; (this->head != node); node = node->next)
	{
		Node *node_to_del = node;
		delete node_to_del;
	}
	this->head->next = this->head;
	return true;
}

template class LList<int>;

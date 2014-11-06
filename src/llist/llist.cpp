/*
 * llist.cpp
 *
 *  Created on: Nov 3, 2014
 */

#include <iostream>
#include <sstream>

#include "llist.h"

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
void LList<DataType>::print(std::string & out_buf)
{
	for(Node *node = this->head->next; (this->head != node); node = node->next)
	{
	    std::ostringstream convert_data;
	    convert_data << node->data;

	    out_buf = out_buf + "#" + convert_data.str() + "->";
	}
	out_buf += "||";
}

template<typename DataType>
bool LList<DataType>::clean()
{
	for(Node *node = this->head->next; (this->head != node); )
	{
		Node *node_to_del = node;
		node = node->next;
		delete node_to_del;
	}
	this->head->next = this->head;
	return true;
}

template class LList<int>;

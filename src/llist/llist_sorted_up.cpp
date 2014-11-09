/*
 * llist_sorted_up.cpp
 *
 *  Created on: Nov 4, 2014
 */

#include "llist_sorted_up.h"

template<typename DataType>
bool LList_SortUP<DataType>::insert(DataType data)
{
	typename LList<DataType>::Node * node = new typename LList<DataType>::Node;
	node->data = data;

	typename LList<DataType>::Node * node_itr = this->head;
	while((this->head != node_itr->next) && (data > node_itr->next->data))
	{
		node_itr = node_itr->next;
	}
	node->next 	   = node_itr->next;
	node_itr->next = node;

	return true;
}

template class LList_SortUP<int>;

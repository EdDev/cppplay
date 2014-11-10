/*
 * llist_sorted_down.h
 *
 *  Created on: Nov 4, 2014
 */

#ifndef LLIST_SORTED_DOWN_H_
#define LLIST_SORTED_DOWN_H_

#include "llist.h"

template<typename DataType>
class LList_SortDOWN : public LList<DataType>
{
public:
	bool insert(DataType data);
};


#endif /* LLIST_SORTED_DOWN_H_ */

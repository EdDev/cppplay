/*
 * llist_sorted_up.h
 *
 *  Created on: Nov 4, 2014
 */

#ifndef LLIST_SORTED_UP_H_
#define LLIST_SORTED_UP_H_

#include "llist.h"

template<typename DataType>
class LList_SortUP : public LList<DataType>
{
public:
	bool insert(DataType data);
};


#endif /* LLIST_SORTED_UP_H_ */

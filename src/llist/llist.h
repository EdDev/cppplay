/*
 * llist.h
 *
 *  Created on: Nov 3, 2014
 */

#ifndef LLIST_H_
#define LLIST_H_

#include <string>


template<typename DataType>
class LList
{
public:
	LList();
	virtual ~LList();

	enum status{SUCCESS, FAIL};

	virtual bool insert(DataType data);

	void print(std::string & out_buf);
	bool clean();

protected:
	struct Node
	{
		Node 	  *next;
		DataType   data;
	};

	Node *head;
};



#endif /* LLIST_H_ */

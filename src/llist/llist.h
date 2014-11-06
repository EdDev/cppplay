/*
 * llist.h
 *
 *  Created on: Nov 3, 2014
 */

#ifndef LLIST_H_
#define LLIST_H_

#include <string>

#define nullptr (void*)0

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

private:
	struct Node
	{
		Node 	  *next;
		DataType   data;
	};

	Node *head;
};



#endif /* LLIST_H_ */

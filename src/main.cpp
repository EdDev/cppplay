//============================================================================
// Name        : main.cpp
// Author      : Ed
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "llist/llist.h"

#include <iostream>
using namespace std;

void run_llist_kata();
void run_llist_base_kata();


int main() {
	cout << "!!!My KATA!!!" << endl;

	run_llist_kata();

	return 0;
}

void run_llist_kata()
{
    run_llist_base_kata();
}

void run_llist_base_kata()
{
    LList<int> list_a;
    list_a.print();

    // Insert one item.
    list_a.insert(0);
    list_a.print();

    // Insert two more items.
    list_a.insert(1);
    list_a.insert(2);
    list_a.print();

    // Clean list and insert two items.
    list_a.clean();
    list_a.insert(1);
    list_a.insert(2);
    list_a.print();
}

/*
 * llist_sorted_up.cpp
 *
 *  Created on: Nov 8, 2014
 */


#include "CppUTest/TestHarness.h"

#include <string>

#include "llist/llist_sorted_up.h"


using namespace std;



TEST_GROUP(llist_sorted_up)
{
    std::string result_buffer;
    LList_SortUP<int> *list;

    void setup()
    {
    	list = new LList_SortUP<int>();
    }

    void teardown()
    {
    	delete list;
    }
};

TEST(llist_sorted_up, empty_list)
{
    list->print(result_buffer);

    std::string expected("||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_sorted_up, insert_item_0)
{
    list->insert(0);
    list->print(result_buffer);

    std::string expected("#0->||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_sorted_up, insert_2_items_0_1)
{
    list->insert(0);
    list->insert(1);
    list->print(result_buffer);

    std::string expected("#0->#1->||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_sorted_up, clean_and_insert_2_items_1_2)
{
    list->clean();
    list->insert(1);
    list->insert(2);
    list->print(result_buffer);

    std::string expected("#1->#2->||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_sorted_up, insert_4_items__ordered_up)
{
    list->insert(0);
    list->insert(3);
    list->insert(2);
    list->insert(1);
    list->print(result_buffer);

    std::string expected("#0->#1->#2->#3->||");
    CHECK_EQUAL(expected, result_buffer);
}

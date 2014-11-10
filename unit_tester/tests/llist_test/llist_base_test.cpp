/*
 * llist_base.cpp
 *
 *  Created on: Nov 5, 2014
 */


#include "CppUTest/TestHarness.h"

#include <string>

#include "llist/llist.h"


using namespace std;



TEST_GROUP(llist_base)
{
    std::string result_buffer;
    LList<int> *list;

    void setup()
    {
        list = new LList<int>();
    }

    void teardown()
    {
        delete list;
    }
};

TEST(llist_base, empty_list)
{
    list->print(result_buffer);

    std::string expected("||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_base, insert_item_0)
{
    list->insert(0);
    list->print(result_buffer);

    std::string expected("#0->||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_base, insert_2_items_0_1)
{

    list->insert(0);
    list->insert(1);
    list->print(result_buffer);

    std::string expected("#1->#0->||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_base, clean_and_insert_2_items_1_2)
{
    list->clean();
    list->insert(1);
    list->insert(2);
    list->print(result_buffer);

    std::string expected("#2->#1->||");
    CHECK_EQUAL(expected, result_buffer);
}

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

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(llist_base, empty_list)
{
    LList<int> list_a;
    list_a.print(result_buffer);

    std::string expected("||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_base, insert_item_0)
{
    LList<int> list_a;
    list_a.insert(0);
    list_a.print(result_buffer);

    std::string expected("#0->||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_base, insert_2_items_0_1)
{
    LList<int> list_a;
    list_a.insert(0);
    list_a.insert(1);
    list_a.print(result_buffer);

    std::string expected("#1->#0->||");
    CHECK_EQUAL(expected, result_buffer);
}

TEST(llist_base, clean_and_insert_2_items_1_2)
{
    LList<int> list_a;
    list_a.clean();
    list_a.insert(1);
    list_a.insert(2);
    list_a.print(result_buffer);

    std::string expected("#2->#1->||");
    CHECK_EQUAL(expected, result_buffer);
}

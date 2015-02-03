/*
 * ring_q.cpp
 *
 */

#include "CppUTest/TestHarness.h"

#include "ring_q.h"

TEST_GROUP(ring)
{
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(ring, create_destroy_q)
{
	queue q(4096);
}

TEST(ring, post_init_q_obj_count)
{
	queue q(4096);

	LONGS_EQUAL(0, q.obj_count());
}

/*
 * char_stream_req_test.cpp
 *
 *  Created on: Nov 14, 2014
 *      Author: edwardh
 */

#include "CppUTest/TestHarness.h"

#include "char_stream_req.h"


TEST_GROUP(char_stream_req)
{
    static const int bulk_size = 100000;

    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(char_stream_req, unique_input_alphanumeric)
{

    const char *cstream_in = "abc123";
    const char *cstream_expected = "123abc";
    char        cstream_out[bulk_size];

    CharStreamReq csr;

    for(char *ch_itr = (char*)cstream_in; (*ch_itr != '\0'); ++ch_itr)
        csr.recv(*ch_itr);

    csr.printRecvSorted(cstream_out, bulk_size);

    STRCMP_EQUAL(cstream_expected, cstream_out);
}

TEST(char_stream_req, non_unique_input_alphanumeric)
{

    const char *cstream_in = "abbc13b213";
    const char *cstream_expected = "11233abbbc";
    char        cstream_out[bulk_size];

    CharStreamReq csr;

    for(char *ch_itr = (char*)cstream_in; (*ch_itr != '\0'); ++ch_itr)
        csr.recv(*ch_itr);

    csr.printRecvSorted(cstream_out, bulk_size);

    STRCMP_EQUAL(cstream_expected, cstream_out);
}

/*
 * Current implementation assumes that the output is sorted based on the
 * ASCII table (For alphanumeric: Numbers, Upper chars and lastly Lower chars.
 */
TEST(char_stream_req, non_unique_input_alphanumeric_w_low_and_up_chars)
{

    const char *cstream_in = "abBc13Ab213";
    const char *cstream_expected = "11233ABabbc";
    char        cstream_out[bulk_size];

    CharStreamReq csr;

    for(char *ch_itr = (char*)cstream_in; (*ch_itr != '\0'); ++ch_itr)
        csr.recv(*ch_itr);

    csr.printRecvSorted(cstream_out, bulk_size);

    STRCMP_EQUAL(cstream_expected, cstream_out);
}

TEST(char_stream_req, input_larger_than_outbuffer__output_only_4_chars)
{

    const char *cstream_in = "a1b3c2";
    const char *cstream_expected = "123";

    const int   small_bulk_size = 4;
    char        cstream_out[small_bulk_size];

    CharStreamReq csr;

    for(char *ch_itr = (char*)cstream_in; (*ch_itr != '\0'); ++ch_itr)
        csr.recv(*ch_itr);

    csr.printRecvSorted(cstream_out, small_bulk_size);

    STRCMP_EQUAL(cstream_expected, cstream_out);
}

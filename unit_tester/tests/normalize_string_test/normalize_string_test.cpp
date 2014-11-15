/*
 * normalize_string_test.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: edwardh
 */



#include "CppUTest/TestHarness.h"

#include "normalize_string.h"


TEST_GROUP(inline_normalize_string)
{
    void setup() {}

    void teardown() {}
};

TEST(inline_normalize_string, nothing_to_normalize)
{
    const char   in_string[]       = "nothing_to_normalize";
    const char   expected_string[] = "nothing_to_normalize";
    size_t       string_len = sizeof(in_string);
    const char   normalize_char = '@';

    char        *result_string = (char*)in_string;
    unsigned int num_of_reduced_appearances;

    num_of_reduced_appearances = Normalizer::normalize_string_inplace((char*)in_string, string_len, normalize_char);
    LONGS_EQUAL(0, num_of_reduced_appearances);
    STRCMP_EQUAL(expected_string, result_string);
}

TEST(inline_normalize_string, normalize_uri)
{
    const char   in_string[]        = "http://someuri//that_we///wouldlike/to/normalize";
    const char   expected_string[]  = "http:/someuri/that_we/wouldlike/to/normalize";
    size_t       string_len = sizeof(in_string);
    const char   normalize_char = '/';

    char        *result_string = (char*)in_string;
    unsigned int num_of_reduced_appearances;

    num_of_reduced_appearances = Normalizer::normalize_string_inplace((char*)in_string, string_len, normalize_char);

    LONGS_EQUAL(4, num_of_reduced_appearances);
    STRCMP_EQUAL(expected_string, result_string);
}

TEST(inline_normalize_string, normalize_string_to_a_single_char)
{
    const char   in_string[]        = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    const char   expected_string[]  = "a";
    size_t       string_len = sizeof(in_string);
    const char   normalize_char = 'a';
    const int    expected_reduced_chars = string_len - 2; // original string size, minus the EOS and the single char left.

    char        *result_string = (char*)in_string;
    unsigned int num_of_reduced_appearances;

    num_of_reduced_appearances = Normalizer::normalize_string_inplace((char*)in_string, string_len, normalize_char);

    LONGS_EQUAL(expected_reduced_chars, num_of_reduced_appearances);
    STRCMP_EQUAL(expected_string, result_string);
}

TEST(inline_normalize_string, normalize_zero_string)
{
    const char   in_string[]        = "";
    const char   expected_string[]  = "";
    size_t       string_len = sizeof(in_string);
    const char   normalize_char = 'a';

    char        *result_string = (char*)in_string;
    unsigned int num_of_reduced_appearances;

    num_of_reduced_appearances = Normalizer::normalize_string_inplace((char*)in_string, string_len, normalize_char);

    LONGS_EQUAL(0, num_of_reduced_appearances);
    STRCMP_EQUAL(expected_string, result_string);
}

TEST_GROUP(fast_normalize_string)
{
    void setup() {}

    void teardown() {}
};

TEST(fast_normalize_string, nothing_to_normalize)
{
    const char   in_string[]       = "nothing_to_normalize";
    const char   expected_string[] = "nothing_to_normalize";
    size_t       string_len = sizeof(in_string);
    char         out_string[sizeof(in_string)] = "";
    const char   normalize_char = '@';

    unsigned int num_of_reduced_appearances;

    num_of_reduced_appearances = Normalizer::normalize_string_fast(in_string, out_string, string_len, normalize_char);
    LONGS_EQUAL(0, num_of_reduced_appearances);
    STRCMP_EQUAL(expected_string, out_string);
}

TEST(fast_normalize_string, normalize_uri)
{
    const char   in_string[]        = "http://someuri//that_we///wouldlike/to/normalize";
    const char   expected_string[]  = "http:/someuri/that_we/wouldlike/to/normalize";
    size_t       string_len = sizeof(in_string);
    char         out_string[sizeof(in_string)] = "";
    const char   normalize_char = '/';

    unsigned int num_of_reduced_appearances;

    num_of_reduced_appearances = Normalizer::normalize_string_fast(in_string, out_string, string_len, normalize_char);

    LONGS_EQUAL(4, num_of_reduced_appearances);
    STRCMP_EQUAL(expected_string, out_string);
}

TEST(fast_normalize_string, normalize_string_to_a_single_char)
{
    const char   in_string[]        = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    const char   expected_string[]  = "a";
    size_t       string_len = sizeof(in_string);
    char         out_string[sizeof(in_string)] = "";
    const char   normalize_char = 'a';
    const int    expected_reduced_chars = string_len - 2; // original string size, minus the EOS and the single char left.

    unsigned int num_of_reduced_appearances;

    num_of_reduced_appearances = Normalizer::normalize_string_fast(in_string, out_string, string_len, normalize_char);

    LONGS_EQUAL(expected_reduced_chars, num_of_reduced_appearances);
    STRCMP_EQUAL(expected_string, out_string);
}

TEST(fast_normalize_string, normalize_zero_string)
{
    const char   in_string[]        = "";
    const char   expected_string[]  = "";
    size_t       string_len = sizeof(in_string);
    char         out_string[8] = "";
    const char   normalize_char = 'a';

    unsigned int num_of_reduced_appearances;

    num_of_reduced_appearances = Normalizer::normalize_string_fast(in_string, out_string, string_len, normalize_char);

    LONGS_EQUAL(0, num_of_reduced_appearances);
    STRCMP_EQUAL(expected_string, out_string);
}

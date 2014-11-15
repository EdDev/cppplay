/*
 * normalize_string.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: edwardh
 */

#include "string.h"
#include "normalize_string.h"


unsigned int Normalizer::normalize_string_inplace(char * string, size_t& string_len, const char norm_char)
{
    size_t normalized_string_len = string_len;

    for(char *str_itr = string; str_itr < &string[normalized_string_len-1]; ++str_itr)
    {
        if(norm_char == *str_itr)
        {
            char *dst;
            for(dst = ++str_itr; (norm_char == *str_itr); ++str_itr);

            if(str_itr > dst)
            {
                memmove(dst, str_itr, normalized_string_len - (str_itr - string));
                normalized_string_len -= str_itr - dst;
            }
        }
    }

    int num_of_reduced_appearances = string_len - normalized_string_len;
    string_len = normalized_string_len;

    return num_of_reduced_appearances;
}



unsigned int Normalizer::normalize_string_fast(const char *src_string, char *dst_string, size_t& string_len, const char norm_char)
{
    const char  *in_itr = src_string;
    char        *out_itr = dst_string;

    while(in_itr < &src_string[string_len-1])
    {
        *out_itr = *in_itr;

        if(norm_char == *in_itr)
            for(++in_itr; (norm_char == *in_itr); ++in_itr);
        else
            ++in_itr;

        ++out_itr;
    }

    string_len = out_itr - dst_string;
    size_t src_string_len             = in_itr - src_string;
    size_t num_of_reduced_appearances = src_string_len - string_len;

    return num_of_reduced_appearances;
}


/*
 * char_stream_req.cpp
 *
 *  Created on: Nov 14, 2014
 *      Author: edwardh
 */

#include <cstring>

#include "char_stream_req.h"


CharStreamReq::CharStreamReq()
{
    this->max_num_of_unique_chars = (unsigned char)~0 + 1;
    this->char_occurrence_count = new unsigned int[max_num_of_unique_chars];

    clearRecv();
}

CharStreamReq::~CharStreamReq()
{
    delete []this->char_occurrence_count;
}


void CharStreamReq::recv(unsigned char in_char)
{
    char_occurrence_count[in_char]++;
}


void CharStreamReq::printRecvSorted(char *outbuffer, size_t buf_size)
{
    size_t char_out_itr = 0;

    for(unsigned int char_in_itr = 0; char_in_itr < max_num_of_unique_chars; ++char_in_itr)
    {
        int num_of_chars_to_output = char_occurrence_count[char_in_itr];
        for(int duplicate_char_out_itr = 0;
           (duplicate_char_out_itr < num_of_chars_to_output) && (char_out_itr < buf_size-1);
           ++duplicate_char_out_itr)
        {
            outbuffer[char_out_itr] = char_in_itr;
            char_out_itr++;
        }
    }

    outbuffer[char_out_itr] = '\0';
}

void CharStreamReq::clearRecv()
{
    std::memset(this->char_occurrence_count, 0 ,max_num_of_unique_chars * sizeof(*char_occurrence_count));
}

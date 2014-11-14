/*
 * char_stream_req.h
 *
 * Description:
 * Receive a stream of characters (ASCII), accumulate them and
 * provide the means to output them in an acceding sorted manner.
 *
 * Limitations:
 * - Sorted based on the ASCII table, no special care has been done to handle upper and lower characters.
 * - It can accumulate between 2^(sizeof(int)) to 256 * (2^(sizeof(int))) characters.
 *
 * Note: It is up to the application that uses this module to specify how many characters to recv
 *       until a print is performed, followed by a clear to reset the data.
 *
 *
 *  Created on: Nov 14, 2014
 *      Author: edwardh
 */

#ifndef CHAR_STREAM_REQ_H_
#define CHAR_STREAM_REQ_H_


class CharStreamReq
{
public:
    CharStreamReq();
    ~CharStreamReq();

    void recv(unsigned char in_char);
    void printRecvSorted(char *outbuffer, size_t buf_size);
    void clearRecv();

private:
    unsigned int *char_occurrence_count;
    unsigned int  max_num_of_unique_chars;
};


#endif /* CHAR_STREAM_REQ_H_ */

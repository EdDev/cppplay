/*
 * normalize_string.h
 *
 * Description:
 * given a string and a char, normalize the string
 * by removing consecutive appearances of the char,
 * outputting a new string.
 *
 * Two implementation are given:
 * - Inplace, which does not require additional memory.
 * - Fast, which process the input at O(n) but requires an additional memory (O(n)).
 *
 * Both implementations output 3 results:
 * - Normalized string.
 * - Updated string length.
 * - The number of characters removed.
 *
 *  Created on: Nov 15, 2014
 *      Author: edwardh
 */

#ifndef NORMALIZE_STRING_H_
#define NORMALIZE_STRING_H_


class Normalizer
{
public:
    static unsigned int normalize_string_inplace(char * string, size_t& string_len, const char norm_char);
    static unsigned int normalize_string_fast(const char *src_string, char *dst_string, size_t& string_len, const char norm_char);
};


#endif /* NORMALIZE_STRING_H_ */

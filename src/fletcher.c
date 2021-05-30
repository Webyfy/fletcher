/**
 * @file fletcher.c
 * @author dhanesh (dhanesh@webyfy.com)
 * @brief library for calculating fletcher's checksums
 *
 * @version 0.1
 * @date 2021-05-30
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "fletcher.h"

/**
 * @brief calculates fletcher16 of given  data
 *
 * @param data data for which checksum needs to be calculated
 * @param bytes length of data in bytes
 * @return fletcher16 checksum of the data
 */
uint16_t fletcher16(const uint8_t *data, size_t bytes) {
  uint16_t sum1 = 0xff, sum2 = 0xff;

  while (bytes) {
    size_t tlen = bytes > 20 ? 20 : bytes;
    bytes -= tlen;
    do {
      sum2 += sum1 += *data++;
    } while (--tlen);
    sum1 = (sum1 & 0xff) + (sum1 >> 8);
    sum2 = (sum2 & 0xff) + (sum2 >> 8);
  }
  /* Second reduction step to reduce sums to 8 bits */
  sum1 = (sum1 & 0xff) + (sum1 >> 8);
  sum2 = (sum2 & 0xff) + (sum2 >> 8);
  return sum2 << 8 | sum1;
}

/**
 * @brief calculates fletcher32 of given  data
 *
 * @param data data for which checksum needs to be calculated
 * @param words length of data in words
 * @return fletcher32 checksum of the data
 */
uint32_t fletcher32(const uint16_t *data, size_t words) {
  uint32_t sum1 = 0xffff, sum2 = 0xffff;

  while (words) {
    unsigned tlen = words > 359 ? 359 : words;
    words -= tlen;
    do {
      sum2 += sum1 += *data++;
    } while (--tlen);
    sum1 = (sum1 & 0xffff) + (sum1 >> 16);
    sum2 = (sum2 & 0xffff) + (sum2 >> 16);
  }
  /* Second reduction step to reduce sums to 16 bits */
  sum1 = (sum1 & 0xffff) + (sum1 >> 16);
  sum2 = (sum2 & 0xffff) + (sum2 >> 16);
  return sum2 << 16 | sum1;
}
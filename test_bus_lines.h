#ifndef EX2_REPO_TESTBUSLINES_H
#define EX2_REPO_TESTBUSLINES_H
#include "sort_bus_lines.h"

/**
 * is_sorted_by_distance - a function that checks if an array of BusLine
 * objects is sorted by distance in ascending order.
 */
int is_sorted_by_distance (BusLine *start, BusLine *end);

/**
 * is_sorted_by_duration - a function that checks if an array of BusLine
 * objects is sorted by duration in ascending order.
 */
int is_sorted_by_duration (BusLine *start, BusLine *end);

/**
 * is_sorted_by_name - a function that checks if an array of BusLine
 * objects is sorted by name in ascending order.
 */
int is_sorted_by_name (BusLine *start, BusLine *end);

/**
 * is_equal - a function that checks if two arrays of BusLine objects are equal.
 */
int is_equal (BusLine *start_sorted,
              BusLine *end_sorted, BusLine *start_original,
              BusLine *end_original);
// write only between #define EX2_REPO_TESTBUSLINES_H and #endif //EX2_REPO_TESTBUSLINES_H
#endif //EX2_REPO_TESTBUSLINES_H

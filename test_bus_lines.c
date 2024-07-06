#include "test_bus_lines.h"
#include <stdbool.h>
#define PASSED 1
#define FAILED 0

/**
 * @brief Counts the number of bus lines between the start and end pointers.
 *
 * @param start Pointer to the start of the bus lines array.
 * @param end Pointer to the end of the bus lines array.
 * @return The number of bus lines.
 */
int count_lines(BusLine *start, BusLine *end){
  int index = 1;
  while(start != end){
    index++;
    start++;
  }
  return index;
}

/**
 * @brief Checks if the current bus line has the minimum distance in the array.
 *
 * @param start Pointer to the current bus line.
 * @param end Pointer to the end of the bus lines array.
 * @return true if the current bus line has the minimum distance, false otherwise.
 */
bool is_min_distance(BusLine *start, BusLine *end){
  BusLine *cur = start;
  while(cur-1!=end){
    if(start->distance > cur->distance){
      return false;
    }
    cur++;
  }
  return true;
}

/**
 * @brief Checks if the current bus line has the minimum duration in the array.
 *
 * @param start Pointer to the current bus line.
 * @param end Pointer to the end of the bus lines array.
 * @return true if the current bus line has the minimum duration, false otherwise.
 */
bool is_min_duration(BusLine *start, BusLine *end){
  BusLine *cur = start;
  while(cur-1!=end){
    if(start->duration > cur->duration){
      return false;
    }
    cur++;
  }
  return true;
}

/**
 * @brief Checks if the current bus line has the minimum name (lexicographically) in the array.
 *
 * @param start Pointer to the current bus line.
 * @param end Pointer to the end of the bus lines array.
 * @return true if the current bus line has the minimum name, false otherwise.
 */
bool is_min_name(BusLine *start, BusLine *end){
  BusLine *cur = start;
  while(cur-1!=end){
    if(strcmp (start->name, cur->name) > 0){
      return false;
    }
    cur++;
  }
  return true;
}

/**
 * @brief Checks if the bus lines are sorted by distance.
 *
 * @param start Pointer to the start of the bus lines array.
 * @param end Pointer to the end of the bus lines array.
 * @return PASSED if the bus lines are sorted by distance, FAILED otherwise.
 */
int is_sorted_by_distance (BusLine *start, BusLine *end){
  if(start == end){
    return PASSED;
  }
  while(start != end){
    if(is_min_distance(start, end) == false){
      return FAILED;
    }
    start++;
  }
  return PASSED;
}

/**
 * @brief Checks if the bus lines are sorted by duration.
 *
 * @param start Pointer to the start of the bus lines array.
 * @param end Pointer to the end of the bus lines array.
 * @return PASSED if the bus lines are sorted by duration, FAILED otherwise.
 */
int is_sorted_by_duration (BusLine *start, BusLine *end){
  if(start == end){
    return PASSED;
  }
  while(start != end){
    if(is_min_duration(start, end) == false){
      return FAILED;
    }
    start++;
  }
  return PASSED;
}

/**
 * @brief Checks if the bus lines are sorted by name (lexicographically).
 *
 * @param start Pointer to the start of the bus lines array.
 * @param end Pointer to the end of the bus lines array.
 * @return PASSED if the bus lines are sorted by name, FAILED otherwise.
 */
int is_sorted_by_name (BusLine *start, BusLine *end){
  if(start == end){
    return PASSED;
  }
  while(start != end){
    if(is_min_name(start, end) == false){
      return FAILED;
    }
    start++;
  }
  return PASSED;
}

/**
 * @brief Checks if two arrays of bus lines are equal.
 *
 * @param start_sorted Pointer to the start of the sorted bus lines array.
 * @param end_sorted Pointer to the end of the sorted bus lines array.
 * @param start_original Pointer to the start of the original bus lines array.
 * @param end_original Pointer to the end of the original bus lines array.
 * @return PASSED if the arrays are equal, FAILED otherwise.
 */
int is_equal (BusLine *start_sorted, BusLine *end_sorted,
              BusLine *start_original, BusLine *end_original){
  int copy_lines_number = count_lines (start_sorted, end_sorted);
  int original_lines_number = count_lines (start_original, end_original);
  if(copy_lines_number != original_lines_number){
    return FAILED;
  }
  if(copy_lines_number == 1)
  {
    if (start_sorted == start_original)
    {
      return PASSED;
    }
    return FAILED;
  }
  while(start_sorted-1 != end_sorted){
    if(start_sorted != start_original){
      return FAILED;
    }
    start_sorted++;
    start_original++;
  }
  return PASSED;
}

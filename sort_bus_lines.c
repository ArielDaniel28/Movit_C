#include "sort_bus_lines.h"
#include <stdbool.h>
#include <string.h>

/**
 * @brief Swaps two bus lines.
 *
 * @param start Pointer to the first bus line.
 * @param end Pointer to the second bus line.
 */
void swap(BusLine *start, BusLine *end);

/**
 * @brief Partitions the bus lines for quicksort.
 *
 * @param start Pointer to the start of the bus lines array.
 * @param end Pointer to the end of the bus lines array.
 * @param sort_type Type of sorting (by distance or duration).
 * @return Pointer to the pivot element.
 */
BusLine *partition (BusLine *start, BusLine *end, SortType sort_type){
  BusLine *pivot = end;
  BusLine *cur_1 = start-1;
  if(sort_type == DISTANCE){
    for(BusLine* cur_2 = start; cur_2<=end-1; cur_2++){
      if(cur_2->distance <= pivot->distance){
        cur_1++;
        swap(cur_1, cur_2);
      }
    }
    swap(cur_1 +1, end);
    return cur_1 +1;
  }
  else{
    for(BusLine* cur_2 = start; cur_2<=end-1; cur_2++){
      if(cur_2->duration <= pivot->duration){
        cur_1++;
        swap(cur_1, cur_2);
      }
    }
    swap(cur_1 +1, end);
    return cur_1 +1;
  }
}

/**
 * @brief Sorts the bus lines using quicksort algorithm.
 *
 * @param start Pointer to the start of the bus lines array.
 * @param end Pointer to the end of the bus lines array.
 * @param sort_type Type of sorting (by distance or duration).
 */
void quick_sort (BusLine *start, BusLine *end, SortType sort_type){
  if(start < end){
    BusLine *pivot = partition (start, end, sort_type);
    quick_sort (start, pivot-1, sort_type);
    quick_sort (pivot + 1, end, sort_type);
  }
}

/**
 * @brief Swaps two bus lines.
 *
 * @param start Pointer to the first bus line.
 * @param end Pointer to the second bus line.
 */
void swap(BusLine *start, BusLine *end){
  BusLine tmp = *start;
  *start = *end;
  *end = tmp;
}

/**
 * @brief Calculates the number of bus lines between the start and end pointers.
 *
 * @param start Pointer to the start of the bus lines array.
 * @param end Pointer to the end of the bus lines array.
 * @return The number of bus lines.
 */
int number_of_lines(BusLine *start, BusLine *end){
  int index = 1;
  while(start != end){
    index++;
    start++;
  }
  return index;
}

/**
 * @brief Sorts the bus lines using bubble sort algorithm.
 *
 * @param start Pointer to the start of the bus lines array.
 * @param end Pointer to the end of the bus lines array.
 */
void bubble_sort (BusLine *start, BusLine *end){
  int lines_num = number_of_lines(start, end);
  for(int i=0; i<lines_num-1;i++){
    for(int j=0; j<lines_num-i-1; j++){
      BusLine *cur_1 =  start + j;
      BusLine *cur_2 =  start + j+1;
      if(strcmp (cur_1->name, cur_2->name) > 0){
        swap (cur_1, cur_2);
      }
    }
  }
}

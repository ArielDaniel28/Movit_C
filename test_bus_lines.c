#include "test_bus_lines.h"
#include <stdbool.h>
#define PASSED 1
#define FAILED 0

int count_lines(BusLine *start, BusLine *end){
  int index = 1;
  while(start != end){
    index++;
    start++;
  }
  return index;
}

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
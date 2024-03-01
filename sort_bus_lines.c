#include "sort_bus_lines.h"
#include <stdbool.h>
#include <string.h>

void swap(BusLine *start, BusLine *end);

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

void quick_sort (BusLine *start, BusLine *end, SortType sort_type){
  if(start < end){
    BusLine *pivot = partition (start, end, sort_type);
    quick_sort (start, pivot-1, sort_type);
    quick_sort (pivot + 1, end, sort_type);
  }
}

void swap(BusLine *start, BusLine *end){
  BusLine tmp = *start;
  *start = *end;
  *end = tmp;
}

int number_of_lines(BusLine *start, BusLine *end){
  int index = 1;
  while(start != end){
    index++;
    start++;
  }
  return index;
}


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
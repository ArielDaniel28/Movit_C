#ifndef EX2_REPO_SORTBUSLINES_H
#define EX2_REPO_SORTBUSLINES_H
#include <string.h>
#define NAME_LEN 21

/**
 * @brief Structure representing a bus line with a name, distance, and duration.
 */
typedef struct BusLine
{
    char name[NAME_LEN];
    int distance, duration;
} BusLine;

/**
 * @brief Enum representing the type of sorting criteria.
 */
typedef enum SortType
{
    DISTANCE,
    DURATION
} SortType;

/**
 *
start: A pointer to the beginning of the array of BusLine objects to be sorted.
end: A pointer to the end of the array of BusLine objects to be sorted.
 */
void bubble_sort (BusLine *start, BusLine *end);

/**
 *
start: A pointer to the beginning of the array of BusLine objects to be sorted.
end: A pointer to the end of the array of BusLine objects to be sorted.
sort_type: A variable of type SortType that specifies the sorting criteria.
 */
void quick_sort (BusLine *start, BusLine *end, SortType sort_type);

/**
 *
start: A pointer to the beginning of the array of BusLine objects to be partitioned.
end: A pointer to the end of the array of BusLine objects to be partitioned.
sort_type: A variable of type SortType that specifies the sorting criteria.
 */
BusLine *partition (BusLine *start, BusLine *end, SortType sort_type);
// write only between #define EX2_REPO_SORTBUSLINES_H and #endif //EX2_REPO_SORTBUSLINES_H
#endif //EX2_REPO_SORTBUSLINES_H

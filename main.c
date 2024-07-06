#include "sort_bus_lines.h"
#include "test_bus_lines.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define ARG_A "by_duration"
#define ARG_B "by_distance"
#define ARG_C "by_name"
#define TEST "test"
#define EQUAL 0
#define INVALID 0
#define VALID_ARGC 2
#define COMMAND 1
#define INPUT_LINE_LENGTH 60
#define ZERO_DIGIT 48
#define NINE_DIGIT 57
#define LETTER_Z 122
#define LETTER_A 97
#define COMMA_CHAR ','
#define END_OF_INPUT_1 '\0'
#define END_OF_INPUT_2 '\n'
#define DISTANCE_LOWER_LIMIT 0
#define DISTANCE_UPPER_LIMIT 1000
#define DURATION_LOWER_LIMIT 10
#define DURATION_UPPER_LIMIT 100
#define TEST_SUCCESS 1

/**
 * @brief Check if the command line argument is invalid.
 *
 * @param input The command line argument to check.
 * @return true if the argument is invalid, false otherwise.
 */
bool invalid_cli(char input[]) // check if the argument from cli is invalid
{
  if(strcmp (input, ARG_A)!=EQUAL){
    if(strcmp (input, ARG_B)!=EQUAL){
      if(strcmp (input, ARG_C)!=EQUAL){
        if(strcmp (input, TEST)!=EQUAL){
          return true;
        }
      }
    }
  }
  return false;
}

/**
 * @brief Get the number of lines from the user and ensure it is valid.
 *
 * @return The number of lines entered by the user.
 */
int get_lines_num() // check if lines number is valid
{
  int lines_num = INVALID;
  char buf[INPUT_LINE_LENGTH] = {0};
  bool valid_num = false;
  while(valid_num == false)
  {
    valid_num = true;
    printf("Enter number of lines. Then enter\n");
    fgets (buf, INPUT_LINE_LENGTH, stdin);
    int index = 0;
    while(buf[index]!=END_OF_INPUT_1 && buf[index]!=END_OF_INPUT_2) // check if the number
      // contains
      // only digits
    {
      if((buf[index]<ZERO_DIGIT)||(buf[index]>NINE_DIGIT))
      {
        printf("Error: The number can only contain digits (0-9), please try "
               "again.\n");
        valid_num = false;
        break;
      }
      index++;
    }
    if(valid_num==true)
    {
      sscanf (buf,"%d", &lines_num);
      if(lines_num == INVALID) // check if sscanf failed
      {
        printf("Error: The lines number has to be >0. Try again\n");
        valid_num = false;
        continue;
      }
    }
  }
  return lines_num;
}

/**
 * @brief Check if the character is a valid name character (digit or lowercase letter).
 *
 * @param c The character to check.
 * @return true if the character is valid, false otherwise.
 */
bool valid_name(char c){
  if(((c>LETTER_Z)||(c<LETTER_A))&&((c>NINE_DIGIT)||(c<ZERO_DIGIT))){
    return false;
  }
  return true;
}

/**
 * @brief Check if the character is a valid distance character (digit).
 *
 * @param c The character to check.
 * @return true if the character is valid, false otherwise.
 */
bool valid_distance(char c){
  if((c>NINE_DIGIT)||(c<ZERO_DIGIT)){
    return false;
  }
  return true;
}

/**
 * @brief Update the details of a bus line.
 *
 * @param line The bus line to update.
 * @param line_name The name of the bus line.
 * @param distance The distance of the bus line.
 * @param duration The duration of the bus line.
 */
void update_line(BusLine *line, char *line_name, int distance, int duration){
  strcpy (line->name, line_name);
  line->distance = distance;
  line->duration = duration;
}

/**
 * @brief Get the details of bus lines from the user.
 *
 * @param bus_lines The array of bus lines to populate.
 * @param lines_num The number of lines to get details for.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int get_lines_details(BusLine *bus_lines, int lines_num){
  char buf[INPUT_LINE_LENGTH];
  for(int i=0;i<lines_num;i++) // one iteration represents one bus line
  {
    bool valid_input = false;
    while(valid_input==false) // The loop will break only if the input is valid
    {
      int name_length = 0;
      valid_input=true;
      int index = 0;
      printf("Enter line info. Then enter\n");
      fgets(buf, INPUT_LINE_LENGTH, stdin);
      while(buf[index] != COMMA_CHAR) // focus on the name part
      {
        if(valid_name(buf[index]) == false){
          printf("ERROR: bus name should contain only digits and small "
                 "letters. Try again.\n");
          valid_input = false;
          break;
        }
        name_length++;
        index++;
      }
      if(valid_input==false){
        continue;
      }
      index++;
      while(buf[index]!= COMMA_CHAR) // focus on distance part
      {
        if((valid_distance(buf[index]) == false)){
          printf("ERROR: distance should be an integer between 0 and 1000 "
                 "(includes)\n");
          valid_input = false;
          break;
        }
        index++;
      }
      if(valid_input == false){
        continue;
      }
      index++;
      while(buf[index] != END_OF_INPUT_1 && buf[index] != END_OF_INPUT_2)
        //focus on
        // duration part
      {
        if((valid_distance (buf[index])) == false){
          printf("ERROR: duration should be an integer between 10 and 100 "
                 "(includes)\n");
          valid_input = false;
          break;
        }
        index++;
      }
      char *name = malloc(name_length+1);
      if(name==NULL){
        return EXIT_FAILURE;
      }
      int distance = DISTANCE_UPPER_LIMIT;
      int duration = 0;
      sscanf (buf, "%[^,],%d,%d", name, &distance, &duration);
      if((distance<DISTANCE_LOWER_LIMIT)||(distance>DISTANCE_UPPER_LIMIT)){
        printf("ERROR: distance should be an integer between 0 and 1000 "
               "(includes)\n");
        valid_input = false;
        continue;
      }
      if((duration<DURATION_LOWER_LIMIT)||(duration>DURATION_UPPER_LIMIT)){
        printf("ERROR: duration should be an integer between 10 and 100 "
               "(includes)\n");
        valid_input = false;
        continue;
      }
      update_line(&bus_lines[i], name, distance, duration);
      free(name);
    }
  }
  return EXIT_SUCCESS;
}

/**
 * @brief Print the sorted array of bus lines.
 *
 * @param bus_lines The array of bus lines to print.
 * @param lines_num The number of bus lines.
 */
void print_sorted_array(BusLine *bus_lines, int lines_num){
  for(int i=0; i < lines_num; i++){
    printf("%s,%d,%d\n", bus_lines->name, bus_lines->distance,
           bus_lines->duration);
    bus_lines++;
  }
}

/**
 * @brief Perform tests on the sorting functions and print the results.
 *
 * @param copy_start Pointer to the start of the copy array.
 * @param copy_end Pointer to the end of the copy array.
 * @param original_start Pointer to the start of the original array.
 * @param original_end Pointer to the end of the original array.
 */
void test_mode(BusLine *copy_start, BusLine *copy_end, BusLine
*original_start, BusLine *original_end){
  quick_sort (copy_start, copy_end, DISTANCE);
  int test_1 = is_sorted_by_distance (copy_start,copy_end);
  int test_2 = is_equal (copy_start, copy_end,
                         original_start,original_end);
  quick_sort (copy_start, copy_end, DURATION);
  int test_3 = is_sorted_by_duration (copy_start,copy_end);
  int test_4 = is_equal (copy_start, copy_end,
                         original_start,original_end);
  bubble_sort (copy_start, copy_end);
  int test_5 = is_sorted_by_name (copy_start, copy_end);
  int test_6 = is_equal (copy_start, copy_end,
                         original_start,original_end);
  if(test_1 == TEST_SUCCESS){
    printf("TEST 1 \n");
  }
  else{
    printf("TEST 1 FAILED\n");
  }
  if(test_2 == TEST_SUCCESS){
    printf("TEST 2 PASSED\n");
  }
  else{
    printf("TEST 2 FAILED\n");
  }
  if(test_3 == TEST_SUCCESS){
    printf("TEST 3 PASSED\n");
  }
  else{
    printf("TEST 3 FAILED\n");
  }
  if(test_4 == TEST_SUCCESS){
    printf("TEST 4 PASSED\n");
  }
  else{
    printf("TEST 4 FAILED\n");
  }
  if(test_5 == TEST_SUCCESS){
    printf("TEST 5 PASSED\n");
  }
  else{
    printf("TEST 5 FAILED\n");
  }
  if(test_6 == TEST_SUCCESS){
    printf("TEST 6 PASSED\n");
  }
  else{
    printf("TEST 6 FAILED\n");
  }
}
/**
 * @brief Main function to run the program.
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main (int argc, char *argv[])
{
  if(argc != VALID_ARGC || invalid_cli (argv[COMMAND]))
  {
    printf ("USAGE: Valid input (only 1): %s, %s, %s, %s\n", ARG_A, ARG_B,
            ARG_C, TEST);
    return EXIT_FAILURE;
  }
  int lines_num = get_lines_num();
  BusLine *bus_lines = NULL;
  bus_lines = (BusLine*) calloc (lines_num, sizeof (BusLine));
  if(bus_lines == NULL){
    return EXIT_FAILURE;
  }
  int check = get_lines_details(bus_lines, lines_num);
  if(check == EXIT_FAILURE){
    return EXIT_FAILURE;
  }
  if(strcmp (argv[COMMAND], TEST) == EQUAL) // if the user chose "Test" mode
  {
    BusLine *array_copy = NULL;
    array_copy = (BusLine*) calloc (lines_num, sizeof(BusLine));
    if(array_copy == NULL){
      return EXIT_FAILURE;
    }
    memcpy (array_copy, bus_lines, (sizeof(BusLine)*lines_num));
    test_mode(&array_copy[0], &array_copy[lines_num-1], &bus_lines[0],
              &bus_lines[lines_num-1]);
  }
  if(strcmp (argv[COMMAND], ARG_B) == EQUAL){
    quick_sort (&bus_lines[0], &bus_lines[lines_num-1], DISTANCE);
    print_sorted_array(bus_lines, lines_num);
  }
  if(strcmp (argv[COMMAND], ARG_A) == EQUAL){
    quick_sort (&bus_lines[0], &bus_lines[lines_num-1], DURATION);
    print_sorted_array(bus_lines, lines_num);
  }
  if(strcmp (argv[COMMAND], ARG_C) == EQUAL){
    bubble_sort (&bus_lines[0], &bus_lines[lines_num-1]);
    print_sorted_array(bus_lines, lines_num);
  }
  free (bus_lines);
  return EXIT_SUCCESS;
}

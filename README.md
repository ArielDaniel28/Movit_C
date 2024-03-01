## Bus Lines Sorting Program
This program allows users to input information about bus lines, including their names, distances, and durations, and then sorts the bus lines based on different criteria such as duration, distance, or name. Additionally, it includes a testing mode to verify the correctness of the sorting algorithms implemented.

## Usage
To run the program, execute the compiled binary with one of the following command-line arguments:

by_duration: Sort bus lines by duration.
by_distance: Sort bus lines by distance.
by_name: Sort bus lines by name.
test: Run testing mode to verify sorting algorithms.

## Input Format
The program prompts the user to input the number of bus lines and then the details for each bus line. The input format for each bus line is as follows:
<name>,<distance>,<duration>
<name>: A string containing only lowercase letters and digits.
<distance>: An integer between 0 and 1000 (inclusive) representing the distance of the bus line.
<duration>: An integer between 10 and 100 (inclusive) representing the duration of the bus line.

## Sorting Options
The program supports three sorting options:

By Duration (by_duration): Sort bus lines by duration in ascending order.
By Distance (by_distance): Sort bus lines by distance in ascending order.
By Name (by_name): Sort bus lines by name in alphabetical order.

## Testing Mode
The program includes a testing mode to verify the correctness of the sorting algorithms implemented. To run testing mode, use the test command-line argument.

Example:

./bus_lines test

## Compilation
To compile the program, ensure you have the necessary header files (sort_bus_lines.h and test_bus_lines.h) included in the same directory as the source code. Then, use a C compiler such as GCC to compile the program:
gcc -o bus_lines main.c sort_bus_lines.c test_bus_lines.c -std=c99

## License
This program was written by a student of the Introduction to Computer Science course at the Hebrew University in Jerusalem.

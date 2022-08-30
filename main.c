/**
 * main.c
 *
 * Demonstrates the use of the array type.
 *
 * Author: Richard Gale
 * Version: 30th August, 2022
 */

#include <stdio.h>

#include "array.h"

int main(int argc, char* argv[])
{
    array storage;          // The array.
    char* data = "MyData";  // The data to store.
    uint64_t num_elems;     // The number of elements of the data.
    uint64_t elem;          // The index of the current element of the array.

    // Initialising the array.
    array_init(&storage);

    // Initialisation of the number of elements in the data.
    num_elems = sizeof(data) / sizeof(char);

    // Adding the data to the array.
    for (elem = 0; elem < num_elems; elem++)
    {
        array_push_back(&storage, &(data[elem]));
    }

    // Printing the data in the array.
    for (elem = 0; elem < array_size(storage); elem++)
    {
        // Printing the current element.
        printf("%c", *((char*) array_get_data(storage, elem)));
    }
    printf("\n");

    // Removing the data from the first element to the last and
    // printing it in that order.
    while (array_size(storage) > 0)
    {
        // Removing and printing the last element in the array.
        printf("%c", *((char*) array_pop_back(&storage)));
    }
    printf("\n");

    // Freeing memory.
    array_free(&storage);

    // Exiting the program.
    return 0;
}
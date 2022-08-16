/**
 * main.c
 *
 * Demonstrates the use of the array type.
 *
 * Author: Richard Gale
 * Version: 16th August, 2022
 */

#include <stdio.h>

#include "array.h"

int main(int argc, char* argv[])
{
    array storage;  // The array.
    char* data_to_store = "MyData"; // The data we're going to store in the array.
    int num_elems = sizeof(data_to_store) / sizeof(char);   // The number of elements in the data.

    // Initialising the array.
    array_init(&storage);

    // Adding the data to the array.
    for (int i = 0; i < num_elems; i++)
    {
        array_push_back(&storage, &(data_to_store[i]));
    }

    // Printing the data in the array.
    for (int i = 0; i < array_size(storage); i++)
    {
        printf("%c", *((char*) array_get_data(storage, i)));
    }
    printf("\n");

    // Removing the data from the first element to the last and
    // printing it in that order.
    for (int i = 0; i < num_elems; i++)
    {
        printf("%c", *((char*) array_pop_back(&storage)));
    }
    printf("\n");

    return 0;
}

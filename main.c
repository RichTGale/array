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
    array storage;          // The array.
    char* data = "MyData";  // The data to store.
    // The number of elements of the data.
    int num_elems = sizeof(data) / sizeof(char);

    // Initialising the array.
    array_init(&storage);

    // Adding the data to the array.
    for (int i = 0; i < num_elems; i++)
    {
        array_push_back(&storage, &(data[i]));
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

    // Freeing memory
    array_free(&storage);

    return 0;
}
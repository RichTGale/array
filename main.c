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

int main(int argc, char* argv)
{
    array storage;
    char* data_to_store = "MyData";
    int num_elems = sizeof(data_to_store) / sizeof(char);

    array_init(&storage);

    for (int i = 0; i < num_elems; i++)
    {
        array_push_back(&storage, &(data_to_store[i]));
    }

    for (int i = 0; i < array_size(storage); i++)
    {
        printf("%c", *((char*) array_get_data(storage, i)));
    }
    printf("\n");

    for (int i = 0; i < num_elems; i++)
    {
        printf("%c", *((char*) array_pop_back(&storage)));
    }
    printf("\n");


    return 0;
}

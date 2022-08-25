/**
 * array.c
 *
 * Data-structure and procedure definitions for a singly-linked-list:
 * an array that dynamically allocates and frees memory as elements
 * are added to it and removed from it.
 *
 * Author: Richard Gale
 * Version: 25th August, 2022
 */

// Including file(s).
#include "array.h"

// Error codes.
#define INDEX_OUT_OF_BOUNDS_ERROR 1
#define EMPTY_LIST_ERROR 2
#define CAPACITY_OVERLOAD_ERROR 3

// The maximum number of elements the array can have.
#define MAX_CAPACITY UINT32_MAX

/**
 * Data contained in the array data-structure
 */
struct array_data {
	void* data;		// The data that the node contains
	array next;		// The next element in the array
};

/**
 * Inititialises the array.
 */
void array_init(array* a_ref)
{
	*a_ref = (array) malloc(sizeof(struct array_data));
	(*a_ref)->data = NULL;
	(*a_ref)->next = NULL;
}

/**
 * Frees the memory allocated at the provided array reference.
 */
void array_free_elem(array* a_ref)
{
	free(*a_ref);
}

/**
 * Frees the memory allocated at the provided array
 * and any arrays (elements) linked to it.
 */
void array_free(array* a_ref)
{
	if ((*a_ref)->next != NULL)
	{
		array_free(&(*a_ref)->next);
	}
	array_free_elem(a_ref);
}

/**
 * Returns the data in the provided array at the element
 * at the provided index.
 */ 
void* array_get_data(array head, uint32_t index)
{
	uint32_t elem; // The current element of the array. 

	for (elem = 0; elem < index; elem++)
	{
		if (head->next != NULL)
		{
			head = head->next;
		} else
		{
			printf(
				"\nERROR: In function array_get_data(): "
				"index %d was out of bounds!\n", 
				elem + 1
			);
			exit(INDEX_OUT_OF_BOUNDS_ERROR);
		}
	}
	return head->data;
}

/**
 * Returns the number of elements in the provided array.
 */
uint32_t array_size(array head)
{
    uint32_t size = 0; // The number of elements in the array

	if (head->data != NULL)
	{
		size++;
		while (head->next != NULL)
		{
			size++;
			head = head->next;
		}
	}
	return size;
}

/**
 * Removes the first element in the array at the provided
 * reference and returns it.
 */
void* array_pop_front(array* head_ref)
{
	array next;		// A copy of the array starting from the second element
	void* front;	// The data contained in the first element

	if (array_size(*head_ref) > 0)
	{
		front = (*head_ref)->data;
		next  = (*head_ref)->next;
		array_free_elem(head_ref);
		*head_ref = next;

		if (*head_ref == NULL)
		{
			// Re-initializing the array because we just destroyed the head
			array_init(head_ref);
		}
	} else
	{
		printf(
			"\nERROR: In function arrary_pop_front: "
			"Attempted to pop front of an empty array!\n"
		);
		exit(EMPTY_LIST_ERROR);
	}
	return front;
}

/**
 * Removes the last element from the array at the provided
 * reference and returns it.
 */
void* array_pop_back(array* head_ref)
{
	void* back;		// The data contained in the back element
	uint32_t size;		// The number of elements in the array

	size = array_size(*head_ref);

	if (size > 0)
	{
		while ((*head_ref)->next != NULL)
		{
			head_ref = &(*head_ref)->next;
		}

		back = (*head_ref)->data;
		array_free_elem(head_ref);

		if (size > 1)
		{
			*head_ref = NULL;
		} else
		{
			// Re-initializing the array because we just destroyed the head
			array_init(head_ref);
		}
	} else
	{
		printf(
			"\nERROR: In function array_pop_back: "
			"Attempted to pop back of empty array!\n"
		);
		exit(EMPTY_LIST_ERROR);
	}

	return back;
}

/**
 * Adds a new element to the beginning of the array at
 * the provided array reference.
 */
void array_push_front(array* head_ref, void* data)
{
	array new;	// The new element to be added to the list

	if ((*head_ref)->data == NULL)
	{
		(*head_ref)->data = data;
	} else
	{
		if (array_size(*head_ref) < MAX_CAPACITY)
		{
			array_init(&new);
			new->data = data;
			new->next = *head_ref;
			*head_ref = new;
		}
		else
		{
			printf(
				"\nERROR: In function array_push_front(): "
				"Attempted to push an element into a full array!\n"
			);
			exit(CAPACITY_OVERLOAD_ERROR);
		}
	}
}

/**
 * Adds a new element to the end of the array at the provided
 * array reference.
 */
void array_push_back(array* head_ref, void* data)
{
	if ((*head_ref)->data == NULL)
	{
		(*head_ref)->data = data;
	}
	else
	{
		if (array_size(*head_ref) < MAX_CAPACITY)
		{
			while ((*head_ref)->next != NULL)
			{
				head_ref = &(*head_ref)->next;
			}
			array_init(&(*head_ref)->next);
			(*head_ref)->next->data = data;
		}
		else
		{
			printf(
				"\nERROR: In function array_push_back(): "
				"Attempted to push an element into a full array!\n"
			);
			exit(CAPACITY_OVERLOAD_ERROR);
		}
	}
}

/**
 * Sets the data in the element at the provided index of the
 * array at the provided array reference.
 */
void array_set_data(array* head_ref, uint32_t index, void* data)
{
	for (uint32_t i = 0; i < index; i++)
	{
		if ((*head_ref)->next != NULL)
		{
			head_ref = &(*head_ref)->next;
		} else
		{
			printf(
				"\nERROR: In function array_set_data(): "
				"index %d out of bounds!", 
				i
			);
			exit(INDEX_OUT_OF_BOUNDS_ERROR);
		}
	}
	(*head_ref)->data = data;
}




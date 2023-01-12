#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define dequeue(l) pop(l)

typedef struct Node{
	void* d;
	struct Node* next;
} node;

typedef struct List{
	uintmax_t total;
	struct Node* head;
	struct Node* tail;
} list;

list *new_list(void);
/* Dynamically allocate a list.
 * Returns a NULL list pointer if it cannot allocate a new list.
 */

void free_list(list* l);
/* Loop through the list, freeing any nodes.
 * Then, free the list struct itself.
 * Should be safe to call on a NULL list pointer.
 */

void *pop(list* l);
/* Remove a list item,
 * return a pointer to the data that
 * the list node contained.
 * You must free the data that is returned.
 */

void push(list* l, const size_t size, const void *restrict data);
/* Prepend a list with a new list item.
 */

void enqueue(list* l, size_t size, void* data);
/* Append to a list with a new list item.
 */

list *argvtol(const int argc, char **argv);
/* Return a list of characters containing argv where
 * there are spaces as delimiters for the argv strings.
 * You must free the list that is returned.
 */

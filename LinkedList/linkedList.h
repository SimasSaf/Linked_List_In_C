#pragma once
#include <stdio.h>

typedef enum
{
	LINKED_OK,
	LINKED_EMPTY,
	LINKED_NOT_FOUND,
	LINKED_FULL,
	LINKED_FOUND
} linkedList_return_codes_t;

typedef struct linkedList_st* linkedList_t;
typedef struct linkedList_node* linkedList_iterator_t;


linkedList_t linkedList_create(void);
linkedList_return_codes_t linkedList_destroy(linkedList_t list);
linkedList_return_codes_t linkedList_push(linkedList_t list, void* item);
void* linkedList_pull(linkedList_t list);
linkedList_return_codes_t linkedList_containsItem(linkedList_t list, void* item);
linkedList_return_codes_t linkedList_removeItem(linkedList_t list, void* item);
void* linkedList_peekItemByIndex(linkedList_t list, int index);
int linkedList_length(linkedList_t list);
void linkedList_clear(linkedList_t list);
linkedList_iterator_t linkedList_getIterator(linkedList_t list);
void* linkedList_itteratorNext(linkedList_t list, linkedList_iterator_t iterator);
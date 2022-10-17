#include "linkedList.h"
#include <stdio.h>

typedef struct linkedList_node
{
	void* item;
	struct linkedList_node* next; //Try with just linkedList_node
}linkedList_node;

typedef struct linkedList_st
{
	linkedList_node* node;
}linkedList_st;

linkedList_t linkedList_create(void)
{
	linkedList_t _newLinkedList = malloc(sizeof(linkedList_st));

	if (NULL == _newLinkedList) { return NULL; }

	_newLinkedList->node = NULL;

	return _newLinkedList;
}

linkedList_return_codes_t linkedList_push(linkedList_t list, void* item)
{
	if (list == NULL)
	{
		return LINKED_NOT_FOUND;
	}
	else
	{
		linkedList_node* _currentNode = malloc(sizeof(linkedList_node));
		_currentNode->item = NULL;
		_currentNode->next = NULL;

		if (list->node == NULL)
		{
			_currentNode->item = item;
			list->node = _currentNode;
			return LINKED_OK;
		}
		else
		{
			_currentNode = list->node;
			while (_currentNode->next != NULL)
			{
				_currentNode = _currentNode->next;
			}
				linkedList_node* _newNode = malloc(sizeof(linkedList_node));
				_newNode->item = item;
				_newNode->next = NULL;

				_currentNode->next = _newNode;
				return LINKED_OK;
		}
	}
}

int linkedList_length(linkedList_t list)
{
	if (list == NULL)
	{
		return LINKED_NOT_FOUND;
	}

	int i = 0;
	struct linkedList_node* _currentNode = list->node;
	
	if (list->node == NULL)
	{
		return LINKED_EMPTY;
	}
	else
	{
		while (_currentNode != NULL)
		{
			i++;
			_currentNode = _currentNode->next;
		}
	}
	return i;
}

void* linkedList_pull(linkedList_t list)
{
	if (list == NULL) { return LINKED_NOT_FOUND; }
	else
	{
		linkedList_node* _currentNode = malloc(sizeof(linkedList_node));
		_currentNode = list->node;

		if (_currentNode == NULL)
		{
			return LINKED_EMPTY;
		}
		else
		{
			while (_currentNode->next != NULL)
			{
				_currentNode = _currentNode->next;
			}
			
			if (_currentNode->item != NULL) { return _currentNode->item; }
			else { return LINKED_EMPTY; }
		}
	}
}

linkedList_return_codes_t linkedList_destroy(linkedList_t list)
{
	if (!list) { return LINKED_NOT_FOUND;}
	
	linkedList_node* _currentNode = malloc(sizeof(linkedList_node));
	_currentNode = list->node;

	struct linkedList_node* _nextNode = malloc(sizeof(linkedList_node));
	_nextNode = NULL;

	while(_currentNode != NULL)
	{ 
		_nextNode = _currentNode->next;
		free(_currentNode);
		_currentNode = _nextNode;
	}
	list->node = NULL;
	free(list->node);
	list = NULL;
	free(list);
	return LINKED_OK;
}

linkedList_return_codes_t linkedList_containsItem(linkedList_t list, void* item)
{
	if (!list) { return LINKED_NOT_FOUND; }

	linkedList_node* _currentNode = malloc(sizeof(linkedList_node));
	_currentNode = list->node;


	while (_currentNode->item != item && _currentNode->next != NULL)
	{
		_currentNode = _currentNode->next;
	}
	if (_currentNode->item == item)
	{
		return LINKED_FOUND;
	}
	else { return LINKED_NOT_FOUND; }
}
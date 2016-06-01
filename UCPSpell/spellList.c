/****************************************************************************
** FILE: spellList.c
** AUTHOR: Brendan Lally
** STUDENT ID: 18407220
** UNIT: COMP1000 (Unix and C Programming)
** PURPOSE: Contains functions relating to the creation and manipulation
** of linked lists
** LAST MOD: 27/10/15
****************************************************************************
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UcpSpell.h"
#include "spellList.h"

/** Takes in no parameters and creates an empty linked list. 
**  Initiallises the new linked list with NULL head and a 
**  size of 0. 
*/
LinkedList* createLinkedList()
{
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->size = 0;
	
	return list;
}

/** Creates a new node and inserts it at the end of the list.
*/
void insertEndNode(LinkedList* list, char data[])
{
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof
	(LinkedListNode));
	LinkedListNode* temp = list->head;
	strncpy(newNode->data, data, MAX_WORD_LENGTH);
	newNode->next = NULL;

	++list->size;

	/*If there are currently no nodes in the list.*/
	if (list->head == NULL)
	{
		list->head = newNode;
	}
	/*If there is one or more nodes in the list.*/
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

/** Creates a new node and inserts it at the start of the list.
*/
void insertStartNode(LinkedList* list, char data[])
{
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof
	(LinkedListNode));
	strncpy(newNode->data, data, MAX_WORD_LENGTH);
	newNode->next = NULL;

	++list->size;

	/*If there are currently no nodes in the list.*/
	if (list->head == NULL)
	{
		list->head = newNode;
	}
	/*If there is one or more nodes in the list.*/
	else
	{
		newNode->next = list->head;
		list->head = newNode;
	}
}

/** Imports a linked list and frees all the nodes.
*/
void freeList(LinkedList* list)
{
	LinkedListNode* current = list->head;
	
	/*Iterates through the list, individually freeing 
	each node.*/
	while (current != NULL)
	{
		LinkedListNode* temp = current;
		current = current->next;
		free(temp);
		
	}
	list->head = NULL;
	/*Free the head of the list.*/
	free(list);
}

/**	Imports a list pointing to the first node and prints each 
**  data item stored in a linked list.  
*/
void printList(LinkedList* list)
{
	/*current points to the first node in the list. */ 
	LinkedListNode* current = list->head;

	/*Iterate through the linked list and print the data field. */ 
	while (current != NULL)
	{
		printf("%s\n", current->data);
		current = current->next;
	}
}


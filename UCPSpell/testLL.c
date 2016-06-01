#include <stdio.h>
#include <stdlib.h>
#include "testLL.h"

int main(int argc, char* argv)
{
	int ii;
	/*int data[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};*/

	LinkedListNode* head;
	LinkedListNode* newNode;
	LinkedListNode* currentNode;

	/*create a new linked list*/
	head = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	head->next = NULL;

	if (head->next == NULL)
	{
		head->next = newNode;
	}
	else
	{
		currentNode = head->next;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		currentNode->data = 5;
	}


	
}
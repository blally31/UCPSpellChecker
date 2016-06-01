/****************************************************************************
** FILE: spellArray.c
** AUTHOR: Brendan Lally
** STUDENT ID: 18407220
** UNIT: COMP1000 (Unix and C Programming)
** PURPOSE: Contains functions relating to the use of arrays in relation
** to the spell checking.
** LAST MOD: 27/10/15
****************************************************************************
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UcpSpell.h"
#include "spellArray.h"

char** listToArray(LinkedList* list, int* arraySize)
{
	char** array;
	LinkedListNode* current = list->head;
	int i = (list->size - 1), j;
	*arraySize = list->size;

	/*Dynamically allocate memory for the array of strings. */
	array = (char**)calloc((*arraySize), sizeof(char*));
	for (j = 0; j < (*arraySize); j++)
	{
		array[j] = (char*)calloc(MAX_WORD_LENGTH, sizeof(char));
	}

	/* Iterate through the list and put each string in reverse 
	** order into the array. 
	*/
	while (current->next != NULL)
	{
		strcpy(array[i], current->data);
		current = current->next;
		i--;
	}
	/*Gets the data stored in the last node and puts it
	 into the array. */
	strcpy(array[i], current->data);
	/*freeList(list);*/

	return array;
}

void freeArray(char** array, int arraySize)
{
	int i;

	for (i = 0; i < arraySize; i++)
	{
		free(array[i]);
	}
	free (array);
}


void writeArrayToFile(char** array, int arraySize, char* filename)
{
	int i; 
	
	FILE* file = fopen(filename, "w");
	if (file == NULL)
	{
		perror("Error opening user file");
	}
	else
	{
		/*Iterate through the array and write each index to file. */
		for (i = 0; i < arraySize; i++)
		{
			fprintf(file, "%s ", array[i]);
		}
	}	
	fclose(file); 
}
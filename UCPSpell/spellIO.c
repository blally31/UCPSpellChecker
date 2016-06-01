/***************************************************************************
** FILE: spellIO.c
** AUTHOR: Brendan Lally
** STUDENT ID: 18407220
** UNIT: COMP1000 (Unix and C Programming)
** PURPOSE: Deals with user input and passes the required information
** to 
** LAST MOD: 27/10/15
****************************************************************************
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UcpSpell.h"
#include "spellIO.h"
#include "spellList.h"
#include "spellArray.h"

/** Reads a file to be spell checked and calls the parseFile
**  and listToArray functions to parse the file into a list and 
**  then from the list into a dynamially allocated array.

**  Imports the filename to be read and a pointer to store the size
**  of the array. Returns the array. 
*/
char** readUserFile(char* filename, int* arraySize)
{
	LinkedList* fileList = NULL;
	char **array;

	/* Open the file to read text and write corrected text back to 
	** the same file.
	*/
	FILE* fSpell = fopen(filename, "r+");
	if (fSpell == NULL)
	{
		perror("Error opening input file");
	}
	else
	{
		fileList = parseFile(fSpell);
		array = listToArray(fileList, arraySize);
	}
	/*Once the data has been copied from the list to the array, the list 
	can be freed. */
	freeList(fileList);
	fclose(fSpell);

	return array;
}

/** Reads the dictionary file specified in the settings file. 
**  Calls functions to parse the file into a list and then into
**  a dynamially allocated array. 

**  Imports the filename to be read and a pointer to store the size
**  of the array. Returns the array. 
*/
/*char** readDictionaryFile(char* dictFile, int* dArraySize)
{
	LinkedList *dictList = NULL;
	char **dArray;

	FILE* fDict = fopen(dictFile, "r");
	if (fDict == NULL)
	{
		perror("Error opening dictionary file");
	}
	else
	{
		dictList = parseFile(fDict);
		dArray = listToArray(dictList, dArraySize);
	}
	freeList(dictList);
	fclose(fDict);

	return dArray;
}*/

/** Parses a text file and stores each string in a linked list. 
**  Imports a file pointer and exports the linked list with the 
**  data in.  
*/
LinkedList* parseFile(FILE* file)
{
	int numScanned, done = 0;
	char data[MAX_WORD_LENGTH];
	LinkedList *list;

	list = createLinkedList();
	do
	{
		numScanned = fscanf(file, "%s", data);
		if (numScanned != 1)
		{
			done = 1;
		}
		else
		{	
			insertStartNode(list, data);	
		}		
	}
	while (done == 0);

	return list;
}

/** Reads the settings file and stores the information in a
**  Settings struct. Returns the Settings struct. 
*/
Settings readSettingsFile(int* errorCheck)
{
	char setting1[MAX_SETTING_LEN];
	char setting2[MAX_SETTING_LEN];
	Settings set1;
	int done = 0, numScanned = 0, mcCount = 0, dCount = 0, acCount = 0;

	FILE* fSettings = fopen("spellrc", "r");
	if (fSettings == NULL)
	{
		perror("Error opening settings file");
	}
	else
	{
		do
		{
			numScanned = fscanf(fSettings, "%s = %s\n", setting1, setting2);
			if ( numScanned != 2 )
			{
				if (numScanned == EOF)
				{
					done = 1;
				}
				else
				{
					printf("Error: Incorrect settings format!\n");
					*errorCheck = TRUE;
				}	
			}
			else
			{	
				/*Checks for the three required settings*/
				if ((strcmp(setting1, "maxcorrection") == 0))
				{
					set1.maxCorrection = atoi(setting2);
					mcCount = 1;
				}
				else if ((strcmp(setting1, "dictionary") == 0))
				{
					strncpy(set1.dictionary, setting2, MAX_SETTING_LEN);
					dCount = 1;
				}
				else if ((strcmp(setting1, "autocorrect") == 0))
				{
					if (strcmp(setting2, "yes") == 0)
					{
						set1.autoCorrect = YES;
					}
					else if (strcmp(setting2, "no") == 0)
					{
						set1.autoCorrect = NO;
					}
					/*Checks for */
					else
					{
						printf("Error: Incorrect autoCorrect value!\n");
						*errorCheck = TRUE;
					}
					acCount = 1;
				}
				else
				{
					printf("Error: Unrecognised setting name!\n");
					*errorCheck = TRUE;
				}
			}		
		}
		while (done == 0);
		if (mcCount == 0 || dCount == 0 || acCount == 0)
		{
			printf("Error: Missing a setting from settings file!\n");
			*errorCheck = TRUE;
		}
	}
	fclose(fSettings);
	return set1;
}
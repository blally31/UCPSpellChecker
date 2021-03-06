/****************************************************************************
** FILE: UcpSpell.c
** AUTHOR: Brendan Lally
** STUDENT ID: 18407220
** UNIT: COMP1000 (Unix and C Programming)
** PURPOSE: Deals with user input and passes the required information
** to various functions
** LAST MOD: 27/10/15
****************************************************************************
**/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check.h"
#include "UcpSpell.h"
#include "spellList.h"
#include "spellArray.h"
#include "spellIO.h"

int main(int argc, char* argv[])
{
	/*user and dictionary arrays*/
	char **uArray, **dArray;
	int uArraySize = 0, dArraySize = 0;
	int errorCheck = FALSE;
	Settings set = readSettingsFile(&errorCheck);

	if (argc != 2)
	{
		printf("Incorrect number of command line arguments!\n");
		errorCheck = TRUE;
	}
	
	/*If there is an error in the setings file, the program does not try
	to spell check anything.*/
	if (errorCheck != TRUE)
	{
		dArray = readUserFile(set.dictionary, &dArraySize);
		uArray = readUserFile(argv[1], &uArraySize);

		printf("****	Welcome to UCP Spell checker	****\n");
		printf("\n");

		/* Call check function, supplying different callback functions 
		** depending on the value of autoCorrect (yes/no) in the settings file.
		*/
		if (set.autoCorrect == YES)
		{
			check(uArray, uArraySize, dArray, dArraySize, set.maxCorrection,
			&autoCorrect);
		}
		else if (set.autoCorrect == NO)	
		{
			check(uArray, uArraySize, dArray, dArraySize, set.maxCorrection,
			&checkCorrect);
		}
		writeArrayToFile(uArray, uArraySize, argv[1]);
		freeArray(dArray, dArraySize);
		freeArray(uArray, uArraySize);

		printf("\n****	Thank you for using UCP Spell checker!	****\n");
		printf("Goodbye!");
		printf("\n");
	}

	return 1;
}

/** First callback function is called if autocorrect in the 
**  settings file is set to 'yes'. If the word can be corrected
**  then it will be. 
*/
int autoCorrect(char* word, char* suggestion)
{
	int result = TRUE;

	/*No possible correction.*/
	if (suggestion == NULL)
	{
		result = FALSE;
	}

	return result;
}

/** Second callback function is called if autocorrect in the 
**  settings file is set to 'no'. Gives the user the option
**  to correct a misspelled word or keep the original.  
*/
int checkCorrect(char* word, char* suggestion)
{
	int result = TRUE;

	/*No possible correction.*/
	if (suggestion == NULL)
	{
		result = FALSE;
	}
	/* Possible corrections are displayed to the user and are asked
	** to choose to keep the original or suggested word.
	*/
	else
	{
		printf("\nOriginal word is '%s'\n", word);
		printf("Suggested correction is '%s'\n", suggestion);

		/* Input validation. */
		result = validateInput();		
	}

	
	return result;
}

/** Asks the user if they would like to change the spelling of a word or not.
**  Provides validation on input so only y/Y or n/N will be accepted.
*/
int validateInput()
{
	int result = TRUE, valid = FALSE;
	char choice[3], ch;

	while (valid == FALSE)
	{
		printf("Would you like to correct the word? (y/n)\n");
		scanf("%2s", choice);
		/*Clears out the stdin stream*/
		while((ch = fgetc(stdin)) != EOF && ch != '\n')
		{
			/*blank----------------------------------------------------------------------------------*/
		}
		/*Checks the user input and decides whether it is correct.*/
		if (strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0)
		{
			result = TRUE;
			valid = TRUE;
			printf("Suggestion has been applied!\n");
		}
		else if (strcmp(choice, "n") == 0 || strcmp(choice, "N") == 0)
		{
			result = FALSE;
			valid = TRUE;
			printf("Suggestion has been ignored!\n");
		}
		else
		{
			printf("\nInvalid input choice!\n");
		}
	}
	return result;
}

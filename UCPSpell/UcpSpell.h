#ifndef UCPSPELL_HEADER
#define UCPSPELL_HEADER

#define NO 0
#define YES !NO
#define FALSE 0
#define TRUE !FALSE

/** Maximum word length for both user and dictionary files.
*/
#define MAX_WORD_LENGTH 51
#define MAX_SETTING_LEN 30 

/** A struct to contain various settings required for the 
**  program to run. The max difference between a misspelled 
**  word and a suggested correction, the dictionary file name
**  and whether or not to auto-correct the spelling.
*/
typedef struct
{
	int maxCorrection;
	char dictionary[MAX_SETTING_LEN];
	int autoCorrect;
} Settings;

/** A struct to represent a linked list node which contains
**  a data field to store a string and a link to the next
**  node in the list.
*/
typedef struct LinkedListNode
{
	/*char* data;*/
	char data[MAX_WORD_LENGTH];
	struct LinkedListNode* next;
} LinkedListNode;

/** A struct to represent a linked list which contains
**  the size of the linked list and a link to the first
**  node in the list.
*/
typedef struct
{
	int size;
	LinkedListNode* head;
} LinkedList;

/*Function definitions*/

int autoCorrect(char* word, char* suggestion);
int checkCorrect(char* word, char* suggestion);
int validateInput();

#endif




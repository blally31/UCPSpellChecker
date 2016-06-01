#ifndef TESTLL_HEADER
#define TESTLL_HEADER
#define ARRAY_SIZE 10

typedef struct 
{
	int data;
	struct LinkedListNode* next;
} LinkedListNode;

typedef struct 
{
	int size;
	LinkedListNode* head;
} LinkedList;
#endif
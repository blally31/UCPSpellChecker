#ifndef SPELL_HEADER
#define SPELL_HEADER

/*Function definitions*/

LinkedList* createLinkedList();
void insertEndNode(LinkedList* list, char data[]);
void insertStartNode(LinkedList* list, char data[]);
void freeList(LinkedList* list);
void printList(LinkedList* list);

#endif
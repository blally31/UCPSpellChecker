#ifndef ARRAY_HEADER
#define ARRAY_HEADER

char** listToArray(LinkedList* list, int* arraySize);
void freeArray(char**, int);
void writeArrayToFile(char**, int, char*);

#endif
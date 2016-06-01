#ifndef IO_HEADER
#define IO_HEADER

char** readUserFile(char*, int*);
char** readDictionaryFile(char*, int*);
LinkedList* parseFile(FILE*);
Settings readSettingsFile(int*);

#endif
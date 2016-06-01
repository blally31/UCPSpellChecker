Unix and C Programming Assignment 2015 Semester 2
Brendan Lally 18407220

	Files

---UcpSpell.c---
Contains the programs main function along with the two callback functions that
are provided for checking. Provides some level of error checking and if an error
does occur, the rest of the program does not run.

---UcpSpell.h---
Corresponding header file contains all the struct typedefs and constants used
throughout the program.


---spellIO.c---
Contains all the functions related to file IO. Reads in all required input files
and parses the date into the required data structures.

---spellIO.h---
Corresponding header file contains related function definitions.


---spellList.c---
Contains all the functions related to creating and manipulating linked lists.
These include; creating an empty list, inserting into the list at the front and
the rear, freeing the memory allocated for the list and a function to print the
list (if required).

---spellList.h---
Corresponding header file contains related function definitions.


---spellArray.c---
Contains all the functions related to arrays. These include copying the contents
of a linked list into a dynamically-allocated array, freeing an array and writing
an array to file.

---spellArray.h---
Corresponding header file contains related function definitions

---check.c---




All the required functionality has been implemented and works to the best of my knowledge.
The program can read in and parse all the neccessary file inputs with appropriate error 
checking for incorrect settings file and if the user or dictionary files don't exist. It
successfully asks the user for input depending on the value of autocorrect again, with 
a level of validation of the user input.

ERRORS

The program compiles and runs without any errors reported from valgrind.

TESTING

The program was tested on computer 



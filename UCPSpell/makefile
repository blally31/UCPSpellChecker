CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = UcpSpell.o spellList.o spellArray.o spellIO.o check.o
EXEC = spell

$(EXEC): $(OBJ)
	$(CC) -g $(OBJ) -o $(EXEC)

UcpSpell.o: UcpSpell.c UcpSpell.h spellList.h check.h spellArray.h spellIO.h
	$(CC) -c UcpSpell.c $(CFLAGS)

spellList.o: spellList.c spellList.h
	$(CC) -c spellList.c $(CFLAGS)

spellArray.o: spellArray.c spellArray.h
	$(CC) -c spellArray.c $(CFLAGS)

spellIO.o: spellIO.c spellIO.h
	$(CC) -c spellIO.c $(CFLAGS)

check.o: check.c check.h
	$(CC) -c check.c $(CFLAGS)

clean: 
	rm -f $(EXEC) $(OBJ)

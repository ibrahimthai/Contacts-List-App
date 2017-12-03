CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g


# Add locations
ASSET = assets/
BINDIR = bin/
SRCDIR = src/
INCLUDE = include/
LIB = lib/

HEADER = $(INCLUDE)contacts.h

OBJECTS = $(BINDIR)readFile.o $(BINDIR)displayList.o $(BINDIR)nameAscending.o $(BINDIR)isNumber.o $(BINDIR)displayContact.o \
		  $(BINDIR)deleteContact.o $(BINDIR)editContact.o $(BINDIR)saveContacts.o

all: main

main: $(OBJECTS) $(BINDIR)main.o
	  $(CC) $(OBJECTS) $(BINDIR)main.o -o $(BINDIR)main

$(BINDIR)main.o: $(SRCDIR)main.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $(BINDIR)main.o

$(BINDIR)isNumber.o: $(SRCDIR)isNumber.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCDIR)isNumber.c -o $(BINDIR)isNumber.o

$(BINDIR)readFile.o: $(SRCDIR)readFile.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCDIR)readFile.c -o $(BINDIR)readFile.o

$(BINDIR)displayList.o: $(SRCDIR)displayList.c $(HEADER) 
	$(CC) $(CFLAGS) -c $(SRCDIR)displayList.c -o $(BINDIR)displayList.o

$(BINDIR)nameAscending.o: $(SRCDIR)nameAscending.c $(HEADER) 
	$(CC) $(CFLAGS) -c $(SRCDIR)nameAscending.c -o $(BINDIR)nameAscending.o

$(BINDIR)displayContact.o: $(SRCDIR)displayContact.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCDIR)displayContact.c -o $(BINDIR)displayContact.o

$(BINDIR)deleteContact.o: $(SRCDIR)deleteContact.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCDIR)deleteContact.c -o $(BINDIR)deleteContact.o

$(BINDIR)editContact.o: $(SRCDIR)editContact.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCDIR)editContact.c -o $(BINDIR)editContact.o

$(BINDIR)saveContacts.o: $(SRCDIR)saveContacts.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCDIR)saveContacts.c -o $(BINDIR)saveContacts.o

cppcheck:
	cppcheck --enable=all --language=c --std=c99 --inconclusive --suppress=missingInclude src/*.c -i ./include

doxy: Doxyfile
	doxygen

clean: 
	rm $(BINDIR)main $(BINDIR)main.o $(BINDIR)readFile.o $(BINDIR)displayList.o $(BINDIR)nameAscending.o $(BINDIR)isNumber.o $(BINDIR)displayContact.o \
			$(BINDIR)deleteContact.o $(BINDIR)editContact.o $(BINDIR)saveContacts.o

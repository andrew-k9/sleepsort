# sleepsort Makefile
CC=gcc
LINK=gcc
CFLAGS=-c -Wall -I.
OBJECT_FILES=sleepsort.o main.o

# Suffix Rules
.SUFFIXES: .c .o

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

# Productions
foo : $(OBJECT_FILES)
	$(LINK) $(OBJECT_FILES) -o $@

# Dependencies
main.o : main.c sleepsort.h
sleepsort.o : sleepsort.c sleepsort.h
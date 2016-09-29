# Makefile for Asg4 server
# client not included in Makefile. Compile client with: gcc client.c -o client

CC=gcc
CFLAGS=-c -Wall

objects = server.o WC.o Readline.o CountsUpdate.o CountWord.o ToString.o


all : server



server : $(objects)
	$(CC) $(objects) -o server

server.o : server.c Definition.h ExternalVar.h
	$(CC) $(CFLAGS) server.c

WC.o : WC.c Definition.h ExternalVar.h
	$(CC) $(CFLAGS) WC.c

Readline.o : Readline.c Definition.h ExternalVar.h
	$(CC) $(CFLAGS) Readline.c

CountsUpdate.o : CountsUpdate.c Definition.h ExternalVar.h
	$(CC) $(CFLAGS) CountsUpdate.c

CountWord.o : CountWord.c Definition.h ExternalVar.h
	$(CC) $(CFLAGS) CountWord.c

ToString.o : ToString.c Definition.h ExternalVar.h
	$(CC) $(CFLAGS) ToString.c


clean : server $(objects)
	rm server $(objects)

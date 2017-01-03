# Kaylan Mettus
# CS302
# Make file for assignment 10.

OBJS	= compress.o huffman.o
OBJS1	= pqTest.o
CC	= g++
DEPS	= priorityQueue.h huffman.h

all: compress pqTest

compress: compress.o huffman.o $(DEPS)
	$(CC) -g -Wall -pedantic -o compress $(OBJS)

compress.o: compress.cpp $(DEPS)
	$(CC) -g -Wall -pedantic -c compress.cpp

huffman.o: huffman.cpp $(DEPS)
	$(CC) -g -Wall -pedantic -c huffman.cpp


pqTest: pqTest.o $(DEPS)
	$(CC) -g -Wall -pedantic -o pqTest $(OBJS1)
	
pqTest.o: pqTest.cpp $(DEPS)
	$(CC) -g -Wall -pedantic -c pqTest.cpp


# -----
# clean by removing object files.

clean:
	rm	$(OBJS)

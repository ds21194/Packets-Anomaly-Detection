CC=g++
CFLAGS=-I.

test_retrival: RetrivalTest.cpp InfoRetrival.o
	$(CC) -o test_retrival RetrivalTest.cpp InfoRetrival.o

InfoRetrival.o: InfoRetrival.cpp InfoRetrival.h
	$(CC) -o InfoRetrival.o InfoRetrival.cpp $(CFLAGS)



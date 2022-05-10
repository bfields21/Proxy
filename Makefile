# Makefile for Proxy Lab 
#

CC = gcc
CFLAGS = -g -Wall -Wno-unused-variable -Wno-unused-function

all: proxy cstringTester

cstringTester: cstringTester.o cstring.o
	$(CC) cstringTester.o cstring.o -o cstringTester

proxy: proxy.o csapp.o cache.o cstring.o
	$(CC) $(CFLAGS) proxy.o csapp.o cache.o cstring.o -o proxy -lpthread

cstringTester.o: cstringTester.c
	$(CC) $(CFLAGS) -c cstringTester.c

cstring.o: cstring.c
	$(CC) $(CFLAGS) -c cstring.c

csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c

cache.o: cache.c cache.h
	$(CC) $(CFLAGS) -c cache.c

proxy.o: proxy.c csapp.h cstring.h
	$(CC) $(CFLAGS) -c proxy.c

clean:
	rm -f *~ *.o cstringTester proxy core *.tar *.zip *.gzip *.bzip *.gz


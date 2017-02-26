CC=g++
CFLAGS=-O -Wall

all: encode decode

encode: urlencode.cc
	$(CC) $(CFLAGS) urlencode.cc -o urlencode

decode: urldecode.cc
	$(CC) $(CFLAGS) urldecode.cc -o urldecode

install:
	chmod +x urlencode
	mv urlencode /usr/local/bin
	chmod +x urldecode
	mv urldecode /usr/local/bin

CC=gcc


server: server.c argparse
	$(CC) server.c -o server

client: client.c argparse
	$(CC) client.c -o client

argparse-test: argparse
	$(CC) src/argparse-test.c build/dep/argparse.o -o build/out/argparse-test

argparse: lib/argparse/argparse.c build-folder
	$(CC) -c lib/argparse/argparse.c -o build/dep/argparse.o

build-folder:
	mkdir -p build/dep build/out build/obj

all: server client

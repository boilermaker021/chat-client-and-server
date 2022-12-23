server: server.c argparse
	gcc server.c -o server

client: client.c argparse
	gcc client.c -o client

argparse: lib/argparse/argparse.c build-folder
	gcc -c lib/argparse/argparse.c -o build/argparse.o

build-folder:
	mkdir -p build/dep build/out

all: server client

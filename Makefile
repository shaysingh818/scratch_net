BIN=bin
CC=gcc
TARGET=target/network
TARGET_TEST=target/test_network
FLAGS = -g -lm -lpthread


# objects files
NETWORK = network/network.o
LAYER = layer/layer.o layer/activations.o
MATRIX = matrix/matrix.c
OBJS = $(MATRIX) $(LAYER) $(NETWORK)

# compile source and unit tests
all: build source

source: main.o $(OBJS)
	$(CC) -o $(TARGET) main.o $(OBJS) $(FLAGS)

build: matrix layer network

matrix:
	$(MAKE) -C ../matrix

layer:
	$(MAKE) -C ../layer

network:
	$(MAKE) -C ../network

main.o: main.c $(HEADERS)
	$(CC) -c main.c

clean:
	rm -f *.o *~ *.pyc


clean:
	rm -f *.o *~
	$(MAKE) -C  ./matrix clean
	$(MAKE) -C ./layer clean
	$(MAKE) -C ./network clean

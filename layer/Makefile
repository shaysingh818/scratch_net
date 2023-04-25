BIN=bin
CC=gcc
TARGET=target/layer
TEST_TARGET=target/test_layer
INCLUDES = -I./includes
FLAGS = -g -lm -lpthread $(INCLUDES)

# object files
TEST_OBJS = test_layer.o
OBJS = layer.o activations.o ../matrix/matrix.o
ALL_OBJS = $(TEST_OBJS) $(OBJS)

all: unit_test source

unit_test: unit_test.o $(ALL_OBJS)
	$(CC) -o $(TEST_TARGET) unit_test.o $(ALL_OBJS) $(FLAGS)

source: main.o $(OBJS)
	$(CC) -o $(TARGET) main.o $(OBJS) $(FLAGS)

activations.o: activations.c includes/activations.h
	$(CC) -c activations.c

layer.o: layer.c includes/layer.h
	$(CC) -c layer.c

test_layer.o: tests/test_layer.c tests/includes/test_layer.h
	$(CC) -c tests/test_layer.c

matrix.o:
	$(MAKE) -C ../matrix

# main files
unit_test.o: tests/unit_test.c tests/includes/test_layer.h
	gcc -c tests/unit_test.c

main.o: main.c $(HEADERS)
	gcc -c main.c

# clean compilation (target doesn't work)
clean_binary:
	rm $(TARGET)

clean:
	rm -f *.o *~ *.pyc
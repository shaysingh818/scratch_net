BIN=bin
CC=gcc
TARGET=target/network
TARGET_TEST=target/test_network
FLAGS = -g -lm -lpthread

# header files 
TEST_MATRIX_HEADER = tests/includes/test_matrix.h
TEST_ACTIVATIONS_HEADER = tests/includes/test_activations.h
TEST_LAYER_HEADER = tests/includes/test_layer.h
TEST_NETWORK_HEADER = tests/includes/test_network.h
HEADERS = includes/matrix.h includes/activations.h includes/network.h includes/layer.h
TEST_HEADERS = $(TEST_MATRIX_HEADER) $(TEST_ACTIVATIONS_HEADER) $(TEST_NETWORK_HEADER) $(TEST_LAYER_HEADER)

# objects files 
OBJS = matrix.o activations.o network.o layer.o
TEST_OBJS = test_matrix.o test_activations.o test_network.o test_layer.o

# compile source and unit tests
all: unit_test source

unit_test: unit_test.o $(OBJS) $(TEST_OBJS)
	$(CC) -o $(TARGET_TEST) unit_test.o $(OBJS) $(TEST_OBJS) $(FLAGS)

source: main.o $(OBJS)
	$(CC) -o $(TARGET) main.o $(OBJS) $(FLAGS)


# source files 
matrix.o: matrix.c includes/matrix.h
	$(CC) -c matrix.c

activations.o: activations.c includes/activations.h
	$(CC) -c activations.c

network.o: network.c includes/network.h
	$(CC) -c network.c

layer.o: layer.c includes/layer.h
	$(CC) -c layer.c


# test files
test_matrix.o: tests/test_matrix.c tests/includes/test_matrix.h
	$(CC) -c tests/test_matrix.c

test_activations.o: tests/test_activations.c tests/includes/test_activations.h
	$(CC) -c tests/test_activations.c

test_network.o: tests/test_network.c tests/includes/test_network.h
	$(CC) -c tests/test_network.c

test_layer.o: tests/test_layer.c tests/includes/test_layer.h
	$(CC) -c tests/test_layer.c

# main driver files
unit_test.o: tests/unit_test.c
	$(CC) -c tests/unit_test.c

main.o: main.c $(HEADERS)
	$(CC) -c main.c


clean:
	rm -f *.o *~ *.pyc

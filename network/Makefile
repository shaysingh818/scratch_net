BIN=bin
CC=gcc
TARGET=target/network
TEST_TARGET=target/test_network
INCLUDES = -I./includes
FLAGS = -g -lm -lpthread $(INCLUDES)

# object files
TEST_OBJS = test_network.o
OBJS = network.o ../layer/layer.o ../layer/activations.o ../matrix/matrix.o
ALL_OBJS = $(TEST_OBJS) $(OBJS)

all: unit_test source

unit_test: unit_test.o $(ALL_OBJS)
	$(CC) -o $(TEST_TARGET) unit_test.o $(ALL_OBJS) $(FLAGS)

source: main.o $(OBJS)
	$(CC) -o $(TARGET) main.o $(OBJS) $(FLAGS)

layer.o:
	$(MAKE) -C ../layer

network.o: network.c includes/network.h
	$(CC) -c network.c

test_network.o: tests/test_network.c tests/includes/test_network.h
	$(CC) -c tests/test_network.c

# main files
unit_test.o: tests/unit_test.c tests/includes/test_network.h
	gcc -c tests/unit_test.c

main.o: main.c $(HEADERS)
	gcc -c main.c

# clean compilation (target doesn't work)
clean_binary:
	rm $(TARGET)

clean:
	rm -f *.o *~ *.pyc
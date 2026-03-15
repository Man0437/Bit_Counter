CC=gcc
CFLAGS=-c -Wall
SOURCES=main.c
EXECUTABLE=bit_counter
OBJECT=$(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECT)
	$(CC) $(OBJECT) -o $(EXECUTABLE)
	rm -rf $(OBJECT)

$(OBJECT): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -rf $(OBJECT) test.bin $(EXECUTABLE)

test: $(EXECUTABLE)
	sh ./test.sh

time: $(EXECUTABLE)
	sh ./test_time.sh
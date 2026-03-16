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
# Команда для тестирования правильности значений
test: $(EXECUTABLE)
	sh ./test.sh

# Команда для тестирования времени выполнения
time: $(EXECUTABLE)
	sh ./test_time.sh
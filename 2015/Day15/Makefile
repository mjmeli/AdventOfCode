CC = gcc
CFLAGS = -Wall -std=c99

SRCS = $(wildcard *.c)
TARGET = $(patsubst %.c,%,$(SRCS))

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

run:
	./$(TARGET) input.txt

test:
	./$(TARGET) input_test.txt

clean:
	$(RM) $(TARGET)

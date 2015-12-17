CC = gcc
CFLAGS = -Wall -std=c99

SRCS = $(wildcard *.c)
TARGET = $(patsubst %.c,%,$(SRCS))

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

run:
	./$(TARGET) input.txt 150

test:
	./$(TARGET) input_test.txt 25

clean:
	$(RM) $(TARGET)

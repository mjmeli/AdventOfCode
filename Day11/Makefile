CC = gcc
CFLAGS = -Wall -std=c99

SRCS = $(wildcard *.c)
TARGET = $(patsubst %.c,%,$(SRCS))

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)

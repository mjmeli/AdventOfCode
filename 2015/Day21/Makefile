CC = gcc
CFLAGS = -Wall -std=c99

SRCS = $(wildcard *.c)
TARGET = $(patsubst %.c,%,$(SRCS))

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -g $(TARGET).c -lm -o $(TARGET) 

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)

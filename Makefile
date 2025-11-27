CC = gcc
CFLAGS = -std=c99 -O2 -Iinclude -Wall -Wextra
SRCS = src/main.c src/list_array.c src/list_linked.c src/algorithms.c
TARGET = survival

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

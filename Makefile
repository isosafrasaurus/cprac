CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

TARGET = main

OBJ = main.o prelims.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Compile main.c -> main.o
main.o: main.c prelims.h
	$(CC) $(CFLAGS) -c main.c

# Compile prelims.c -> prelims.o
prelims.o: prelims.c prelims.h
	$(CC) $(CFLAGS) -c prelims.c

clean:
	rm -f $(OBJ) $(TARGET)

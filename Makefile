CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

TARGET = main

OBJ = main.o prelims.o arrays.o pointers.o strings_and_structs.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Compile main.c -> main.o
main.o: main.c prelims.h
	$(CC) $(CFLAGS) -c main.c

# Compile prelims.c -> prelims.o
prelims.o: prelims.c prelims.h
	$(CC) $(CFLAGS) -c prelims.c

# Compile arrays.c -> arrays.o
arrays.o: arrays.c arrays.h
	$(CC) $(CFLAGS) -c arrays.c

# Compile pointers.c -> pointers.h
pointers.o: pointers.c pointers.h
	$(CC) $(CFLAGS) -c pointers.c

# Compile strings_and_structs.c -> strings_and_structs.h
strings_and_structs.o: strings_and_structs.c strings_and_structs.h
	$(CC) $(CFLAGS) -c strings_and_structs.c

clean:
	rm -f $(OBJ) $(TARGET)

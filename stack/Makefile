TARGET = example
CC=gcc
CFLAGS =-I. -Wall -Wextra
HEADERS = stack.h
OBJ = example.o stack.o

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm ./$(TARGET) *.o 
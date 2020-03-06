TARGET = stack
CC=gcc
CFLAGS =-I. -Wall -Wextra
HEADERS = stack.h
OBJ = stack_ex.o stack.o

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm ./$(TARGET) *.o 
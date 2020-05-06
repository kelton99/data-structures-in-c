TARGET = linked_list
CC=gcc
CFLAGS =-I. -Wall -Wextra
HEADERS = linked_list.h node.h
OBJ = linked_list_ex.o linked_list.o node.o

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm ./$(TARGET) *.o 
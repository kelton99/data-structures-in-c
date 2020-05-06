TARGET = dlinked_list
CC=gcc
CFLAGS =-I. -Wall -Wextra
HEADERS = dlinked_list.h node.h
OBJ = node.o dlinked_list_ex.o dlinked_list.o 

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm ./$(TARGET) *.o 
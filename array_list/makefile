TARGET = array_list
CC=gcc
CFLAGS =-I. -Wall -Wextra
HEADERS = array_list.h
OBJ = array_list_ex.o array_list.o

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm ./$(TARGET) *.o 
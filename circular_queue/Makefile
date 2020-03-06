TARGET = circular_queue
CC=gcc
CFLAGS =-I. -Wall -Wextra
HEADERS = queue.h
OBJ = circular_queue_ex.o circular_queue.o

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm ./$(TARGET) *.o 
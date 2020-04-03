TARGET = priority_queue
CC=gcc
CFLAGS =-I. -Wall -Wextra
HEADERS = queue.h
OBJ = priority_queue_ex.o priority_queue.o

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm ./$(TARGET) *.o 
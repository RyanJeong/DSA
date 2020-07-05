CC=cc
CFLAGS=-g -ansi -Wall
OBJS=obj/main.o obj/linkedlist.o
TARGET=SinglyLinkedList

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

obj/main.o: main.c
	$(CC) -c $< $(CFLAGS) -o $@

obj/linkedlist.o: linkedlist.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -f obj/*.o $(TARGET)

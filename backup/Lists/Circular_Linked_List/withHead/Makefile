CC=cc
CFLAGS=-g -ansi -Wall
OBJS=obj/main.o obj/circularLinkedlist.o
TARGET=CircularLinkedList

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

obj/main.o: main.c
	$(CC) -c $< $(CFLAGS) -o $@

obj/circularLinkedlist.o: circularLinkedlist.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -f obj/*.o $(TARGET)

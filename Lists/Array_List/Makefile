CC=cc
CFLAGS=-g -ansi -Wall
OBJS=obj/main.o obj/arraylist.o
TARGET=Array_List

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

obj/main.o: main.c
	$(CC) -c $< $(CFLAGS) -o $@

obj/arraylist.o: arraylist.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -f obj/*.o $(TARGET)

CFLAGS += -ggdb -Wall -ansi -pedantic -I.

test: libqueue.so test.c queue.h
	$(CC) $(CFLAGS) -o test test.c -L. -lqueue

libqueue.so: libqueue.c queue.h
	$(CC) $(CFLAGS) -shared -o libqueue.so libqueue.c

clean:
	-$(RM) libqueue.so test


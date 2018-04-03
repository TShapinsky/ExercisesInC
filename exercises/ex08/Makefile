CC = gcc
CFLAGS = -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LIBS = -lglib-2.0

ex_compile: ex_compile.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

word_count: word_count.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

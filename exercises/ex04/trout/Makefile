trout: trout.h main.c trout.c util.o
	gcc -g -Wall -o trout trout.c util.o main.c

util.o: util.c util.h
	gcc -c -Wall -o util.o util.c

clean:
	rm util.o trout

test: test_util.c util.o
	gcc -g -Wall -o test util.o test_util.c
	./test

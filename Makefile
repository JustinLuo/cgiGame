CFLAGS=-g -Wall -o
CC=gcc
LIBS=-L./cgic/ -lcgic -L./lua/install/lib/ -llua -lm -ldl

main.cgi:
	# $(CC) main.c $(CFLAGS) main.cgi
	$(CC) main.c common.c $(CFLAGS) main.cgi ${LIBS}

clean:
	rm -f *.o *.a main.cgi

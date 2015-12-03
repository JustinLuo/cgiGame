CFLAGS=-g -Wall -o
CC=gcc
LIBS=-L./cgic/ -lcgic -L./lua/install/lib/ -llua -lm -ldl
MYSQL_LIBS=-L./usr/lib/ -lmysqlclient

main.cgi:
	# $(CC) main.c $(CFLAGS) main.cgi
	$(CC) main.c common.c $(CFLAGS) main.cgi ${LIBS} ${MYSQL_LIBS}

clean:
	rm -f *.o *.a main.cgi

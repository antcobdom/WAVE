CC=gcc
CFLAGS=-Wall
SRC=wsmp.c encode.c decode.c utils_wsmp.c
HDR=wsmp.h encode.h decode.h utils_wsmp.h
OBJS=wsmp.o encode.o decode.o utils_wsmp.o
LIB=-lpcap

main: $(SRC) $(HDR)
	$(CC) $(CFLAGS) -c $(SRC)

test: test.c $(OBJS)
	$(CC) $(CFLAGS) test.c $(OBJS) -o test

wireless: wireless.c $(OBJS)
	$(CC) $(CFLAGS) wireless.c $(OBJS) $(LIB) -o wireless

all: main test wireless

clean:
	rm -f *.o wireless test

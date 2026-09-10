.PHONY: build clean

CC = gcc
CFLAGS = -I. -Wall
LDFLAGS =

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
filestat: filestat.c
	$(CC) filestat.c -o $@ $(CFLAGS) $(LDFLAGS)
clean:
	rm -rf *.o *.a *.so filestat

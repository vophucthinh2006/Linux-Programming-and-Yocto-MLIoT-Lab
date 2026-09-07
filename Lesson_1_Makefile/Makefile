.PHONY: all clean static shared

CC = gcc
CFLAGS = -I. -Wall

all: static shared

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f *.o *.a *.so main_static main_shared

# Static linking
static: main_static

main_static: main.c libstrutils.a
	$(CC) main.c -L. -lstrutils -o $@ $(CFLAGS)

libstrutils.a: strutils.o
	ar rcs $@ $<

# Shared linking
shared: main_shared

main_shared: main.c libstrutils.so
	$(CC) main.c -L. -lstrutils -o $@ $(CFLAGS)

strutils_shared.o: strutils.c
	$(CC) -c $< -o $@ -fPIC $(CFLAGS)

libstrutils.so: strutils_shared.o
	$(CC) -shared -o $@ $<
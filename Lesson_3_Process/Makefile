.PHONY: all clean

CC = gcc
CFLAGS = -I. -Wall -Wextra
LDFLAGS =

SRCS = $(wildcard *.c)
TARGETS = $(SRCS:.c=)

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGETS) *.o *.a *.so
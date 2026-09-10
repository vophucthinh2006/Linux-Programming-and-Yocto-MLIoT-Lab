.PHONY: all clean static shared

CC = gcc
CFLAGS = -I. -Wall
BUILD_DIR = build

all: $(BUILD_DIR) static shared

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR) *.o *.a *.so main_static main_shared

# Static linking
static: main_static

main_static: main.c $(BUILD_DIR)/libstrutils.a
	$(CC) main.c -L$(BUILD_DIR) -lstrutils -o $@ $(CFLAGS)

$(BUILD_DIR)/libstrutils.a: $(BUILD_DIR)/strutils.o
	ar rcs $@ $<

# Shared linking
shared: main_shared

main_shared: main.c $(BUILD_DIR)/libstrutils.so
	$(CC) main.c -L$(BUILD_DIR) -lstrutils -o $@ $(CFLAGS) -Wl,-rpath=$(BUILD_DIR)

$(BUILD_DIR)/strutils_shared.o: strutils.c | $(BUILD_DIR)
	$(CC) -c $< -o $@ -fPIC $(CFLAGS)

$(BUILD_DIR)/libstrutils.so: $(BUILD_DIR)/strutils_shared.o
	$(CC) -shared -o $@ $<
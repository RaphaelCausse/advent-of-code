# ===========================
#  Advent of Code — Makefile
# ===========================

# Sources
SOURCES := $(wildcard *.c)

# Dependencies
DEPENDENCIES := $(SOURCES:.c=.d)

# Detect Windows
ifeq ($(OS),Windows_NT)
    TARGET := $(SOURCES:.c=.exe)
    RM := del /f/q
else
    TARGET := $(SOURCES:.c=)
    RM := rm -f
endif

# Includes
INCLUDES := -I..

# Compiler
CC := gcc
CFLAGS := -std=c99 -O2 -pedantic -Wall -Wextra
CPPFLAGS := $(INCLUDES)
DEPFLAGS := -MMD -MP

# Phony rules
.PHONY: all build test run clean

# All rules
all: clean build run

# ===========================
#  Build
# ===========================
build: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) $^ -o $@

# ===========================
#  Test mode
# ===========================
test: CPPFLAGS += -DTEST
test: $(TARGET)

# ===========================
#  Run executable
# ===========================
run: $(TARGET)
	./$(TARGET)

# ===========================
#  Cleanup
# ===========================
clean:
	$(RM) $(TARGET) $(DEPENDENCIES)

# ===========================
#  Auto dependencies
# ===========================
-include $(DEPENDENCIES)

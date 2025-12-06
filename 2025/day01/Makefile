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
CFLAGS := -std=c99 -O2 -Wall -Wextra -Wpedantic
CPPFLAGS := $(INCLUDES)
DEPFLAGS := -MMD -MP

# Phony rules
.PHONY: all clean test run

# ===========================
#  Default build
# ===========================
all: clean $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) $^ -o $@

# ===========================
#  Test mode
# ===========================
test: CPPFLAGS += -DTEST
test: clean $(TARGET)

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

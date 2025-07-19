SOURCES := day03.c
DEPENDANCIES := $(SOURCES:.c=.d)

INCLUDE_DIRS := ..

ifeq ($(OS),Windows_NT)
TARGET := $(SOURCES:.c=.exe)
else
TARGET := $(SOURCES:.c=.out)
endif

## COMPILER ###############################################

CC := gcc
CFLAGS := -std=c99 -O2 -Wall -Wextra -pedantic
CPPFLAGS := -I$(INCLUDE_DIRS)
DEPSFLAGS := -MMD -MP

## VERBOSITY ##############################################

VERBOSE := $(or $(v), $(verbose))
ifeq ($(VERBOSE),)
    Q := @
else
    Q :=
endif

## SHELL ##################################################

ifeq ($(OS),Windows_NT)
RM := del /f/q
else
RM := rm -f
endif

## RULES ##################################################

.PHONY: all test clean run

all: $(TARGET)

$(TARGET): $(SOURCES)
	@echo "Building target $(TARGET) ..."
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPSFLAGS) $^ -o $@

test: CPPFLAGS += -DTEST
test: $(TARGET)

clean:
	$(Q)$(RM) $(TARGET) $(DEPENDANCIES)

run: $(TARGET)
	@./$(TARGET)

-include $(DEPENDANCIES)

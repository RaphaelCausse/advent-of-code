SOURCES := day01.c

INCLUDES := ..

TARGET := $(SOURCES:.c=.out)

## COMPILER ###############################################

CC := gcc
CFLAGS := -std=c99 -O2 -Wall
CPPFLAGS := -I$(INCLUDES)

## VERBOSITY ##############################################

VERBOSE := $(or $(v), $(verbose))
ifeq ($(VERBOSE),)
    Q := @
else
    Q :=
endif

## RULES ##################################################

.PHONY: all test clean run

all: $(TARGET)

$(TARGET): $(SOURCES)
	@echo "Building target $(TARGET) ..."
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

test: CPPFLAGS += -DTEST
test: $(TARGET)

clean:
	$(Q)rm -f $(TARGET)

run: $(TARGET)
	@./$(TARGET)
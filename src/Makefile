CC=gcc
CFLAGS=-c
INCLUDES=-I ./
SOURCES=counter.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=count

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -rf *o count

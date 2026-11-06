CC = cc
CFLAGS = -Wall -Wextra
TARGET = convert
OBJECTS = main.o binary.o ascii.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

main.o: ascii.h binary.h
binary.o: binary.h
ascii.o: ascii.h binary.h

clean:
	rm -f $(TARGET) $(OBJECTS)
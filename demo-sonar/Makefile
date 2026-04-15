CC=gcc
CFLAGS=-Wall -Wextra -O0
TARGET=demo_sonar_bug
SRC=demo_sonar_bug.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
CC = gcc
CFLAGS = -Wall -g
TARGET = tp1

all: $(TARGET)

$(TARGET): main.o kmp.o boyer_moore.o uteis.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o kmp.o boyer_moore.o uteis.o

main.o: main.c kmp.h boyer_moore.h uteis.h
	$(CC) $(CFLAGS) -c main.c

kmp.o: kmp.c kmp.h
	$(CC) $(CFLAGS) -c kmp.c

boyer_moore.o: boyer_moore.c boyer_moore.h
	$(CC) $(CFLAGS) -c boyer_moore.c

uteis.o: uteis.c uteis.h
	$(CC) $(CFLAGS) -c uteis.c

clean:
	rm -f *.o $(TARGET)

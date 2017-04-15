# Compiler options
CC=gcc
CFLAGS=-c -Wall
LDFLAGS=

# For cross-platform with Windows
# On Unix, just rm
# On Windows, 2>nul del to suppress error messages
RM=2>nul del

all: launch

launch: launch.o
	$(CC) launch.o -o launch $(LDFLAGS)

launch.o: launch.c
	$(CC) $(CFLAGS) launch.c

clean:
	$(RM) *.o
	$(RM) *.exe
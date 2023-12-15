CC = clang 
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c
EXECUTABLE = server 

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTABLE)

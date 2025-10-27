CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o user.o route.o flight.o booking.o search.o storage.o
TARGET = flight

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

CC=gcc
CFLAGS=
LIBS=-lwiringPi -lpthread

DEPS= 

OBJ = motorctrl.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

motorctrl: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f *.o *~ core motorctrl 

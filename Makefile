TARGET=PolyPlexer
CC=gcc
OBJECT= Color.o main.o
CFLAGS=-W -Wall -g
VERBOSE=no


ifeq ($(VERBOSE), yes)
        CFLAGS+= -DVERBOSE -DCOLOR
endif


$(TARGET) : $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -o $(TARGET)



all: $(OBJ)

verbose:
	@make clean
	@make VERBOSE=yes

gnuplot:
	@make clean
	@make GNUPLOT=yes


Color.o : src/Color.c src/Color.h
	$(CC) $(CFLAGS) -c src/Color.c


main.o : src/main.c 
	$(CC) $(CFLAGS) -c src/main.c

.PHONY: clean mrproper                                                                                                                        

clean:
	@rm -fv *.o

mrproper: clean

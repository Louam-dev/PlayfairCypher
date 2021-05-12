CC = gcc
objects = main.o fileIO.o matrixGenerator.o playfair.o

all : playfair

playfair : $(objects)
	$(CC) -o playfair $(objects)

main.o : main.c playfair.h

fileIO.o : fileIO.c

matrixGenerator.o : matrixGenerator.c

playfair.o : playfair.c fileIO.h matrixGenerator.h


clean : 
	rm *.o playfair




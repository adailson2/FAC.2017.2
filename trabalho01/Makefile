CC = gcc
CFLAGS = -Wall -W -pedantic -ansi -I.

all: tipos_compostos main
tipos_compostos:
	gcc -c tipos_compostos.c tipos_compostos.h $(CFLAGS)
main:
	gcc -o main.out main.c tipos_compostos.h $(CFLAGS)
clean:
	rm	-rf	*.o
mrproper:	clean
	rm	-rf	teste
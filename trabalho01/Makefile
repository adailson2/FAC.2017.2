CC = gcc
CFLAGS = -Wall -W -pedantic -ansi -I.

all: tipos_compostos operacoes main
tipos_compostos:
	gcc -c tipos_compostos.c tipos_compostos.h $(CFLAGS)
operacoes:
	gcc -c operacoes.c operacoes.h tipos_compostos.h $(CFLAGS)
main:
	gcc -o main.out main.c tipos_compostos.h operacoes.h $(CFLAGS)
clean:
	rm	-rf	*.o
mrproper:	clean
	rm	-rf	teste
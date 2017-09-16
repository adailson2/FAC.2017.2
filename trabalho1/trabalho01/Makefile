CC = gcc
CFLAGS = -Wall -W -pedantic -ansi -I. -lm

all: tipos_compostos operacoes the_io main output
tipos_compostos:	
	$(CC) -c tipos_compostos.c tipos_compostos.h $(CFLAGS)
operacoes:
	$(CC) -c operacoes.c operacoes.h $(CFLAGS)
the_io:
	$(CC) -c the_io.c the_io.h $(CFLAGS)
main:
	$(CC) -c main.c tipos_compostos.h operacoes.h the_io.h $(CFLAGS)
output:
	$(CC) -o main.out main.o tipos_compostos.o operacoes.o the_io.o $(CFLAGS)
clean:
	rm	-rf	*.o *.out *.h.gch
mrproper:	clean
	rm	-rf	teste
run: all
	./main.out
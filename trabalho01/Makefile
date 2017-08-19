CC = gcc
CFLAGS = -Wall -W -pedantic -ansi -I. -lm

all: 
	gcc -o main.out main.c tipos_compostos.c operacoes.c the_io.c $(CFLAGS)
clean:
	rm	-rf	*.o *.out *.h.gch
mrproper:	clean
	rm	-rf	teste
run: all
	./main.out
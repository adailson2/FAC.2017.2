/*====================== main.c =================*/
#include <stdio.h>
#include <stdlib.h>
#include "tipos_compostos.h"
#include "operacoes.h"
#include "the_io.h"

/* Aqui main ;( */
int main(void){
	circulo *c = getCirculo();
	ppc *p = getPPC();

	leia_pontos(p);
	calculaRaio(p, c);
	calculaCentro(p, c);

	if(c->msg == NULL) {
		imprima_msg_erro(c);
	} else {
		imprima_resposta(c);
	}

	return (0);
}
/* 
	Adailson Pinho dos Santos - 13/0140724
	Vitor Nere Araújo Ribeiro - 13/0137413 
*/
#include <stdio.h>
#include <stdlib.h>
#include "tipos_compostos.h"
#include "operacoes.h"
#include "the_io.h"

int main(){
	circulo *c = getCirculo();
	ppc *p = getPPC();
	
	leia_pontos(p);
	
	calculaCentro(p, c);

	if(c->msg != NULL) {
		imprima_msg_erro(c);
	} else {
		calculaRaio(p, c);
		calculaArea(c);
		imprima_resposta(c);
	}

	free(p);
	free(c);
	
	return 0;
}
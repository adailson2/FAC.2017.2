#include <stdlib.h>
#include "tipos_compostos.h"

struct _ponto_plano_cartesiano* getPPC() {
	ppc *pontos = (ppc*) malloc(sizeof(ppc));

	pontos->ponto1 = (int*) malloc(sizeof(int)*2);
	pontos->ponto2 = (int*) malloc(sizeof(int)*2);
	pontos->ponto3 = (int*) malloc(sizeof(int)*2);

	pontos -> ponto1[0] = 0;
	pontos -> ponto1[1] = 0;
	pontos -> ponto2[0] = 0;
	pontos -> ponto2[1] = 0;
	pontos -> ponto3[0] = 0;
	pontos -> ponto3[1] = 0;

	return pontos;
}

struct _circulo* getCirculo() {
	circulo *c = (circulo*) malloc(sizeof(circulo));
	c -> x = 0.0;
	c -> y = 0.0;
	c -> msg = NULL;

	/* Realizar cálculo do raio e centro */

	return c;
}
#include <stdlib.h>
#include "tipos_compostos.h"

ppc* getPPC() {
	ppc *pontos = (ppc*) malloc(sizeof(ppc));

	pontos->ponto1 = malloc(sizeof(int)*2);
	pontos->ponto2 = malloc(sizeof(int)*2);
	pontos->ponto3 = malloc(sizeof(int)*2);

	pontos -> ponto1[0] = 0;
	pontos -> ponto1[1] = 0;
	pontos -> ponto2[0] = 0;
	pontos -> ponto2[1] = 0;
	pontos -> ponto3[0] = 0;
	pontos -> ponto3[1] = 0;

	return pontos;
}

circulo* getCirculo() {
	circulo *c = (circulo*) malloc(sizeof(circulo));
	c -> x = 0.0;
	c -> y = 0.0;
	c -> raio = 0.0;
	c -> msg = NULL;

	return c;
}
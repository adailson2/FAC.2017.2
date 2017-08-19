#include "tipos_compostos.h"

struct _ponto_plano_cartesiano* getPPC(int x0, int x1, int y0, int y1, int z0, int z1) {
	ppc *pontos = (ppc*) malloc(sizeof(ppc));

	pontos -> ponto1[0] = x0;
	pontos -> ponto1[1] = x1;
	pontos -> ponto2[0] = y0;
	pontos -> ponto2[1] = y1;
	pontos -> ponto3[0] = z0;
	pontos -> ponto3[1] = z1;

	return pontos;
}

struct _circulo* getCirculo(struct _ponto_plano_cartesiano *pontos) {
	circulo *c = (circulo*) malloc(sizeof(circulo));
	c -> raio = 0.0;
	c -> centro = 0.0;

	/* Realizar cálculo do raio e centro */

	return c;
}
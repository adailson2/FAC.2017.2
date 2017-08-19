#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "tipos_compostos.h"

void *calculaCentro(ppc *p, circulo *c) {
	double x, y, raio, a, b, c, d, k1, k2, det;
	
	/* Ao determinar os valores de x e y, calcular o raio */
	a = 2*(p->ponto2[0] - p->ponto1[0]);
	b = 2*(p->ponto2[1] - p->ponto1[1]);
	c = 2*(p->ponto3[0] - p->ponto1[0]);
	d = 2*(p->ponto3[1] - p->ponto1[1]);

	det = a*d - b*c;

	if(det == 0) {
		msg = (char*) malloc(sizeof(char*20));
		strcpy("Pontos colineares.", msg);
		c = msg;
		return c;
	}
		

	k1 = (p->ponto2[0]*p->ponto2[0] + p->ponto2[1]*p->ponto2[1]) - 
		 (p->ponto1[0]*p->ponto1[0] + p->ponto1[1]*p->ponto1[1]);

	k2 = (p->ponto3[0]*p->ponto3[0] + p->ponto3[1]*p->ponto3[1]) - 
		 (p->ponto1[0]*p->ponto1[0] + p->ponto1[1]*p->ponto1[1]);

	x = (k1*d - k2*b)/det;
	y = (a*k2 - c*k1)/det;

	c.x = x;
	c.y = y;

	return c;
}	

void calculaRaio(ppp *p, circulo *c) {
	/* Pela equação reduzida da circunferência, temos que:
		raio^2 = (x-a)^2 + (y-b)^2, portanto: */

	double r;

	r = sqrt((c.x-p->ponto1[0])^2 + (c.y-ponto1[1])^2);
	
	c.raio = r;

	return c;
}	
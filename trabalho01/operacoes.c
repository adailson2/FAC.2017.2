#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "operacoes.h"
#include "tipos_compostos.h"

void calculaCentro(ppc *p, circulo *circ) {
	double x, y, a, b, c, d, k1, k2, det;
	char *msg;

	/* Ao determinar os valores de x e y, calcular o raio */
	a = 2*(p->ponto2[0] - p->ponto1[0]);
	b = 2*(p->ponto2[1] - p->ponto1[1]);
	c = 2*(p->ponto3[0] - p->ponto1[0]);
	d = 2*(p->ponto3[1] - p->ponto1[1]);

	det = a*d - b*c;

	if(det == 0) {
		msg = (char*) malloc(sizeof(char)*20);
		strcpy("Pontos colineares.", msg);
		circ->msg = msg;
		return;
	}
		

	k1 = (p->ponto2[0]*p->ponto2[0] + p->ponto2[1]*p->ponto2[1]) - 
		 (p->ponto1[0]*p->ponto1[0] + p->ponto1[1]*p->ponto1[1]);

	k2 = (p->ponto3[0]*p->ponto3[0] + p->ponto3[1]*p->ponto3[1]) - 
		 (p->ponto1[0]*p->ponto1[0] + p->ponto1[1]*p->ponto1[1]);

	x = (k1*d - k2*b)/det;
	y = (a*k2 - c*k1)/det;

	circ->x = x;
	circ->y = y;
}	

void calculaRaio(ppc *p, circulo *c) {
	/* Pela equação reduzida da circunferência, temos que:
		raio^2 = (x-a)^2 + (y-b)^2, portanto: */

	double r;

	r = sqrt((c->x - p->ponto1[0])*(c->x - p->ponto1[0]) + (c->y - p->ponto1[1])*(c->y - p->ponto1[1]));
	
	c->raio = r;
}	
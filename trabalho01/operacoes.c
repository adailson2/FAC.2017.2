#include <stdio.h>
#include <stdlib.h>
#include "tipos_compostos.h"

double calculaRaio(int x0, int x1, int y0, int y1,int z0, int z1) {
	/* Pela equação reduzida da circunferência, temos que:
		raio^2 = (x-a)^2 + (y-b)^2, portanto: */

	int x, y, /* coordenadas do centro */
		raio;
	
	/* Pensar numa solução que determine x e y com o sistema de 3 equações com 3 incógnitas como abaixo: */
	raio = sqrt((x-x0)^2 + (y-x1)^2);  
	raio = sqrt((x-y0)^2 + (y-y1)^2);
	raio = sqrt((x-z0)^2 + (y-z1)^2);

	/* Ao determinar os valores de x e y, calcular o raio */

	return raio;
}

double calculaCentro() {
	/* a função calculaRaio já calcula o centro */

}	
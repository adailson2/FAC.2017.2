#include <stdio.h>
#include "the_io.h"

void leia_pontos(ppc *p) {
    scanf("%d %d", p->ponto1[0], p->ponto1[1]);
    scanf("%d %d", p->ponto2[0], p->ponto2[1]);
    scanf("%d %d", p->ponto3[0], p->ponto3[1]);
}
void imprima_resposta(circulo *c) {
    printf("Raio: %.3lf\n", c->raio);
    printf("(%.3lf, %.3lf).\n", c->x, c->y);
}

void imprima_msg_erro(circulo *c) {
    printf("%s", c->msg);
}
#include <stdio.h>
#include "the_io.h"
/* inputs e outputs */
void leia_pontos(ppc *p) {
    scanf("%d %d", &p->ponto1[0], &p->ponto1[1]);
    scanf("%d %d", &p->ponto2[0], &p->ponto2[1]);
    scanf("%d %d", &p->ponto3[0], &p->ponto3[1]);
}

void imprima_resposta(circulo *c) {
    printf("\nRaio: %f\n", c->raio);
    printf("Centro: (%f, %f).\n", c->x, c->y);
}

void imprima_msg_erro(circulo *c) {
    printf("\n%s\n\n", c->msg);
}

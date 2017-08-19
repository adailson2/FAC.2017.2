#include <stdio.h>
#include "tipos_compostos.h"
#include "the_io.h"

void leia_pontos(ppc *p) {
    int x1, x2, x3, y1, y2, y3;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    printf("sakjdsh");

    p->ponto1[0] = x1;
    p->ponto2[0] = x2;
    p->ponto3[0] = x3;
    p->ponto1[1] = y1;
    p->ponto2[1] = y2;
    p->ponto3[1] = y3;

    printf("sEGMENTOU");
}
void imprima_resposta(circulo *c) {
    printf("Raio: %f\n", c->raio);
    printf("(%f, %f).\n", c->x, c->y);
}

void imprima_msg_erro(circulo *c) {
    printf("%s", c->msg);
}
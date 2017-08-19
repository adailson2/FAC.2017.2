#ifndef TIPOS_COMPOSTOS_H
#define TIPOS_COMPOSTOS_H

typedef struct _ponto_plano_cartesiano {
    int ponto1[2]; /* ponto1 = [x0, x1] */
    int ponto2[2]; /* ponto2 = [y0, y1] */
    int ponto3[2]; /* ponto3 = [z0, z1] */
} ppc;

typedef struct _circulo {
    double raio;
    double x;
    double y;
    char *msg;
} circulo;

struct _ponto_plano_cartesiano *getPPC();

struct _circulo *getCirculo();

#endif

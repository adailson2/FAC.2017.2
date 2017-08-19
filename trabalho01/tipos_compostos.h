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

struct _ponto_plano_cartesiano *getPPC(int x0, int x1, int y0, int y1, int z0, int z1);

struct _circulo *getCirculo(struct _ponto_plano_cartesiano *pontos);

#endif

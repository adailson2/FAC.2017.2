/* 
    Adailson Pinho dos Santos - 13/0140724
    Vitor Nere Araújo Ribeiro - 13/0137413 
*/
#ifndef TIPOS_COMPOSTOS_H
#define TIPOS_COMPOSTOS_H
/* Assinaturas */
typedef struct _ponto_plano_cartesiano {
    int *ponto1; /* ponto1 = [x0, x1] */
    int *ponto2; /* ponto2 = [y0, y1] */
    int *ponto3; /* ponto3 = [z0, z1] */
} ppc;

typedef struct _circulo {
    double raio;
    double x; /* coordenada x do centro */
    double y; /* coordenada y do centro */
    double area;
    char *msg;
} circulo;

ppc* getPPC();

circulo* getCirculo();

#endif

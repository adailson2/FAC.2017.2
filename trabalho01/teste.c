#include <stdio.h>
#include <stdlib.h>
/*A funçao makeTeste()*/
void generatorRoot(void){

    double x[1], /* Vetor que armazena as coordenadas do ponto X */ 
    	   y[1], /* Vetor que armazena as coordenadas do ponto Y */ 
    	   z[1], /* Vetor que armazena as coordenadas do ponto Z */ 
    	   w[1]; /* Vetor que armazena as coordenadas do centro da circunferência */ 
    int i;

    /* Entradas */
    for(i; i<=1 ; i++){
    	printf("Digite a coordenada x%d\n",i);
    	scanf("%lf",&x[i]);
    }
    i=0;
    for(i; i<=1 ; i++){
    	printf("Digite a coordenada y%d\n",i);
    	scanf("%lf",&y[i]);
    }
    i=0;
    for(i; i<=1 ; i++){
    	printf("Digite a coordenada z%d\n",i);
    	scanf("%lf",&z[i]);
    }
    i=0;
    for(i; i<=1 ; i++){
    	printf("Digite a coordenada w%d\n",i);
    	scanf("%lf",&w[i]);
    }
    printf("A coordenada digitada foi %1.f\n",x[0]);
    i=0;

    /* Saídas */
    for(i; i<=1 ; i++){
    	printf("Coordenada x: %1.f\n",x[i]);
    	printf("Coordenada y: %1.f\n",y[i]);
    	printf("Coordenada z: %1.f\n",z[i]);
    	printf("Coordenada w: %1.f\n",w[i]);
    }
}
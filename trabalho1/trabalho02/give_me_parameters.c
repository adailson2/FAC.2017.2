/* 
    Adailson Pinho dos Santos - 13/0140724
    Vitor Nere Araújo Ribeiro - 13/0137413 
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i = 1;
    int args_len = argc;
    int name_len = strlen(argv[0]);

    printf("\n# de parametros: %d\n", argc - 1);
    
    printf("Nome do executavel: ");
    for(i=2; i<name_len; i++)
        printf("%c", argv[0][i]);

    printf("\n");

    for(i = 1; i<args_len; i++) {
        printf("Parametro #%d: %s\n", i, argv[i]);
    }

    printf("\n");

    return 0;
}
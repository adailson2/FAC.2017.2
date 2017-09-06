#include <stdio.h>

int main() {
    int num1, num2, i, mod;

    scanf("%d", &num1);
    scanf("%d", &num2);

    i = num1 - 1;

    while(i--) {
        mod = num2 * i;
        mod = mod % num1;
        if(mod == 1) {
            printf("O inverso multiplicativo é %d.\n", i);
            return 0;
        }
    }
    printf("O modulo nao eh primo.\n");

    return 0;
}
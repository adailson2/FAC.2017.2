#include <stdio.h>

int eh_primo(int p) {
    if(p < 3 && p >= 1) 
        return 1; // 
    else if(p<1)
        return 0;
    else {
        i = p-2;
        do {
            if(p%i == 0)
                return 0;

            i = i-2;    
        } while(i != 1);
    }

    return 1;
}

int main() {
    int num1, num2, i, mod;

    scanf("%d", &num1);
    scanf("%d", &num2);

    if(eh_primo(num1) != 1)
        printf("O modulo nao eh primo.\n");

    i = num1 - 1;

    while(i--) {
        mod = num2 * i;
        mod = mod % num1;
        if(mod == 1) {
            printf("O inverso multiplicativo é %d.\n", i);
        }
    }

    return 0;
}
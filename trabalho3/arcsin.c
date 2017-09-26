#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double arcsin(double x) {
    double last=x;
    double sum=last;
    int i, n = 5000;

    for(i=1;i<=n;i++)
    {
        last *= ((x*x)*(2*i-1)*(2*i-1))/((2*i)*(2*i+1));
        sum += last;
    }

    return sum;
}

int main() {
    double angle;
    double arcs;

    scanf("%lf", &angle);

    printf("ArcSin(%lf) = %lf\n", angle, arcsin(angle));

    return 0;
}
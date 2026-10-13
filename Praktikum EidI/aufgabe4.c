#include <stdio.h>

int main(void) {
    int a = 7;
    int b = 2;
    double x = 7.0;
    double y = 2.0;

    printf("%d\n", a/b); // a/b gibt 3 aus, da es sich um eine ganzzahlige Division handelt
    printf("%d\n", a%b);
    printf("%f\n", x/y);

    return 0;
}
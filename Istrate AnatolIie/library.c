#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    printf("Introduceti un numar: ");
    scanf("%d", &num);
    printf("Factorialul este: %d\n", factorial(num));
    return 0;
}

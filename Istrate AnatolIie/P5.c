//Generarea numerelor prime până la un număr dat:
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    printf("Numere prime pana la %d sunt:\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}


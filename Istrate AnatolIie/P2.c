//Determinarea celui mai mare divizor comun (CMMDc) al a două numere:
#include <stdio.h>

int cmmdc(int a, int b) {
    if (b == 0)
        return a;
    else
        return cmmdc(b, a % b);
}

int main() {
    int num1, num2;
    printf("Introduceti doua numere: ");
    scanf("%d %d", &num1, &num2);
    printf("Cel mai mare divizor comun este: %d\n", cmmdc(num1, num2));
    return 0;
}

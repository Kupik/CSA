//Verificarea palindromului:
#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0; // nu este palindrom
    }
    return 1; // este palindrom
}

int main() {
    char str[100];
    printf("Introduceti un string: ");
    scanf("%s", str);
    if (isPalindrome(str))
        printf("%s este palindrom.\n", str);
    else
        printf("%s nu este palindrom.\n", str);
    return 0;
}


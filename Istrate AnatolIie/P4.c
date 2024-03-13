//Conversia unei temperaturi din Fahrenheit în Celsius:
#include <stdio.h>

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    float fahrenheit;
    printf("Introduceti temperatura in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    printf("Temperatura in Celsius este: %.2f\n", fahrenheitToCelsius(fahrenheit));
    return 0;
}

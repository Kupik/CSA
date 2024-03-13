//
////Scrie un program care să afișeze toate numerele pare între 1 și 100 folosind o buclă for.
//#include<stdio.h>
//int main(){
//    int i;
//    for (i=1;i<=100;i++){
//        if(i%2==0){
//            printf("%d\n",i);
//        }
//    }
//}


// Scrie un program pentru a afișa numerele impare între 1 și 100 folosind o buclă while.
// Print numbers from 1 to 5
//#include<stdio.h>
//int main(){
//
//    int i;
//
//    //Print numbers from 1 to 100
//    for(i = 1; i <= 100; i++){
//        if(i%3==0){
//          printf("%d\n",i);
//
//       }
//
//    }
//
//    return 0;
//}

//Funcții:
//2.1  Creează o funcție care să calculeze factorialul unui număr dat.

//#include<stdio.h>
//int main()
//{
//    int i,fact=1,num;
//    printf("Scrie o cifra: ");
//    scanf("%d",&num);
//    for(i=1;i<=num;i++){
//        fact=fact*i;
//    }
//    printf("Factorial este:  %d rspuns:  %d",num,fact);
//    return 0;
//}

//2.2  Creează o funcție care să calculeze aria unui triunghi pe baza datelor introduse de la tastatură.

//#include <stdio.h>
//int main() {
//    float baza, inaltime, zona;
//    printf("Introduce baza triunghiului: ");
//    scanf("%f", &baza);
//    printf("Introduce inaltimea triunghiului: ");
//    scanf("%f", &inaltime);
//    zona = (baza * inaltime) / 2;
//    printf("Aria triunghiului este: %.2f\n", zona);
//    return 0;
//}

//3. Array-uri:
//2.1  Scrie un program în C care să găsească și să afișeze valoarea maximă și pozițiile acesteia într-un array

//#include <stdio.h>
//int main() {
//    int n;
//    double arr[100];
//    printf("Introdu elementele de la 1 pana la 100: ");
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; ++i) {
//        printf("Introdu numerele%d: ", i + 1);
//        scanf("%lf", &arr[i]);
//    }
//    for (int i = 1; i < n; ++i) {
//        if (arr[0] < arr[i]) {
//            arr[0] = arr[i];
//        }
//    }
//    printf("Cel mai mare element este: = %.2lf", arr[0]);
//    return 0; }

//4.Șiruri de Caractere:
//4.1  Scrie un program care să numere și să afișeze numărul de vocale dintr-un șir de caractere dat.
//#include <stdio.h>
//void Solve()
//{  unsigned short numara = 0, vocale = 0;
//    char str[100], c;
//    printf("Introduceti un sir in care doriti sa aflati numarul de vocale: ");
//    scanf("%[^\n]", str);
//    while(str[numara] != '\0') {
//        c = str[numara];
//        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'
//           || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
//            vocale++;
//            printf("%c", c); }
//        numara++; }
//    printf("\n");
//    printf("NUMAR DE VOCALE in sirul dat sunt: %hu \n", vocale); }
//int main()
//{ //    Solve(); //    return 0; //}

//Avansate
//5 Extinde programul de la punctul 3 pentru a sorta array-ul în ordine crescătoare.
//#include <stdio.h>
//int main() {
//    int n;
//    double arr[100];
//    printf("Introdu elementele de la 1 pana la 100: ");
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; ++i) {
//        printf("Introdu numerele%d: ", i + 1);
//        scanf("%lf", &arr[i]);
//    }
//    for (int i = 1; i < n; ++i) {
//        if (arr[0] < arr[i]) {
//            arr[0] = arr[i];
//        }
//    }
//
//     printf("Array-ul sortat in ordine crescatoare: \n");
//    for (int i = 0; i < n; ++i) {
//        printf("%.2lf ", arr[i]);
//    }
//    return 0; }

//6 Extinde programul de la punctul 4 pentru a inversa șirul de caractere.
//(4.1  Scrie un program care să numere și să afișeze
//numărul de vocale dintr-un șir de caractere dat.)
//#include <stdio.h>
//void Solve() {
//    unsigned short numara = 0, vocale = 0;
//    char str[100], c;
//    printf("Introduceti un sir in care doriti sa aflati numarul de vocale: ");
//    scanf("%[^\n]", str);
//    while (str[numara] != '\0') {
//        c = str[numara];
//        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'
//            || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
//            vocale++;
//            printf("%c", c);
//        }     numara++; }
//    printf("\n");
//    printf("NUMAR DE VOCALE in sirul dat sunt: %hu \n ", vocale); // inversam sirul
//    printf("Sirul inversat este: ");
//    numara--;
//    while (numara >= 0) {
//        printf("%c", str[numara]);
//        numara--; } }
//
//int main() {
//    Solve();
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>
void citire(int *arr, int n) {
    printf("Introduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        printf("Elementul %d: ", i + 1);
        scanf("%d", &arr[i]); } }
void afisare(int *arr, int n) {
    printf("Elementele tabloului sunt:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); }
    printf("\n"); }
int* inserare_la_sfarsit(int *arr, int *n, int element) {
    (*n)++;
    arr = (int*)realloc(arr, (*n) * sizeof(int));
    arr[*n - 1] = element;
    return arr; }
int* inserare_la_inceput(int *arr, int *n, int element) {
    (*n)++;
    arr = (int*)realloc(arr, (*n) * sizeof(int));
    for (int i = *n - 1; i > 0; i--) {
        arr[i] = arr[i - 1]; }
    arr[0] = element;
    return arr;
} int main() {
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    citire(arr, n); afisare(arr, n);
    int element;
    printf("Introduceti elementul pe care doriti sa-l adaugati la sfarsitul tabloului: ");
    scanf("%d", &element);
    arr = inserare_la_sfarsit(arr, &n, element); afisare(arr, n);
    printf("Introduceti elementul pe care doriti sa-l adaugati la inceputul tabloului: ");
    scanf("%d", &element);
    arr = inserare_la_inceput(arr, &n, element); afisare(arr, n); free(arr); return 0; }







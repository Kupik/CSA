//Varianta 1
//Identifică elementul cel mai mic și cel mai mare.
//#include <stdio.h>
////Calculate array size
//#define ARRAY_SIZE(a)  sizeof(a)/sizeof(a[0])
//int main() //{
//    int arr[] = {3,5,8,6,2,7,10,11};
//    int i, small, large;
//    const int N = ARRAY_SIZE(arr);
//    small = arr[0];//Assume first element is smallest
//    large = arr[0];//Assume first element is largest
//    //iterate through the array
//    for (i = 1; i < N; i++) //    {
//        if (arr[i] < small) //        {
//            small = arr[i]; //        }
//        if (arr[i] > large) //        {
//            large = arr[i]; //        } //    }
//    printf("Largest element is : %d\n", large);
//    printf("Smallest element is : %d\n", small);
//    return 0; //}

// b) Identifică cele mai mari trei numere ale unui vector.
//v1[]={3,4,5,8,9,1,2,7,10,0}
//
//#include <limits.h>
//#include <stdio.h>
//void print3number(int arr[], int arr_size) {
//    int i, first,second,third;
//    if(arr_size <3 ) {
//        printf("Intrare gresita: ");
//        return; }
//    third = first = second = INT_MIN;
//    for (int i = 0; i < arr_size; i++) {
//        if(arr[i] > first) {
//            third = second;
//            second = first;
//            first = arr[i]; }
//        else if (arr[i] > second) {
//            third = second;
//            second = arr[i]; }
//        else if(arr[i] > third)
//            third = arr[i]; }
//    printf("Articolele cele mai mari: %d %d %d \n", first,second,third); }
//int main() {
//    int arr[] = {3,4,5,8,9,1,2,7,10,0};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    print3number(arr,n);
//    return 0; }

//c)
//Identifică toate elementele fără repetiţii şi indică numărul dublurilor.
//Afişează rezultatul în ordine crescătoare a dublurii.
//v1[]={45,30,45,35,67,35,30,89,90,35}

//#include "stdio.h"
//int Dublicate(int arr[],int n) {
//    if(n == 0 || n == 1)
//        return n;
//    int temp[n];
//    int j =0;
//    for(int i = 0; i<n-1;i++)
//        if(arr[i] != arr[i + 1])
//            temp[j++] = arr[i];
//    temp[j++] = arr[n - 1];
//    for (int i = 0; i < j; i++)
//        arr[i] = temp[i];
//    return j; }
//int main() {
//int arr[] = { 45,30,45,35,67,35,30,89,90,35 };
//int n = sizeof(arr) / sizeof(arr[0]);
//     n = Dublicate(arr,n) ;
//     for (int i = 0; i < n; i++) {
//     printf("%d ",arr[i]);
//      return 0; }}

//Determină reuniunea a doi vectori, într-un alt vector.
//v1[]={2,3,1,7}
//v2[]={3,5,8,2,4,6}

//#include <stdio.h>
//// Funcție pentru a verifica dacă un element există deja într-un vector
//int existaInVector(int x, int vector[], int lungime) {
//    for (int i = 0; i < lungime; i++) {
//        if (vector[i] == x) {
//            return 1; // Returnează 1 dacă elementul există în vector
//        } } return 0; // Returnează 0
//     }
//void reuniuneVectori(int v1[], int lungime_v1, int v2[], int lungime_v2) {
//    int reuniune[100];
//    int lungime_reuniune = 0;
//    for (int i = 0; i < lungime_v1; i++) {
//        if (!existaInVector(v1[i], reuniune, lungime_reuniune)) {
//            reuniune[lungime_reuniune++] = v1[i]; } }
//    // Adaugă toate elementele din al doilea vector care nu există deja în reuniune
//    for (int i = 0; i < lungime_v2; i++) {
//        if (!existaInVector(v2[i], reuniune, lungime_reuniune)) {
//            reuniune[lungime_reuniune++] = v2[i]; } }
//    printf("Reuniunea vectorilor: {");
//    for (int i = 0; i < lungime_reuniune; i++) {
//        printf("%d", reuniune[i]);
//        if (i < lungime_reuniune - 1) {
//            printf(", "); } } printf("}\n"); }
//int main() {
//    int v1[] = {2, 3, 1, 7};
//    int lungime_v1 = sizeof(v1) / sizeof(v1[0]);
//    int v2[] = {3, 5, 8, 2, 4, 6};
//    int lungime_v2 = sizeof(v2) / sizeof(v2[0]);
//    reuniuneVectori(v1, lungime_v1, v2, lungime_v2);
//    return 0; }

//Afişează elementele unei matrici care sunt poziţionate pe diagonala principală.
//m1[][] = {{1,2,3},
//         {4,5,6},
//         {7,8,9}}
//
#include <stdio.h>

int main() {
    // Declarați și inițializați matricea
    int matrice[3][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};

    // Parcurgeți matricea și afișați elementele de pe diagonala principală
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                printf("%d ", matrice[i][j]);
            }
        }
    }

    return 0;
}






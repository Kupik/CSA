#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 100 // Definim o dimensiune maximă a listei
#define SUCCESS 0
#define POSITION_INIT 1
#define INVALID_POSITION 2
#define POSITION_EMPTY 3
#define LIST_FULL 4

// Structura prin care definim elementul listei
typedef struct {
    char codBanca[6];
    char codClient[11];
    char dataOperatiune[11];
    double sumaOperatiune;
} OperatiuneBancara;

typedef struct ListaOperatiuni {
    OperatiuneBancara operatiuni[MAX_SIZE];
    int size; // Numărul de operațiuni
} ListaOperatiuni;

// Funcție de initializare
void initializeaza_lista_operatiuni(ListaOperatiuni *lista){
    lista->size = 0; // Lista este goală
}

// Funcție de adăugare în lista
int adauga_operatiune(ListaOperatiuni *lista, OperatiuneBancara operatiuneNoua){
    if(lista->size < MAX_SIZE){
        lista->operatiuni[lista->size] = operatiuneNoua;
        lista->size++;
        return SUCCESS;
    } else {
        return LIST_FULL; // Cod 4 - lista este plină!
    }
}

// Funcție de afișare a operațiunilor
void afiseaza_operatiuni(ListaOperatiuni *lista){
    if(lista->size == 0){
        printf("Lista este goala! Nu exista nicio operatiune bancara.");
        return;
    }
    for(int i = 0;  i < lista->size; i++){
        printf("Nr.%d, Cod banca: %s, Client: %s, Data: %s, Suma: %.3f\n",
               i+1,
               lista->operatiuni[i].codBanca,
               lista->operatiuni[i].codClient,
               lista->operatiuni[i].dataOperatiune,
               lista->operatiuni[i].sumaOperatiune
        );
    }
    printf("\n");
}

// Funcție de scriere în fișier a operațiunilor
void scrie_operatiuni_in_fisier(FILE *outputFile, ListaOperatiuni *lista){
    if(lista->size == 0){
        printf("Lista este goala! Nu exista nicio operatiune bancara.");
        return;
    }
    for(int i = 0;  i < lista->size; i++){
        fprintf(outputFile, "Nr.%d, Cod banca: %s, Client: %s, Data: %s, Suma: %.3f\n",
                i+1,
                lista->operatiuni[i].codBanca,
                lista->operatiuni[i].codClient,
                lista->operatiuni[i].dataOperatiune,
                lista->operatiuni[i].sumaOperatiune
        );
    }
    printf("\n");
}

// Funcție de sortare a operațiunilor după dată
void sorteaza_operatiuni(ListaOperatiuni *lista){
    for (int i = 0; i < lista->size-1; ++i) {
        for (int j = 0; j < lista->size-1-i; ++j) {
            if(strcmp(lista->operatiuni[j].dataOperatiune, lista->operatiuni[j+1].dataOperatiune) > 0){
                OperatiuneBancara temp = lista->operatiuni[j];
                lista->operatiuni[j] = lista->operatiuni[j+1];
                lista->operatiuni[j+1] = temp;
            }
        }
    }
}

// Funcție de citire a operațiunilor din fișier
void citeste_operatiuni_din_fisier(FILE *inputFile, ListaOperatiuni *lista){
    if(!inputFile){
        printf("A aparut o eroare la deschiderea fisierului!");
        return;
    }

    OperatiuneBancara op;
    char line[100];
    while (fgets(line, sizeof(line), inputFile) != NULL){
        strncpy(op.codBanca, line, 5);
        op.codBanca[5] = '\0';

        strncpy(op.codClient, line+5, 10);
        op.codClient[10] = '\0';

        strncpy(op.dataOperatiune, line+15, 10);
        op.dataOperatiune[10] = '\0';

        char *ptr;
        op.sumaOperatiune = strtod(line+25, &ptr);

        adauga_operatiune(lista, op);
    }
}

int main() {
    ListaOperatiuni listaOperatiuni;
    initializeaza_lista_operatiuni(&listaOperatiuni);

    FILE *inputFile = fopen("operatiuni.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    citeste_operatiuni_din_fisier(inputFile, &listaOperatiuni);
    afiseaza_operatiuni(&listaOperatiuni);

    // Suma operațiunilor pentru fiecare client
    float sumaClient0001 = 0;
    float sumaClient0021 = 0;

    for(int i = 0; i < listaOperatiuni.size; i++) {
        // Verificăm codul clientului și actualizăm suma corespunzătoare
        if(strcmp(listaOperatiuni.operatiuni[i].codClient, "0000000001") == 0) {
            sumaClient0001 += listaOperatiuni.operatiuni[i].sumaOperatiune;
        } else if(strcmp(listaOperatiuni.operatiuni[i].codClient, "0000000021") == 0) {
            sumaClient0021 += listaOperatiuni.operatiuni[i].sumaOperatiune;
        }
    }

    // Afisăm suma pentru fiecare client
    printf("Suma pentru clientul cu codul 0000000001: %.3f\n", sumaClient0001);
    printf("Suma pentru clientul cu codul 0000000021: %.3f\n", sumaClient0021);

    // Afisăm suma totală pentru ambii clienți
    float sumaTotala = sumaClient0001 + sumaClient0021;
    printf("Suma totala pentru ambii clienti 00001 9999999999 : %.3f\n", sumaTotala);

    // Scriem operațiunile sortate în fișierul de ieșire
    scrie_operatiuni_in_fisier(outputFile, &listaOperatiuni);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}



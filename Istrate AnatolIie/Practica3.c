#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura pentru un nod de carte
typedef struct Carte {
    char titlu[100];
    char autor[50];
    int an_publicare;
    struct Carte* next;
} Carte;

// Funcție pentru verificarea dacă lista este goală
int listaGoala(Carte* cap) {
    return cap == NULL;
}

// Funcție pentru inserarea unei cărți la sfârșitul listei
void inserareSfarsit(Carte** cap, Carte* nou) {
    if (*cap == NULL) {
        *cap = nou;
    } else {
        Carte* temp = *cap;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nou;
    }
}

// Funcție pentru inserarea unei cărți la începutul listei
void inserareInceput(Carte** cap, Carte* nou) {
    nou->next = *cap;
    *cap = nou;
}

// Funcție pentru afișarea tuturor cărților din listă
void afisareCarti(Carte* cap) {
    if (listaGoala(cap)) {
        printf("Lista este goala.\n");
    } else {
        while (cap != NULL) {
            printf("Titlu: %s | Autor: %s | An publicare: %d\n", cap->titlu, cap->autor, cap->an_publicare);
            cap = cap->next;
        }
    }
}

// Funcție pentru ștergerea unei cărți după titlu
void stergereCarteDupaTitlu(Carte** cap, char* titlu) {
    Carte* temp = *cap;
    Carte* anterior = NULL;

    if (temp != NULL && strcmp(temp->titlu, titlu) == 0) {
        *cap = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->titlu, titlu) != 0) {
        anterior = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Cartea cu titlul %s nu a fost gasita.\n", titlu);
        return;
    }

    anterior->next = temp->next;
    free(temp);
}

// Funcție pentru actualizarea anului de publicare pentru o carte dată
void actualizareAnPublicare(Carte* cap, char* titlu, int noulAn) {
    while (cap != NULL) {
        if (strcmp(cap->titlu, titlu) == 0) {
            cap->an_publicare = noulAn;
            return;
        }
        cap = cap->next;
    }
    printf("Cartea cu titlul %s nu a fost gasita.\n", titlu);
}

// Funcție pentru eliberarea memoriei listei
void eliberareMemorie(Carte** cap) {
    Carte* temp;
    while (*cap != NULL) {
        temp = *cap;
        *cap = (*cap)->next;
        free(temp);
    }
}

int main() {
    Carte* listaCarti = NULL;

    // Exemplu de inserare la început
    Carte* carte1 = (Carte*)malloc(sizeof(Carte));
    strcpy(carte1->titlu, "Amintiri din copilarie");
    strcpy(carte1->autor, "Ion Creanga");
    carte1->an_publicare = 1892;
    carte1->next = NULL;
    inserareInceput(&listaCarti, carte1);

    // Exemplu de inserare la sfârșit
    Carte* carte2 = (Carte*)malloc(sizeof(Carte));
    strcpy(carte2->titlu, "Ana Consinzeana");
    strcpy(carte2->autor, "Mihai Eminescu");
    carte2->an_publicare = 1996;
    carte2->next = NULL;
    inserareSfarsit(&listaCarti, carte2);

    // Afisare carti
    printf("Lista initiala:\n");
    afisareCarti(listaCarti);

    // Stergere carte dupa titlu
    stergereCarteDupaTitlu(&listaCarti, "Ana Consinzeana");
    printf("\nLista dupa stergerea cartii 'Ana Consinzeana':\n");
    afisareCarti(listaCarti);

    // Actualizare an publicare pentru o carte
    actualizareAnPublicare(listaCarti, "Amintiri din copilarie", 1996);
    printf("\nLista dupa actualizarea anului de publicare pentru 'Mandrie si prejudecata':\n");
    afisareCarti(listaCarti);

    // Eliberare memorie  este utilizată pentru a elibera memoria alocată
    eliberareMemorie(&listaCarti);

    return 0;
}

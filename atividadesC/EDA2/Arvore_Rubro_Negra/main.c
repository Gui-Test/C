#include <stdlib.h>
#include <stdio.h>
#include "ARB.h"

int main() {
    Arvore* a = criar();

    adicionar(a, 2);
    adicionar(a, 6);
    adicionar(a, 3);
    adicionar(a, 1);
    adicionar(a, 5);
    adicionar(a, 7);
    adicionar(a, 4);

    printf("In-order: ");
    percorrer(a->raiz,visitar);
    printf("\n");
    
}
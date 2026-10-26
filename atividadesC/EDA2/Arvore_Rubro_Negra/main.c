#include <stdlib.h>
#include <stdio.h>
#include "ARB.h"

int main() {
    Arvore* a = criar();

    adicionar(a, 4);
    adicionar(a, 2);
    adicionar(a, 3);
    adicionar(a, 1);
    adicionar(a, 8);
    adicionar(a, 9);
    adicionar(a, 6);
    adicionar(a, 7);
    adicionar(a, 5);

    printf("In-order: ");
    percorrerPreOrder(a, a->raiz,visitar);
    printf("\n");
    
}
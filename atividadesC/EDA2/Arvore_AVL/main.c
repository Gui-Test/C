#include "AVL.h"
//gcc main.c AVL.h

int main(){

    AVL* arvr = cria(); 
    adiciona(arvr,1);
    adiciona(arvr,2);
    adiciona(arvr,3);
    

    percorrer(arvr->raiz);

}
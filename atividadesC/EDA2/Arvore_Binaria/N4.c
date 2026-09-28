#include "ABB.h"

int main(){
    
    //Exc 4
    ABB* arvr = cria();
    adiciona(arvr,4);
    adiciona(arvr,2);
    adiciona(arvr,1);
    adiciona(arvr,3);
    adiciona(arvr,8);
    adiciona(arvr,9);
    adiciona(arvr,6);
    adiciona(arvr,5);
    adiciona(arvr,7);

    percorrer(arvr->raiz);


}
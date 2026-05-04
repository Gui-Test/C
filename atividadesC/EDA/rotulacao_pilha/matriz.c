#include "arq.h"

void cria_matriz(){
    FILE *f = fopen("entrada_1.txt", "r");
    if(!f){
        printf("Arquivo não encontrado.\n");
        return;
    }
    char buffer[256];
    fgets(buffer, sizeof(buffer), f);
    printf("%s", buffer);

    fclose(f);
}


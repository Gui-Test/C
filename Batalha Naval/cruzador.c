#include <stdio.h>
#include <math.h>
#include"naval.h"

int posCruz(char tabuleiro[TAM][TAM]){
    int coluna, linha, dir;
    char linha_l;

    printf("\nAgora vamos posicionar o Cruzador(ocupa 3A espaços).\n");
        printf("\nEscolha entre (A - G) para definir a linha inicial para embarcação.\n");
        scanf(" %c", &linha_l);

        switch (linha_l){
            case 'A':
                linha=1;
            break;
            case 'B':
                linha=2;
            break;
            case 'C':
                linha=3;
            break;
            case 'D':
                linha=4;
            break;
            case 'E':
                linha=5;
            break;
            case 'F':
                linha=6;
            break;
            case 'G':
                linha=7;
            break;
            default:{
                printf("Valor incorreto, tente escrever novamente, verificando se é a letra correta ou se está em maiusculo\n");
                scanf(" %c", &linha_l);
            }
        }
        
    printf("\nEscolha entre (1 - 7) para a coluna inicial do Cruzador:\n");
    scanf(" %i", &coluna);

    printf("\nDigite o número relativo a direção que está apontando:\n 1-horizontal ou 2-vertical\n");
    scanf(" %i", &dir);
    if(dir==1){
        if(coluna+1>TAM){
            printf("Posição inválida, tente novamente\n");
            return 0;
        }
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha-1][coluna-1+i] == 'N') {
                printf("\nJá existe navio aqui, tente novamente.\n");
                return 0;
            }
        }
        for (int i = 0; i < 3; i++){
            tabuleiro[linha-1][coluna-1+i] = 'N';
        }
    }else if(dir==2){
        if(linha+1>TAM){
            printf("Posição inválida, tente novamente\n");
            return 0;
        }
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha-1+i][coluna-1] == 'N') {
                printf("Já existe navio aqui, tente novamente.\n");
                return 0;
            }
        }
        for (int i = 0; i < 3; i++){
            tabuleiro[linha-1+i][coluna-1] = 'N';
        }

        }

    return 1;

}
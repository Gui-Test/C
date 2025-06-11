#include <stdio.h>
#include <math.h>
#include"naval.h"

int posSub(char tabuleiro[TAM][TAM]){
    int coluna, linha;
    char linha_l;


    printf("\nComeçando pelo Submarino(ocupa um espaço).\n");
        printf("\nEscolha entre (A - G) que linha quer posicionar o Sub:\n");
        scanf(" %c", &linha_l);

        do{
            switch (linha_l){
            case 'A':
            linha = 0;
            break;
            case 'B':
            linha = 1;
            break;
            case 'C':
            linha = 2;
            break;
            case 'D':
            linha = 3;
            break;
            case 'E':
            linha = 4;
            break;
            case 'F':
            linha = 5;
            break;
            case 'G':
            linha = 6;
            break;
            default:{
            printf("Cordenada Inválida.Tente Novamente, marujo:\n");
            return 0;
            }
            };
        } while (linha < 0);
        
    printf("\nEscolha entre (1 - 7) que coluna quer posicionar o Sub:\n");
    scanf(" %i", &coluna);
    if(coluna>TAM){
        printf("Posição inválida, tente novamente\n");
        return 0;
    }
    tabuleiro[linha][coluna-1] = 'N';
    return 1;
}

int posFrag(char tabuleiro[TAM][TAM]){
    int coluna, linha, dir;
    char linha_l;


    printf("\n\nAgora vamos posicionar a Fragata(ocupa 2 espaços).\n");
    printf("\nEscolha entre (A - G) para definir a linha inicial para embarcação.\n");
    scanf(" %c", &linha_l);

        do{
            switch (linha_l){
            case 'A':
            linha = 0;
            break;
            case 'B':
            linha = 1;
            break;
            case 'C':
            linha = 2;
            break;
            case 'D':
            linha = 3;
            break;
            case 'E':
            linha = 4;
            break;
            case 'F':
            linha = 5;
            break;
            case 'G':
            linha = 6;
            break;
            default:{
            printf("Cordenada Inválida.Tente Novamente, marujo:\n");
            printf("\nEscolha a linha à qual deseja atirar:(A - G): \n");
            scanf(" %c", &linha_l);
            }
            };
        } while (linha < 0);
    
        printf("\nEscolha entre (1 - 7) para a coluna inicial da Fragata:\n");
        scanf(" %i", &coluna);

        printf("\nDigite o número relativo a direção que está apontando:\n 1-horizontal ou 2-vertical\n");
        scanf(" %i", &dir);
        if(dir==1){
            if(coluna+1>TAM){
                printf("Posição inválida, tente novamente\n");
                return 0;
            }
            for (int i = 0; i < 2; i++) {
                if (tabuleiro[linha][coluna-1+i] == 'N') {
                    printf("\nJá existe navio aqui, tente novamente.\n");
                    return 0;
                }
            }
            
            for (int i = 0; i < 2; i++){
                tabuleiro[linha][coluna-1+i] = 'N';
                
            }
        }else if(dir==2){
            if(linha+1>TAM){
                printf("Posição inválida, tente novamente\n");
                return 0;
            }
            for (int i = 0; i < 2; i++) {
                if (tabuleiro[linha+i][coluna-1] == 'N') {
                    printf("Já existe navio aqui, tente novamente.\n");
                    return 0;
                }
            }
            for (int i = 0; i < 2; i++){
                tabuleiro[linha+i][coluna-1] = 'N';
                
            }

        }else{
            printf("\nValor Inválido.\n");
            return 0;
        }

    return 1;
}

int posCruz(char tabuleiro[TAM][TAM]){
    int coluna, linha, dir;
    char linha_l;

    printf("\n\nAgora vamos posicionar o Cruzador(ocupa 3A espaços).\n");
        printf("\nEscolha entre (A - G) para definir a linha inicial para embarcação.\n");
        scanf(" %c", &linha_l);

        do{
            switch (linha_l){
            case 'A':
            linha = 0;
            break;
            case 'B':
            linha = 1;
            break;
            case 'C':
            linha = 2;
            break;
            case 'D':
            linha = 3;
            break;
            case 'E':
            linha = 4;
            break;
            case 'F':
            linha = 5;
            break;
            case 'G':
            linha = 6;
            break;
            default:{
            printf("Cordenada Inválida.Tente Novamente, marujo:\n");
            printf("\nEscolha a linha à qual deseja atirar:(A - G): \n");
            scanf(" %c", &linha_l);
            }
            };
        } while (linha < 0);
        
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
            if (tabuleiro[linha][coluna-1+i] == 'N') {
                printf("\nJá existe navio aqui, tente novamente.\n");
                return 0;
            }
        }
        for (int i = 0; i < 3; i++){
            tabuleiro[linha][coluna-1+i] = 'N';
        }
    }else if(dir==2){
        if(linha+1>TAM){
            printf("Posição inválida, tente novamente\n");
            return 0;
        }
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha+i][coluna-1] == 'N') {
                printf("Já existe navio aqui, tente novamente.\n");
                return 0;
            }
        }
        for (int i = 0; i < 3; i++){
            tabuleiro[linha+i][coluna-1] = 'N';
        }

        }else{
            printf("\nValor Inválido.\n");
            return 0;
        }

    return 1;

}
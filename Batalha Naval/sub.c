#include <stdio.h>
#include <math.h>
#include"naval.h"

void posSub(char tabuleiro[TAM][TAM]){
    int coluna, linha;
    char linha_l;


    printf("\nVamos começar a posicionar nossas peças, começando pelo Submarino que ocupa um espaço.\n");
        printf("\nEscolha entre (A - G) que linha quer posicionar o Sub:\n");
        scanf(" %c", &linha_l);

        do{
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
    }while(linha<1);
        
    printf("\nEscolha entre (1 - 7) que coluna quer posicionar o Sub:\n");
    scanf(" %i", &coluna);
    tabuleiro[linha-1][coluna-1] = 'N';
}
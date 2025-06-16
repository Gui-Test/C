#include <stdio.h>
#include <math.h>
#include"naval.h"
//arquivo com as funções principalmente relacionadas ao tabuleiro em si.

//função para "criar" o tabuleiro.
void iniciarTabuleiro(char tabuleiro [TAM][TAM]){
    //este FOR serve para puxar as linhas do tabuleiro, em cada linha, rodará o próximo for, quantas linhas terá é definido pelo TAM no arquivo "naval.h"
    for(int i=0; i<TAM; i++){
        //este FOR puxa a coluna do tabuleiro, a partir dela, define-se que '~' será posicionado na linha e coluna do momento.
        for(int j=0;j<TAM;j++){
            tabuleiro[i][j] = '~';
        }
    }
}


//função para printar o tabuleiro
void mostraTabuleiro(char tabuleiro [TAM][TAM]){
    //printa os números das colunas
    printf("\n   0 1 2 3 4 5 6");
    for(int i=0; i<TAM; i++){
        //printa as letras das linhas, começa partindo de A+0=A, depois A+1=B...
        printf("\n %c", 'A' + i);
        for(int j=0;j<TAM;j++){
            //printa os valores definidos de cada [linha][coluna].
            printf(" %c", tabuleiro[i][j]);
        }
    }
}

//função para fim de jogo
int tabuleiroVazio(char tabuleiro [TAM][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            //basicamente verifica se em alguma linha tem Navio, quando nenhuma linha tiver, ele vai retornar 1, concluindo a função na tela de JxJ.
            if(tabuleiro[i][j]=='N'){
                return 0;
            }
        }
    }
    return 1;
}
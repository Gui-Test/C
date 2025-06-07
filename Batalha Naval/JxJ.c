#include <stdio.h>
#include <math.h>
#include"naval.h"



//função para jogar realmente, onde os jogadores escolherão seus ataques, os tabuleiros serão printados, etc...
void jogar(Jogador* j1, Jogador* j2) {

    //define p1 e p2 para o tipo jogo, colocando as informações contidas do "naval.h"
    Jogo p1, p2;
    //relaciona as informações da função iniciar tabuleiro, vinda de "tabuleiro.c" e relaciona com os p1 e p2 em cada informação, guardando o mapa normal e o mapa com os tiros de cada jogador
    iniciarTabuleiro(p1.tabuleiro);
    iniciarTabuleiro(p1.tiros);
    iniciarTabuleiro(p2.tabuleiro);
    iniciarTabuleiro(p2.tiros);


int i;
int sucesso ,suc , turno = 0;
char passar;


    printf("Vamos iniciar o jogo. P1 escolha as posições dos seus navios.\n");
    
        posSub(p1.tabuleiro);

        do{
            sucesso=posFrag(p1.tabuleiro);
        }while(!sucesso);

        do{
            suc=posCruz(p1.tabuleiro);
        }while(!suc);

        printf("\033[2J\033[H");

    printf("Vamos iniciar o jogo. P2 escolha as posições dos seus navios.\n");
    
        posSub(p2.tabuleiro);

        do{
            sucesso=posFrag(p2.tabuleiro);
        }while(!sucesso);

        do{
            suc=posCruz(p2.tabuleiro);
        }while(!suc);

        printf("\033[2J\033[H");
            

    //while de divisão de turnos e ações dos jogadores.
    while(1){
        if(turno % 2 ==0){
            printf("Vez do P1, digite x para iniciar\n");
            scanf(" %c", &passar);

            printf("Tabuleiro P1:\n");

            mostraTabuleiro(p1.tabuleiro);

            printf("\n\nO inimigo lhe atacou em: 'insira coordenadas aqui'\n");
            printf("\nTabuleiro Inimigo:\n");

            mostraTabuleiro(p2.tiros);

            atirar(p2.tabuleiro,p2.tiros);

            printf("\nFinalizar seu turno? Digite x:\n");
            scanf(" %c", &passar);
            printf("\033[2J\033[H");
            turno++;
        }else if(turno % 2 != 0){
            printf("Vez do P2, digite x para iniciar\n");
            scanf(" %c", &passar);

            printf("Tabuleiro P2:\n");

            mostraTabuleiro(p2.tabuleiro);

            printf("\n\nO inimigo lhe atacou em: 'insira coordenadas aqui'\n");
            printf("\nTabuleiro Inimigo:\n");

            mostraTabuleiro(p1.tiros);

            atirar(p1.tabuleiro,p1.tiros);
            
            printf("\nFinalizar seu turno? Digite x:\n");
            scanf(" %c", &passar);
            printf("\033[2J\033[H");
            turno++;
        }
    }
}
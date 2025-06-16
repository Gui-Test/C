#include <stdio.h>
#include <math.h>
#include"naval.h"



//função para jogar realmente, onde os jogadores escolherão seus ataques, os tabuleiros serão printados, etc...
void jogar(Jogador* j1, Jogador* j2) {
int enq = 1;


while(enq == 1){
        //define p1 e p2 para o tipo jogo, colocando as informações contidas do "naval.h"
        Jogo p1, p2;
        //pega as informações da função iniciar tabuleiro, vinda de "tabuleiro.c" e relaciona com os p1 e p2 em cada informação, guardando o mapa normal e o mapa com os tiros de cada jogador
        iniciarTabuleiro(p1.tabuleiro);
        iniciarTabuleiro(p1.tiros);
        iniciarTabuleiro(p2.tabuleiro);
        iniciarTabuleiro(p2.tiros);


        int i;
        int sucesso ,suc , turno = 0, L, C;
        char passar, continua;


        printf("\n\nVamos iniciar o jogo.\n\nP1 escolha as posições dos seus navios.\n");
            //chama a função para posicionar o submarino
            do{
                sucesso=posSub(p1.tabuleiro);
                printf("\033[2J\033[H");
                //^esse "código" limpa o terminal, basicamente empurrando todas as informações para cima do terminal, ainda queremos encontrar uma forma melhor de trabalhar com limpeza de tela.
            }while(!sucesso);

            mostraTabuleiro(p1.tabuleiro);
            //^mostra como ficou após adição do submarino
            do{
                //chama a função para posicionar a Fragata, caso a função retorne 1.
                sucesso=posFrag(p1.tabuleiro);
                
            }while(!sucesso);
            
            printf("\033[2J\033[H");
            mostraTabuleiro(p1.tabuleiro);
            //^mostra como ficou após adição da fragata

            do{
                //chama a função para posicionar o Cruzador, caso a função retorne 1.
                suc=posCruz(p1.tabuleiro);
            }while(!suc);
            printf("\033[2J\033[H");

            mostraTabuleiro(p1.tabuleiro);
            //^mostra como ficou o seu tabuleiro após todas as adições


            printf("\n\nSeu tabuleiro ficou assim, digite x para passar a vez.\n");
            scanf(" %c", &passar);

            printf("\033[2J\033[H");
        
        
        //vai repetir as ações do anterior, desta vez para o player 2.
        printf("\nP2 escolha as posições dos seus navios.\n");
        
            posSub(p2.tabuleiro);
            printf("\033[2J\033[H");
            mostraTabuleiro(p2.tabuleiro);

            do{
                sucesso=posFrag(p2.tabuleiro);
                
            }while(!sucesso);
            
            printf("\033[2J\033[H");
            mostraTabuleiro(p2.tabuleiro);

            do{
                suc=posCruz(p2.tabuleiro);
            }while(!suc);
            printf("\033[2J\033[H");
            mostraTabuleiro(p2.tabuleiro);
            printf("\n\nSeu tabuleiro ficou assim, digite x para passar a vez.\n");
            scanf(" %c", &passar);

            printf("\033[2J\033[H");

                

        //while de divisão de turnos e ações dos jogadores.
        while(1){
            //turno é dividido por modulo de 2, a cada while, ele verifica se tem resto 0 ou não, e isso define os turnos.
            if(turno % 2 ==0){
                printf("Vez do P1, digite x para iniciar\n");
                scanf(" %c", &passar);
                printf("\033[2J\033[H");
                //^apenas uma confirmação para iniciar turno, para que o P2 pare de olhar o pc. 

                printf("Tabuleiro P1:\n");

                //mostra o seu tabuleiro, com tiros dados contra você e posições dos seus barcos 
                mostraTabuleiro(p1.tabuleiro);
                
                printf("\n\nTabuleiro Inimigo:\n");

                //mostra tabuleiro do inimigo, apenas com os tiros já realizados
                mostraTabuleiro(p2.tiros);


                //função de atirar.
                atirar(p2.tabuleiro,p2.tiros);

                printf("\nTabuleiro Inimigo atacado\n");
                //mostra o resultado do ataque
                mostraTabuleiro(p2.tiros);

                printf("\n\nFinalizar seu turno? Digite x:\n");
                scanf(" %c", &passar);
                printf("\033[2J\033[H");
                //confirmação para finalizar o turno
            
            }else{

                //repete o ciclo, para o p2
                printf("Vez do P2, digite x para iniciar\n");
                scanf(" %c", &passar);
                printf("\033[2J\033[H");

                printf("Tabuleiro P2:\n");

                mostraTabuleiro(p2.tabuleiro);

                printf("\n\nTabuleiro Inimigo:\n");

                mostraTabuleiro(p1.tiros);

                atirar(p1.tabuleiro,p1.tiros);

                printf("\nTabuleiro Inimigo atacado\n");
                
                mostraTabuleiro(p1.tiros);

                printf("\n\nFinalizar seu turno? Digite x:\n");
                scanf(" %c", &passar);
                printf("\033[2J\033[H");
                
            }

            //finalizar o jogo, atualmente não esta funcional, temos que corrigir, mas é tranquilo de fazer.
            if (tabuleiroVazio(p2.tabuleiro)){
                printf("\nP1 vencedor.\n");
                j1->vitorias++;
                j2->derrotas++;
                break;   
            }

            if (tabuleiroVazio(p1.tabuleiro)){
                printf("\nP2 vencedor.\n");
                j2->vitorias++;  
                j1->derrotas++;
                break;  
            }

            turno++;
        }
        printf("\nPontuação Jogador 1: %d\n\nPontuação Jogador 2: %d\n\nVitórias Jogador 1: %d\n\nVitórias Jogador 2: %d\n",
            j1->pontuacao, j2->pontuacao, j1->vitorias, j2->vitorias);

        printf("\n\nIniciar um novo jogo?(S ou N)\n");
        scanf(" %c", &continua);
        if(continua != 'S'){
            printf("\n\nObrigado por jogar!!! Até a próxima\n\n");
            enq=0;
        }else if(continua == 'S'){
            enq=1;
        }
    }
}
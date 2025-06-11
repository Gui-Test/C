#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "naval.h"

void atirar(char tabuleiro[TAM][TAM],char tiros[TAM][TAM]){

  int linha, coluna;
  char linha_1;

  printf("\nEscolha a linha à qual deseja atirar:(A - G): \n");
  scanf(" %c", &linha_1);

  do{
    switch (linha_1){
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
      scanf(" %c", &linha_1);
    }
    };
  } while (linha < 0);

  do{
    printf("\nEscolha a coluna à qual deseja atirar:(1 - 7): \n");
    scanf(" %i", &coluna);
  } while (coluna < 1 || coluna > 7);

  printf("\033[2J\033[H");
  printf("\nDISPARAR CANHÃO!!!");
  printf("\n ...");

  if (tabuleiro[linha][coluna - 1] == '~'){
    tabuleiro[linha][coluna - 1] = 'x';
    tiros[linha][coluna - 1] = 'x';
    printf("\nNada foi atingindo.");
  }else{
    if (tabuleiro[linha][coluna - 1] == 'N'){
      tabuleiro[linha][coluna - 1] = 'o';
      tiros[linha][coluna - 1] = 'o';
      printf("\nNavio inimigo atingido!");
    }
    else{
      printf("\nJá atiramos aqui, capitão...");
    }
    
  }
}
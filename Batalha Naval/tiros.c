#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "naval.h"

void atirar(char tabuleiro[TAM][TAM],char tiros[TAM][TAM]){

  int linha, coluna;
  char linha_1;

  printf("\nEscolha a linha aonde quer atirar:(A-G): \n");
  scanf(" %c", &linha_1);

  do{
    switch (linha_1){
    case 'A':
      linha = 1;
      break;
    case 'B':
      linha = 2;
      break;
    case 'C':
      linha = 3;
      break;
    case 'D':
      linha = 4;
      break;
    case 'E':
      linha = 5;
      break;
    case 'F':
      linha = 6;
      break;
    case 'G':
      linha = 7;
      break;
    default:{
      printf("Cordenada Inválida.Tente Novamente, marujo:\n");
      printf("\nEscolha a linha aonde quer atirar:(A-G): \n");
      scanf(" %c", &linha_1);
    }
    };
  } while (linha < 1);

  do{
    printf("\nEscolha a coluna aonde quer atirar:(1-7): \n");
    scanf(" %i", &coluna);
  } while (coluna < 1 || coluna > 7);

  printf("\nDISPARAR CANHAO!!!");
  printf("\n ...");

  if (tabuleiro[linha - 1][coluna - 1] == '~'){
    tabuleiro[linha - 1][coluna - 1] = 'x';
    tiros[linha - 1][coluna - 1] = 'x';
    printf("\nNada foi atingindo.");
  }
  else{
    if (tabuleiro[linha - 1][coluna - 1] == 'N'){
      tabuleiro[linha - 1][coluna - 1] = '0';
      tiros[linha - 1][coluna - 1] = '0';
      printf("\nNavio inimigo atingido!");
    }
    else{
      printf("\nJá atiramos aqui,capitão...");
    }
  }
}

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>


#define M 8
#define N 10


//menu
void menu();

//gerador
void gera_matriz(int conjuntos[M][N], int cont);

//opcoes
void cria_conj(int conjuntos[M][N], int *cont);
void insere_dados(int conjuntos[M][N], int cont);
void remover(int conjuntos [M][N], int *cont);
void uniao(int conjuntos[M][N], int *cont);
void inter(int conjuntos[M][N], int *cont);
void mostra_conj(int conjuntos[M][N], int cont);
void mostra_todos(int conjuntos[M][N], int cont);
void buscar(int conjuntos[M][N], int cont);

//aux
int busca(int conjuntos[M][N], int conj, int n);
void auxiliar(int vet[N*2]);
void pausa();

#endif
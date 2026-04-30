#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0
#define M 10
#define N 8

typedef struct{
	int lin;
	int col;
}info;

info direcao[]={{-1,0},{0,1},{1,0},{0,-1}}; //Norte, Leste, Sul, Oeste

struct caixa{	
	info dados;
	struct caixa *abaixo;
};	

struct pilha{ 
	struct caixa *topo;
	int tamPilha;
};
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0
#define M 20
#define N 38

typedef struct{
	int lin;
	int col;
}info;

//info direcao[4]={{-1,0},{0,1},{1,0},{0,-1}}; //Norte, Leste, Sul, Oeste

struct caixa{	
	info dados;
	struct caixa *acima;
	struct caixa *abaixo;
};	

struct pilha{ 
	struct caixa *topo;
	int tamPilha;
};

//Funções da matriz
void cria_matriz();

//Funções da Pilha
struct pilha * cria(void);
int vazia(struct pilha *pil);
int empilha(info *reg, struct pilha *pil);
int desempilha(info *reg, struct pilha *pil);
int busca(info *reg, struct pilha *pil);
void reinicia(struct pilha *pil);
struct pilha *destroi(struct pilha *pil);
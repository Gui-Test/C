#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0

typedef struct {
    int lin;
    int col;
    int mov;
}info;

struct caixa{	
	info dados;
	struct caixa *abaixo;
};	

struct pilha{ 
	struct caixa *topo;
	int tamPilha;
};
#include <stdlib.h>
#include <stdio.h>

struct Data{
    int dia, mes, ano;
};

typedef struct Data data; // da um novo nome para o tipo struct, que faz com que seja possível declarar "struct Data x" como "data x" apenas;

/* 
    //Outra forma de usar 'typedef'
    typedef struct{
        int dia, mes, ano;
    }data;
*/

/*
    struct Produto {
        int codigo;
        char descricao[20];
        float preco;
        struct Data validade; <-- É possível criar um struct com uma variável do tipo struct dentro dela
    };
*/

int main(){
  data x;
  x.dia = 12;
  x.mes = 12;
  x.ano = 2012;
  printf("%d/%d/%d", x.dia,x.mes,x.ano);    
}
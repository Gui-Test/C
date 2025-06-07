#include <stdio.h>
#define S 10


void imprime_vetor(int v[],int tamanho){
    printf("[");
    for (int indice = 0; indice < tamanho;indice++){
        printf("%i ", v[indice]);
    }
    printf("]\n");
}

int main(){

    int v[S] = {2,6,8,3,10,9,1,21,33,14},menor,imenor,indice = 0,temp,i;

    //Código que procura o menor valor
    for (indice = 0; indice < S;indice++){
           
            if (v[indice]< menor){
                menor = v[indice];
                imenor = indice;
            }
    }

    printf("\nMenor Valor: %i na posicao %i \n", menor,imenor);
    imprime_vetor(v,S);

    //Codigo que organiza os elementos do vetor
    for(i = 0;i < S;i++){
    
        menor = v[i];

        for (indice = i; indice < S;indice++){
           
            if (v[indice]< menor){
                temp = v[i];
                v[i] = v[indice];
                v[indice] = temp;
            }
        }    
    }

    printf("Vetor ordenado:\n");
    imprime_vetor(v,S);    
    
}


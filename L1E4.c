#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Par, Impar, Positivo e Negativo

int main(int argc, char const *argv[])
{
    int n,total = 0;
    int pares = 0,impares = 0,positivos = 0,negativos = 0;
    
    printf("Digite o numero de inteiros que quer inserir: \n");
    scanf("%d \n", &total);

    int i = 0;
    while(i < total){
        scanf("%d", &n);

        if(n % 2 == 0){
            pares++;
        }else{
            impares++;
        }
        if(n < 0){
            negativos++;
        }else{
            positivos++;
        }
        i++;
    }

    printf("%d valor(es) par(es)\n", pares);
    printf("%d valor(es) impar(es)\n", impares);
    printf("%d valor(es) positivo(s)\n", positivos);
    printf("%d valor(es) negativo(s)\n", negativos);

}

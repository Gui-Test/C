#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Soma Impares entre X e Y II

int main(int argc, char const *argv[])
{
    int n,x,y,soma_impar = 0;

    printf("Digite quantas vezes quer fazer a soma de impares: \n");
    scanf("%d", &n);

    for(int i = 0;i < n;i++){

        soma_impar = 0;
        printf("Digite 2 numeros inteiros \n");
        scanf("%d %d", &x,&y);

        if (x > y){
            int aux = x;
            x = y;
            y = aux;
        }

        for(x++; x < y;x++){
            if(x % 2 != 0){
                soma_impar += x;
            }
        }

        printf("A soma dos impares e: %d\n", soma_impar);
    }
    
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Soma Impares entre X e Y

int main(int argc, char const *argv[])
{
    int x,y,soma_impar = 0;

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

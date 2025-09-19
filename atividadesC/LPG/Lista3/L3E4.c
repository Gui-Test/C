#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Função Soma Impares entre X e Y

int soma_impar(int x,int y);

int main(int argc, char const *argv[]){
    int x,y;
    printf("Digite 2 numeros inteiros \n");
    scanf("%d %d", &x,&y);

    printf("A soma dos impares e: %d\n", soma_impar(x,y));
    
}

int soma_impar(int x,int y){  

    if (x > y){
        int aux = x;
        x = y;
        y = aux;
    }

    if (x==y)
        return 0;
    
    x++;
    if(x % 2 != 0)
        return x + soma_impar(x,y);
    else
        return 0 + soma_impar(x,y);
}
